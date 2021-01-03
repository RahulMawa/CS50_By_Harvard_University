#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    FILE *inputCard = fopen(argv[1], "r");
    FILE *output = NULL;

    //check for correct argv[1]
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
   
    //check for empty card
    if (inputCard == NULL)
    {
        printf("Card is empty");
        return 1;
    }

    //intialising variables
    int count = 0;
    char fileName[8];
    BYTE buffer[512];
    
    while (true)
    {
        //reading the content of the files
        size_t read = fread(buffer, sizeof(BYTE), 512, inputCard);
        
        //finding the end of the file in card
        if (read == 0 && feof(inputCard))
        {
            break;
        }
        
        //finding if the file read is jpeg
        bool jpeg = (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0);
        
        //closing the ouput file, if it is finalised
        if ((jpeg == true) && (output != NULL))
        {
            fclose(output);
            count++;
        }
        
        //output the name of the file
        if (jpeg == true)
        {
            sprintf(fileName, "%03i.jpg", count);
            output = fopen(fileName, "w");
        }
        
        //writing the data from the buffer to final jpeg output file
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), read, output);
        }
    }
        
    //closing all files
    fclose(inputCard);
    fclose(output);
    return 0;
}