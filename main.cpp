#include<stdio.h>
#include<string.h>

//get length of string
int length(char x[])
{
    int i;

    for (i = 0; x[i] != '\0'; i++);

    return i;

}

//function to determine if the password has a lowercase letter, if so return 1
int hasLowercase(char x[])
{

    //initialize variable for loop and to check if string has lowercase letter
    int i;
    int has_lower = 0;

    for (i = 0; x[i] != '\0'; i++)
    {

        //if the character is a lowercase set has_lower to 1 and break
        if (x[i]>= 'a' && x[i] <= 'z') {

            has_lower = 1;
            break;

        }

    }

    //return 1 if string has lowercase else return 0
    return has_lower;

}

//function to determine if string has uppercase
int hasUppercase(char x[])
{

    //initialize variable for loop and to check if string has uppercase letter
    int i;
    int has_upper = 0;

    for (i = 0; x[i] != '\0'; i++)
    {

        //if the character is uppercase set has_lower to 1 and break
        if (x[i] >= 'A' && x[i] <= 'Z') {

            has_upper = 1;
            break;

        }

    }

    //return 1 if string has lowercase else return 0
    return has_upper;

}


//function to check if a string has a digit
int hasDigit(char c[])
{

    //initialize variable for loop and bool to check if string has digit
    int i;
    int has_digit = 0;

    for (i = 0; c[i] != '\0'; i++)
    {

        //if character is digit make has_digit 1 and break
        if ((c[i] >= '0') && (c[i] <= '9')) //FIND ALTERNATIVE
        {
            has_digit = 1;
            break;
        }
    }

    //return value of has_digit
    return has_digit;

}

//function to check if there are special characters in string
int hasSpecialChar(char x[])
{

    //initialize loop variable and bool to check if it has special chars
    int i;
    int has_special_char = 0;

    //variable to check if the current element is a character
    int char_checker = 0;

    //variable to check if the current element is a digit
    int digit_checker = 0;

    for (i = 0; x[i] != '\0'; i++)
    {

        //check if the element is a digit
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
        {

            //if the element is a letter return 1
            char_checker = 1;

        }

            //check if element is digit
        else if ((x[i] >= '0') && (x[i] <= '9'))
        {
            //if element is digit return 1
            digit_checker = 1;

        }

        //if both equal 0 that means element is not a char or digit hence it is a special character
        if (char_checker == 0 && digit_checker == 0)
        {
            has_special_char = 1;
            break;
        }

        //reset digit_checker and char_checker
        digit_checker = 0;
        char_checker = 0;

    }

    return has_special_char;

}


int evaluateStrength(char userpass[])
{

    //keep score of password
    int score = 0;

    //check if it has a lower case letter
    int has_lower;
    has_lower = hasLowercase(userpass);
    // printf("\nhas lower or no 0/1: %d", has_lower);

    //check if it has upper
    int has_upper;
    has_upper = hasUppercase(userpass);
    // printf("\nhas upper 0/1: %d", has_upper);

    //check if it has numerical digits
    int has_digit;
    has_digit = hasDigit(userpass);
    // printf("\nhas digit 0/1: %d", has_digit);

    //check if it has special characters
    int has_special_char;
    has_special_char = hasSpecialChar(userpass);
    // printf("\nhas special char 0/1: %d", has_special_char);

    //check length of password
    int has_long_pass = 0;
    if (length(userpass) > 12)
    {

        has_long_pass = 1;

    }
    // printf("\nhas long pass 0/1: %d", has_long_pass);

    score = has_lower + has_upper + has_digit + has_special_char + has_long_pass;

    // printf("\ntotal score: %d", score);

    return score;
}


int main()
{

    //create password strength score
    int score = 0;

    //create variable for user input
    char user_resp;

    //create variable to hold string status
    char score_status[10];


    do {

        //print interface
        printf("\nPassword Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of previously tested password\n");
        printf("3. Exit\n");

        //prompt user to select an option
        printf("Please select an option: ");
        scanf(" %c", &user_resp);
        // printf("\nuser_resp: %c", user_resp);

        if (user_resp == '1')
        {

            //store user password
            char user_pass[100];
            int user_pass_len;



            printf("Please enter the password: ");
            scanf("%s", &user_pass); //allows spaces

            //check length of user_pass
            user_pass_len = length(user_pass);

            if (user_pass_len < 8) {

                printf("Error: Password must be longer than 8 characters.\n");
                continue;
            }


            //create variable to hold score
            int score;

            //send password to get checked and retrieve score
            score = evaluateStrength(user_pass);

            //get score status
            if (score <= 2)
            {

                score_status[0] = 'W';
                score_status[1] = 'e';
                score_status[2] = 'a';
                score_status[3] = 'k';
                score_status[4] = '\0';
                score_status[5] = '\0';
                score_status[6] = '\0';
                score_status[7] = '\0';

            }
            else if (score == 3 || score == 4)
            {

                score_status[0] = 'M';
                score_status[1] = 'o';
                score_status[2] = 'd';
                score_status[3] = 'e';
                score_status[4] = 'r';
                score_status[5] = 'a';
                score_status[6] = 't';
                score_status[7] = 'e';


            }
            else if (score == 5)
            {

                score_status[0] = 'S';
                score_status[1] = 't';
                score_status[2] = 'r';
                score_status[3] = 'o';
                score_status[4] = 'n';
                score_status[5] = 'g';
                score_status[6] = '\0';
                score_status[7] = '\0';



            }

            //print password score
            printf("Password Strength: %s\n", score_status);

        }
        else if (user_resp == '2')
        {
            //if the user has not tested a password yet
            if (score_status[0] == '\0')
            {
                printf("Please test a password first.\n");
            }

                //if the user has already tested a password
            else
            {
                printf("Last tested password stregth: %s\n", score_status);
            }

        }
        else if (user_resp == '3')
        {
            printf("Exiting...\n");
        }
        else if (user_resp != '1' || user_resp != '2' || user_resp != '3')
        {
            printf("Error: Please enter a valid option.\n");
        }

    } while (user_resp != '3');


    return 0;
}
