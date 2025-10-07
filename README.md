# Student-Assignment-Submission-System

Description:
This C program manages student assignment submissions using a singly linked list. It allows adding new submissions, updating their status, searching by student ID, and displaying all submissions. Each record contains Student ID, Assignment Title, Submission Date, and Status (Submitted/Pending).

Features:
1. Add Submission – Add a record with Student ID, Assignment Title, Date, and Status.
2. Update Status – Update the submission status for a specific assignment.
3. Search by Student ID – View all submissions by a particular student.
4. Display All – Show all assignment submissions.
5. Exit – Close the program.

How it Works:
- Uses a struct Assignment with fields: Student ID, Title, Date, Status, and pointer to the next node.
- Linked list dynamically stores submission records.
- New submissions are added to the head of the list.
- Provides a menu-driven interface for easy operation.

Compilation and Execution:
gcc studentsrecord_assignment.c -o studentsrecord_assignment
./studentsrecord_assignment

Sample Input/Output:
Enter choice: 1
Enter Student ID: 101
Enter Assignment Title: Project1
Enter Submission Date: 29/09/2025
Enter Status (Submitted/Pending): Submitted
Submission added!

Enter choice: 4
Assignment Submissions:
Student 101 | Project1 | 29/09/2025 | Submitted
