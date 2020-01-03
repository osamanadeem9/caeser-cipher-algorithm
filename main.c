/*
Name: Osama Nadeem      CMS#207376
Section: BSCS-7C

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100    //defines max size of strings

char result[SIZE];

void encrypt(char input[], int k)   //char input[] is the input string and k is the caeser shift
{
    int i;

    fgets (input, SIZE, stdin);     // inputs a string from the user


    for (i=0; i<strlen(input); i++) {
        if ((isalpha(input[i]))) {
            if (isupper(input[i])) {
                if (input[i]+k<=90) {
                    input[i]+=k;
                } else {
                    input[i]=input[i]+k-26;
                }
            }

    /*  --> Searches if the character is upper case alphabet.
        --> if character + caeser shift is within upper case alphabet range, perform
            caeser addition else wrap the text.
    */
            else if (islower(input[i])) {
                if (input[i]+k<=122) {
                    input[i]+=k;
                } else {
                    input[i]=input[i]+k-26;
                }
            }
        }

    /*  --> Searches if the character is lower case alphabet.
        --> if character + caeser shift is within lower case alphabet range, perform
            caeser addition else wrap the text.
    */
        else {
                input[i]=input[i];  //if the character is not an alphabet (like space or dot etc), don't change it
        }
     }
        printf("\nThe encrypted input is:             %s\n", input);
        strcpy(result,input);
}

void decrypt(char result[], int k)
{
    result[SIZE];

    int i;
    for (i=0; i<strlen(result); i++) {
        if ((isalpha(result[i]))) {
            if (isupper(result[i])) {
                if (result[i]-k<65) {
                    result[i]=result[i]-k+26;
                } else {
                    result[i]-=k;
                }
            }
            else if (islower(result[i])) {
                if (result[i]-k<97) {
                    result[i]=result[i]-k+26;
                } else {
                    result[i]-=k;
                }
            }
        }
        // adds caeser shift to alphabets and wraps the text if necessary
        else {
                result[i]=result[i];
        }
    }

    printf("\nThe decrypted cipher is: %s", result);

}
int main()
{
    char input[SIZE];
    int i,k;;
    char choice;
    printf("|===============================|\n");
    printf("|   Caeser Cipher Algorithm     |\n");
    printf("|===============================|\n");
    printf("\nEnter the line you want to encrypt: ");
    encrypt(input,15);  // applies caeser encryption with a caeser shift of 15

    printf("\nDo you know value of k? (Y or N) :  ");
    scanf("%c", &choice);   //Asks if user knows the caeser shift for decryption or not

    if (choice=='Y') {
        printf("\nEnter the value: ");
        scanf("%d", &k);
        decrypt(result, k);
    }
    // decrypts the message using caeser shift
    else if (choice=='N') {
        printf("\nDeciphering Caeser through Brute Force:\n\n");
        for (k=1; k<=25; k++) {
            printf("\nFor k= %d : ",k);
            i=1;
            decrypt(result, i);
        }
    // displays all possible caeser outputs using brute force
    }
    return 0;
}
