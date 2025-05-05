#include <stdio.h>

#define NUM_LOCATIONS 10

char *locations[NUM_LOCATIONS] = {
    "Talkha",
    "El Gamaa",
    "El Toriel",
    "Gehan Street",
    "Sandoob",
    "Shinnawy",
    "El Mashaya",
    "El Mogamaa",
    "El Dawahi",
    "El Mahatta"
};

float prices[NUM_LOCATIONS] = {
    30.0, 40.0, 35.0, 45.0, 50.0,
    25.0, 55.0, 38.0, 42.0, 60.0
};

int main() {
    int choice;

    printf("Select your shipping address from the list below:\n");
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        printf("%d. %s\n", i + 1, locations[i]);
    }

    printf("Enter the number of your location: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > NUM_LOCATIONS) {
        printf("Invalid location number.\n");
        return 1;
    }

    printf("Shipping to %s costs %.2f EGP.\n", locations[choice - 1], prices[choice - 1]);

    return 0;
}

