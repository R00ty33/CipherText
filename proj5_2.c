/*******************************/
/****** Nicholas Rudolph  ******/
/****** Shift Array       ******/
/****** March 28, 202     ******/
/******                   ******/
/******                   ******/
/******                   ******/
/*******************************/


/****    D I R E C T I V E S    *****/
#include <stdio.h> /* printf */
#include <stdlib.h> /* for generating random number */
#include <string.h>
#include <time.h>  /* seeding */
#include <stdbool.h> /* boolean */
#include <ctype.h> /* isalpha(), toupper(), tolower() */


/****    M A C R O S    *****/
#define STR_LEN 80

/****    F U N C T I O N S    *****/
/* reads user input */
void read_line(char str[]) /* read_line */
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < STR_LEN + 1)
            str[i++] = ch; 
    str[i] = '\0';
}

/* shifts each char in msg by defined amount */
void encrypt(char str[], int n) { /* encrypt */
    char ch;

    for (int i=0; str[i] != '\0' ; i++) {
        ch = str[i];
        
        if (islower(ch))  {
            ch = ch + n;

            if (ch > 'z') {
                ch = ch -'z' + 'a' - 1;
            }

            str[i] = ch;
        }
        else if (isupper(ch)) {
            ch = ch + n;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            str[i] = ch;
        }
    }
}
/****    D R I V E R   *****/
int main() {
    /****    D A T A - F I E L D S    *****/
    char str[STR_LEN + 1];

    printf("\nEnter message to be encrypted: ");
    read_line(str);
    
    int shiftAmount;
    printf("\nEnter shift amount (1-25): ");
    scanf("%d", &shiftAmount);

    encrypt(str, shiftAmount);
    printf("\nEncrypted message: %s", str);

} // end of main