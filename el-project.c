// Yousab Nabil Nasrala   || Section (39)
// Yahia Khaled Elsafty   || Section (39)
// Mohamed Hamada AboSeda || Section (39)
// Yassin Khaled Elnaggar || Section (39)
// Omar Mohamed Ragaa     || Section (22)
// Omar Mohamed Shehata   || Section (22)
// Mahmoud Saad Helal     || Section (33)
// Mohamed Sobhi Eltelwy  || Section (29)
// Mohamed Elnagar        || Section (30)
// Mahmoud Samir Saad     || SEction (33)

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
    "Smoothie           ",
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
char coupons[5][20] = { "yousab", "yahia", "omar", "yassin", "dr.mohamed" }; // 5 coupons
float discount[5] = { 0.05, 0.1, 0.15, 0.2, 0.99 }; // 5%, 10%, 15%, 20% , 99%
float discount_value = 0.0;
//---------------------------------------------------------------------------------------------------------

// Global Variables
double full_price = 0; // Full Price of the purchased items
int number_of_items = 0; // Number of Purchesed items
struct product item[100]; // Array of items in the cart
int item_index = 0; // Index for the items
int shipping_method; // Shipping Method


char locations[10][30] = {
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

char greetings_3m_far8ali [10][100] = {
    "[3m far8ali👳 : menawar el ma7al yam3alem eh a5barak keda]",
    "[3m far8ali👳 : Ahlan wasahlan ya basha]",
    "[3m far8ali👳 : Izayyak ya me3alem kollo tamam?]",
    "[3m far8ali👳 : Sabah el fol ya gameel!]",
    "[3m far8ali👳 : Feenak ya rayes? mabt3adee4 leh]",
    "[3m far8ali👳 : el samalo 3liko ya ba4a!, t3ala e4rab 4ay m3ana]",
    "[3m far8ali👳 : 3mel eih ya gada3 eh a5barak el ayam di]",
    "[3m far8ali👳 : kont lesa fi dema8i walahi enta fen keda ya me3alem]",
    "[3m far8ali👳 : el dukan dukanak ye me3alem 5od ra7tak]",
    "[3m far8ali👳 : el ducan nawar lma enta da5alt walahi]" 
};

char farewells_3m_far8ali [10][100] = {
    "[3m far8ali👳 : Maʿ el salama ya basha!🧾]",
    "[3m far8ali👳 : Yalla salam ya gameel!🧾]",
    "[3m far8ali👳 : Ashofak 3la 5eir insha2 Allah!🧾]",
    "[3m far8ali👳 : Matet2akharsh 3alina keda ya ma3lem!🧾]",
    "[3m far8ali👳 : Yalla bye bye ya ma3lem !🧾]",
    "[3m far8ali👳 : tenawatna fi 2y wa3t, el makan makanak!🧾]",
    "[3m far8ali👳 : Dayman menawarna ya 7abibi!🧾]",
    "[3m far8ali👳 : 7ala ya kebeer salamli 3la el 3eyal🧾]",
    "[3m far8ali👳 : 7adretak tesharraf ay wa2t🧾]",
    "[3m far8ali👳 : te4arfna 3alatoon ya m3alem🧾]" 
};


//=========================================================================================================================================================================//
//================================================================!! ALL THE ADDED FEATURES TO THE SHOP !!=================================================================//
//=========================================================================================================================================================================//

// Shipping Locations Function Pricing
int Shipping() {
    int run = 1;
    int shippingPrice = 0;
    while (run) {
        printf("\n1. Standard Shipping\t5-7 Days\t10$\n2. Fast Shipping\t2-3 Days\t17$\n3. Overnight Shipping\tNext Day\t25$\n\nchoose shipping option: "); // All Shipping choices
        scanf("%d", &shipping_method); // Receives The Shipping Option Chose By The User.
        fflush(stdin);
        
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
    fflush(stdin);

    // Checking for Coupons
    if (coupon_response == 'y' || coupon_response == 'Y') { // Check for the Availability of a coupon.
        printf("Please enter your coupon code: ");
        scanf("%s", coupon_code);
        fflush(stdin);

        for (coupon_index = 0; coupon_index < 5; coupon_index++) { // Goes into each coupon in the array for valid ones.
            if (strcmp(coupons[coupon_index], coupon_code) == 0) {
                discount_value = full_price * discount[coupon_index]; 
                valid_coupon = 1;
                if (strcmp("dr.mohamed", coupon_code) == 0) {
                    printf("\n==================================================================");
                    printf("\n!!!!!!!!!!! OOOOOH THE GOLDEN COUPON [YOU GET 99%% OFF] !!!!!!!!!!!\n");
                    printf("==================================================================\n");
                }
                break;
            }
        }
      
    if (valid_coupon != 1) { // if the coupon is not valid print out this message.
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
    printf("1. Cash 💲\n");
    printf("2. Credit Card 💳\n");
    printf("3. Vodafone Cash \\ Fawary 📲\n");
    printf("-----------------------------");
    printf("\n\nChoice: ");
    scanf("%d", &paymentMethod);
    fflush(stdin);

    switch (paymentMethod) {
        case 1:
            printf("Total Price [%0.2f EGP]: ", full_price - discount_value);
            scanf("%f", &paidAmount);
            fflush(stdin);

            if (paidAmount < total) {
                printf("\nInsufficient amount! Please pay at least [%0.2f EGP]\n\n\n", total);
                Payment_Function(total); // Re-prompt recursively
            } else {
                printf("\n\t\tPayment accepted. Change: %.2f EGP\n\n\n", paidAmount - total);
            }
            break;
        case 2:
            printf("\n\t\t\t==============================================");
            printf("\n\t\t\tProcessing credit card payment of %0.2f EGP...", total);
            printf("\n\t\t\t\t\tPayment successful!");
            printf("\n\t\t\t==============================================\n\n\n");

            break;
        case 3:
        {
            int len, not_valid=1;
            char mobile_number[11];
            char check_number;

            printf("\n\t\t\t==============================================");
            printf("\n\t\t\tPaying via digital services %.2f EGP...",total);

            while(not_valid){
                
                printf("\n\t\t\tPlease Enter your mobile number: ");
                scanf("%s", mobile_number);
                fflush(stdin);
                len = strlen(mobile_number);

                if ( (len !=11) || (mobile_number[0] != '0') || (mobile_number[1] != '1' ) ){
                    printf("\n\t\t\tInvalid mobile number. Please try again.\n");
                    not_valid = 1;
                }   
                else{
                   printf("\n\t\t\t confirm this is your mobile number: %s ? [Y/n] \n", mobile_number);
                    scanf(" %c", &check_number);
                    fflush(stdin);

                    if (check_number == 'Y' || check_number == 'y') {
                        not_valid = 0; 
                        printf("\t\t\t\t\tPayment Successfully Processed!");
                        printf("\n\t\t\t==============================================\n\n\n");
                    } else {
                        not_valid = 1;
                    }
                }
            }
            break;
        }

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
            if (choice == 1) {
                printf("\t\t[3m Far8ali👳: Mawgood Mawgood! El Mooz Lesah Gai Gdeed!]\n");
            } else if (choice == 2) { 
                printf("\t\t[3m Far8ali👳: 3andak Toffa7 w 7leeb. Momken Te3mel Behom Milkshake Lazeez]\n");
            } else if (choice == 3) {
                printf("\t\t[3m Far8ali👳: El 3eesh Tazah lesah Gai Embar7! Law tgeeb gebna aw zebda yb2a 3al El 3al]\n");
            } else if (choice == 4) {
                printf("\t\t[3m Far8ali👳: El beid yeb2a gameel law 3maltoh m3 Gbnah, Shakshookah Ya M3lem!]\n");
            } else if (choice == 5) {
                printf("\t\t[3m Far8al👳: El laban dayman mofeed!]\n");
            } else if (choice == 6) {
                printf("\t\t[3m Far8ali👳: 3andak Gbnah w Zbdah lw 3ayz.]\n");
            } else if (choice == 7) {
                printf("\t\t[3m Far8ali👳: El Zebda m3 el toast We El 3asal teb2a 7ekaya.]\n");
            } else if (choice == 8) {
                printf("\t\t[3m Far8ali👳: 3andak Laban w Gbnah fi El Tlagah Eli Odam!]\n");
            } else if (choice == 9) {
                printf("\t\t[3m Far8ali👳: Yeb2a smoothie ya fa5eem.]\n");
            }
        break;
        //-----------------------------------------------------------------------------------------

        case 2: // Drinks Section Recommendations
            if (choice == 1) {
                printf("\t\t[3m Far8ali👳: El Laban El Rayeb da momtaz!]\n");
            } else if (choice == 2) {
                printf("\t\t[3m Far8ali👳: T7eb Smoothie wla Milkshake kman?]\n");
            } else if (choice == 3) {
                printf("\t\t[3m Far8ali👳: El Cola Sa23ah bas ma tensash El Maya... El Gaw 7ar Elnahardah.]\n");
            } else if (choice == 4) { 
                printf("\t\t[3m Far8ali👳: Fi Energy Drink we Iced Tea fi el freezer]\n");
            } else if (choice == 5) {
                printf("\t\t[3m Far8ali👳: El Energy Drink da yenfa3 ma3 el sahra.]\n");
            } else if (choice == 6) {
                printf("\t\t[3m Far8ali👳: Zo2ak Hayel fi el 2hwa!]\n");
            } else if (choice == 7) {
                printf("\t\t[3m Far8ali👳: 2hwa we 7aleeb, a7la nescafe!]\n");
            } else if (choice == 8) {
                printf("\t\t[3m Far8ali👳: El Milkshake da fatkarny b sob7 el elgoma3a... lw 3andak smoothie tamam!]\n");
            } else if (choice == 9) {
                printf("\t\t[3m Far8ali👳: Smoothie? Da y3ady el sob7 b nafs tayba. 7ot ma3ah laban w toffa7.]\n");
            } else if (choice == 10) {
                printf("\t\t[3m Far8ali👳: Iced Tea da 3ashan el gaw. W lw shay sokh, ana 3andy bard.]\n");
            }
        break;
        //-----------------------------------------------------------------------------------------

        case 3: // Clothes Section Recommendations
            if (choice == 1) {
                printf("\t\t[3m Far8ali👳: El T-Shirt da yelzemlo Shorts 3leek.]\n");
            } else if (choice == 2) {
                printf("\t\t[3m Far8ali👳: Jeans? Gamed! El Sneakers haykamlak el style.]\n");
            } else if (choice == 3) {
                printf("\t\t[3m Far8ali👳: El Jacket dah to7fah 3leek!]\n");
            } else if (choice == 4) {
                printf("\t\t[3m Far8ali👳: El Hoodie dah m3 el jeans el sodah damaaaar]\n");
            } else if (choice == 5) {
                printf("\t\t[3m Far8ali👳: Shorts Lel sa7el! Ragel Betfham.]\n");
            } else if (choice == 6) {
                printf("\t\t[3m Far8ali👳: El Sneakers dol lesah nazleen gdeed!]\n");
            } else if (choice == 7) {
                printf("\t\t[3m Far8ali👳: Law el gaw 7ar, geeb Shorts w T-Shirts.]\n");
            }
        break;   
        //-----------------------------------------------------------------------------------------

        case 4: // Medicine Section Recommendations
            if (choice == 1) {
                printf("\t\t[3m Far8ali👳: lw 3andak 7asasia 5od dwa ko7a kman e7tyati.]\n");
            } else if (choice == 2) {
                printf("\t\t[3m Far8ali👳: dah momtaz le el soda3 !]\n");
            } else if (choice == 3) {
                printf("\t\t[3m Far8ali👳: dah 4alklo bard mata5odlak Vitamin C kman]\n");
            } else if (choice == 4) {
                printf("\t\t[3m Far8ali👳: lw el ko7a 4ededa 5od paracetamol 3l4an lw sada3t kman]\n");
            } else if (choice == 5) {
                printf("\t\t[3m Far8ali👳: yaah modad 7ayawi! alaf salama ya 7abibi]\n");
            } else if (choice == 6) {
                printf("\t\t[3m Far8ali👳: agiblak kilo borto2an knam ?]\n");
            } else if (choice == 7) {
                printf("\t\t[3m Far8ali👳: el tofa7 bysa3ed fi 3osr el hadm 3la fekra agebla kilo ?]\n");
            }
        break;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// Customer Support Function

void printQuestions() {
    printf("========== Customer Support Center ==========\n");
    printf("Please select your question by entering the number:\n\n");
    printf("1.  What are your store hours?\n");
    printf("2.  How can I track my order?\n");
    printf("3.  What is your return policy?\n");
    printf("4.  Can I modify my order after placing it?\n");
    printf("5.  What payment methods do you accept?\n");
    printf("6.  How do I use a coupon code?\n");
    printf("7.  Is there a minimum order for delivery?\n");
    printf("8.  How are cold/frozen items delivered?\n");
    printf("9.  Do you have organic products?\n");
    printf("10. How can I contact customer service?\n");
    printf("=============================================\n");
}

void answerQuestion(int choice) {
    switch (choice) {
        case 1: printf("\n[3m far8ali 👳‍♂ : el ma7al fake7 kol yom mn 8 AM le 10 PM. ]\n\n"); break;
        case 2: printf("\n[3m far8ali 👳 : haneb3atlak resala ow hanetesl beek yom el tawsil ]\n\n"); break;
        case 3: printf("\n[3m far8ali 👳 : ay montag ma3ada el akal we el 4orb momken teraga3o fi 5lal 7 ayam ]\n\n"); break;
        case 4: printf("\n[3m far8ali 👳 : tab3an ! e7tar \"5. view cart\" 2abal me te7aseb we hatla2i el option enak te4eel 7agat ]\n\n"); break;
        case 5: printf("\n[3m far8ali 👳 : te2dar tedfa3 cach aw be el criedt card aw 7ata vodafon cash we fawry ]\n\n"); break;
        case 6: printf("\n[3m far8ali 👳 : el barnameg hys2alak lw kan m3ak coupon we enta be t-check out 25tar 'y' we da5al el coupon ]\n\n"); break;
        case 7: printf("\n[3m far8ali 👳 : la2 te2dar totlop 4o7na be ay se3r te7ebo ]\n\n"); break;
        case 8: printf("\n[3m far8ali 👳 : beneb3athom fi sandoo2 mo5asas be7afez 3la daraget 7ararithom ta7et el sefr ]\n\n"); break;
        case 9: printf("\n[3m far8ali 👳 : kol el fwakeh we el 4odrawat 3andena organic 100 fi el 100 ]\n\n"); break;
        case 10:printf("\n[3m far8ali 👳 : momken tetwasel ma3ana 3la DUKAN404@gmail.com aw tetesl 3la 0103-345-4949 ]\n\n"); break; //dah rakami begad ya 4bab ma7ade4 ye troll XD
        default:printf("\n[3m far8ali 👳 : atamano akoon 3ereft asa3dak ]\n\n");
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// Cart Function
void show_selected_items() {
    printf("\n======= Your Selected Items =======\n");
    if ( number_of_items == 0) {
        printf("No items selected yet.\n");
    } else {
        for (int i = 0; i < number_of_items; i++) {
            printf("%2d. %-20s - %.2f EGP\n", i + 1, item[i].name, item[i].price); // Print out the selected items
        }
        printf("----------------------------------\n");
        printf("Total so far: %.2f EGP\n", full_price); // Print out the total price for the current selected items.
    }
    printf("===================================\n\n");
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// Function for removing items from the cart

void remove_item_from_cart(int item_index) {
    if (item_index < 0 || item_index >= number_of_items) {
        printf("Invalid item index.\n");
        return;
    }
    // Shift items to the left
    for (int i = item_index; i < number_of_items - 1; i++) {
        item[i] = item[i + 1];
    }
    number_of_items--;
    full_price -= item[item_index].price; // Update the total price
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// 3am Far8ali's recipes from cart items

void suggestRecipeFromFood() {
    int hasBananas = 0, hasRice = 0, hasBread = 0, hasEggs = 0, hasMilk = 0, hasCheese = 0, hasButter = 0, hasChicken = 0, hasApples = 0;

    for (int i = 0; i < number_of_items; i++) {
        if (strcmp(item[i].name, "Bananas (1kg)      ") == 0) hasBananas = 1;
        if (strcmp(item[i].name, "Rice    (1kg)      ") == 0) hasRice = 1;
        if (strcmp(item[i].name, "Bread  (loaf)      ") == 0) hasBread = 1;
        if (strcmp(item[i].name, "Eggs  (dozen)      ") == 0) hasEggs = 1;
        if (strcmp(item[i].name, "Milk     (1L)      ") == 0) hasMilk = 1;
        if (strcmp(item[i].name, "Cheese (200g)      ") == 0) hasCheese = 1;
        if (strcmp(item[i].name, "Butter (250g)      ") == 0) hasButter = 1;
        if (strcmp(item[i].name, "Chicken (1kg)      ") == 0) hasChicken = 1;
        if (strcmp(item[i].name, "Apples  (1kg)      ") == 0) hasApples = 1;
    }
    
    int all_of_them = hasApples + hasBananas + hasRice + hasBread + hasEggs + hasMilk + hasCheese + hasButter + hasChicken;

    if (all_of_them > 0) {
        printf("\n3m Far8ali👳: 7abibi, el akl elly 3andak fi el cart da 7aga 7elw awi! \n");
    }

    // Recipe suggestions based on available ingredients
    if (hasBananas && hasMilk) {
        printf("Bananas + Milk = Smoothie farghali, ya 7abibi 🥤🍌\n");
    }
    if (hasChicken && hasRice) {
        printf("Chicken + Rice = Farghali's Special Chicken & Rice 🍗🍚\n");
    }
    if (hasEggs && hasCheese && hasBread) {
        printf("Eggs + Cheese + Bread = Sandwich farghali style! 🍞🧀🍳\n");
    }
    if (hasApples && hasCheese) {
        printf("Apples + Cheese = Salata farghali, ba7ebeh 🧀🍏\n");
    }
    if (hasBananas && hasEggs) {
        printf("Bananas + Eggs = Pancakes farghali style! 🥞🍌\n");
    }
    if (hasChicken && hasCheese && hasBread) {
        printf("Chicken + Cheese + Bread = Sandwich ala Farghali! 🍗🧀🍞\n");
    }
    if (hasRice && hasMilk) {
        printf("Rice + Milk = Rice pudding, ya 7abibi! 🍚🥛\n");
    }
    if (hasBananas && hasApples && hasMilk) {
        printf("Bananas + Apples + Milk = Smoothie farghali style, ya m3alem 🍌🍏🥛\n");
    }
    if (hasEggs && hasCheese) {
        printf("Eggs + Cheese = Omelette farghali! 🍳🧀\n");
    }
    if (hasBananas && hasEggs && hasButter) {
        printf("Bananas + Eggs + Butter = Banana bread, farghali style! 🍌🍞\n");
    }

    if (all_of_them == 0) {
        printf("\nMafish Akl kifayah 3shan elwasfah fi Al salah ya m3lem. 👳\n\n");
    }
}

void Rating ()
{
    int presentation_rating,costumerSupport_rating,readabilty_rating,CodeEfficiency_rating,full_rating,precentage;
    printf("          ||========================================||\n");
    printf("          ||      Please rate our online shop!      ||\n");
    printf("          ||      3shan 3m far8ali 👳 m4 rady ydf3  ||\n");

    printf("          ||========================================||\n");
    printf("               costumer support? (out of 10):    ");
    scanf("%d",&costumerSupport_rating);
    printf("          ||----------------------------------------||\n");
 
    printf("               Code readabilty? (out of 10):     ");
    scanf("%d",&readabilty_rating);
    printf("          ||----------------------------------------||\n");

    printf("                Code Efficiency ? (out of 10):   ");
    scanf("%d",&CodeEfficiency_rating);
    printf("          ||----------------------------------------||\n");

    printf("                presentation? (out of 10):       "); 
    scanf("%d", &presentation_rating);
    printf("          ||========================================||\n\n\n");

    full_rating=presentation_rating+costumerSupport_rating+readabilty_rating+CodeEfficiency_rating;
    precentage= (full_rating/40)*100;

    if(precentage>=90)
        printf("3m far8ali 👳: bainy keda lazm a7asb el 3yal di begad!");
    else if(precentage>=75)
        printf("3m far8ali 👳: El eyal te3bt fe3lan h7asb b 25%% discount");
    else if (precentage>=50)
        printf("3m far8ali 👳: El 3yal e4t8lt w shrt brdo hdf3 50%% mn el mabl8");
    else if (precentage<=50)
         printf("3m far8ali 👳: bernamg 3la el kd khals hdf3 30%% 3shan mz3lhm4");
}
//=========================================================================================================================================================================//
//=================================================================END OF FEATURES SECTION OF THE CODE=====================================================================//
//=========================================================================================================================================================================//

int main() {
    bool run = true;
    bool checker = true;
    char other_section;
    int section;
    bool run_the_cart_rmoval = true;

    // Random number generators ::   
        srand(time(NULL));  
        int orderNumber = (rand() % 99) + 1;   // Generating a Random Number between 1 and 99 for use in order number
        int greeting_number = (rand() % 10);   // Generating a Random Number between 0 and 9 for use in greeting greeting message
        int farewell_number = (rand() % 10);   // Generating a Random Number between 0 and 9 for use in farewell message
    //=====================================================================

    printf("\n\t\t\t%s\n\n", greetings_3m_far8ali[greeting_number]); // Print out the greeting message

    while (checker) {
        int run = 1;

        printf("Choose the section you want: \n\n");

        // Choosing the desired section in the grocery shop
        while (run) {
            printf("For Food Enter \"1\" 🍔 \nFor Drinks Enter \"2\" 🍹 \nFor Clothes Enter \"3\" 👕 \nFor Medicine Enter \"4\" 💊 \n======================\nTo See Your Cart Enter \"5\" 🛒 \nFor Es2al Far8ali Enter \"6\" ❓ \nFor Far8li's Recipes Enter \"7\" 🥘👳 \n"); // Print out the sections
            if (number_of_items > 0) { // If there are items in the cart then print the payment option
                printf("\n\t\t\t\t[Proceed to payment Enter \"8\" 💵 ] \n");
            }
            printf("\nSection [Enter 0 to Exit the Program]: "); // Choossing the section
            scanf("%d", &section); // Choosing the section
            fflush(stdin);

            if (number_of_items > 0) { // If there are items in the cart then show the payment option
                if (section < 0 || section > 8) {
                    printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                } else if (section == 8) { // Proceed to payment
                        checker = false;
                        run = 0;
                } else if (section == 0) { // Exit the program
                    checker = false;
                    run = 0;
                } else { // Valid section
                    run = 0;
                }
            }

            if (number_of_items == 0) { // If there are no items in the cart then do not show the payment option
                if (section < 0 || section > 7) {
                    printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                } else if (section == 0) { // Exit the program
                    checker = false;
                    run = 0;
                } else { // Valid section
                    run = 0;
                }
    
            }
            
        }
        //---------------------------------------------------------------------
        
        switch (section) { 
            case 1: // FOOD SECTION
                run = 1;
                printf("Foods:\n");
                    for(int i = 1; i <= 9; i++) {
                        printf("%d. %s ............... $%.2f\n", i, foods[i-1], foods_prices[i-1]); // Print out the food items.
                    }
                while (run) {
                    food_choice = 0;
                    printf("\nEnter the number of the food you want to buy (Enter 0 to exit): ");
                    scanf("%d", &food_choice);
                    fflush(stdin);
                
                    if (food_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the food section............\n\n");
                        run = 0;
                        break;
                    }
                    else if (food_choice >= 1 && food_choice <= 9) { // Valid choices
                        printf("\n\t\tYOU HAVE SELECTED %s\n", foods[food_choice - 1]); // Print out the selected item
                        // Adding the selected item to the cart
                        strcpy(item[item_index].name, foods[food_choice - 1]);
                        item[item_index].price = foods_prices[food_choice - 1];
                        item_index++; // Increment the item index to add the new item.
                        number_of_items++; // Increment the number of items in the cart
                        full_price += foods_prices[food_choice - 1]; // Adding the price of the selected item to the full price

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
                    printf("%d. %s ............... $%.2f\n", i, drinks[i-1], drinks_prices[i-1]); // Print out the drinks items.
                }
                while (run) {
                    drink_choice = 0;
                    printf("\nEnter the number of the drink you want to buy (Enter 0 to exit): ");
                    scanf("%d", &drink_choice);
                    fflush(stdin);
                
                    if (drink_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the drinks section............\n\n");
                        run = 0;
                        break;
                    }
                    else if (drink_choice >= 1 && drink_choice <= 10) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", drinks[drink_choice - 1]); // Print out the selected item
                        // Adding the selected item to the cart
                        strcpy(item[item_index].name, drinks[drink_choice - 1]);
                        item[item_index].price = drinks_prices[drink_choice - 1];
                        item_index++; // Increment the item index to add the new item.
                        number_of_items++; // Increment the number of items in the cart
                        full_price += drinks_prices[drink_choice - 1]; // Adding the price of the selected item to the full price

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
                    printf("%d. %s ............... $%.2f\n", i, clothes[i-1], clothes_prices[i-1]); // Print out the clothes items.
                }
                while (run) {
                    clothes_choice = 0;
                    printf("\nEnter the number of the clothes you want to buy (Enter 0 to exit): ");
                    scanf("%d", &clothes_choice);
                    fflush(stdin);
                
                    if (clothes_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the clothes section...........\n\n");
                        run = 0;
                        break;
                    }
                    else if (clothes_choice >= 1 && clothes_choice <= 7) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", clothes[clothes_choice - 1]); // Print out the selected item

                        // Adding the selected item to the cart
                        strcpy(item[item_index].name, clothes[clothes_choice - 1]);
                        item[item_index].price = clothes_prices[clothes_choice - 1];
                        item_index++; // Increment the item index to add the new item.
                        number_of_items++; // Increment the number of items in the cart
                        full_price += clothes_prices[clothes_choice - 1]; // Adding the price of the selected item to the full price

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
                    printf("%d. %s ............... $%.2f\n", i, Medicine[i-1], Medicine_prices[i-1]); // Print out the medicine items.
                }
                
                while (run) {
                    Medicine_choice = 0;
                    printf("\nEnter the number of the Medicine you want to buy (Enter 0 to exit): ");
                    scanf("%d", &Medicine_choice);
                    fflush(stdin);
                
                    if (Medicine_choice == 0) {  // Exit when user enters 0
                        printf("\nExiting the medicine section...........\n\n");
                        run = 0;
                        break;
                    }
                    else if (Medicine_choice >= 1 && Medicine_choice <= 7) { // Valid choices
                        printf("\n\t\tYou have selected %s\n", Medicine[Medicine_choice - 1]); // Print out the selected item
                        
                        // Adding the selected item to the cart
                        strcpy(item[item_index].name, Medicine[Medicine_choice - 1]);
                        item[item_index].price = Medicine_prices[Medicine_choice - 1];
                        item_index++; // Increment the item index to add the new item.
                        number_of_items++; // Increment the number of items in the cart
                        full_price += Medicine_prices[Medicine_choice - 1]; // Adding the price of the selected item to the full price

                        // Call out for Recommendations Function
                        recommend_items(section, Medicine_choice);
                    }
                    else {
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        continue;
                    }
                }
                break;
            case 5: // Show the selected items
                show_selected_items();
                char check_for_removal;
                int item_to_remove;
                printf("\nEnter [r] to enter the page where you can remove the items from your cart, else press any key: ");
                scanf("%s", &check_for_removal);
                fflush(stdin);
              
                if (check_for_removal == 'r') { // If the user wants to remove an item from the cart
                    run = true;

                    while (run_the_cart_rmoval) 
                    {
                        printf("Enter the number of the item you want to remove [Press 0 for exit]: ");
                        scanf("%d", &item_to_remove);
                        fflush(stdin);

                        if (item_to_remove == 0) { // Exit when user enters 0
                            printf("\nExiting the cart section...........\n\n");
                            run_the_cart_rmoval = false;
                        } else if (item_to_remove < 1 || item_to_remove > number_of_items) { // Invalid choice
                            printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                            run_the_cart_rmoval = true; 
                        } else if (item_to_remove >= 1 || item_to_remove <= number_of_items) {
                            remove_item_from_cart(item_to_remove - 1);
                            run_the_cart_rmoval = true;
                            printf("\n[Item removed from cart.]\n");
                        }
                        show_selected_items(); // Show the updated cart
                    }
                    checker = true;
                } else {
                    checker = true;
                }

                break;
            
            case 6: // Customer Support Section
                run = 1;
                printf("\n3m Far8ali👳: ahlan beek fi 5edmet el 3omala2 2a2dar asa3dak ezay ?\n\n"); // Customer Support Section welcome message
                printQuestions(); // Print out the questions
                int question_choice; // Variable to store the question choice

                while (run) {
                    printf("Enter the number of your question [Press 0 for Exit]: "); // Get the question choice
                    scanf("%d", &question_choice);
                    fflush(stdin);

                    if (question_choice == 0) { // Exit when user enters 0
                        printf("\nExiting the customer support section...........\n\n");
                        run = 0;
                    } else if (question_choice < 1 || question_choice > 10) { // Invalid choice
                        printf("\n\t!Wrong Input! \n\t! Try Again ! \n\n");
                        run = 1; 
                    }
                    else {
                        answerQuestion(question_choice); // Answer the question
                        run = 1;
                    }
                }
            break;
            case 7: // far8ali's recipe suggestion
                suggestRecipeFromFood();
            break;
        }

}

if (section == 0) { // Exit the program
    printf("\n3m Far8ali👳: Mafeesh Moshkelah ya Basha Tnwar Fi ei wa2t 🫡!\n\n");
    return 0;
} else { // Proceed to payment      
    float shipping_price = Shipping(); // get the value of the shipping method
    full_price += shipping_price; // Adding the shipping method price to the full price
    // Determining the shipping location
    bool LocationVerification = true;
    int choiceOfShipping;
        
        while (LocationVerification) { // Loop until a valid location is selected
                
            printf("\nSelect your shipping address from the list below:\n"); // Show the locations
            for (int i = 0; i < 10; i++) {
                printf("%d. %s\n", i + 1, locations[i]);
            }
        
                printf("Enter the number of your location: "); // Get the location number
                scanf("%d", &choiceOfShipping);
                fflush(stdin);
        
                if (choiceOfShipping < 1 || choiceOfShipping > 10) { // Invalid location number
                    printf("\n\t!Invalid location number.!\n");
                    LocationVerification = true;
                } else {
                    LocationVerification = false;
                }
            }
        
            //----------------------------------------------------------------------------------------------------------------------------------------------------------------
            
            check_coupon(); // check for the coupon
            int payment_m_print = Payment_Function(full_price - discount_value);


       

        //============================================================================================================================================//
                                                    //             ###     Printing Out the Receipt    ###             //
        //==========================================================================================================================================//
        
        printf("\n%s\n\n",farewells_3m_far8ali[farewell_number]); // Print out the farewell message
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
                printf("          || Raw Price:                  %.2f EGP ||\n", full_price);      
        } 
        else if(full_price > 10) {
                printf("          || Raw Price:                   %.2f EGP ||\n", full_price);
        }
        else{
                printf("          || Raw Price:                    %.2f EGP ||\n", full_price);
        }
        if(shipping_price > 10){
                printf("          || Shipping Price:              %.2f EGP ||\n", shipping_price); // Printing the shipping price
        } 
        else{
                printf("          || Shipping Price:               %.2f EGP ||\n", shipping_price); // Printing the shipping price
        }

        if (discount_value>100) {
            printf("          || Discount:                  -%.2f EGP ||\n", discount_value);  
        }                                                                                        
        else if(discount_value > 10) {
            printf("          || Discount:                   -%.2f EGP ||\n", discount_value);  //lines 660 to end are to adjust spacing
        }                                                                                        //for the love of god do not mess with them
        else {                                                                                   //         IAM WATCHINH YOU !!
            printf("          || Discount:                    -%.2f EGP ||\n", discount_value); //          ############
        }                                                                                        //   #######    0000    ########
                                                                                                 // /##        00 ** 00          ##\ 
                                                                                                 // \##        00 ** 00          ##/                            
        full_price -= discount_value;                                                            //   #######    0000     #######
                                                                                                 //          ############
        if(full_price >100){                                                            
                printf("          || Total Price:                %.2f EGP ||\n", full_price);
        } 
        else if (full_price > 10) {
                printf("          || Total Price:                 %.2f EGP ||\n", full_price);
        }
        else{
                printf("          || Total Price:                  %.2f EGP ||\n", full_price);
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
        printf("          ||----------------------------------------||\n");
        printf("          ||    The Shipping Address Is %s||\n",locations[choiceOfShipping - 1]);
        printf("          || The Package Will Be On Your Door In %.0f ||\n",deldevrytime[choiceOfShipping - 1]);
        printf("          ||   Mins After You Receive The Message   ||\n");
        printf("          ||        Thanks For Buying From Us!      ||\n");
        printf("          ||             See You Soon :)            ||\n"); 
        printf("          ||========================================||\n\n\n");
        }

         Rating();
         
    return 0;

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
