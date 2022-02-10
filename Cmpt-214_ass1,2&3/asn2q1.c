/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include "stdio.h"

int treasure_hunting(int OpenSesame){ //function required
    int number = 0;
    while (OpenSesame != 0){ //checks whether is not to 0
        OpenSesame/=10;
        ++number; //incremental
    }
    return number; //returns number
}


int main() {
    int OpenSesame, reverseNumber = 0, number;

    do {
        printf("The number entered by the user: "); //print statement
        scanf("%d", &OpenSesame); //input console
    }
        while (treasure_hunting(OpenSesame) != 6); //user enters only six digits
    while (OpenSesame != 0){
        number = OpenSesame % 10; //remainder 10
        reverseNumber = reverseNumber * 10 + number;
        OpenSesame /= 10;
    }




    printf("The Secret code to open the door: %d", reverseNumber);
    return 0;









}