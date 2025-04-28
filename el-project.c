// Youssab Nabil Nasrala || Section (39)
// Yahia Khaled Elsafty || Section (39)
// Mohamed Hamada AboSeda || Section (39)
// Yassin Khaled Elnaggar || Section (39)
// Omar Mohamed Ragaa || Section (22)
// Omar Mohamed Shehata || Section (22)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// class of items
struct product { 
    char name[30];
    float price;
};
//database for our shop
int food_choice;
char foods[10][30] = {
    "exit               ",
    "Rice    (1kg)      ",
    "Bread  (loaf)      ",
    "Eggs  (dozen)      ",
    "Milk     (1L)      ",
    "Cheese (200g)      ",
    "Butter (250g)      ",
    "Chicken (1kg)      ",
    "Apples  (1kg)      ",
    "Bananas (1kg)      "
};
float foods_prices[10] = { 0 ,1.20, 0.99, 2.50, 1.30, 2.75, 2.10, 6.50, 1.80, 1.10 };

int drink_choice;
char drinks[11][30] = {
    "exit               ",
    "Water              ",
    "Cola               ",
    "Juice              ",
    "Energy Drink       ",
    "Coffee             ",
    "Tea                ",
    "Milkshake          ",
    "smoothie           ",
    "Iced Tea           ",
    "Yogurt Drink       "
};
float drinks_prices[11] = { 0, 0.80, 1.50, 2.00, 2.25, 3.99, 2.20, 1.75, 1.10, 1.30, 1.60 };

int clothes_choice;
char clothes[8][30] = {
    "exit               ",
    "T-Shirt            ",
    "Jeans              ",
    "Jacket             ",
    "Hoodie             ",
    "Shorts             ",
    "Sneakers           ",
    "Cap                "
};
float clothes_prices[8] = { 0, 9.99, 24.99, 39.99, 29.99, 14.50, 49.99, 7.99 };

int Medicine_choice;
char Medicine[8][30] = {
    "exit               ",
    "Paracetamol        ",
    "Ibuprofen          ",
    "Cough Syrup        ",
    "Antibiotic Pills   ",
    "Vitamin C          ",
    "Antacid Tablets    ",
    "Allergy Relief     "
};
float Medicine_prices[8] = { 0, 1.50, 2.00, 3.25, 5.99, 2.75, 1.80, 3.50 };

char coupons[4][10] = { "yousab", "yahia", "mohamed", "yassin" };
float discount[4] = { 0.1, 0.2, 0.3, 0.4 };
float discount_value = 0.0;
//---------------------------------------------------------------------------------------------------------
double full_price = 0;
int number_of_items = 0;

// shipping fnction
int Shipping() {
    int shipping_method, run = 1;
    while (1) {
        printf("\n1. Standard Shipping\t5-7 Days\t10$\n2. Fast Shipping\t\t2-3 Days\t17$\n3. Overnight Shipping\tNext Day\t25$\nchoose shipping option: "); // All Shipping choices
        scanf("%d", &shipping_method); // Receives the shipping option chose by the user.
        
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
//--------------------------------------------------------------------------------------------------------- 


// coupon function
void check_coupon() {
    char coupon_response, coupon_code[20];
    int coupon_index = -1;
    
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
                else {
                printf("invalid coupon\n");
            }
        }      
    }   
}
//---------------------------------------------------------------------------------------------------------    


int main() {
    struct product item[100];
    int item_index = 0;
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

                printf("Foods:\n");
                    for(int i = 1; i <= 10; i++) {
                        printf("%d. %s ............... $%.2f\n", i, foods[i-1], foods_prices[i-1]);
                    }
                while (run) {
                    printf("Enter the number of the food you want to buy: ");
                    scanf("%d", &food_choice);

                    if(food_choice == 1) {
                        printf("Exiting the food section.\n");
                        run = 0;
                        break;
                    }
                    else if (food_choice > 11|| food_choice < 1) {
                        printf("wrong input \nTry Again \n\n");
                    }
                    else
                        printf("You have selected %s\n", foods[food_choice - 1]);
                        // This part adds chosen items to the Cart
                        strcpy(item[item_index].name, foods[food_choice - 1]);
                        item[item_index].price = foods_prices[food_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += foods_prices[food_choice - 1];


                }
                break;

            case 2: // DRINKS SECTION
                run = 1;
                printf("\nDrinks:\n");
                for(int i = 1; i <= 11; i++) {
                    printf("%d. %s ............... $%.2f\n", i, drinks[i-1], drinks_prices[i-1]);
                }
                while (run) {
                    
                    printf("Enter the number of the drink you want to buy: ");
                    scanf("%d", &drink_choice);

                    if(drink_choice == 1) {
                        printf("Exiting the drinks section.\n");
                        run = 0;
                        break;
                    }
                    else if (drink_choice > 11 || drink_choice < 1) {
                        printf("wrong input \nTry Again \n\n");
                    }
                    else
                        printf("You have selected %s\n", drinks[drink_choice - 1]);
                        strcpy(item[item_index].name, drinks[drink_choice - 1]);
                        item[item_index].price = drinks_prices[drink_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += drinks_prices[drink_choice - 1];
                    
                    //---------------------------------------------------------
                    
                }
                break;

            case 3: // CLOTHES SECTION
                run = 1;
                printf("Clothes:\n");
                for(int i = 1; i <= 8; i++) {
                    printf("%d. %s ............... $%.2f\n", i, clothes[i-1], clothes_prices[i-1]);
                }
                while (run) {

                    printf("Enter the number of the clothes you want to buy: ");
                    scanf("%d", &clothes_choice);

                    if(clothes_choice == 1) {
                        printf("Exiting the clothes section.\n");
                        run = 0;
                        break;
                    }
                    else if (clothes_choice > 8 || clothes_choice < 1){
                        printf("wrong input \nTry Again \n\n");
                    }
                    else
                        printf("You have selected %s\n", clothes[clothes_choice - 1]);
                        strcpy(item[item_index].name, clothes[clothes_choice - 1]);
                        item[item_index].price = clothes_prices[clothes_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += clothes_prices[clothes_choice - 1];
                    //------------------------------------------------------------
                    
                    
                }
                break;

            case 4: // MEDICINE SECTION
                run = 1;
                printf("Medicines:\n");
                for(int i = 1; i <= 8; i++) {
                    printf("%d. %s ............... $%.2f\n", i, Medicine[i-1], Medicine_prices[i-1]);
                }
                
                while (run) {
                                       
                    printf("Enter the number of the Medicine you want to buy: ");
                    scanf("%d", &Medicine_choice);

                    if(Medicine_choice == 1) {
                        printf("Exiting the medicine section.\n");
                        run = 0;
                        break;
                    }
                    else if (Medicine_choice > 8 || Medicine_choice < 1) {
                        printf("wrong input \nTry Again \n\n");
                    }
                    else
                        printf("You have selected %s\n", Medicine[Medicine_choice - 1]);
                        strcpy(item[item_index].name, Medicine[Medicine_choice - 1]);
                        item[item_index].price = Medicine_prices[Medicine_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += Medicine_prices[Medicine_choice - 1];
                    //-------------------------------------------------------------
                    
                
                }
                break;
        }

        printf("Do you want to Buy from another section? (y/n): ");
        scanf(" %c", &other_section);
        checker = (other_section == 'y' || other_section == 'Y') ? true : false;
    }

    


                                
    if(number_of_items == 0) {
        printf("we are sorry no product intrested you\n");
        return 0;
    }  
    else{
        int shipping_method = Shipping(); // get the value of the shipping method
        void check_coupon(); // check for the coupon

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
}