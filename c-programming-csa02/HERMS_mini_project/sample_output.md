# Sample Output

## 1. Main Menu and System Initialization

The application starts by displaying the system title and provides an option to load previously saved resource records.

<img width="855" height="612" alt="WhatsApp Image 2026-09-01 at 10 26 02 AM" src="https://github.com/user-attachments/assets/15da6258-3546-429f-b183-4ad1b3777307" />



---

## 2. Add Resource

A new resource can be added by entering its ID, name, category, department, quantity, minimum threshold, and priority. The system automatically determines the resource status.

<img width="535" height="266" alt="WhatsApp Image 2026-09-01 at 10 26 59 AM" src="https://github.com/user-attachments/assets/2590b216-b90e-420d-b219-f23da045ef34" />


---

## 3. Update Resource

Existing resource details can be modified. After an update, the system recalculates the resource status based on the updated quantity and threshold.

<img width="576" height="268" alt="WhatsApp Image 2026-09-01 at 10 27 26 AM" src="https://github.com/user-attachments/assets/f9b7a72f-617f-4ae7-826f-d0ac4b234a7b" />


---

## 4. Display All Resources

The system displays all stored resources in a structured table containing the resource ID, name, category, quantity, threshold, priority, status, and department.

<img width="855" height="237" alt="WhatsApp Image 2026-09-01 at 10 28 13 AM" src="https://github.com/user-attachments/assets/1fa8d6d4-8da3-413b-9b60-29e37306e62e" />


---

## 5. Search Resource

Resources can be searched using different criteria such as ID, name, category, or department. The system also provides binary search by ID after automatically sorting the records by ID.

<img width="857" height="377" alt="WhatsApp Image 2026-09-01 at 10 28 52 AM" src="https://github.com/user-attachments/assets/f14f0fc2-369d-4aaf-9aac-06ff1193a0ac" />


---

## 6. Sort Resources

The records can be sorted according to quantity, priority, department, or ID. Recursive Quick Sort is used for organizing the resource records.

<img width="580" height="260" alt="WhatsApp Image 2026-09-01 at 10 29 07 AM" src="https://github.com/user-attachments/assets/c84b9747-ad6e-44b3-8a3a-5dd15bcd37d7" />


---

## 7. Identify Duplicate Resources

The system checks the available records for duplicate resources based on the defined resource identification conditions.

<img width="793" height="152" alt="WhatsApp Image 2026-09-01 at 10 30 03 AM" src="https://github.com/user-attachments/assets/1f2216a7-9ba6-48e7-b8f3-a592e25c36aa" />


---

## 8. Merge Department Records

Duplicate resource records from different departments can be merged. Their quantities are consolidated and the relevant department information is retained.

<img width="592" height="102" alt="WhatsApp Image 2026-09-01 at 10 30 29 AM" src="https://github.com/user-attachments/assets/073d5510-19aa-4100-9786-6f1e2f16edb1" />


---

## 9. Analyse Resource Availability

The availability analysis provides a summary of the total number of resources classified as adequate, low-stock, and critical.

<img width="585" height="222" alt="WhatsApp Image 2026-09-01 at 10 32 43 AM" src="https://github.com/user-attachments/assets/920838a7-4e38-4e20-928c-577d75238d4d" />


---

## 10. Display Critical and Low-Stock Resources

The system separately displays resources that are currently critical or below their required stock threshold, making them easier to identify.

<img width="797" height="216" alt="WhatsApp Image 2026-09-01 at 10 32 55 AM" src="https://github.com/user-attachments/assets/c56eadc6-8ff9-49e2-a213-92cd022f126c" />


---

## 11. Generate Consolidated Report

A consolidated report containing resource statistics and resource details can be generated as a text file for further reference.

<img width="565" height="107" alt="WhatsApp Image 2026-09-01 at 10 33 10 AM" src="https://github.com/user-attachments/assets/41eb3c86-685e-4c9d-b4ac-8fc41bbca570" />


---

## 12. Save Records

The current resource records can be stored in a binary data file so that they can be retrieved during a future program session.

<img width="562" height="107" alt="WhatsApp Image 2026-09-01 at 10 35 29 AM" src="https://github.com/user-attachments/assets/2c747472-b284-4c63-b415-31c525305a00" />


---

## 13. Load Records

Previously saved resource records can be loaded from the data file when the application starts or through the Load Records option.

<img width="538" height="110" alt="WhatsApp Image 2026-09-01 at 10 36 16 AM" src="https://github.com/user-attachments/assets/4eca775e-2fb4-4c1a-9480-8855b619517f" />


---

## 14. Exit

The application provides an exit option that safely terminates the program after completing the required operations.
<img width="533" height="60" alt="WhatsApp Image 2026-09-01 at 10 36 43 AM" src="https://github.com/user-attachments/assets/d0ee62c1-03f3-4c83-a3c7-f889d7724cea" />

______
![Exit](../screenshots/14_exit.png)
