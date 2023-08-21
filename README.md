# abcu-computer-system

Advising Assistance Software for ABCU's Computer Science Department
Introduction
This repository contains the implementation of the advising assistance software for the Computer Science department at ABCU. Designed to streamline and facilitate the academic advising process, this software is built in C++ and makes use of advanced algorithms and data structures.

Competency
The primary focus of this project is to:

Develop code using algorithms and data structures to solve basic programming problems.
Problem Statement
Academic advisors in ABCU's Computer Science department expressed a need for a tool to efficiently manage course information when advising students. This software aims to meet that need by providing quick access to course data, listing courses in the department, and offering detailed course information.

Features & Functionalities
Input Design: The program prompts the user for the file name containing the course data. It then reads this file and stores the course objects in a specialized data structure.

Menu Interface: The software provides a menu interface with the following options:

Load Data Structure
Print Course List
Print Individual Course Information
Exit Program
Loading Data Structure: Before any course data can be accessed or printed, it first needs to be loaded into the application's internal data structure from the specified file.

Course List: This feature allows the printing of an alphanumeric list of all courses in the Computer Science department, including all associated math courses. The list is sorted alphanumerically from the lowest to the highest.

Course Information: Users can look up detailed information about a specific course by entering its course number. The software then displays the course title and its prerequisites.

Error Handling: In line with industry best practices, the program provides meaningful error messages if user input falls outside expected parameters.

Industry Standard Best Practices
Error Handling: The program is robust, handling potential errors gracefully by informing users of discrepancies in their input.

In-Line Comments: For improved readability and future maintainability, the code is supplemented with in-line comments explaining the logic and functionality.

Appropriate Naming Conventions: To ensure clarity and consistency, variables, functions, and classes are named following industry-standard conventions.

Getting Started
Compile the C++ files in your preferred C++ compiler or IDE.
Run the compiled program.
Follow on-screen prompts to load course data and navigate through the menu options.
