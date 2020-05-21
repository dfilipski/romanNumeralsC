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
}

char* toRoman(int a)
{

}