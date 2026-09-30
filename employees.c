#include <stdio.h>
#include "employees.h"

/* Employee records are shared with the reports module. */
Employee employees[MAX_RECORDS];
int employee_count = 0;

static int find_employee_by_id(int id)
{
    int i;

    for (i = 0; i < employee_count; i++) {
        if (employees[i].id == id)
            return i;
    }

    return -1;
}

static double calculate_salary(const Employee *employee)
{
    return employee->basic_salary
         + employee->housing_allowance
         + employee->transport_allowance;
}

static void display_employee(const Employee *employee)
{
    printf("\nEmployee ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Department: %s\n", employee->department);
    printf("Basic salary: N$%.2f\n", employee->basic_salary);
    printf("Housing allowance: N$%.2f\n", employee->housing_allowance);
    printf("Transport allowance: N$%.2f\n",
           employee->transport_allowance);
    printf("Total salary: N$%.2f\n", calculate_salary(employee));
}

static void add_employee(void)
{
    Employee employee;

    if (employee_count >= MAX_RECORDS) {
        printf("Employee list is full.\n");
        return;
    }

    if (!read_int("Employee ID: ", &employee.id) || employee.id <= 0) {
        printf("Enter a valid positive ID.\n");
        return;
    }

    if (find_employee_by_id(employee.id) != -1) {
        printf("That employee ID already exists.\n");
        return;
    }

    if (!read_text("Name: ", employee.name, sizeof employee.name)) {
        printf("Name cannot be empty.\n");
        return;
    }

    if (!read_text("Department: ", employee.department,
                   sizeof employee.department)) {
        printf("Department cannot be empty.\n");
        return;
    }

    if (!read_double("Basic salary: N$", &employee.basic_salary) ||
        employee.basic_salary < 0) {
        printf("Enter a valid non-negative salary.\n");
        return;
    }

    if (!read_double("Housing allowance: N$",
                     &employee.housing_allowance) ||
        employee.housing_allowance < 0) {
        printf("Enter a valid non-negative allowance.\n");
        return;
    }

    if (!read_double("Transport allowance: N$",
                     &employee.transport_allowance) ||
        employee.transport_allowance < 0) {
        printf("Enter a valid non-negative allowance.\n");
        return;
    }

    employees[employee_count] = employee;
    employee_count++;

    printf("Employee added successfully.\n");
}

static void display_employees(void)
{
    int i;

    if (employee_count == 0) {
        printf("No employees registered.\n");
        return;
    }

    for (i = 0; i < employee_count; i++)
        display_employee(&employees[i]);
}

static void search_employee(void)
{
    int id;
    int index;

    if (!read_int("Enter employee ID: ", &id)) {
        printf("Invalid ID.\n");
        return;
    }

    index = find_employee_by_id(id);

    if (index == -1)
        printf("Employee not found.\n");
    else
        display_employee(&employees[index]);
}

void employee_menu(void)
{
    int choice;

    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee by ID\n");
        printf("0. Return to main menu\n");

        if (!read_int("Choice: ", &choice)) {
            printf("Invalid menu choice. Enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                search_employee();
                break;
            case 0:
                break;
            default:
                printf("Choose a listed option.\n");
        }
    } while (choice != 0);
}