#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height ");
    }
    while (height > 8 || height < 1);

    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < height - 1 - i; h++)     //mirrors left pyramid
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)    //creates the left pyramid
        {
            printf("#");
        }

        printf("  "); //creates 2 spaces between pyramids

        for (int j = 0; j <= i; j++)  //creates right pyramid
        {
            printf("#");
        }

        printf("\n");
    }
}