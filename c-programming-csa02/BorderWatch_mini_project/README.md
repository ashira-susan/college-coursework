# 🛡️ BorderWatch
### Intelligent Multi-Station Surveillance and Object Correlation System

> **Turning distributed detections into one consistent view.**

BorderWatch is a C-based surveillance simulation that models how multiple monitoring stations can communicate with a central command center, detect and correlate objects, maintain a synchronized object database, and generate alerts for critical detections.

The core idea is simple:

**Multiple Stations → Multiple Detections → Object Correlation → One Master Record**

---

## 📌 Overview

In a multi-station surveillance environment, the same object may be detected by several monitoring stations at nearly the same time.

If every detection is stored independently, the system can create duplicate records for the same physical object.

**BorderWatch solves this problem through cross-station object correlation.**

Each incoming detection is compared with existing objects using factors such as:

- 📍 Spatial proximity
- ⏱️ Detection time
- 🎯 Object characteristics
- 📡 Station source
- 📊 Detection confidence

If a new detection matches an existing object within the defined spatial and temporal thresholds, it is treated as a **duplicate detection** and merged into the existing master record.

Otherwise, a new object record is created.

---

## 🎯 Key Idea

Imagine three surveillance stations detecting the same object:

```text
Station 1 ─────┐
               │
Station 2 ─────┼──→ BorderWatch ──→ One Master Object
               │
Station 3 ─────┘
