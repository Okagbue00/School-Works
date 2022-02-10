/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include "stdio.h"

int main(){
    double diameter; //diameter
    double pie = 3.14; // pie
    double radius;
    double Area;
    double circumference;

    printf("Enter the diameter: ");
    scanf("%lf", &diameter);

    //radius to be diameter divided by 2
    //area: pie * radius * radius
    //circumference: 2 * pie * radius
    radius = diameter / 2;
    Area = pie * radius * radius;
    circumference = 2 * pie * radius;

    printf("The radius of the circle is %lf\n", radius);
    printf("The area of the circle is %.3g\n", Area);
    printf("The circumference is %.4g\n", circumference);


}
