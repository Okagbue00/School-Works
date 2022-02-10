/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include<stdio.h>
#include<stdlib.h>

int main(){
    //it creates a file pointer in my main function
    FILE* fpr; //fpr --- file pointer
    fpr = fopen("/Users/francis/CLionProjects/Workouts/treasure_journal.txt","r");
    if (fpr == NULL){  //checks if the file is empty
        printf("NO FILE");
        return 0;
    }

    //it reads the integer
    int number;
    fscanf(fpr,"%d",&number); //reads formatted input from a file

    //it stores arrays on count
    //for maximum and minimum

    int arr; //reps an integer
    fscanf(fpr,"%d",&arr);

    //store int in arr
    int maximum = arr; //stores max
    int minimum = arr; // stores min
    double average = arr;

    //sums up
    for(int num = 0; num < (number - 1); num++){


        //minimum
        if(minimum > arr){ //checks if minimum is greater than arr
            minimum = arr;
        }


        fscanf(fpr,"%d",&arr);
        average += arr;

        //maximum
        if(maximum < arr){ //checks if maximum is less than arr
            maximum = arr;
        }
    }


    // printing on the console
    printf("Smallest number of the shipping case: %d\n",minimum);
    printf("Largest number of the shipping case: %d\n",maximum);
    printf("Average number of the shipment size: %lf\n",(average/number));

    // close file after been read
    fclose(fpr);

    return 0;
}

