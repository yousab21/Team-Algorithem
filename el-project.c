// Youssab Nabil Nasrala  || Section (39)
// Yahia Khaled Elsafty   || Section (39)
// Mohamed Hamada AboSeda || Section (39)
// Yassin Khaled Elnaggar || Section (39)
// Omar Mohamed Ragaa     || Section (22)
// Omar Mohamed Shehata   || Section (22)

// Libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------------------------------------------------------

// class of items
struct product { 
    char name[30];
    float price;
};

//Products Database For Our Shop

int food_choice;  // FOOD
char foods[9][30] = {
    "Bananas (1kg)      ",
    "Rice    (1kg)      ",
    "Bread  (loaf)      ",
    "Eggs  (dozen)      ",
    "Milk     (1L)      ",
    "Cheese (200g)      ",
    "Butter (250g)      ",
    "Chicken (1kg)      ",
    "Apples  (1kg)      ",
};
float foods_prices[9] = { 1.20, 0.99, 2.50, 1.30, 2.75, 2.10, 6.50, 1.80, 1.10 };

int drink_choice; // DRINKS
char drinks[10][30] = {
    "Yogurt Drink       ",
    "Water              ",
    "Cola               ",
    "Juice              ",
    "Energy Drink       ",
    "Coffee             ",
    "Tea                ",
    "Milkshake          ",
    "smoothie           ",
    "Iced Tea           ",
};
float drinks_prices[10] = { 0.80, 1.50, 2.00, 2.25, 3.99, 2.20, 1.75, 1.10, 1.30, 1.60 };

int clothes_choice; // CLOTHES
char clothes[7][30] = {
    "Cap                ",
    "T-Shirt            ",
    "Jeans              ",
    "Jacket             ",
    "Hoodie             ",
    "Shorts             ",
    "Sneakers           ",
};
float clothes_prices[7] = { 11.99, 24.99, 39.99, 29.99, 14.50, 49.99, 17.99 };

int Medicine_choice; // MEDICINE
char Medicine[7][30] = {
    "Allergy Relief     ",
    "Paracetamol        ",
    "Ibuprofen          ",
    "Cough Syrup        ",
    "Antibiotic Pills   ",
    "Vitamin C          ",
    "Antacid Tablets    ",
};
float Medicine_prices[7] = { 1.50, 2.00, 3.25, 5.99, 2.75, 1.80, 3.50 };
//----------------------------------------------------------------------------------


// Coupons and Discounts Intiation Section
char coupons[4][10] = { "yousab", "yahia", "omar", "yassin" };
float discount[4] = { 0.05, 0.1, 0.15, 0.2 };
float discount_value = 0.0;
//---------------------------------------------------------------------------------------------------------

// Global Variables
double full_price = 0; // Full Price of the purchased items
int number_of_items = 0; // Number of Purchesed items


//=========================================================================================================================================================================//
//================================================================!! ALL THE ADDED FEATURES TO THE SHOP !!=================================================================//
//=========================================================================================================================================================================//

// Shipping Locations Function Pricing

char *locations[10] = {
    "Talkha      ",
    "El Gamaa    ",
    "El Toriel   ",
    "Gehan Street",
    "Sandoob     ",
    "Shinnawy    ",
    "El Mashaya  ",
    "El Mogamaa  ",
    "El Dawahi   ",
    "El Mahatta  "
};

float deldevrytime[10] = {
    30.0, 40.0, 35.0, 45.0, 50.0,
    25.0, 55.0, 38.0, 42.0, 60.0
};


// Shipping Function
int Shipping() {
    int shipping_method, run = 1;
    int shippingPrice = 0;
    while (run) {
        printf("\n1. Standard Shipping\t5-7 Days\t10$\n2. Fast Shipping\t2-3 Days\t17$\n3. Overnight Shipping\tNext Day\t25$\n\nchoose shipping option: "); // All Shipping choices
        scanf("%d", &shipping_method); // Receives The Shipping Option Chose By The User.
        
        // Choosing The Shipping Method By The User.
        switch (shipping_method) {
            case 1:           
                shippingPrice += 10;
                run = 0;
            break;
            case 2:
                shippingPrice += 17;
                run = 0;
            break;
            case 3:
                shippingPrice += 25;
                run = 0;
            break;
            default:
                printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n"); // The Message if the user entered a wrong value.
                run = 1;
                break;
        }
    }
    return shippingPrice;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------ 
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// Coupons Function
void check_coupon() {
    char coupon_response, coupon_code[20];
    int coupon_index = -1;
    int valid_coupon = 0; 
    printf("Do you have a discount coupon [y/n]? ");
    scanf(" %c", &coupon_response);

    // Checking for Coupons
    if (coupon_response == 'y' || coupon_response == 'Y') { // Check for the Availability of a coupon.
        printf("Please enter your coupon code: ");
        scanf("%s", coupon_code);

        for (coupon_index = 0; coupon_index < 4; coupon_index++) { // Goes into each coupon in the array for valid ones.
            if (strcmp(coupons[coupon_index], coupon_code) == 0) {
                discount_value = full_price * discount[coupon_index]; 
                valid_coupon = 1;
                break;
            }
        }
      
    if (valid_coupon != 1) {
            printf("\nInvalid coupon code.\n"); 
        }      
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Payment Function
int Payment_Function(double total) {  // Choosing out the payment method

    int paymentMethod;
    float paidAmount;

    printf("\n------ Payment ------\n");
    printf("Select payment method:\n");
    printf("1. Cash\n");
    printf("2. Credit Card\n");
    printf("3. Vodafone Cash \\ Fawary\n");
    printf("-----------------------------");
    printf("\n\nChoice: ");
    scanf("%d", &paymentMethod);

    switch (paymentMethod) {
        case 1:
            printf("Total Price [%f EGP]: ", full_price);
            scanf("%f", &paidAmount);
            if (paidAmount < total) {
                printf("\nInsufficient amount! Please pay at least [%f EGP]\n\n\n", total);
                Payment_Function(total); // Re-prompt recursively
            } else {
                printf("\nPayment accepted. Change: %f EGP\n\n\n", paidAmount - total);
            }
            break;
        case 2:
            printf("\n==============================================");
            printf("\nProcessing credit card payment of %f EGP...\n", total);
            printf("\t\tPayment successful!\n");
            printf("==============================================\n\n\n");

            break;
        case 3:
            printf("\n==============================================");
            printf("\nPaying via digital services %f EGP...\n",total);
            printf("\t\tPayment Succefully Proccesed!\n");
            printf("==============================================\n\n\n");
            break;
        default:
            printf("\nInvalid choice. Try again.\n");
            Payment_Function(total);
    }
    return paymentMethod;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Items Recommendation Function
void recommend_items(int section_number, int choice) {
    // Suggests items based on category and selected item
    switch (section_number) {
        case 1: // Food Section Recommendations
            if (choice == 5) {
                printf("\t\t[You may also like: Cheese, Butter.]\n");
            } else if (choice == 7) {
                printf("\t\t[You may also like: Milk, Cheese.]\n");
            } else if (choice == 1) {
                printf("\t\t[You may also like: Apple, Milk.]\n");
            }
            break;
      
        case 2: // Drinks Section Recommendations
            if (choice == 1) {
                printf("\t\t[You may also like: Smoothie, Milkshake.]\n");
            } else if (choice == 3) {
                printf("\t\t[You may also like: Energy Drink, Iced Tea.]\n");
            } else if (choice == 6) {
                printf("\t\t[You may also like: Coffee, Milk.]\n");
            }
            break;
      
        case 3: // Clothes Section Recommendations
            if (choice == 2) {
                printf("\t\t[You may also like: Jeans, Sneakers.]\n");
            } else if (choice == 4) {
                printf("\t\t[You may also like: Hoodie, Jeans.]\n");
            } else if (choice == 7) {
                printf("\t\t[You may also like: Shorts, T-Shirt.]\n");
            }
            break;
      
        case 4: // Medicine Section Recommendations
            if (choice == 1) {
                printf("\t\t[You may also like: Antihistamines.]\n");
            } else if (choice == 3) {
                printf("\t\t[You may also like: Paracetamol.]\n");
            } else if (choice == 6) {
                printf("\t\t[You may also like: Cough Syrup.]\n");
            }
            break;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//=========================================================================================================================================================================//
//=================================================================END OF FEATURES SECTION OF THE CODE=====================================================================//
//=========================================================================================================================================================================//

int main() {
    struct product item[100];
    int item_index = 0;
    bool run = true;
    bool checker = true;
    char other_section;

    printf("\n\t\t\t\t\t\tWelcome to Dukan-404!\n\n");

    while (checker) {
        int section, run = 1;

        printf("Choose the section you want: \n\n");

        // Choosing the desired section in the grocery shop
        while (run) {
            printf("For Food Enter \"1\" \nFor Drinks Enter \"2\" \nFor Clothes Enter \"3\" \nFor Medicine Enter \"4\" \n");
            printf("\nSection: ");
            scanf("%d", &section);

            if (section < 1 || section > 4)
                printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
            else
                run = 0;
        }
        //---------------------------------------------------------------------
        
        switch (section) { 
            case 1: // FOOD SECTION
                run = 1;
                printf("Foods:\n");
                    for(int i = 1; i <= 9; i++) {
                        printf("%d. %s ............... $%.2f\n", i, foods[i-1], foods_prices[i-1]);
                    }
                while (run) {
                    food_choice = 0;
                    printf("\nEnter the number of the food you want to buy (Enter 0 to exit): ");
                    scanf("%d", &food_choice);
                    fflush(stdin);
                
                    if (food_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the food section............\n");
                        run = 0;
                        break;
                    }
                    else if (food_choice >= 1 && food_choice <= 9) { // Valid choices
                        printf("\n\t\tYOU HAVE SELECTED %s\n", foods[food_choice - 1]);
                        strcpy(item[item_index].name, foods[food_choice - 1]);
                        item[item_index].price = foods_prices[food_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += foods_prices[food_choice - 1];

                        // Call out for Recommendations Function
                        recommend_items(section, food_choice);
                        
                    }
                    else {
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        continue;
                    }
                }
                break;

            case 2: // DRINKS SECTION
                run = 1;
                printf("\nDrinks:\n");
                for(int i = 1; i <= 10; i++) {
                    printf("%d. %s ............... $%.2f\n", i, drinks[i-1], drinks_prices[i-1]);
                }
                while (run) {
                    drink_choice = 0;
                    printf("\nEnter the number of the drink you want to buy (Enter 0 to exit): ");
                    scanf("%d", &drink_choice);
                    fflush(stdin);
                
                    if (drink_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the drinks section............\n");
                        run = 0;
                        break;
                    }
                    else if (drink_choice >= 1 && drink_choice <= 10) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", drinks[drink_choice - 1]);
                        strcpy(item[item_index].name, drinks[drink_choice - 1]);
                        item[item_index].price = drinks_prices[drink_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += drinks_prices[drink_choice - 1];

                        // Call out for Recommendations Function
                        recommend_items(section, drink_choice);
                    }
                    else {
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        continue;
                    }
                }
                break;

            case 3: // CLOTHES SECTION
                run = 1;
                printf("Clothes:\n");
                for(int i = 1; i <= 7; i++) {
                    printf("%d. %s ............... $%.2f\n", i, clothes[i-1], clothes_prices[i-1]);
                }
                while (run) {
                    clothes_choice = 0;
                    printf("\nEnter the number of the clothes you want to buy (Enter 0 to exit): ");
                    scanf("%d", &clothes_choice);
                    fflush(stdin);
                
                    if (clothes_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the clothes section...........\n");
                        run = 0;
                        break;
                    }
                    else if (clothes_choice >= 1 && clothes_choice <= 7) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", clothes[clothes_choice - 1]);
                        strcpy(item[item_index].name, clothes[clothes_choice - 1]);
                        item[item_index].price = clothes_prices[clothes_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += clothes_prices[clothes_choice - 1];

                        // Call out for Recommendations Function
                        recommend_items(section, clothes_choice);
                    }
                    else {
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        continue;
                    }
                }
                break;

            case 4: // MEDICINE SECTION
                run = 1;
                printf("Medicines:\n");
                for(int i = 1; i <= 7; i++) {
                    printf("%d. %s ............... $%.2f\n", i, Medicine[i-1], Medicine_prices[i-1]);
                }
                
                while (run) {
                    Medicine_choice = 0;
                    printf("\nEnter the number of the Medicine you want to buy (Enter 0 to exit): ");
                    scanf("%d", &Medicine_choice);
                    fflush(stdin);
                
                    if (Medicine_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the medicine section...........\n");
                        run = 0;
                        break;
                    }
                    else if (Medicine_choice >= 1 && Medicine_choice <= 7) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", Medicine[Medicine_choice - 1]);
                        strcpy(item[item_index].name, Medicine[Medicine_choice - 1]);
                        item[item_index].price = Medicine_prices[Medicine_choice - 1];
                        item_index++;
                        number_of_items++;
                        full_price += Medicine_prices[Medicine_choice - 1];

                        // Call out for Recommendations Function
                        recommend_items(section, Medicine_choice);
                    }
                    else {
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        continue;
                    }
                }
                break;
        }

        printf("\nDo you want to Buy from another section? (y/n): "); // Asking for continuance.
        scanf(" %c", &other_section);
        if (other_section == 'n' || other_section == 'N') {
            checker = false;
        }
        else if (other_section == 'y' || other_section == 'Y') {
            checker = true;
        }
        else {
            printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
            continue;
        }
}
                   
    if (number_of_items == 0) { // Sorry Message
        printf("\nWe are sorry that none of our products has intrested you and we're willing to see you soon :(\n");
        return 0;
    } else {
        int shipping_method = Shipping(); // get the value of the shipping method
        full_price += shipping_method; // Adding the shipping method price to the full price
        // Determining the shipping location
        bool LocationVerification = true;
        int choiceOfShipping;
        while (LocationVerification) {
            
            printf("\nSelect your shipping address from the list below:\n");
            for (int i = 0; i < 10; i++) {
                printf("%d. %s\n", i + 1, locations[i]);
            }
    
            printf("Enter the number of your location: ");
            scanf("%d", &choiceOfShipping);
    
            if (choiceOfShipping < 1 || choiceOfShipping > 10) {
                printf("\n\t!Invalid location number.!\n");
                LocationVerification = true;
            } else {
                LocationVerification = false;
            }
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
        
        check_coupon(); // check for the coupon
        int payment_m_print = Payment_Function(full_price);


      // Random Order Number
      srand(time(NULL));  // Seeding the random number with a random value
      int orderNumber = (rand() % 99) + 1;  // Generating a Random Number
      //=====================================================================

      //============================================================================================================================================//
                                                //             ###     Printing Out the Receipt    ###             //
      //==========================================================================================================================================//
      
      printf("\n");
      printf("          ||========================================||\n");
      printf("          ||              Your Receipt              ||\n");    
      printf("          ||========================================||\n");
      printf("          || Product Name:                    Price ||\n");
      printf("          ||                                        ||\n");
      // Printing item list
      for (item_index = 0; item_index < number_of_items; item_index++) {  
        if(item[item_index].price < 10){   
             printf("          || %d- %-25s +%.2f EGP ||\n",item_index + 1, item[item_index].name, item[item_index].price);    
        }
        else if (item[item_index].price >= 10){   
             printf("          || %d- %-25s+%.2f EGP ||\n",item_index + 1, item[item_index].name, item[item_index].price);  
        }     
    }

      printf("          ||                                        ||\n");
      printf("          ||----------------------------------------||\n");
      

      // Pricing Section
      if(full_price >100){
            printf("          || Raw Price:                  %.2lf EGP ||\n", full_price);      
      } 
      else{
            printf("          || Raw Price:                  %.2lf EGP  ||\n", full_price);
      }

      printf("          || Shipping Price:                %d EGP  ||\n", shipping_method); // Printing the shipping price

      if (discount_value>10) {
        printf("          || Discount:                   -%2.2f EGP ||\n", discount_value);  //lines 476 to end are to adjust spacing
      }                                                                               //for the love of god dont mess with them
      else {                                                                          //         IAM WATCHINH YOU !!
        printf("          || Discount:                   -%2.2f EGP  ||\n", discount_value); //          ############
      }                                                                               //   #######    0000    ########
                                                                                      // /##        00 ** 00          ##\ 
                                                                                      // \##        00 ** 00          ##/                            
      full_price -= discount_value;                                                   //   #######    0000     #######
                                                                                      //          ############
      if(full_price >100){                                                            
            printf("          || Total Price:                %.2lf EGP ||\n", full_price);
      } 
      else{
            printf("          || Total Price:                %.2lf EGP  ||\n", full_price);
      }
      
      
      printf("          ||----------------------------------------||\n");
      
      // Payment Method Section
      if (payment_m_print == 1) {
        printf("          ||           Payment Method: Cash         ||\n");
      } else if (payment_m_print == 2) {
        printf("          ||       Payment Method: Credit Card      ||\n");
      } else {
        printf("          ||    Payment Method: Digital Services    ||\n");
      }

      if (orderNumber >= 10) {
          printf("          ||            Order Number: %d            ||\n", orderNumber);
      } else {
          printf("          ||            Order Number: %d             ||\n", orderNumber);
      }
        

      // Thanks Message
      printf("          ||----------------------------------------||\n");
      printf("          ||    The Shipping Address Is %s||\n",locations[choiceOfShipping - 1]);
      printf("          || The Package Will Be On Your Door In %.0f ||\n",deldevrytime[choiceOfShipping - 1]);
      printf("          ||   Mins After You Receive The Message   ||\n");
      printf("          ||      Thanks For Buying From Us!        ||\n");
      printf("          ||           See You Soon :)              ||\n"); 
      printf("          ||========================================||\n\n\n");
      
          return 0;
    }
}
