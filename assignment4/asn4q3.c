/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure type for my smoothie with members for storing info
struct smoothies{
    char smoothieName[50];
    int numberSold;
    float sellingPrice, totalSales;

};

// function for bestSeller smoothie

struct smoothies bestSeller(char inputData[] ){
    struct smoothies total;
    float sales = 20;

    char smoothie_Name[500]; //column title
    float priceSold;
    float total_Sale;
    int Number_Sold;

    //reads my file
    FILE *fpr = fopen("/Users/francis/CLionProjects/assignment4/sales.txt", "r");
    if (fpr == NULL){
        printf("NO FILE: EMPTY.");}

    {
    //it reads line from the file and skips the next file
        char *file = NULL;

        size_t num = 0;
        getline(&file, &num, fpr); //gets my line in the file

        while (getline(&file, &num, fpr) != -1){ //iterates to check if the file is not minus one in the line

            //token line takes an initial string & const character delimiter
            //it takes two arguments
            char *tl = strtok(file, " "); //token --- strtok--- takes two arguments
            int x = 1; //reads words on the line
            while (tl) {
                if (x == 1) { // first word is name of smoothie
                    strcpy(smoothie_Name, tl);
                }
                    //2nd word is numbers of smoothie sold
                else if (x == 2) {
                    Number_Sold = atoi(tl);

                }
                    //3rd word is price charged foe one smoothie
                else if (x == 3) {
                    priceSold = atof(tl); //used to convert string to a floating value
                }
                    //4th word is total sales of flavours(smoothies)
                else if (x == 4) {
                    total_Sale = atof(tl); //won't return error ASCII to float

                    //checks whether the smoothie has the highest sales and stores it in the struct


                    if (total_Sale > sales) {
                        sales = total_Sale;
                        strcpy(total.smoothieName, smoothie_Name);
                        total.sellingPrice = priceSold;
                        total.numberSold = Number_Sold;
                        total.totalSales = total_Sale;
                    }

                    //sets the next line to 0
                    x = 0;

                }

                tl = strtok(NULL, " ");
                x++;

            }
        }


    }

    //closes the file
    fclose(fpr);
    return total;

}

//My main method to run my function above

int main(){

    char inputData[700] = "sales.txt";
    struct smoothies best_sellerSmoothie = bestSeller(inputData);

    printf("Name:- %s\n", best_sellerSmoothie.smoothieName);
    printf("Price:- %.6f\n", best_sellerSmoothie.sellingPrice);
    printf("Number sold:- %d\n", best_sellerSmoothie.numberSold);
    printf("Total sales:- %.6f\n", best_sellerSmoothie.totalSales);

}





