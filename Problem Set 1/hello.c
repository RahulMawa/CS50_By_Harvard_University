#include <stdio.h>
#include <cs50.h>

//main function
int main(void)
{
    //code to input user name
    string userName = get_string("What's your name?\n");
    
    //code to output "hello, name"
    printf("hello, %s\n", userName);
}
