/* response.c - a SEPARATE process (not a thread!) representing the
 * "response team" system. It blocks on the System V message queue
 * and reacts whenever main.c's command center pushes a high-priority
 * alert via ipc.c. This is the IPC leg: two independent processes
 * (detection side = main.c, response side = this file) talking
 * through a kernel-managed queue rather than shared memory/threads.
 */
#include <stdio.h>
#include <sys/msg.h>
#include "types.h"
#include "ipc.h"

int main(void) {
    int qid = get_alert_queue();
    if (qid == -1) {
        fprintf(stderr, "[RESPONSE] could not attach to alert queue\n");
        return 1;
    }
    printf("[RESPONSE] Response process online. Waiting for alerts...\n");

    AlertMsg msg;
    while (1) {
        ssize_t n = msgrcv(qid, &msg, sizeof(AlertMsg) - sizeof(long), ALERT_MSG_TYPE, 0);
        if (n == -1) { perror("msgrcv"); break; }

        printf("\n*** RESPONSE ALERT ***\n");
        printf("  Object ID     : %d\n", msg.object_id);
        printf("  Classification: %s\n", msg.classification);
        printf("  Location      : (%.4f, %.4f)\n", msg.latitude, msg.longitude);
        printf("  Confidence    : %.2f\n", msg.confidence);
        printf("  -> Dispatching response unit.\n");
        printf("***********************\n\n");
    }
    return 0;
}
