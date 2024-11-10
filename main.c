#include <stdio.h>

void menu()
{
    printf("MENU\n");
    // Snacks menu
    printf("-----------------------------------\n");
    printf("Snacks:\n");
    printf("-----------------------------------\n");
    printf("1) Muffin                    Rs 65\n");
    printf("2) Red Velvet Pop            Rs 75\n");
    printf("3) Fruit Cake                Rs 100\n");
    printf("4) Pastry                    Rs 95\n");
    printf("5) Lemon Slice Cake          Rs 110\n\n");

    // Drinks menu
    printf("-----------------------------------\n");
    printf("Drinks:\n");
    printf("-----------------------------------\n");
    printf("1) Americano                 Rs 110\n");
    printf("2) Double Shot Americano     Rs 130\n");
    printf("3) Latte                     Rs 150\n");
    printf("4) Cappuccino                Rs 150\n");
    printf("5) Mocha                     Rs 165\n");
    printf("-----------------------------------\n\n");
}

double mySnack(int snack, int snackQuantity)
{
    switch (snack)
    {
    case 1:
        printf("You have ordered a Muffin.\n\n");
        return 65 * snackQuantity;
    case 2:
        printf("You have ordered a Red Velvet Pop.\n\n");
        return 75 * snackQuantity;
    case 3:
        printf("You have ordered a Fruit Cake.\n\n");
        return 100 * snackQuantity;
    case 4:
        printf("You have ordered a Pastry.\n\n");
        return 95 * snackQuantity;
    case 5:
        printf("You have ordered a Lemon Slice Cake.\n\n");
        return 110 * snackQuantity;
    default:
        printf("You didin't order any snacks.\n\n");
        return 0;
    }
}

double myDrink(int drink, int drinkQuantity)
{
    switch (drink)
    {
    case 1:
        printf("You have ordered an Americano.\n\n");
        return 110 * drinkQuantity;
    case 2:
        printf("You have ordered a Double Shot Americano.\n\n");
        return 130 * drinkQuantity;
    case 3:
        printf("You have ordered a Latte.\n\n");
        return 150 * drinkQuantity;
    case 4:
        printf("You have ordered a Cappuccino.\n\n");
        return 150 * drinkQuantity;
    case 5:
        printf("You have ordered a Mocha.\n\n");
        return 150 * drinkQuantity;
    default:
        printf("You didin't order any drinks.\n\n");
        return 0;
    }
}

int main()
{
    menu();
    int snack, drink;
    int snackQuantity = 0, drinkQuantity = 0;
    char more;
    double total = 0.00;

    //loop to take snack order from user
    do
    {
        printf("Please choose a snack (enter 1-5 to order, 0 if you don't want any snack): ");
        scanf("%d", &snack);
        printf("\n");

        if (snack > 0)
        {
            printf("How many would you like to order?\n");
            scanf("%d", &snackQuantity);
        }

        total = total + mySnack(snack, snackQuantity);
        getchar();

        if (snack > 0)
        {
            printf("Would you like to add more snacks? (y/n): ");
            scanf("%c", &more);
            printf("\n");
        }
    } while (more == 'y' || more == 'Y');

    //loop to take drink order from user
    do
    {
        printf("Please choose a drink (enter 1-5 to order, 0 if you don't want any drink): ");
        scanf("%d", &drink);
        printf("\n");

        if (drink > 0)
        {
            printf("How many would you like to order?\n");
            scanf("%d", &drinkQuantity);
        }

        total = total + myDrink(drink, drinkQuantity);
        getchar();

        if (drink > 0)
        {
            printf("Would you like to add more drinks? (y/n): ");
            scanf("%c", &more);
            printf("\n");
        }

    } while (more == 'y' || more == 'Y');

    double serviceCharge = 0.1 * total; //Add service charge in total
    double vat = 0.13 * total; //Add VAT tax in total
    total = total + serviceCharge + vat; //Total after adding service charge and VAT
    printf("Your total is Rs %.2lf adding service charge and VAT.\n\n", total);
    return 0;
}