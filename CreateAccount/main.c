#include <stdio.h>
#include <stdlib.h>


#define SPACE 32 // ASCII CODE
#define BCKSP 8 // ASCII CODE
#define TAB 9 // ASCII CODE
#define ENTER 13 // ASCII CODE

// Create username and password and the account is save in Accounts.txt .
void create_account(){

    char create_username[16], create_password[16];
    int iterator = 0;
    char chars;

    FILE *fptr ;
    fptr = fopen("Accounts.txt", "a+");
    if (fptr == NULL)
    {
    printf("Error opening file!\n");
    exit(1);
    }


    printf(" \n Write your username (maximum 16 characters):");
    scanf("%s", &create_username);


    fprintf(fptr,"Username: %s\n", create_username);

    printf(" \n Write your password (maximum 16 characters):");
    while(1){
        chars = getch();
        if(chars == ENTER){
            create_password[iterator] = '\0';
            break;
        }
        else if(chars == BCKSP){
           if(iterator>0){
            iterator--;
            printf("\b \b");
           }

        }
        else if(chars == TAB ){
            continue;
        }
        else if(chars == SPACE){
           continue;
        }
        else{
            create_password[iterator] = chars;
            iterator++;
            printf("*");
        }
    }


    fprintf(fptr,"Password: %s\n\n", create_password);

    printf(" \n\n Your account has been created successfully!\n\n");


    fclose(fptr);

    return 0 ;


}


int main()
{

    int option ;

    do
        {

        printf("   ### Menu ###\n");
        printf("\n- Create account -\n\n");
        printf(" - End program - \n\n");
        printf("    Your option is: ");
        scanf("%d", &option);






        switch(option)
            {

            case 1:

                create_account();
                break;

            case 2:

                printf("\nExit..");
                exit(0);
                break;
            default:
                printf("#######################\n");
                printf("\n    INVALID OPTION!\n\n");
                printf("#######################");
                break;


            }

        }
    while(option != 2 );



    return 0;
}
