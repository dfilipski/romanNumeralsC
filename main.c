#include <stdio.h>
#include <stdlib.h>

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
}