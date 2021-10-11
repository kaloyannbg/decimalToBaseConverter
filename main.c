#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Упражнение 7.16.*  Напишете функция void itob(int n, char s[], int b), която
преобразува цяло число n в низ s базиран на основа b.
Например itob( n, s[], 16) представя числото n като шеснадесетично число в
стринга s[].
*/

void itob(int number, char *arr, int base);

void printMenu();

int main()
{

    int inputNumber = 0, inputBase = 0;

    //int num = 1555;

    char str[50];

    //int base = 16;

    do {

    printMenu();

    scanf("%d", &inputNumber);

    if(inputNumber == 0) {
        printf("  -- Bye Bye --  \n");
        break;
    }

    printf("  --  Please, enter your base (number system): ");

    scanf("%d", &inputBase);

    printf("  -- Your number %d(%d number system) is: ", inputNumber, inputBase);

    itob(inputNumber, str, inputBase);

    printf("\n\n");

    for(int i = 0; i < strlen(str); i++ ) {
        str[i] = ' ';
    }

    } while(inputNumber != 0);

    //itob(num, str, base);

    return 0;
}

void printMenu() {

    printf("  --  DECIMAL TO BASE CONVERTER --   \n\n");
    printf("  -- Please enter number \'0\' if you want to quit!\n");
    printf("  -- Please, enter your number: ");

}

void itob(int number, char *arr, int base)
{

    int remainder = 0;

    int counter = 0;

    while (number > 0)
    {
        remainder = number % base;

        if (remainder == 15)
        {
            arr[counter] = 'F';
        }
        else if (remainder == 14)
        {
            arr[counter] = 'E';
        }
        else if (remainder == 13)
        {
            arr[counter] = 'D';
        }
        else if (remainder == 12)
        {
            arr[counter] = 'C';
        }
        else if (remainder == 11)
        {
            arr[counter] = 'B';
        }
        else if (remainder == 10)
        {
            arr[counter] = 'A';
        }
        else
        {
            arr[counter] = remainder + '0';
        }

        number = number / base;

        counter++;
    }

    arr[counter] = '\0';

    int arrLength = strlen(arr)-1;

    for(int i = arrLength; i >= 0; i-- ){
        printf("%c", arr[i]);
    }
}
