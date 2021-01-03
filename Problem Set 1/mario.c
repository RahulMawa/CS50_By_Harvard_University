#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do{
        height = get_int("Choose a number between 1 and 8: ");
    }
    while(height < 1 || height > 8);
    
    // the main function for making the pyramid
    for(int n = 1; n <= height; n++){
        
        //space functions
        for(int counter1 = height - n; counter1 > 0; counter1 = counter1 - 1)
            {
                printf(" ");
            }

        //hash function on the left    
        for(int counter2 = n - 1; counter2 > 0; counter2 = counter2 - 1)
            {
                printf("#");
            }

        //the middle part
        printf("#  #");
        
        //hash function on the right    
        for(int counter3 = n - 1; counter3 > 0; counter3 = counter3 - 1)
            {
                printf("#");
            }
        
        //next line code
        printf("\n");
    }
}
