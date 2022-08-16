#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* dynamic_char(int n); 
char* intToRoman(int num);


int main(void)
{
    int n;
    char* ipsum = 0;

    while (true)
    {
        printf("Chose a number to convert in roman: ");
        scanf("%d", &n);

        if (n > 3999 || n < 0)
        {
            printf("Try again\n");
            continue;
        }
        ipsum = intToRoman(n);
        break;
    }
    printf("%s", ipsum);
    return 0;
}

char* dynamic_char(int n)
{
    char* p = malloc(n * sizeof(char));
    memset(p, 0, n * sizeof(char));

    if(!p)
    {
        fprintf(stderr,"Error\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

char * intToRoman(int num)
{
    char* result = (char*)dynamic_char(10);
    int i = 0;

    while (num)
    {
        if (num >= 1000)
        {
            result[i++] = 'M';
            num -= 1000;
        }
        else if (num >= 900)
        {
            result[i++] = 'C';
            result[i++] = 'M';
            num -= 900;
        }
        else if (num >= 500)
        {
            result[i++] = 'D';
            num -= 500;
        }
        else if (num >= 400)
        {
            result[i++] = 'C';
            result[i++] = 'D';
            num -= 400;
        }
        else if (num >= 100)
        {
            result[i++] = 'C';
            num -= 100;
        }
        else if (num >= 90)
        {
            result[i++] = 'X';
            result[i++] = 'C';
            num -= 90;
        }
        else if (num >= 50)
        {
            result[i++] = 'L';
            num -= 50;
        }
        else if (num >= 40)
        {
            result[i++] = 'X';
            result[i++] = 'L';
            num -= 40;
        }
        else if (num >= 10)
        {
            result[i++] = 'X';
            num -= 10;
        }
        else if (num >= 9)
        {
            result[i++] = 'I';
            result[i++] = 'X';
            num -= 9;
        }
        else if (num >= 5)
        {
            result[i++] = 'V';
            num -= 5;
        }
        else if (num >= 4)
        {
            result[i++] = 'I';
            result[i++] = 'V';
            num -= 4;
        }
        else if (num >= 1)
        {
            result[i++] = 'I';
            num--;
        }
    }
    return result;
}