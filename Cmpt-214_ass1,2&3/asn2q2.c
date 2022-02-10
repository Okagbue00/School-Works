/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include "stdio.h"

int pond_triangle(double x, double z, double y){ // my function
    if (y + z > x & x + z > y & x + y > z){ //checking the side of the pond triangle
        return 1; //return true


    } else{
        return 0; //if not going return false
    }



}

int main(){
    double first_side; //my first side
    double second_side; //second side
    double third_side; //third side

    printf("Enter 3 numbers to indicate whether the triangle is valid or not: ");
    scanf("%lf %lf %lf", &first_side, &second_side, &third_side);

    if (pond_triangle(first_side, second_side, third_side) == 1){ //called my function to check if the sides are true
        printf("Valid Triangle Pond side "); //will then return valid



    } else{
        printf("Not valid Triangle Pond side "); //else will be false, not valid
    }

}


