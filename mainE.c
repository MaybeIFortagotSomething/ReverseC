
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* check = "ouicestunfakeauth";

int main(int argc, char* argv[])
{

    int bool = 1;
    while(bool)
    {
        char* user = malloc(100);
        char* pwd = malloc(100);
        printf("===== Password Annexe =====");
        printf("User: ");
        scanf("%s", user);
        if(!user)
        {
            printf("An error has occured");
            return 1;
        }
        scanf("%s", pwd);
        if(!pwd)
        {
            printf("An error has occured");
            return 1;
        }

        if(strlen(pwd) == 36 && strcmp(check, pwd) == 0)
        {
            printf("An error hasn't occured");
            bool = 0;
        }
        else
        {
            printf("Password and user association does not work");
        }
        free(pwd);
        free(user);
    }

    return 0;
}