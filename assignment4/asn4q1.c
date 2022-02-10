/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>
/*
 * Reading the food text and accessing the arrays in the text file
 */
void readFoodText(float price2020[], float price2018[]){
    FILE *fpr;
    fpr = fopen("/Users/francis/CLionProjects/assignment4/food.txt", "r"); // reading my food text file
    if (fpr == NULL){
        printf("NO FILE: EMPTY.");

    }
    int repeat = 0;
    char data1[900];
    char data2[900]; //containing column titles less than 1000 characters
    fscanf(fpr, "%[^'\n']s", data1);
    while (fscanf(fpr, "%s %s %f %f", data2, data2,  &price2020[repeat], &price2018[repeat]) != EOF){ // EOF --> End of file, to check if that is the end of the file
        repeat++;
    }
    fclose(fpr);
}

int main() {
    float totalCost2020 = 0;
    float totalCost2018 = 0;
    float foodPrice2020[10]; //assuming there are exactly 10 food items in my data file in 2020
    float foodPrice2018[10]; //assuming there are exactly 10 food items in my data file in 2018
    float diff;
    readFoodText(foodPrice2018, foodPrice2020);
    for (int item = 0; item < 10; item++) {
        totalCost2018 += foodPrice2018[item];
        totalCost2020 += foodPrice2020[item];


        diff = totalCost2018 - totalCost2020; //difference price in 2018 and 2020
        printf("Total cost in 2018:- %1.2f\n", totalCost2018);
        printf("Total cost in 2020:- %1.2f\n", totalCost2020);
        printf("Difference in the total costs:- %1.2f\n", diff);

    }

    void fruitDiaryFile(char fruitText[], char dairyText[]);
    char fruit[50];
    char dairy[50];
    char total[20];
    int fileLine;
    printf("yyyyy:-" "%d\n", fruit);


}