#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zones.h"

static ZoneNode *make_zone(int id, const char *name,
                            double lat_min, double lat_max,
                            double lon_min, double lon_max) {
    ZoneNode *z = malloc(sizeof(ZoneNode));
    z->zone_id = id;
    strncpy(z->name, name, MAX_ZONE_NAME - 1);
    z->name[MAX_ZONE_NAME - 1] = '\0';
    z->lat_min = lat_min; z->lat_max = lat_max;
    z->lon_min = lon_min; z->lon_max = lon_max;
    z->object_count = 0;
    z->num_children = 0;
    return z;
}

/* Builds a small demo hierarchy:
 *   Sector-North (root)
 *     Subsector-A
 *       Post-A1
 *       Post-A2
 *     Subsector-B
 *       Post-B1
 *       Post-B2
 */
ZoneNode *build_demo_zone_tree(void) {
    ZoneNode *root = make_zone(1, "Sector-North", 10.0, 14.0, 76.0, 82.0);

    ZoneNode *subA = make_zone(2, "Subsector-A", 12.0, 14.0, 76.0, 79.0);
    ZoneNode *postA1 = make_zone(3, "Post-A1", 12.0, 13.0, 76.0, 77.5);
    ZoneNode *postA2 = make_zone(4, "Post-A2", 13.0, 14.0, 77.5, 79.0);
    subA->children[subA->num_children++] = postA1;
    subA->children[subA->num_children++] = postA2;

    ZoneNode *subB = make_zone(5, "Subsector-B", 10.0, 12.0, 79.0, 82.0);
    ZoneNode *postB1 = make_zone(6, "Post-B1", 10.0, 11.0, 79.0, 80.5);
    ZoneNode *postB2 = make_zone(7, "Post-B2", 11.0, 12.0, 80.5, 82.0);
    subB->children[subB->num_children++] = postB1;
    subB->children[subB->num_children++] = postB2;

    root->children[root->num_children++] = subA;
    root->children[root->num_children++] = subB;
    return root;
}

static void free_zone_recursive(ZoneNode *node) {
    if (!node) return;
    for (int i = 0; i < node->num_children; i++)
        free_zone_recursive(node->children[i]);
    free(node);
}

void free_zone_tree(ZoneNode *root) { free_zone_recursive(root); }

/* RECURSION #1: descend into whichever child's bounding box contains
 * the point; if none of the children match, this node itself is the
 * answer (leaf-most containing zone). */
int find_zone_recursive(ZoneNode *node, double lat, double lon) {
    if (!node) return -1;

    if (lat < node->lat_min || lat > node->lat_max ||
        lon < node->lon_min || lon > node->lon_max) {
        return -1; /* outside this node's box entirely */
    }

    for (int i = 0; i < node->num_children; i++) {
        int result = find_zone_recursive(node->children[i], lat, lon);
        if (result != -1) return result; /* a deeper zone matched */
    }
    return node->zone_id; /* this node is the deepest match */
}

/* RECURSION #2: walk the whole tree looking for the zone_id to bump
 * its counter. Demonstrates recursive search separate from the
 * geometric descent above. */
int tag_object_in_zone(ZoneNode *node, int zone_id) {
    if (!node) return 0;
    if (node->zone_id == zone_id) {
        node->object_count++;
        return 1;
    }
    for (int i = 0; i < node->num_children; i++) {
        if (tag_object_in_zone(node->children[i], zone_id)) return 1;
    }
    return 0;
}

/* RECURSION #3: pretty-print the hierarchy. */
void print_zone_tree(ZoneNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("- %s (zone_id=%d, objects=%d)\n",
           node->name, node->zone_id, node->object_count);
    for (int i = 0; i < node->num_children; i++)
        print_zone_tree(node->children[i], depth + 1);
}
