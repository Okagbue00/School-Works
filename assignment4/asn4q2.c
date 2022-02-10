/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>

/*
 * Passing arrays to functions
 */

/*
 * Function that calculates the average life expectancy
 */
float lifeExpectancy(const float arr[], int scope){
    float avg = 0;
    for (int i = 0; i < scope; ++i) {
        avg+= arr[i]; //assignment statement; to calculate the value of the right operator to the left

    }

    avg = avg / scope; //divided by average by the size to find the average
    printf("Average of the life expectancy values: %1.4f\n", avg);

    return 0; //return value

}

/*
 * Calculates the smallest and highest life expectancy value
 */
float lowestToHighestLifeExpectancy(const float arr[], int scope){
    float small = arr[0]; //
    float large = arr[0];
    for (int i = 0; i < scope; ++i) { //iterate in the loop
        //to compare if the array is large or small
        if (arr[i] > large)
            large = arr[i];
        if (arr[i] < small)
            small = arr[i];
    }


        printf("Lowest life expectancy value is: %1.4f\n", small);
        printf("Highest life expectancy value is: %1.4f\n", large);


    return 0; //return value
}

/*
 * To sort the array in descending to ascending order
 */
void sorting(float arr[], int scope){
    float total = 0; //set total to be empty
    for (int i = 1, num = 1; i < scope; ++i) { //Insertion sort
        num = i;

        while (num > 0 && arr[num] > arr[num - 1]){ //used to compare in my while loop, using "and"
            total = arr[num];
            arr[num] = arr[num - 1];
            arr[num - 1] = total;
            num--; //decremental

        }

    }

    printf("The list of sorted life expectancy values: \n"); //print in my console
    for (int i = 0; i < scope; ++i) { //to print my life expectancy in a sorted form
        printf("%1.4f \n", arr[i]);


    }


}



/*
 * To call all my functions above in my main function
 */
int main(){
    int scope = 0; //set as empty
    float LifeEx[] = {75.981, 82.675, 68.745, 99.425, 88.442}; // float array given
    scope = sizeof(LifeEx) / sizeof(float); //is to divide the size of the life expectancy in float
    lifeExpectancy(LifeEx, scope);
    lowestToHighestLifeExpectancy(LifeEx, scope);
    sorting(LifeEx, scope);

}


