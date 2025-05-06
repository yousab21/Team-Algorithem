// Yousab Nabil Nasrala || Section (39)
// Yahia Khaled Elsafty || Section (39)
// Mohamed Hamada AboSeda || Section (39)
// Yassin Khaled Elnaggar || Section (39)
// Omar Mohamed Ragaa || Section (22)

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

// Struct of item
typedef struct item {
    char name[30];
    float price;
} data;

double full_price = 0;

    char coupons[4][10] = { "yousab", "yahia", "mohamed", "yassin" };
    float discount[4] = { 0.1, 0.2, 0.3, 0.4 };

// Overnight shipping prompt
int overnight_checker() {
    char a;
    while (1) {
        printf("Overnight shipping? [y/n]: ");
        scanf(" %c", &a);  // Note the space before %c to skip leftover newline

        if (a == 'y' || a == 'Y') {
            full_price += 5;
            return 1;
        } else if (a == 'n' || a == 'N') {
            return 0;
        } else {
            printf("Wrong input! Please try again.\n");
        }
    }
}

int main() {
    int items_number = 0, total_items = 0, counter = 1;
    int total_shipping = 0;
    bool run = true;
    data item[100];  // Set a max of 100 items

    printf("Welcome to our small shop\n\n");

    while (run) {
        int new_items = 0;

        if (counter == 1) {
            printf("Please enter the number of items you want to buy (minimum 2): ");
        } else {
            printf("If you clicked YES by mistake, you can write 0 to stop.\n");
            printf("Please enter the number of items you want to add: ");
        }

        while (scanf("%d", &new_items) != 1 || new_items < 0) {
            printf("Invalid input. Enter a non-negative number: ");
            while (getchar() != '\n');
        }

        if (counter == 1 && new_items < 2) {
            printf("Wrong input. You must buy at least 2 items.\n");
            return 1;
        }

        if (new_items == 0 && counter != 1) {
            break; // stop adding more items
        }

        // Store total items
        int start_index = items_number;
        items_number += new_items;

        // Collect item data
        printf("\nTHANKS! Now enter the specifications of your items:\n\n");
        for (int i = start_index; i < items_number; i++, counter++) {
            while (getchar() != '\n'); // clear input buffer

            printf("Please enter the name of item %d: ", counter);
            fgets(item[i].name, sizeof(item[i].name), stdin);
            strtok(item[i].name, "\n"); // remove newline

            printf("Enter the price of item %d: ", counter);
            while (scanf("%f", &item[i].price) != 1 || item[i].price < 0) {
                printf("Invalid input. Please enter a positive number: ");
                while (getchar() != '\n');
            }

            full_price += item[i].price;

            // Shipping cost per item
            if (item[i].price < 10) {
                full_price += 2;
                total_shipping += 2;
            } else {
                full_price += 3;
                total_shipping += 3;
            }
        }

        printf("\nCurrent total price (including shipping): %.2lf$\n", full_price);
        printf("Current total shipping cost: %d$\n", total_shipping);
        sleep(1);

        // Ask if the user wants to continue
        char response;
        while (1) {
            printf("\nDo you want to continue shopping? [y/n]: ");
            scanf(" %c", &response);

            if (response == 'y' || response == 'Y') {
                break;  // continue loop
            } else if (response == 'n' || response == 'N') {
                run = false;
                break;
            } else {
                printf("Invalid input. Please type 'y' or 'n'.\n");
            }
        }
    }

    // Overnight shipping option
    bool overnight = overnight_checker();

    char coupon_response ,coupon_code[20];
    int coupon_index = -1;
    float discount_value = 0.0;

    printf("do you have a discount coupon [y/n] :");
    scanf(" %c", &coupon_response);
    if (coupon_response == 'y' || coupon_response == 'Y') {
      
        printf("Please enter your coupon code: ");
        scanf("%s", coupon_code);
           for (coupon_index = 0; coupon_index < 4; coupon_index++) {
            if (strcmp(coupons[coupon_index], coupon_code) == 0) {
                discount_value = full_price * discount[coupon_index];
                break;
            }
        }
    }
    else {
        printf("invalid copoun \n");
    }
    

    printf("\n\t\tYour Receipt:\n\n");
    for (int i = 0; i < items_number; i++) {
        printf("%s\t\tPrice: %.2f$\n", item[i].name, item[i].price);
    }

    printf("\nTotal shipping:\t\t+%d$\n", total_shipping);
    if (overnight) {
        printf("Overnight delivery:\t+5.00$\n");
    }
    printf("raw price:\t\t%.2lf$\n", full_price);
    printf("Discount:\t\t-%.2f$\n", discount_value);
    full_price -= discount_value;
    printf("Final price:\t\t%.2lf$\n", full_price);
    printf("\nThanks For Buying From Us!\nSee you soon :)\n");

    return 0;
}
