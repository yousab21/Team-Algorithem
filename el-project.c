//yousab nabil nasrala || section (39)
//Yahia Khaled Elsafty || Section (39)
//Mohamed Hamada AboSeda || Secton (39)
//Yassin Khaled Elnaggar || section (39)

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
//struct of item
typedef struct item
{
    char name[30];
    float price;
}data;

double full_price=0;

//overnight shipping asking
int overnight_checker()
{

    for (;;)
    {
        char a;
        printf("overnight shiping?[y/n] ");
        scanf("%c",&a);
        if (a == 'y' || a == 'Y')
        {
            full_price+=5;
            return 1;
        }
        else if (a == 'n'|| a == 'N')
        {
            full_price+=0;
            return 0;
        }
        else 
       printf("wrong input! Please try again\n");
    }
}

int main()
{

    //some var
    int items_number, temp ,counter=1 ,i= 0,n=0,total_shipping=0;
    bool run=1,overnight_checker1;
    data item[items_number];

    printf("Welcome to our small shop\n\n");
    while(run){
        //num of items 
        if (counter == 1)
        {
            printf ("Please enter the number of items you want ot buy (minimum 2): ");
            scanf("%d",&items_number);
            fflush(stdin);

            if (items_number<2)
            {
                 printf("wrong input");
                return 1;
            }
        }
        else
        {
            printf ("if you have mistakenly clicked YES you can write 0\n");
            printf ("Please enter the number of items you want ot buy: ");


            scanf("%d",&items_number);
            fflush(stdin);
            items_number+=temp;
        }



        printf("THANKS! Now enter the specefies of your items\n");

// data of the items
        for (; i< items_number;)
        {
            printf("Please enter the name of your %d item: \n",counter);
            fgets(item[i].name , 30 , stdin);

            printf("Enter the price of your %d item: \n",counter);
            scanf("%f", &item[i].price);

            fflush(stdin);
            full_price += item[i].price;

            i++;
            counter++;
        }

        //shipping
        for(; n<items_number;n++ )
        {
            if(item[n].price<10)
            {
                full_price += 2;
                total_shipping +=2;
            }
            else
            {
                full_price +=3;
                total_shipping +=3;
            }
        }



        //show full price before Receipt 
        printf("your full price now is :%0.2lf\n",full_price);
        printf("your full price now is :%d\n",total_shipping);

        Sleep(3000);
        //cheking if you want to continue 
        //if the user Entered yes by mistake he could easily write 0 in new shopping quistions
        int continue1 = MessageBox(NULL,"Do you want to continue?","continue shopping",MB_YESNO |MB_ICONQUESTION|MB_DEFBUTTON1|MB_TASKMODAL);
        if (continue1 ==6)
        {
            temp = items_number;
            run = 1;
        }
        else
            {
            run =0;
            }
    }

    //overnight 
    overnight_checker1=overnight_checker();

    //Receipt
    printf("\t\tYour Receipt:\n");

    for(int m=0;m<items_number;)
    {
        printf("%s\tPrice +%0.2f$\n",item[m].name,item[m].price);
        m++;
    }

    printf("Total shipping \n\t price +%d$\n",total_shipping);
    if(overnight_checker1==1)
        printf("Overnight delivering\n\tprice +5.00$\n");

    printf("TOTAL PRICE =\t %0.2lf\n",full_price);
    printf("Thanks For Buying From US!!\nSEE YOU SOON");
}
