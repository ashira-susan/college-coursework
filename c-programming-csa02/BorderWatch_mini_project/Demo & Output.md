# BorderWatch — Execution & Demonstration

This section captures the live execution of **BorderWatch**, showing how the Response Process, Central Command Center, and multiple Surveillance Stations interact during a complete surveillance cycle.

---

## 01 — The Response System Takes Position

The Response Process is launched first and remains on standby, ready to receive critical or high-priority alerts from the command center through **System V Message Queues**.

<img width="1156" height="347" alt="image" src="https://github.com/user-attachments/assets/9928e422-ef81-47ec-acc3-73c67f4762e9" />


> **Status:** Response Process active — waiting for incoming alerts.

---

## 02 — The Command Center Goes Live

The BorderWatch Central Command Center is now running and listening for incoming surveillance stations through a **TCP connection**.

<img width="993" height="241" alt="image" src="https://github.com/user-attachments/assets/34e169dc-bb2a-4a64-92c8-73740e128d62" />


> **Status:** Command Center active — waiting for surveillance stations.

---

## 03 — Surveillance Station 1 Enters the Network

Station 1 establishes a connection with the Central Command Center and begins transmitting its surveillance observations.

<img width="1306" height="517" alt="image" src="https://github.com/user-attachments/assets/803d040f-7d8d-48ed-bef3-ad883302a578" />


> **Event:** Station 1 connected successfully and began transmitting detection data.

---

## 04 — Station 1 Completes Its Transmission

After sending its detection reports, Station 1 completes its communication session and disconnects from the command center.

<img width="1306" height="517" alt="image" src="https://github.com/user-attachments/assets/79d86290-3608-4035-9a85-7f47ea39fcd4" />


> **Event:** Station 1 completed its transmission and disconnected successfully.

---

## 05 — An Alert Reaches the Response Process

The surveillance information processed by the command center results in an alert being delivered to the independent Response Process.

<img width="1305" height="632" alt="image" src="https://github.com/user-attachments/assets/2d9e693a-8c2c-47ed-8bf1-d4eb0234e904" />


> **Alert:** The Response Process successfully received and processed the incoming surveillance alert.

---

## 06 — The Command Center Processes the Evidence

The Central Command Center processes Station 1's reports and updates its dynamically managed object database.

<img width="1327" height="558" alt="image" src="https://github.com/user-attachments/assets/405155f3-c3d4-4de6-a683-ca3d9292b265" />


> **Processing:** Incoming detections are analyzed against existing object records to identify new objects and possible duplicates.

---

## 07 — A Second Station Joins the Operation

Station 2 now connects to the command center, introducing another independent surveillance source into the system.

<img width="1340" height="615" alt="image" src="https://github.com/user-attachments/assets/46d2fa62-8c54-49d1-9181-906d687a0c00" />


> **Event:** Station 2 connected successfully and began transmitting its observations.

---

## 08 — Station 2 Completes Its Transmission

After delivering its surveillance reports, Station 2 closes its connection with the command center.

<img width="1340" height="615" alt="image" src="https://github.com/user-attachments/assets/97a48a39-334b-4586-9a42-66da051ae7d3" />


> **Event:** Station 2 completed its transmission and disconnected successfully.

---

## 09 — The Response System Receives Another Alert

The Response Process continues operating independently and receives the alert generated from the newly processed surveillance data.

<img width="1033" height="827" alt="image" src="https://github.com/user-attachments/assets/59d4e832-400f-42dd-8925-0a9cfa51386f" />


> **Alert:** A subsequent surveillance event has been forwarded to the Response Process for attention.

---

## 10 — Multiple Observations Become One Consistent View

The Central Command Center processes Station 2's observations and compares them with the existing object records.

Through **spatial-temporal correlation**, detections representing the same physical object can be recognized and merged instead of creating duplicate records.

<img width="1030" height="488" alt="image" src="https://github.com/user-attachments/assets/f50e00af-0135-4530-bbe6-db5abfc3ca2f" />


> **Correlation:** Observations from different surveillance stations are consolidated into a consistent master object record.

---

# The Complete Execution Flow

```text
        RESPONSE PROCESS
              │
              │  waits for alerts
              ▼
       COMMAND CENTER
              │
       ┌──────┴──────┐
       │             │
       ▼             ▼
   STATION 1      STATION 2
       │             │
       ▼             ▼
   Detection      Detection
       │             │
       └──────┬──────┘
              ▼
      OBJECT CORRELATION
              │
              ▼
       MASTER DATABASE
              │
              ▼
        ALERT / LOGGING
```

The execution demonstrates the complete interaction between **distributed surveillance stations, the centralized command center, the dynamic object database, and the independent response system**.

Each station contributes observations, while BorderWatch brings those observations together to build a unified view of detected objects.
