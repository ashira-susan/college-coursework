# Sample Output

## 1. Main Menu and System Initialization

The application starts by displaying the system title and provides an option to load previously saved resource records.

<img width="855" height="612" alt="image" src="https://github.com/user-attachments/assets/ce9683e8-e732-4e02-8079-e0f679523a8f" />




---

## 2. Add Resource

A new resource can be added by entering its ID, name, category, department, quantity, minimum threshold, and priority. The system automatically determines the resource status.

<img width="535" height="266" alt="image" src="https://github.com/user-attachments/assets/e50cf266-9347-4d43-ba03-13c0e61caf06" />



---

## 3. Update Resource

Existing resource details can be modified. After an update, the system recalculates the resource status based on the updated quantity and threshold.

<img width="576" height="268" alt="image" src="https://github.com/user-attachments/assets/1dc3fc7d-17ac-4e78-ac57-f7d9c3068427" />



---

## 4. Display All Resources

The system displays all stored resources in a structured table containing the resource ID, name, category, quantity, threshold, priority, status, and department.

<img width="855" height="237" alt="image" src="https://github.com/user-attachments/assets/1768d378-41ef-4518-9114-01c78e7c8173" />



---

## 5. Search Resource

Resources can be searched using different criteria such as ID, name, category, or department. The system also provides binary search by ID after automatically sorting the records by ID.

<img width="857" height="377" alt="image" src="https://github.com/user-attachments/assets/78ba68c2-c09b-4ff6-a539-ab0ba7cf4374" />



---

## 6. Sort Resources

The records can be sorted according to quantity, priority, department, or ID. Recursive Quick Sort is used for organizing the resource records.

<img width="580" height="260" alt="image" src="https://github.com/user-attachments/assets/41e6272c-f408-4269-ba83-ebe1344d7c4b" />




---

## 7. Identify Duplicate Resources

The system checks the available records for duplicate resources based on the defined resource identification conditions.

<img width="793" height="152" alt="image" src="https://github.com/user-attachments/assets/782391db-3857-4b67-831c-2dd56eb2b491" />



---

## 8. Merge Department Records

Duplicate resource records from different departments can be merged. Their quantities are consolidated and the relevant department information is retained.


<img width="592" height="102" alt="image" src="https://github.com/user-attachments/assets/24cd7ba5-0336-4e39-ab94-40c1180960ae" />



---

## 9. Analyse Resource Availability

The availability analysis provides a summary of the total number of resources classified as adequate, low-stock, and critical.

<img width="585" height="222" alt="image" src="https://github.com/user-attachments/assets/7b35b35d-4366-4e2d-b656-6f7f1afbe2f2" />



---

## 10. Display Critical and Low-Stock Resources

The system separately displays resources that are currently critical or below their required stock threshold, making them easier to identify.

<img width="797" height="216" alt="image" src="https://github.com/user-attachments/assets/1b1511f6-be02-41ab-b9a7-06ce41edbd8c" />



---

## 11. Generate Consolidated Report

A consolidated report containing resource statistics and resource details can be generated as a text file for further reference.

<img width="565" height="107" alt="image" src="https://github.com/user-attachments/assets/cfba0ec0-c22e-4c04-9311-a654a8fb918f" />

Consolidated Report:

<img width="1097" height="711" alt="image" src="https://github.com/user-attachments/assets/b1a21f2f-3d17-448e-9f10-62eb06144c8b" />


---

## 12. Save Records

The current resource records can be stored in a binary data file so that they can be retrieved during a future program session.

<img width="562" height="107" alt="image" src="https://github.com/user-attachments/assets/e3de328b-2b34-48a5-8bea-56b3dca7fcf5" />




---

## 13. Load Records

Previously saved resource records can be loaded from the data file when the application starts or through the Load Records option.

<img width="538" height="110" alt="image" src="https://github.com/user-attachments/assets/7a953ad3-7852-4b74-b113-a95689764780" />



---

## 14. Exit

The application provides an exit option that safely terminates the program after completing the required operations.

<img width="533" height="60" alt="image" src="https://github.com/user-attachments/assets/80f2ad46-27e7-49dd-a68a-fde515830311" />

______
