#ifndef ZONES_H
#define ZONES_H

#define MAX_ZONE_CHILDREN 6
#define MAX_ZONE_NAME     32

typedef struct ZoneNode {
    int    zone_id;
    char   name[MAX_ZONE_NAME];
    double lat_min, lat_max;
    double lon_min, lon_max;
    int    object_count;
    struct ZoneNode *children[MAX_ZONE_CHILDREN];
    int    num_children;
} ZoneNode;

ZoneNode *build_demo_zone_tree(void);
void      free_zone_tree(ZoneNode *root);

/* RECURSION: finds the smallest (leaf-most) zone containing (lat,lon). */
int find_zone_recursive(ZoneNode *node, double lat, double lon);

/* RECURSION: walks the tree to bump the object_count of a zone_id. */
int tag_object_in_zone(ZoneNode *node, int zone_id);

/* RECURSION: pretty-prints the whole hierarchy with indentation. */
void print_zone_tree(ZoneNode *node, int depth);

#endif
