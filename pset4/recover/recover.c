#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

bool isHeader(uint8_t buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *input = argv[1];
    if (!input)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *inputPointer = fopen(input, "r");
    if (!inputPointer)
    {
        printf("Could not open that file: %s\n", input);
        return 1;
    }

    char filename[8];
    FILE *outputPointer = NULL;
    uint8_t buffer[BLOCKSIZE];
    int counter = 0;

    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputPointer) || feof(inputPointer) == 0)
    {
        if (isHeader(buffer))
        {
            if (outputPointer)
            {
                fclose(outputPointer);
            }
            sprintf(filename, "%03i.jpg", counter);
            outputPointer = fopen(filename, "w");
            counter += 1;
        }
        if (outputPointer)
        {
            fwrite(buffer, sizeof(buffer), 1, outputPointer);
        }

    }
    
    if (!inputPointer)
    {
        fclose(inputPointer);
    }
    
    if (!outputPointer)
    {
        fclose(outputPointer);
    }


    return 0;
}