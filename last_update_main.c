#include <stdio.h>

void decimalToBase(int num, char *arr, int base);

int main()
{

    int inputNumber = 0;

    int inputBase = 0;

    char numberSystem[100];

    do
    {

        printf("\n");

        printf("  -- Enter number system (2) (8) (16) : ");

        scanf("%d", &inputBase);

        printf("  -- Please enter number: ");

        scanf("%d", &inputNumber);

        printf("\n");

        printf("  -- Your number %d in (%d) system is : ", inputNumber, inputBase);

        decimalToBase(inputNumber, numberSystem, inputBase);

        printf("\n\n");

    } while (inputNumber > 0);
}

void decimalToBase(int num, char *arr, int base)
{

    if ((base != 2 && base != 8 && base != 16) || base < 0)
    {
        base = 2;
    }

    int counter = 0;

    if (num == 0)
    {

        while (counter < 4)
        {
            arr[counter] = '0';
            counter++;
        }

        arr[counter] = '\0';

        printf("%s", arr);

        return;
    }

    int rem = 0;

    while (num > 0)
    {

        rem = num % base;

        if (rem == 10)
        {
            arr[counter] = 'A';
        }
        else if (rem == 11)
        {
            arr[counter] = 'B';
        }
        else if (rem == 12)
        {
            arr[counter] = 'C';
        }
        else if (rem == 13)
        {
            arr[counter] = 'D';
        }
        else if (rem == 14)
        {
            arr[counter] = 'E';
        }
        else if (rem == 15)
        {
            arr[counter] = 'F';
        }
        else
        {
            arr[counter] = rem + '0';
        }

        num = num / base;

        counter++;
    }

    if (base == 2)
    {
        arr[counter] = 'b';
        arr[++counter] = '0';
    }
    else if (base == 8)
    {
        arr[counter] = 'o';
        arr[++counter] = '0';
    }
    else if (base == 16)
    {
        arr[counter] = 'x';
        arr[++counter] = '0';
    }

    arr[++counter] = '\0';

    int length = counter - 1;

    for (int i = length; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
}
