#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mfms.h"

/*
 * Reads a line safely and removes its newline.
 * Returns 0 if input is empty or invalid.
 */
int read_text(const char *prompt, char *destination, int size)
{
    size_t length;
    int ch;

    if (size <= 1)
        return 0;

    printf("%s", prompt);

    if (fgets(destination, size, stdin) == NULL)
        return 0;

    length = strlen(destination);

    if (length > 0 && destination[length - 1] == '\n') {
        destination[length - 1] = '\0';
    } else {
        /* Discard extra characters if the input exceeded the buffer. */
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return destination[0] != '\0';
}

int read_int(const char *prompt, int *value)
{
    char line[100];
    char extra;

    printf("%s", prompt);

    if (fgets(line, sizeof line, stdin) == NULL)
        return 0;

    if (sscanf(line, " %d %c", value, &extra) != 1)
        return 0;

    return 1;
}

int read_double(const char *prompt, double *value)
{
    char line[100];
    char extra;

    printf("%s", prompt);

    if (fgets(line, sizeof line, stdin) == NULL)
        return 0;

    if (sscanf(line, " %lf %c", value, &extra) != 1)
        return 0;

    return 1;
}

static void display_main_menu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("0. Exit\n");
}

int main(void)
{
    int choice = -1;

    do {
        display_main_menu();

        if (!read_int("Enter your choice: ", &choice)) {
            printf("Invalid input. Enter a number.\n");
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: employee_menu(); break;
            case 2: budget_menu(); break;
            case 3: supplier_menu(); break;
            case 4: asset_menu(); break;
            case 5: reports_menu(); break;
            case 0: printf("Exiting MFMS. Goodbye.\n"); break;
            default: printf("Invalid menu choice.\n");
        }
    } while (choice != 0);

    return 0;
}