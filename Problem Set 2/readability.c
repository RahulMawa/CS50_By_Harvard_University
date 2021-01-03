#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string para = get_string("The text: ");

    //main algorithm
    int numWords = 1;
    int numLetters = 0;
    int numSentences = 0;

    for(int i = 0; i < strlen(para); i++){
        //count of letters
        if((int) para[i] >= 65 && (int) para[i] <= 122){
            numLetters++;
            }

        if((int) para[i] >= 91 && (int) para[i] <= 96){
            numLetters = numLetters - 1;
            }

        //count of sentences
        if((int) para[i] == 33 || (int) para[i] == 46 || (int) para[i] == 63){
            numSentences++;
            }

        //count of words
        if( ((int) para[i] == 34 || (int) para[i] == 40 || (int) para[i] == 32) && (int) para[i+1] >= 65 && (int) para[i+1] <= 122){
            numWords++;
            }
        }

    //calculating the index
    float L = (numLetters * 100) / numWords;
    float S = (numSentences * 100) / numWords;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //printing out result
    if(index <= 1){
        printf("Before Grade 1\n");
    }

    else if(index > 16){
        printf("Grade 16+\n");
    }

    else{
        printf("Grade %.0f\n", index);
        //printf("%i%i%i", numLetters, numWords, numSentences);
    }
}