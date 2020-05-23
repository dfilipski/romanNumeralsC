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
    /*[I,IV,V,IX,X,XL,L,XC,C,CD,D,CM]
     *[1,4,5,9,10,40,50,90,100,400,500,900,100]*/
    int numerals[13];

    char result[1024] = "";

    /*Create array of numerals*/
    numerals[12] = a/1000;
    a -= 1000*numerals[12];

    numerals[11] = a/900;
    a -= 900*numerals[11];

    numerals[10] = a/500;
    a -= 500*numerals[10];

    numerals[9] = a/400;
    a -= 400*numerals[9];

    numerals[8] = a/100;
    a -= 100*numerals[8];

    numerals[7] = a/90;
    a -= 90*numerals[7];

    numerals[6] = a/50;
    a -= 50*numerals[6];

    numerals[5] = a/40;
    a -= 40*numerals[5];

    numerals[4] = a/10;
    a -= 10*numerals[4];

    numerals[3] = a/9;
    a -= 9*numerals[3];

    numerals[2] = a/5;
    a -= 5*numerals[2];

    numerals[1] = a/4;
    a -= 4*numerals[1];

    numerals[0] = a;
    a -= numerals[0];

//    printf("Numerals Array: ");
//    for (int i = 0; i < 13; ++i)
//    {
//        printf("%d ", numerals[i]);
//    }
//    printf("\n");

    /*Construct result string*/

    for (int j = 0; j < numerals[12]; ++j)
    {

        strcat(result, "M");
    }

    for (int j = 0; j < numerals[11]; ++j)
    {

        strcat(result, "CM");
    }

    for (int j = 0; j < numerals[10]; ++j)
    {

        strcat(result, "D");
    }

    for (int j = 0; j < numerals[9]; ++j)
    {

        strcat(result, "CD");
    }

    for (int j = 0; j < numerals[8]; ++j)
    {

        strcat(result, "C");
    }

    for (int j = 0; j < numerals[7]; ++j)
    {

        strcat(result, "XC");
    }

    for (int j = 0; j < numerals[6]; ++j)
    {

        strcat(result, "L");
    }

    for (int j = 0; j < numerals[5]; ++j)
    {
        strcat(result,"XL");
    }

    for (int j = 0; j < numerals[4]; ++j)
    {
        strcat(result,"X");
    }

    for (int j = 0; j < numerals[3]; ++j)
    {
        strcat(result,"IX");
    }

    for (int j = 0; j < numerals[2]; ++j)
    {
        strcat(result,"V");
    }

    for (int j = 0; j < numerals[1]; ++j)
    {
        strcat(result,"IV");
    }

    for (int j = 0; j < numerals[0]; ++j)
    {
        strcat(result,"I");
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