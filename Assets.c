#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_RECORDS];
int asset_count = 0;

static int find_asset_by_id(int id)
{
    int i;

    for (i = 0; i < asset_count; i++) {
        if (assets[i].id == id)
            return i;
    }

    return -1;
}

static void display_asset(const Asset *asset)
{
    printf("\nAsset ID: %d\n", asset->id);
    printf("Asset name: %s\n", asset->name);
    printf("Asset type: %s\n", asset->type);
    printf("Purchase value: N$%.2f\n", asset->purchase_value);
    printf("Department: %s\n", asset->department);
    printf("Condition: %s\n", asset->condition);
}

static void add_asset(void)
{
    Asset asset;

    if (asset_count >= MAX_RECORDS) {
        printf("Asset list is full.\n");
        return;
    }

    if (!read_int("Asset ID: ", &asset.id) || asset.id <= 0) {
        printf("Enter a valid positive ID.\n");
        return;
    }

    if (find_asset_by_id(asset.id) != -1) {
        printf("That asset ID already exists.\n");
        return;
    }

    if (!read_text("Asset name: ", asset.name, sizeof asset.name) ||
        !read_text("Asset type: ", asset.type, sizeof asset.type) ||
        !read_text("Department: ", asset.department,
                   sizeof asset.department) ||
        !read_text("Condition: ", asset.condition,
                   sizeof asset.condition)) {
        printf("Asset information cannot be empty.\n");
        return;
    }

    if (!read_double("Purchase value: N$", &asset.purchase_value) ||
        asset.purchase_value < 0) {
        printf("Enter a valid non-negative purchase value.\n");
        return;
    }

    assets[asset_count++] = asset;
    printf("Asset added successfully.\n");
}

static void display_assets(void)
{
    int i;

    if (asset_count == 0) {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < asset_count; i++)
        display_asset(&assets[i]);
}

static void search_asset(void)
{
    int choice;

    printf("1. Search by ID\n");
    printf("2. Search by exact name\n");

    if (!read_int("Choice: ", &choice)) {
        printf("Invalid choice.\n");
        return;
    }

    if (choice == 1) {
        int id;
        int index;

        if (!read_int("Asset ID: ", &id)) {
            printf("Invalid ID.\n");
            return;
        }

        index = find_asset_by_id(id);

        if (index == -1)
            printf("Asset not found.\n");
        else
            display_asset(&assets[index]);
    } else if (choice == 2) {
        char name[NAME_LENGTH];
        int i;
        int found = 0;

        if (!read_text("Asset name: ", name, sizeof name)) {
            printf("Name cannot be empty.\n");
            return;
        }

        for (i = 0; i < asset_count; i++) {
            if (strcmp(assets[i].name, name) == 0) {
                display_asset(&assets[i]);
                found = 1;
            }
        }

        if (!found)
            printf("Asset not found.\n");
    } else {
        printf("Choose a listed option.\n");
    }
}

void asset_menu(void)
{
    int choice;

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search assets\n");
        printf("0. Return to main menu\n");

        if (!read_int("Choice: ", &choice)) {
            printf("Invalid menu choice.\n");
            continue;
        }

        switch (choice) {
            case 1: add_asset(); break;
            case 2: display_assets(); break;
            case 3: search_asset(); break;
            case 0: break;
            default: printf("Choose a listed option.\n");
        }
    } while (choice != 0);
}
