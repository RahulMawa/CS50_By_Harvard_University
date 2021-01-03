#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int a = 0;
    char encryptionCode[25];
    int ctr_err = 0;
    

    //check for only 1 input
    if(argc != 2)
    {
        printf("./substitution key");
        return 1;
    } 
        
            
    if (strlen(argv[1]) != 26) // must be 26 means 0 to 25 
    {
        printf("Encryption key should only be 26 characters long");
        return 1;
    }
        
    for(a = 0; a < 26; a++) // a must be 25 
    {
           encryptionCode[a] = argv[1][a];
        //check for all letters input are alphabet
        if ( (int)encryptionCode[a] < 65 || (int)encryptionCode[a] > 122 )
           {
             printf("All characters must be alphabets, no digits to be used");
                return 1;  
           }
           
           if( (int)encryptionCode[a] >90 && (int)encryptionCode[a] < 97 )
           {
             printf("All characters must be alphabets, no digits to be used");
                return 1;  
           }
           
           if(encryptionCode[a] >= 97)
           {
               encryptionCode[a] = (int)encryptionCode[a] - 32;
           }
           
           //printf("\n%c", encryptionCode[a]);
    }
        
        //check for string length
        //int length = strlen(encryptionCode);
        
        // Check for repeat alphabets 
    for (int i = 0; i < 26; i++) // for encryptioncode array 
    {
        for (int j = 0; j < 26; j++) // for argv array 
        {
            if (i != j)
            {
                if (encryptionCode[i] == argv[1][j])
                {
                    ctr_err ++;
                   
                }
            }
                
        }
    }
        
    if (ctr_err > 0)
    {
        printf("Do not repeat the alphabets");
        return 1;   
    }
         
    // ==================================================
 
    //main function
    char cipherText[900];
    string temp = get_string("plaintext: ");
    char plainText[900];
    int alpha = 0;
    int x = 0;
    int y = 0;
   
    for(x = 0; x <= 900; x++)  // Convert Plaintext to char array 
    {
        plainText[x] = temp[x];

        alpha = (int)plainText[x]; // ascii code

        //ensure all capitals are capitalised
        if(alpha >= 65 && alpha <= 90)
        {
            cipherText[x] = encryptionCode[alpha - 65];
        }
            
        //ensure all that are not capital, are kept the same way
        else if(alpha >= 97 && alpha <= 122)
        {
            cipherText[x] = encryptionCode[alpha - 97] + 32;  
        }
            
        //for other characters and numbers
        else if(alpha >= 32 && alpha <= 64){
            cipherText[x] = plainText[x];
        }
            
        //printf("%c  %c\n", plainText[x], cipherText[x]);
    }
        
    //final output
    printf("ciphertext: %s\n", cipherText);
        
}