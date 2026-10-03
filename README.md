mfms c lab A assignment

Group3

Haitula Melkisedek  223011878,

Tuwilika Andreas 225170302,

Frieda  Nashongo  225111039,

Naomi Kamenye 221019855, 

Dagmar da Silva- 222132884, 

 Festus shinedima mt  224086391


Project description

The Municipal Financial Management System (MFMS) is a menu-driven application developed in C to support basic municipal financial and administrative tasks. It provides modules for managing employee information and salary details, departmental budgets and expenditure, supplier records, and municipal assets. Users can add, display, and search records, calculate budget balances and salary information, and generate basic reports.

The project demonstrates core C programming concepts, including functions, arrays, string processing, loops, decision-making, calculations, and input validation. It is a foundation version intended to address a realistic municipal management problem and to be extended in a future project.

System Features

1.Main menu: Provides clear navigation between system modules and an option to exit.

2.Employee management: Add, display, and search employee records, and calculate salary information.

3.Budget management: Enter departmental budgets and expenditure, calculate remaining balances, and identify departments over budget.

4.Supplier management: Add, display, and search supplier records, including contact details and location.

5.Asset management: Register, display, and search municipal assets such as vehicles, equipment, and buildings.

6.Reports: Generate basic employee, budget, supplier, and asset reports.

7.Input validation: Handle invalid menu choices and prevent entries such as negative salaries or budgets and empty names.

8.Organised C program: Use functions, arrays, strings, loops, and decision-making structures to manage and process information.

Compilation Instructions

The MFMS is written in C and can be compiled using GCC. Open a terminal in the project directory and run this:

1. gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
2. ./mfms in windows   or  mfms.exe in Linux/macOS to execute the project

How to Run the System

1.Save the project’s C source files in one folder.

2.Open a terminal or command prompt in that folder.

3.Compile the program with GCC, including all required source files:
- gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
- ./mfms in windows   or  mfms.exe in Linux/macOS to execute the project

4.Run the compiled program:
Windows: ./mfms

Linux/macOS: mfms.exe

5.Use the on-screen menu to select a module or exit the system

Individual responsibilities

1.Haitula Melkisedek: I created the group’s GitHub account and invite members to join the github group. I developed the employee-management files, employees.c and employees.h, along with main.c.


 main.c is the program’s entry point. It provides safe input functions for reading text, integers, and decimal numbers, then displays the Municipal Financial Management System’s main menu. Based on the user’s choice, it calls the relevant menu function for employee, budget, supplier, asset, or report management. The menu repeats until the user chooses 0, at which point the program displays a goodbye message and exits.

Together, the files work like this: main.c calls employee_menu() when the user selects Employee Management. That function, implemented in employees.c and declared in employees.h, lets the user add, display, or search employee records. The program prints prompts, menu options, employee details, salary totals, and validation messages as the user interacts with it.

When the user selects employee management, the program displays a submenu. The user can add an employee, view employee details and total salary, search by ID, or return to the main menu. Employee records are stored in memory while the program runs.

2.Frieda Nashongo’s responsibility: 
Developed the reports module, including reports.c and reports.h.

-The module provides a reports menu with four options:

-Employee report: Shows the employee count and average, highest, and lowest salaries.

-Budget report: Summarizes allocated budgets and expenditures, calculates the remaining budget, and identifies departments over budget.

-Supplier report: Lists registered suppliers and their contact details.

-Asset report: Lists registered assets, including their type, purchase value, department, and condition.

-The user can return to the main menu from the reports menu.

3.Dagmar da Silva’s responsibility: Developed the supplier management module, including supplier record storage and the supplier menu.

The module allows users to add suppliers, display all registered suppliers, and search for a supplier by ID. It checks that IDs are positive and unique, required details are not empty, and the record limit has not been reached. Supplier records include an ID, name, email, telephone number, and location.

4.Tuwilika Andreas’s responsibility: Developed an Asset management.

This responsibility covers maintaining asset records, such as recording and displaying asset details, including the asset ID, name, type, purchase value, department, and condition.


5. Naomi Kamenye’s responsibility: Developed the budget management module. It allows users to enter or update department budgets and view allocated funds, expenditure, remaining balances, and whether each department is within or over budget. It also validates that budget amounts are non-negative.

6.  Festus Shinedima mt: I developed the supplier-management module for the group’s MFMS project.

The supplier-management files let users add suppliers, display all registered suppliers, and search for a supplier by ID. When adding a supplier, the program checks that the ID is positive and unique, that the required details are not empty, and that the supplier list has room for another record.

Supplier details—including ID, name, email, telephone number, and location—are stored in memory while the program runs. The supplier menu lets users choose an operation or return to the main menu.

I also worked on mfms.h, the shared header file for the project. It defines the structures for employees, budgets, suppliers, and assets, along with shared limits for record counts and text fields. It also declares the shared record lists, input helper functions, and menus used by the different parts of the program.i also  test the project code to identify errors and correct them.
