#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("give me a start size ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("give me an end size ");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    int count = 0;
    while (start < end)
    {
        start = start + start / 3 - start / 4;
        count++;
    }
    // TODO: Print number of years
    printf("Years: %i", count);
}