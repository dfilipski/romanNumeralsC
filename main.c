#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toRoman(int a);

int main(void)
{
    int a;
    char buf[1024];

    do
    {
        printf("Enter a integer: ");
        if (!fgets(buf, 1024, stdin))
        {
            printf("Reading failed");
            return 1;
        }
        a = atoi(buf);
    } while (a == 0);
    toRoman(a);
}

char* toRoman(int a)
{
    /*[I,V,X ,L ,C  ,D  ,M]
     *[1,5,10,50,100,500,1000]*/
    int numerals[7];
    char result[1024] = "";
    const char symbols[7] ="IVXLCDM";

    /*Create array of numerals*/
    numerals[6] = a/1000;
    a -= 1000*numerals[6];

    numerals[5] = a/500;
    a -= 500*numerals[5];

    numerals[4] = a/100;
    a -= 100*numerals[4];

    numerals[3] = a/50;
    a -= 50*numerals[3];

    numerals[2] = a/10;
    a -= 10*numerals[2];

    numerals[1] = a/5;
    a -= 5*numerals[1];

    numerals[0] = a;
    a -= numerals[0];

    printf("Numerals Array: ");
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", numerals[i]);
    }
    printf("\n");

    /*Construct result string*/

    for (int j = 0; j < numerals[6]; ++j)
    {

        strcat(result, "M");
    }

    for (int j = 0; j < numerals[5]; ++j)
    {

        strcat(result, "D");
    }

    for (int j = 0; j < numerals[4]; ++j)
    {

        strcat(result, "C");
    }

    for (int j = 0; j < numerals[3]; ++j)
    {

        strcat(result, "L");
    }

    for (int j = 0; j < numerals[2]; ++j)
    {

        strcat(result, "X");
    }

    for (int j = 0; j < numerals[1]; ++j)
    {

        strcat(result, "V");
    }

    for (int j = 0; j < numerals[0]; ++j)
    {

        strcat(result, "I");
    }



//    if (numerals[4] >= 4)
//    {
//        strcat(result, "CD");
//        numerals[4] = 0;
//        --numerals[5];
//    }
//
//    for (int k = 0; k < numerals[5]; ++k)
//    {
//        strcat(result, "D");
//    }

    printf("%s", result);
}