#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "ipc.h"
#include "types.h"

int get_alert_queue(void) {
    key_t key = ftok(IPC_KEY_PATH, IPC_KEY_ID);
    if (key == -1) { perror("ftok"); return -1; }
    int qid = msgget(key, IPC_CREAT | 0666);
    if (qid == -1) { perror("msgget"); return -1; }
    return qid;
}

void send_alert(int object_id, const char *classification,
                 double lat, double lon, float confidence) {
    int qid = get_alert_queue();
    if (qid == -1) return;

    AlertMsg msg;
    msg.mtype = ALERT_MSG_TYPE;
    msg.object_id = object_id;
    strncpy(msg.classification, classification, MAX_CLASS_LEN - 1);
    msg.classification[MAX_CLASS_LEN - 1] = '\0';
    msg.latitude = lat;
    msg.longitude = lon;
    msg.confidence = confidence;

    if (msgsnd(qid, &msg, sizeof(AlertMsg) - sizeof(long), 0) == -1) {
        perror("msgsnd");
    } else {
        printf("[ALERT-SENT] object %d (%s) pushed to response.c via IPC\n",
               object_id, classification);
    }
}
