# BorderWatch

## Intelligent Multi-Station Surveillance and Object Correlation System

> Turning multiple station detections into one consistent object record.

BorderWatch is a C-based multi-station surveillance simulation developed using GCC on Linux/WSL Ubuntu.

The system models multiple surveillance stations communicating with a central command center through TCP sockets. Since different stations may detect the same physical object at nearly the same time, BorderWatch uses a spatial-temporal duplicate detection mechanism to determine whether an incoming detection represents a new object or an already detected object.

When a duplicate is identified, the new detection is merged into the existing master record instead of creating another object.

The project combines C programming, structures, pointers, dynamic memory allocation, linked lists, recursion, TCP networking, POSIX threads, mutex synchronization, file handling, and System V IPC into one integrated system.


--------------------------------------------------
PROJECT OVERVIEW
--------------------------------------------------

In a multi-station surveillance environment, the same object may be detected by several monitoring stations.

For example:

Station 1 → detects Object X
Station 2 → detects the same Object X
Station 3 → detects the same Object X

Without correlation:

Detection 1 → Object A
Detection 2 → Object B
Detection 3 → Object C

BorderWatch instead identifies these detections as belonging to the same physical object:

                    MASTER OBJECT
                   /      |      \
                  /       |       \
            Station 1  Station 2  Station 3

This prevents duplicate records and maintains a consistent representation of monitored objects.


--------------------------------------------------
KEY FEATURES
--------------------------------------------------

1. Multi-Station TCP Communication

Multiple simulated surveillance stations operate as TCP clients and send detection reports to a central command center.

2. Spatial-Temporal Duplicate Detection

Incoming detections are compared with existing objects using spatial and temporal conditions.

3. Object Correlation and Merging

If a detection matches an existing object, it is merged into the existing master record instead of creating a duplicate.

4. Multithreaded Processing

The command center uses POSIX threads to process multiple station connections concurrently.

5. Mutex Synchronization

A pthread_mutex_t protects shared database operations and prevents race conditions.

6. Dynamic Linked-List Database

Objects are dynamically allocated using malloc() and maintained through a linked-list database.

7. Hierarchical Surveillance Zones

The surveillance area is represented using a hierarchy such as:

Sector
    └── Subsector
            └── Post

8. Recursive Zone Traversal

Recursion is used to traverse the hierarchical surveillance zone structure.

9. Event Logging

Important surveillance events are stored in an append-only surveillance.log file.

10. System V IPC Alerts

High-priority objects can generate alerts through a System V message queue.

11. Independent Response Process

The response component runs as a separate process and receives alerts through IPC.

12. Modular Architecture

Each major responsibility is separated into its own C source and header files.


--------------------------------------------------
SYSTEM ARCHITECTURE
--------------------------------------------------

                    +------------------+
                    |    Station 1     |
                    |    TCP Client    |
                    +--------+---------+
                             |
                             |
                    +--------v---------+
                    |    Station 2     |
                    |    TCP Client    |
                    +--------+---------+
                             |
                             |
                    +--------v---------+
                    |    Station N     |
                    |    TCP Client    |
                    +--------+---------+
                             |
                             |
                           TCP
                             |
                             v
              +-----------------------------+
              |     CENTRAL COMMAND        |
              |          CENTER            |
              |                             |
              |   TCP Server + Pthreads    |
              +-------------+---------------+
                            |
                            v
                 +----------------------+
                 | Object Registration  |
                 +----------+-----------+
                            |
                            v
                 +----------------------+
                 | Duplicate Detection |
                 | Spatial + Temporal   |
                 +----------+-----------+
                            |
                     +------+------+
                     |             |
                   MATCH        NO MATCH
                     |             |
                     v             v
                  MERGE         CREATE
                 EXISTING       NEW OBJECT
                     |             |
                     +------+------+
                            |
                            v
                 +----------------------+
                 | Synchronized Linked  |
                 |    List Database     |
                 +----------+-----------+
                            |
                    +-------+-------+
                    |               |
                    v               v
              surveillance.log   Alert / IPC
                                    |
                                    v
                            Response Process


--------------------------------------------------
SYSTEM WORKFLOW
--------------------------------------------------

Station Detection
        |
        v
TCP Communication
        |
        v
Central Command Center
        |
        v
Object Registration
        |
        v
Object Classification
        |
        v
Duplicate Detection
        |
        +----------------------+
        |                      |
      Match                 No Match
        |                      |
        v                      v
     Merge                  New Record
        |                      |
        +----------+-----------+
                   |
                   v
          Synchronized Database
                   |
                   v
             Event Logging
                   |
                   v
            Alert Generation
                   |
                   v
         System V Message Queue
                   |
                   v
           Response Process


--------------------------------------------------
PROJECT STRUCTURE
--------------------------------------------------

BorderWatch/
|
|-- types.h
|
|-- object.c
|-- object.h
|
|-- duplicate.c
|-- duplicate.h
|
|-- database.c
|-- database.h
|
|-- zones.c
|-- zones.h
|
|-- server.c
|-- server.h
|
|-- station.c
|-- station.h
|
|-- ipc.c
|-- ipc.h
|
|-- logger.c
|-- logger.h
|
|-- main.c
|-- response.c
|
|-- Makefile
|
`-- surveillance.log


--------------------------------------------------
MODULE DESCRIPTION
--------------------------------------------------

types.h

Contains shared structures, constants, and common data definitions used throughout the project.


object.c / object.h

Responsible for the object model.

Main responsibilities include:

- Creating objects
- Classifying objects
- Printing object information


duplicate.c / duplicate.h

Contains the core duplicate-detection algorithm.

This module is deliberately isolated because duplicate detection and object correlation are the central features of BorderWatch.

It determines whether a new detection should be treated as:

- A new object
- A duplicate of an existing object


database.c / database.h

Responsible for:

- Linked-list object storage
- Dynamic object management
- Mutex synchronization
- Object registration
- Duplicate handling
- Record merging


zones.c / zones.h

Responsible for the hierarchical surveillance zone tree.

All recursive zone traversal functionality is contained in this module.


server.c / server.h

Responsible for:

- TCP server operation
- Accepting station connections
- Creating station threads
- Receiving detection reports
- Processing incoming reports


station.c / station.h

Implements the simulated surveillance station.

Each station acts as an independent TCP client and sends detection reports to the command center.


ipc.c / ipc.h

Handles System V message queue operations used for alert communication.


logger.c / logger.h

Responsible for writing surveillance events to surveillance.log.


main.c

Command-center entry point that initializes and connects the different modules.


response.c

Independent response process.

It has its own main() function and waits for alerts through the System V message queue.


Makefile

Automates compilation of the three independent executables.


--------------------------------------------------
WHY THE PROJECT IS SPLIT THIS WAY
--------------------------------------------------

The project follows a modular architecture so that each major responsibility remains isolated.

The most important separation is between object management and database management.

object.c handles one object.

database.c handles the collection of objects.

duplicate.c handles the decision of whether a detection belongs to an existing object.

This makes the core correlation algorithm easy to locate and understand without going through the networking implementation.

The station and response components also have their own main() functions because they represent independent processes.

Therefore, the project is intentionally built into separate executables instead of compiling every .c file into a single program.


--------------------------------------------------
OBJECT CORRELATION
--------------------------------------------------

Object correlation is the core feature of BorderWatch.

When a new detection arrives, the system compares it with existing objects.

The basic process is:

                 NEW DETECTION
                       |
                       v
              SEARCH EXISTING OBJECTS
                       |
                       v
             COMPARE LOCATION & TIME
                       |
                 +-----+-----+
                 |           |
              MATCH       NO MATCH
                 |           |
                 v           v
              DUPLICATE   NEW OBJECT
                 |
                 v
              MERGE
                 |
                 v
        UPDATE MASTER RECORD


The correlation process considers factors such as:

- Spatial distance
- Time difference
- Object characteristics
- Detection information
- Station source


--------------------------------------------------
DUPLICATE DETECTION
--------------------------------------------------

The system uses spatial-temporal thresholds to determine whether two detections are likely to represent the same physical object.

For example:

Station 1:

Object detected
Location: Near Point A
Time: T1

Station 2:

Object detected
Location: Very close to Point A
Time: Shortly after T1

If the detection satisfies the configured correlation conditions, BorderWatch classifies it as a duplicate.

The system then updates the existing master object rather than creating another object.


--------------------------------------------------
RECORD MERGING
--------------------------------------------------

When a duplicate is detected:

Existing Master Record
        +
New Detection
        |
        v
Updated Master Record

The master record can be updated with information such as:

- Latest location
- Last-seen time
- Confidence
- Detection source
- Other relevant object information

This allows the system to maintain one consistent record for an object detected by multiple stations.


--------------------------------------------------
DYNAMIC OBJECT DATABASE
--------------------------------------------------

BorderWatch maintains objects using a dynamically allocated linked list.

Objects are created using:

malloc()

Each object contains information related to its detection and tracking state.

Conceptually:

ObjectNode
|
|-- Object Information
|-- Location
|-- Timestamp
|-- Confidence
|-- Classification
|-- Source Station
|-- Status / Priority
`-- Next Object

Dynamic allocation allows the object database to grow during runtime without requiring a fixed number of objects.


--------------------------------------------------
MULTITHREADING
--------------------------------------------------

Multiple stations can send detection reports at the same time.

The command center creates a separate POSIX thread for each station connection.

                TCP SERVER
                    |
          +---------+---------+
          |         |         |
          v         v         v
       Thread 1  Thread 2  Thread 3
          |         |         |
          v         v         v
       Station 1 Station 2 Station 3

This allows the command center to process multiple station feeds concurrently.


--------------------------------------------------
MUTEX SYNCHRONIZATION
--------------------------------------------------

Because multiple station threads access the same object database, shared operations must be protected.

BorderWatch uses:

pthread_mutex_t

to protect critical database operations.

The mutex is important during:

- Object insertion
- Duplicate checking
- Object merging
- Linked-list modification

Conceptually:

Station Thread 1 ----+
Station Thread 2 ----+----> MUTEX LOCK
Station Thread 3 ----+
                          |
                          v
                   SHARED DATABASE
                          |
                          v
                     MUTEX UNLOCK

This prevents multiple threads from modifying shared data in an unsafe manner.


--------------------------------------------------
TCP COMMUNICATION
--------------------------------------------------

The surveillance stations act as TCP clients.

The command center operates as a TCP server.

Station 1 ----+
Station 2 ----+---- TCP ----> Command Center
Station 3 ----+

The server accepts station connections and processes their reports using separate threads.


--------------------------------------------------
TCP STREAM HANDLING
--------------------------------------------------

One important implementation detail is that TCP is a byte stream and does not preserve application-level message boundaries.

A single report may be split across multiple recv() calls.

Therefore, BorderWatch uses a per-connection accumulator buffer.

Incoming bytes
      |
      v
Connection Buffer
      |
      v
Extract Complete Lines
      |
      v
Process Complete Reports
      |
      v
Keep Partial Data
      |
      v
Wait for Next recv()


This ensures that incomplete TCP messages are not processed incorrectly.


--------------------------------------------------
THREAD-SAFE REPORT PARSING
--------------------------------------------------

The server uses:

strtok_r()

for parsing incoming station reports.

The original implementation used:

strtok()

However, strtok() maintains parsing state that is not suitable for concurrent parsing across multiple station threads.

This could result in corrupted token streams when multiple threads attempted to parse reports simultaneously.

The parser was therefore changed to strtok_r(), which provides independent parsing state for each parsing operation.

This change was verified through concurrent testing.


--------------------------------------------------
HIERARCHICAL SURVEILLANCE ZONES
--------------------------------------------------

BorderWatch represents surveillance locations using a hierarchical tree.

Example:

Sector
|
+-- Subsector A
|   |
|   +-- Post 1
|   `-- Post 2
|
+-- Subsector B
|   |
|   +-- Post 3
|   `-- Post 4
|
`-- Subsector C
    |
    `-- Post 5

Recursive functions are used to traverse the zone hierarchy.

This demonstrates practical use of:

- Trees
- Recursion
- Hierarchical data representation


--------------------------------------------------
LOGGING
--------------------------------------------------

Important system events are stored in:

surveillance.log

Examples include:

- Detection received
- New object created
- Duplicate detected
- Object merged
- High-priority object identified
- Alert generated

The log provides a persistent audit trail of surveillance activity.

The log is also used during testing to verify that reports were correctly processed.


--------------------------------------------------
SYSTEM V IPC
--------------------------------------------------

When a high-priority or suspicious object is identified, BorderWatch can generate an alert.

The command center sends the alert through a System V message queue.

Command Center
      |
      | Alert
      v
System V Message Queue
      |
      v
Response Process
      |
      v
Alert Display

The response process is independent of the command center and receives alerts through IPC.


--------------------------------------------------
TECHNOLOGY STACK
--------------------------------------------------

Programming Language:
C

Operating Environment:
Linux / WSL Ubuntu

Compiler:
GCC

Development Environment:
VS Code + WSL

Networking:
TCP Sockets

Concurrency:
POSIX Threads (pthreads)

Synchronization:
pthread_mutex_t

Data Structure:
Linked List

Dynamic Memory:
malloc()

Hierarchical Structure:
Tree

Algorithm:
Spatial-Temporal Duplicate Detection

Recursion:
Hierarchical Zone Traversal

Inter-Process Communication:
System V Message Queue

File Handling:
Append-Only Logging

Build System:
GNU Make


--------------------------------------------------
REQUIREMENTS
--------------------------------------------------

The project requires:

- Linux or WSL Ubuntu
- GCC
- GNU Make
- POSIX thread support
- Linux socket support
- System V IPC support


--------------------------------------------------
WSL + VS CODE SETUP
--------------------------------------------------

1. Install WSL

Open PowerShell as Administrator:

wsl --install

Restart Windows if prompted.

Then open Ubuntu.


2. Install Build Tools

Inside Ubuntu:

sudo apt update
sudo apt install build-essential

Check GCC:

gcc --version

Check Make:

make --version


3. Open the Project in VS Code

Install the WSL extension in VS Code.

From the Ubuntu terminal, navigate to the BorderWatch project directory and run:

code .

This opens the project inside the Linux/WSL development environment.


--------------------------------------------------
BUILDING THE PROJECT
--------------------------------------------------

The project contains three independent executables:

borderwatch
station
response

Build the complete project using:

make


--------------------------------------------------
WHY gcc *.c DOES NOT WORK
--------------------------------------------------

A common approach would be:

gcc *.c -o borderwatch -pthread

However, this will fail because the project contains multiple main() functions.

main.c
    -> Command Center

station.c
    -> Station Process

response.c
    -> Response Process

The linker therefore encounters multiple definitions of main().

The Makefile solves this by compiling the different components into separate executables.

Therefore:

make

is the recommended build command.


--------------------------------------------------
RUNNING THE DEMO
--------------------------------------------------

Build the project:

make

Start the response process first:

./response &

Start the command center:

./borderwatch &

Start Station 1:

./station 1

Start Station 2:

./station 2


The demonstration allows multiple stations to send overlapping detection reports to the command center.


--------------------------------------------------
WHAT TO OBSERVE
--------------------------------------------------

Command Center:

The command center displays whether incoming reports are:

NEW

or:

DUPLICATE-MERGED


Response Process:

For high-priority objects, the response process displays:

*** RESPONSE ALERT ***


Log File:

The file:

surveillance.log

accumulates timestamped surveillance events.


--------------------------------------------------
DEMONSTRATION SCENARIO
--------------------------------------------------

Station 1 detects an object.

Station 1
    |
    v
Object Detection
    |
    v
Command Center
    |
    v
NEW Object

Station 2 then detects a similar object within the configured spatial and temporal thresholds.

Station 2
    |
    v
Similar Detection
    |
    v
Command Center
    |
    v
Duplicate Detection
    |
    v
DUPLICATE-MERGED

Instead of storing two objects, the command center maintains one master record.

Example:

Before correlation:

Object 101
Object 102

After correlation:

Master Object 101
    |
    +-- Station 1 Detection
    `-- Station 2 Detection


--------------------------------------------------
VERIFICATION
--------------------------------------------------

The complete project pipeline was compiled and executed successfully.

Compilation was performed using:

gcc -Wall -Wextra -pthread -lm

The project compiled with zero warnings.

The end-to-end test included:

- Command center
- Response process
- Multiple station processes
- TCP communication
- Duplicate detection
- Object merging
- Logging
- IPC alerts

An initial functional test used two stations reporting overlapping detections.

The result was:

3 physical objects
        |
        v
Detected by both stations
        |
        v
6 incoming reports
        |
        v
3 master object records

All three objects were correctly collapsed into one record each.


--------------------------------------------------
CONCURRENCY STRESS TEST
--------------------------------------------------

The system was tested under significantly heavier conditions.

Test configuration:

10 concurrent stations
x
100 reports per station
=
1000 total reports

The TCP messages were deliberately fragmented into 3-byte sends.

This was done to test both:

1. Concurrent station processing
2. TCP partial-message handling

Final result:

Total Reports: 1000
Processed:     1000
Malformed:     0
Dropped:       0

The results were verified against surveillance.log.

The log is treated as the authoritative event record because each event is explicitly written and closed using fopen() / fclose().


--------------------------------------------------
BUGS FOUND AND FIXED
--------------------------------------------------

The project was tested beyond the normal demonstration path.

Two important implementation issues were discovered and fixed.


1. strtok() Thread-Safety Issue

The original server parser used:

strtok()

The problem was that multiple station threads could call strtok() at the same time.

Because strtok() maintains internal parsing state, concurrent calls could interfere with one another.

An isolated 8-thread stress test of bare strtok() demonstrated that parsing corruption could occur under contention.

The observed behavior matched the type of issue that could result in:

Malformed report ignored

under concurrent station activity.

Fix:

The parser was changed from:

strtok()

to:

strtok_r()

strtok_r() keeps the parsing state separate for each parsing operation.

This makes the report parsing suitable for concurrent station threads.


2. TCP Message Fragmentation

The original server assumed that each recv() call would return a complete newline-terminated report.

This assumption is incorrect because TCP is a byte-stream protocol.

A single application-level message can be split across multiple recv() calls.

For example:

Expected:

REPORT DATA\n

Actual TCP delivery:

recv() -> REPORT
recv() ->  DATA
recv() -> \n

Fix:

A per-connection accumulator buffer was implemented.

Incoming bytes are:

1. Appended to the connection buffer
2. Checked for complete lines
3. Processed when a complete line is available
4. Retained if a partial line remains

This allows the server to correctly reconstruct fragmented TCP reports.


--------------------------------------------------
FINAL STRESS TEST
--------------------------------------------------

After both fixes were implemented, the system was tested again.

Test:

10 concurrent stations
100 reports per station
1000 total reports
3-byte TCP fragmentation
Maximum thread contention

Result:

1000 reports received
1000 reports processed
0 malformed reports
0 dropped reports

The final result confirmed correct handling of both concurrency and fragmented TCP delivery.


--------------------------------------------------
ADVANTAGES
--------------------------------------------------

- Reduces duplicate object records across stations.
- Supports concurrent multi-station communication.
- Maintains synchronized shared data.
- Dynamically allocates objects at runtime.
- Uses a modular architecture.
- Handles fragmented TCP messages correctly.
- Uses thread-safe report parsing.
- Maintains a persistent surveillance log.
- Separates alert handling into an independent process.
- Demonstrates multiple practical Linux systems-programming concepts.


--------------------------------------------------
LIMITATIONS
--------------------------------------------------

- Detection data is simulated rather than collected from physical sensors.
- Duplicate detection depends on predefined spatial and temporal thresholds.
- A linked-list database may become less efficient for extremely large datasets.
- The system does not currently perform advanced computer-vision-based object recognition.
- Communication security such as encryption and authentication is not implemented.
- The project is a surveillance simulation and is not intended as a production deployment.


--------------------------------------------------
FUTURE SCOPE
--------------------------------------------------

1. Real Sensor Integration

The simulated stations can be replaced or supplemented with:

- Cameras
- Radar
- GPS
- IoT sensors


2. Advanced Object Tracking

The correlation mechanism can be extended with:

- Multi-object tracking
- Predictive movement analysis
- Trajectory matching
- Anomaly detection


3. Live Surveillance Dashboard

A graphical dashboard could display:

- Station locations
- Detected objects
- Object movement
- Surveillance zones
- Real-time alerts


4. Secure Communication

Future versions can introduce:

- Station authentication
- Encrypted communication
- Secure command-center access


5. Scalable Storage

The linked-list prototype can be extended with:

- Indexed data structures
- Persistent databases
- High-volume object storage


6. Intelligent Alert Management

The alert system can be extended with:

- Configurable priority levels
- Automated response workflows
- Advanced event classification


--------------------------------------------------
CORE C / LINUX CONCEPTS DEMONSTRATED
--------------------------------------------------

C Programming:

- Structures
- Pointers
- Functions
- Modular programming
- Dynamic memory allocation
- File handling

Data Structures:

- Linked lists
- Trees
- Hierarchical data structures

Algorithms:

- Spatial-temporal comparison
- Duplicate detection
- Object merging
- Recursive traversal

Linux Systems Programming:

- TCP sockets
- POSIX threads
- Mutex synchronization
- System V message queues
- Multi-process execution

Concurrency:

- Thread creation
- Shared data protection
- Thread-safe parsing
- Concurrent client processing

Networking:

- TCP client-server architecture
- recv() handling
- Partial message reconstruction
- Multi-client communication


--------------------------------------------------
DEVELOPMENT ORDER
--------------------------------------------------

The project can be developed incrementally from the basic object model to the complete surveillance system.

1. Object Model

types.h
object.c
object.h

Create, classify, allocate, and display objects.


2. Database

database.c
database.h

Implement the linked list and basic object registration.


3. Duplicate Detection

duplicate.c
duplicate.h

Add spatial-temporal matching and object merging.


4. Zone Tree

zones.c
zones.h

Implement hierarchical zones and recursive traversal.


5. Logging

logger.c
logger.h

Add persistent event logging.


6. Networking

server.c
station.c

Add TCP communication and pthread-based station processing.


7. IPC

ipc.c
response.c

Add System V message queues and the independent response process.


--------------------------------------------------
LEARNING OUTCOMES
--------------------------------------------------

This project provided practical experience with:

- Modular C programming
- Structures and pointers
- Dynamic memory allocation
- Linked-list implementation
- Recursive tree traversal
- TCP client-server programming
- POSIX multithreading
- Mutex synchronization
- Thread-safe parsing
- TCP stream handling
- File-based logging
- System V IPC
- Multi-process architecture
- Concurrent system design
- Debugging and stress testing


--------------------------------------------------
PROJECT HIGHLIGHT
--------------------------------------------------

The central idea of BorderWatch is not simply detecting objects.

It is correlating information from multiple sources.

The system asks:

"What did each station detect?"

and then goes one step further:

"Which detections belong to the same physical object?"

This allows distributed observations to be transformed into a single continuously updated master record.


--------------------------------------------------
PROJECT SUMMARY
--------------------------------------------------

BorderWatch demonstrates how fundamental C and Linux systems-programming concepts can be combined to create a multi-station surveillance simulation.

The system integrates:

TCP Networking
      +
POSIX Multithreading
      +
Mutex Synchronization
      +
Dynamic Memory
      +
Linked Lists
      +
Recursive Tree Traversal
      +
Spatial-Temporal Correlation
      +
Object Merging
      +
File Logging
      +
System V IPC
      +
Multi-Process Communication

The result is a modular system where multiple stations can report detections concurrently while the command center maintains a synchronized and deduplicated view of monitored objects.


--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

"BorderWatch connects the dots — transforming distributed surveillance detections into one consistent view of the monitored environment."


--------------------------------------------------
PROJECT INFORMATION
--------------------------------------------------

Project Name:
BorderWatch

Full Title:
Intelligent Multi-Station Surveillance and Object Correlation System

Language:
C

Platform:
Linux / WSL Ubuntu

Compiler:
GCC

Development Environment:
VS Code + WSL

Architecture:
Multi-Station Client-Server

Communication:
TCP + System V IPC

Concurrency:
POSIX Threads + Mutex

Database:
Dynamic Linked List

Hierarchy:
Recursive Zone Tree

Build System:
GNU Make


--------------------------------------------------
LICENSE
--------------------------------------------------

This project was developed as an academic/hackathon project for learning, experimentation, and demonstration of C/Linux systems programming concepts.

If you reuse or extend this project, please provide appropriate attribution.
