# Student Database Management System

## Project Overview
This project implements a Student Database Management System using the C programming language, following the modular programming concept. The system allows users to efficiently manage student data by supporting operations like adding, deleting, reading, and validating student information.

## System Description
- The project consists of two main components:
1. Database Module: Handles all student data operations.
2. Application Module: Provides the user interface and controls the program flow.

### Features:

- Maximum of 10 students and a minimum of 3 students in the database.
- Perform operations such as:
- Add a new student entry.
- Delete an existing student entry.
- Check if the database is full.
- Get the number of students in the database.
- Retrieve student details by ID.
- List all student IDs.
- Check if a specific student ID exists.
- Project Structure

### Header Files:

- STD.h: Contains essential data type definitions.
- SDB.h: Declares the functions and defines the student struct used in the database.

### Source Files:

- SDB.c: Implements all database-related functionalities.
- SDBAPP.c: Contains the main application logic and user interaction.
- main.c: The entry point for the program.

### Software Tools
- C Compiler: GCC, Clang, or equivalent.
- Text Editor or IDE: Code::Blocks, Visual Studio, or any C-compatible IDE.
- Operating System: Windows, Linux, or macOS.

### Hardware (Optional for Embedded Systems)
1. ATmega32 microcontroller.
2. LCD Display for data visualization.
3. Keypad for user input.
4. External memory for persistent storage.

### Notes
- Ensure valid input to prevent errors.
- Database is volatile and will reset upon program termination.
- Increase the maximum number of students by modifying the MAX_STUDENTS constant in the header file.
