#ifndef SERVER_H
#define SERVER_H

/* Sets up the TCP listening socket and runs the accept loop, spawning
 * one pthread per connected station, until a SIGINT sets g_running=0. */
void run_server(void);

#endif
