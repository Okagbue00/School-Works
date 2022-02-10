/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include "stdio.h"

int main() {

    int integer;
    float realNumber;
    int realInteger;

    //printing story to the console

    printf("Enter an integer: ");
    scanf("%d", &integer);

    printf("Enter a real number: ");
    scanf("%f", &realNumber);

    printf("Enter an integer: ");
    scanf("%d", &realInteger);


    printf("A young hobbit was walking in the woods about %d " "miles from home.", integer);
    printf("\n");
    printf("After collecting %.5g baskets of tasty mushrooms they were beset", realNumber);
    printf("\n");
    printf("upon by %d restless spirits.", realInteger);
    printf(" ");
    printf("The hobbit took a bite of a mushroom");
    printf("\n");
    printf("and offered some to the spirits. The spirits, their hunger sated,");
    printf("\n");
    printf("left the hobbit in peace.");
}

