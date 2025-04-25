// Menu concept
#include <stdio.h>
#include <string.h>

float total_price=0;
 void full_price(float price)
{
  total_price+=price;
}

int main ()
{
  int checker=1;
  char idk ;

  while(checker)
  {
    int section,run=1;

    printf("Choose the section you want: \n\n");
    while(run)
    {
      printf("For Food Enter \"1\" \nFor Drinks Enter \"2\" \nFor Clothes Enter \"3\" \nFor Medicine Enter \"4\" \n" );
      scanf("%d",&section);

      if(section>4)
        printf("\nworng input \"ya kosmok\" \nTry Again \n\n");
      else 
      run=0;
    }

    //Menu chooses
    switch (section)
    {
 //food section
      case 1:
      run=1;

      while(run)
      {
        int food_choice;
        char foods[9][20]={"Rice","Bread","Eggs","Milk","Cheese","Butter","Chicken Breast","Apples","Bananas"},continue_choice;
        float foods_prices[9]={1.20,0.99,2.50,1.30,2.75,2.10,6.50,1.80,1.10};

          printf("Foods:\n");
          printf("1. Rice (1kg) ............... $1.20\n");
          printf("2. Bread (loaf) ............. $0.99\n");
          printf("3. Eggs (dozen) ............. $2.50\n");
          printf("4. Milk (1L) ................ $1.30\n");
          printf("5. Cheese (200g) ............ $2.75\n");
          printf("6. Butter (250g) ............ $2.10\n");
          printf("7. Chicken Breast (1kg) ..... $6.50\n");
          printf("8. Apples (1kg) ............. $1.80\n");
          printf("9. Bananas (1kg) ........... $1.10\n");
//choosing
          printf("Enter the number of the food you want to buy: ");
          scanf("%d",&food_choice);
          if(food_choice>9)
            printf("worng input \nTry Again \n\n");
          else
            printf("You have selected %s\n",foods[food_choice-1]);

          full_price(foods_prices[food_choice-1]);

//continue full-loop / mini-loop
          printf("Do you want to continue? (y/n): ");
          scanf(" %c",&continue_choice);
          if(continue_choice=='y'||continue_choice=='Y')
          run=1; 
          else
          run=0;
          
          if(run==0)
          { 
            printf("Do you want to Buy from another section?(y/n)");
            scanf(" %c",&idk);
            if(idk=='y'||idk=='Y')
            checker=1; 
            else
            checker=0;
          }
          
      }
        break;

      case 2:

      run=1;
      while(run)
      {
        int drink_choice;
        char drinks[10][20]={"Water","Cola","Juice","Energy Drink","Coffee","Tea","Milkshake","Sparkling Water","Iced Tea","Yogurt Drink"},continue_choice;
        float drinks_prices[10]={0.80,1.50,2.00,2.25,3.99,2.20,1.75,1.10,1.30,1.60};
//Drinks
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
//choosing
        printf("Enter the number of the drink you want to buy: ");
        scanf("%d",&drink_choice);
        if(drink_choice>10)
          printf("worng input \nTry Again \n\n");
        else
          printf("You have selected %s\n",drinks[drink_choice-1]);

          full_price(drinks_prices[drink_choice-1]);
//continue full-loop / mini-loop
          printf("Do you want to continue? (y/n): ");
          scanf(" %c",&continue_choice);
          if(continue_choice=='y'||continue_choice=='Y')
          run=1; 
          else
          run=0;

          if(run==0)
          {
            printf("Do you want to Buy from another section?(y/n)");
            scanf(" %c",&idk);
            if(idk=='y'||idk=='Y')
            checker=1; 
            else
            checker=0;
          }
      }
      break;

      case 3:
      run=1;
      while(run)
      {
        int clothes_choice;
        char clothes[7][20]={"T-Shirt","Jeans","Jacket","Hoodie","Shorts","Sneakers","Cap"},continue_choice;
        float clothes_prices[7]={9.99,24.99,39.99,29.99,14.50,49.99,7.99};
//clothes
          printf("Clothes:\n");
          printf("1. T-Shirt ............ $9.99\n");
          printf("2. Jeans .............. $24.99\n");
          printf("3. Jacket ............. $39.99\n");
          printf("4. Hoodie ............. $29.99\n");
          printf("5. Shorts ............. $14.50\n");
          printf("6. Sneakers ........... $49.99\n");
          printf("7. Cap ................ $7.99\n");
//choosing
          printf("Enter the number of the clothes you want to buy: ");
          scanf("%d",&clothes_choice);
          if(clothes_choice>7)
            printf("worng input \nTry Again \n\n");
          else
            printf("You have selected %s\n",clothes[clothes_choice-1]); 

          full_price(clothes_prices[clothes_choice-1]);
//continue full-loop / mini-loop
          printf("Do you want to continue? (y/n): ");
          scanf(" %c",&continue_choice);
          if(continue_choice=='y'||continue_choice=='Y')
          run=1; 
          else
          run=0;

          if(run==0)
         {
            printf("Do you want to Buy from another section?(y/n)");
            scanf(" %c",&idk);
            if(idk=='y'||idk=='Y')
            checker=1; 
            else
            checker=0;
          }
      }
        break;

      case 4:
        
        run=1;
        while(run)
        {
//Medicine
          int Medicine_choice;
          char Medicine[7][30]={"Paracetamol","Ibuprofen","Cough Syrup","Antibiotic Pills","Vitamin C","Antacid Tablets","Allergy Relief"},continue_choice;
          float Medicine_prices [7]={1.50,2.00,3.25,5.99,2.75,1.80,3.50};
        printf("Medicines:\n");
        printf("1. Paracetamol ........ $10.50\n");
        printf("2. Ibuprofen .......... $7.00\n");
        printf("3. Cough Syrup ........ $19.25\n");
        printf("4. Antibiotic Pills ... $4.99\n");
        printf("5. Vitamin C .......... $11.75\n");
        printf("6. Antacid Tablets .... $10.80\n");
        printf("7. Allergy Relief ......$21.50\n");
//choosing
        printf("Enter the number of the Medicine you want to buy: ");
          scanf("%d",&Medicine_choice);
          if(Medicine_choice>7)
            printf("worng input \nTry Again \n\n");
          else
            printf("You have selected %s\n",Medicine[Medicine_choice-1]); 

          full_price(Medicine_prices[Medicine_choice-1]);
//continue full-loop / mini-loop
          printf("Do you want to continue? (y/n): ");
          scanf(" %c",&continue_choice);
          if(continue_choice=='y'||continue_choice=='Y')
          run=1; 
          else
          run=0;
          if(run==0)
          {
            printf("Do you want to Buy from another section?(y/n)");
            scanf(" %c",&idk);
            if(idk=='y'||idk=='Y')
            checker=1; 
            else
            checker=0;
          }
        }
        break;
      
    
    }
  }
      printf("Total price: $%.2f\n",total_price);
}