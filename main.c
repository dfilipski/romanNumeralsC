#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toRoman(int a, char result[]);

int main(void)
{
    int a;
    char buf[1024];
	char result[1024];

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

    toRoman(a, result);
	printf("%s\n", result);
}

void toRoman(int a, char result[])
{
	const int value[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	const char *roman[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

	int numerals[13];

    /*Create array of numerals*/
	for (int i = 0; i < 13; ++i)
	{
		int index = 12 - i;
        numerals[index] = a / value[index];
		a -= value[index] * numerals[index];
	}

//    printf("Numerals Array: ");
//    for (int i = 0; i < 13; ++i)
//    {
//        printf("%d ", numerals[i]);
//    }
//    printf("\n");

    /*Construct result string*/
	for (int i = 0; i < 13; ++i)
	{
		int index = 12 - i;
		for (int j = 0; j < numerals[index]; ++j)
		{
			strcat(result, roman[index]);
		}
	}
}