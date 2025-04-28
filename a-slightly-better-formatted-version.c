// Youssab Nabil Nasrala || Section (39)
// Yahia Khaled Elsafty || Section (39)
// Mohamed Hamada AboSeda || Section (39)
// Yassin Khaled Elnaggar || Section (39)
// Omar Mohamed Ragaa || Section (22)
// Omar Mohamed Shehata || Section (22)

#include <stdio.h>
#include <string.h>

// Struct of item
struct product { 
    char name[30];
    float price;
};

double full_price = 0;
char coupons[4][10] = { "yousab", "yahia", "mohamed", "yassin" };
float discount[4] = { 0.1, 0.2, 0.3, 0.4 };

// shipping prompt
int Shipping() {
    int shipping_method, run = 1;
    while (1) {
        printf("\nStandard Shipping\t5-7 Days\t10$\tEnter1\nFast Shipping\t\t2-3 Days\t17$\tEnter 2\nOvernight Shipping\tNext Day\t25$\tEnter 3\nInsert the Number: "); // All Shipping choices
        scanf("%d", &shipping_method); // Receives the shipping option chose by the user.
        fflush(stdin);

        // Choosing The shipping method by the user.
        switch (shipping_method) {
            case 1:           
                full_price += 10;
                return 1;
            case 2:
                full_price += 17;
                return 2;
            case 3:
                full_price += 25;
                return 3;
            default:
                printf("wrong input\nPlease Try Again\n\n"); // The Message if the user entered a wrong value.
                run = 1;
                break;
        }
    }
    return 0;
}

int main() {
    struct product item[100];
    int item_index = 0, number_of_items = 0;
    bool run = true;
    bool checker = true;
    char other_section;

    printf("Welcome to our small shop\n\n");

    while (checker) {
        int section, run = 1;

        printf("Choose the section you want: \n\n");

        // Choosing the desired section in the grocery shop
        while (run) {
            printf("For Food Enter \"1\" \nFor Drinks Enter \"2\" \nFor Clothes Enter \"3\" \nFor Medicine Enter \"4\" \n");
            scanf("%d", &section);

            if (section > 4)
                printf("\nwrong input \nTry Again \n\n");
            else
                run = 0;
        }
        //---------------------------------------------------------------------
        
        switch (section) {
            case 1: // FOOD SECTION
                run = 1;
                while (run) {
                    int food_choice;
                    char foods[9][20] = { "Rice", "Bread", "Eggs", "Milk", "Cheese", "Butter", "Chicken Breast", "Apples", "Bananas" };
                    float foods_prices[9] = { 1.20, 0.99, 2.50, 1.30, 2.75, 2.10, 6.50, 1.80, 1.10 };
                    char continue_choice;

                    printf("Foods:\n");
                    printf("1. Rice (1kg) ............... $1.20\n");
                    printf("2. Bread (loaf) ............. $0.99\n");
                    printf("3. Eggs (dozen) ............. $2.50\n");
                    printf("4. Milk (1L) ................ $1.30\n");
                    printf("5. Cheese (200g) ............ $2.75\n");
                    printf("6. Butter (250g) ............ $2.10\n");
                    printf("7. Chicken Breast (1kg) ..... $6.50\n");
                    printf("8. Apples (1kg) ............. $1.80\n");
                    printf("9. Bananas (1kg) ............ $1.10\n");

                    printf("Enter the number of the food you want to buy: ");
                    scanf("%d", &food_choice);

                    if (food_choice > 9)
                        printf("wrong input \nTry Again \n\n");
                    else
                        printf("You have selected %s\n", foods[food_choice - 1]);

                    strcpy(item[item_index].name, foods[food_choice - 1]);
                    item[item_index].price = foods_prices[food_choice - 1];
                    item_index++;
                    number_of_items++;
                    full_price += foods_prices[food_choice - 1];

                    printf("Do you want to continue in this section? (y/n): ");
                    scanf(" %c", &continue_choice);
                    run = (continue_choice == 'y' || continue_choice == 'Y') ? 1 : 0;
                }
                break;

            case 2: // DRINKS SECTION
                run = 1;
                while (run) {
                    int drink_choice;
                    char drinks[10][20] = { "Water", "Cola", "Juice", "Energy Drink", "Coffee", "Tea", "Milkshake", "Sparkling Water", "Iced Tea", "Yogurt Drink" };
                    float drinks_prices[10] = { 0.80, 1.50, 2.00, 2.25, 3.99, 2.20, 1.75, 1.10, 1.30, 1.60 };
                    char continue_choice;
                    
                    // Products
                    printf("\nDrinks:\n");
                    printf("1. Water .............. $0.80\n");
                    printf("2. Cola ............... $1.50\n");
                    printf("3. Juice .............. $2.00\n");
                    printf("4. Energy Drink ....... $2.25\n");
                    printf("5. Coffee ............. $3.99\n");
                    printf("6. Tea ................ $2.20\n");
                    printf("7. Milkshake .......... $1.75\n");
                    printf("8. Sparkling Water .... $1.10\n");
                    printf("9. Iced Tea ........... $1.30\n");
                    printf("10. Yogurt Drink ...... $1.60\n");

                    printf("Enter the number of the drink you want to buy: ");
                    scanf("%d", &drink_choice);

                    if (drink_choice > 10)
                        printf("wrong input \nTry Again \n\n");
                    else
                        printf("You have selected %s\n", drinks[drink_choice - 1]);
                    
                    // This part adds chosen items to the Cart
                    strcpy(item[item_index].name, drinks[drink_choice - 1]);
                    item[item_index].price = drinks_prices[drink_choice - 1];
                    item_index++;
                    number_of_items++;
                    full_price += drinks_prices[drink_choice - 1];
                    //---------------------------------------------------------
                    
                    printf("Do you want to continue in this section? (y/n): ");
                    scanf(" %c", &continue_choice);
                    run = (continue_choice == 'y' || continue_choice == 'Y') ? 1 : 0;
                }
                break;

            case 3: // CLOTHES SECTION
                run = 1;
                while (run) {
                    int clothes_choice;
                    char clothes[7][20] = { "T-Shirt", "Jeans", "Jacket", "Hoodie", "Shorts", "Sneakers", "Cap" };
                    float clothes_prices[7] = { 9.99, 24.99, 39.99, 29.99, 14.50, 49.99, 7.99 };
                    char continue_choice;
                   
                    // Products
                    printf("Clothes:\n");
                    printf("1. T-Shirt ............ $9.99\n");
                    printf("2. Jeans .............. $24.99\n");
                    printf("3. Jacket ............. $39.99\n");
                    printf("4. Hoodie ............. $29.99\n");
                    printf("5. Shorts ............. $14.50\n");
                    printf("6. Sneakers ........... $49.99\n");
                    printf("7. Cap ................ $7.99\n");
                    //-------------------------------------------
                    
                    printf("Enter the number of the clothes you want to buy: ");
                    scanf("%d", &clothes_choice);

                    if (clothes_choice > 7)
                        printf("wrong input \nTry Again \n\n");
                    else
                        printf("You have selected %s\n", clothes[clothes_choice - 1]);

                    // This part adds chosen items to the Cart
                    strcpy(item[item_index].name, clothes[clothes_choice - 1]);
                    item[item_index].price = clothes_prices[clothes_choice - 1];
                    item_index++;
                    number_of_items++;
                    full_price += clothes_prices[clothes_choice - 1];
                    //------------------------------------------------------------
                    
                    printf("Do you want to continue in this section? (y/n): ");
                    scanf(" %c", &continue_choice);
                    run = (continue_choice == 'y' || continue_choice == 'Y') ? 1 : 0;
                }
                break;

            case 4: // MEDICINE SECTION
                run = 1;
                while (run) {
                    int Medicine_choice;
                    char Medicine[7][30] = { "Paracetamol", "Ibuprofen", "Cough Syrup", "Antibiotic Pills", "Vitamin C", "Antacid Tablets", "Allergy Relief" };
                    float Medicine_prices[7] = { 1.50, 2.00, 3.25, 5.99, 2.75, 1.80, 3.50 };
                    char continue_choice;
                   
                    // Products
                    printf("Medicines:\n");
                    printf("1. Paracetamol ........ $10.50\n");
                    printf("2. Ibuprofen .......... $7.00\n");
                    printf("3. Cough Syrup ........ $19.25\n");
                    printf("4. Antibiotic Pills ... $4.99\n");
                    printf("5. Vitamin C .......... $11.75\n");
                    printf("6. Antacid Tablets .... $10.80\n");
                    printf("7. Allergy Relief ..... $21.50\n");
                    //------------------------------------------------
                    
                    printf("Enter the number of the Medicine you want to buy: ");
                    scanf("%d", &Medicine_choice);

                    if (Medicine_choice > 7)
                        printf("wrong input \nTry Again \n\n");
                    else
                        printf("You have selected %s\n", Medicine[Medicine_choice - 1]);
                    
                    // This part adds chosen items to the Cart
                    strcpy(item[item_index].name, Medicine[Medicine_choice - 1]);
                    item[item_index].price = Medicine_prices[Medicine_choice - 1];
                    item_index++;
                    number_of_items++;
                    full_price += Medicine_prices[Medicine_choice - 1];
                    //-------------------------------------------------------------
                    
                    printf("Do you want to continue in this section? (y/n): ");
                    scanf(" %c", &continue_choice);
                    run = (continue_choice == 'y' || continue_choice == 'Y') ? 1 : 0;
                }
                break;
        }

        printf("Do you want to Buy from another section? (y/n): ");
        scanf(" %c", &other_section);
        checker = (other_section == 'y' || other_section == 'Y') ? true : false;
    }

    int shipping_method = Shipping(); // Restoring the value of the shipping method

    char coupon_response, coupon_code[20];
    int coupon_index = -1;
    float discount_value = 0.0;

    printf("do you have a discount coupon [y/n]: ");
    scanf(" %c", &coupon_response);

    // Checking for Coupons
    if (coupon_response == 'y' || coupon_response == 'Y') { // Check for the Availability of a coupon.
        printf("Please enter your coupon code: ");
        scanf("%s", coupon_code);

        for (coupon_index = 0; coupon_index < 4; coupon_index++) { // Goes into each coupon in the array for valid ones.
            if (strcmp(coupons[coupon_index], coupon_code) == 0) {
                discount_value = full_price * discount[coupon_index]; 
                break;
            }
        }
    } else {
        printf("invalid coupon\n");
    }

                                //             ###     Printing Out the Receipt    ###             //
    printf("\n\t\tYour Receipt:\n\n");
    for (item_index = 0; item_index < number_of_items; item_index++) {
        printf("%s\t\t%.2f$\n", item[item_index].name, item[item_index].price);
    }

    printf("=====================\n");

    // Determining Shipping Cost at the end of the receipt.
    if (shipping_method == 1)
        printf("Total shipping:         10.00$\n");
    else if (shipping_method == 2)
        printf("Total shipping:         17.00$\n");
    else if (shipping_method == 3)
        printf("Total shipping:         25.00$\n");

    // Pricing
    printf("raw price:\t\t%.2lf$\n", full_price);
    printf("Discount:\t\t-%.2f$\n", discount_value);
    
    full_price -= discount_value;
    printf("Final price:\t\t%.2lf$\n", full_price);
    //------------------------------------------------
    printf("\nThanks For Buying From Us!\nSee you soon :)\n");

    return 0;
}
