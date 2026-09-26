/* main.c - entry point for the BorderWatch Command Center executable.
 * Wires together: logger, database, zone tree, and the socket server.
 * (station.c and response.c each have their OWN main() and are built
 * as separate executables - see the Makefile.)
 */
#include <stdio.h>
#include "logger.h"
#include "database.h"
#include "zones.h"
#include "server.h"

ZoneNode *g_zone_root = NULL; /* referenced by database.c for zone lookups */

int main(void) {
    logger_init();
    db_init();
    g_zone_root = build_demo_zone_tree();

    run_server();   /* blocks here until Ctrl+C (SIGINT) */

    printf("\n[MAIN] Shutting down. Final report:\n");
    db_print_all();
    printf("\n[MAIN] Zone hierarchy (recursive traversal):\n");
    print_zone_tree(g_zone_root, 0);

    free_zone_tree(g_zone_root);
    db_destroy();
    return 0;
}
