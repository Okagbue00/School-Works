/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//function to read file for fruit & dairy txt
void fruitDiaryFile(char fruitText[], char dairyText[]) {
    char fruit[50];
    char dairy[50];
    char total[20];
    int fileLine;

    //opening fruit & dairy text file

    FILE *fprFruitText;
    fprFruitText = fopen("/Users/francis/CLionProjects/assignment5/fruits.txt", "r");
    if (fprFruitText == NULL){
     printf("Empty fruit  text file");}



    FILE *fprDairyText;
    fprDairyText = fopen("/Users/francis/CLionProjects/assignment5/dairy.txt", "r");
    if (fprDairyText == NULL) {
        printf("Empty dairy  text file");}

    //writing fruit & dairy text file
        FILE *fprWriteFruitText;
        fprWriteFruitText = fopen("/Users/francis/CLionProjects/assignment5/fruit-revised.txt", "w");
        if (fprWriteFruitText == NULL){
            printf("Empty fruit not written");
        }



            FILE *fprWriteDairyText;
            fprWriteDairyText = fopen("/Users/francis/CLionProjects/assignment5/dairy-revised.txt", "w");
            if (fprWriteDairyText == NULL){
                printf("Empty dairy not written");
         }

            //check if file is empty

            if (fprFruitText == NULL || fprDairyText == NULL) {
                printf("Error file is empty/not read");
                EXIT_SUCCESS;
            } else if (fprWriteFruitText == NULL || fprWriteDairyText == NULL) {
                printf("Error the file is not written yet");
                EXIT_SUCCESS;

            } else {
                fscanf(fprFruitText, "%[^\n]", fruit); //read fruit and writes in fruit revised file
                fprintf(fprWriteFruitText, "%s\n", fruit);

                fscanf(fprDairyText, "%[^\n]", dairy); //read dairy and writes into diary revised file
                fprintf(fprWriteDairyText, "%s\n", dairy);

                //iterates to check when it reaches end of the file
                while (!feof(fprFruitText) ||
                       !feof(fprDairyText)) { //feof --- determine whether the end of the file has been reached
                    //reads the days of the week of fruit & diary
                    fscanf(fprFruitText, "%s", total);
                    fprintf(fprWriteFruitText, "%s", total);

                    fscanf(fprDairyText, "%s", total);
                    fprintf(fprWriteDairyText, "%s", total);

                    //reads from fifth column
                    for (int k = 0; k < 4; k++) {
                        fscanf(fprFruitText, "%d", &fileLine); //reads fruit file line to the revised text file
                        fprintf(fprWriteFruitText, "%d", fileLine);

                        fscanf(fprDairyText, "%d", &fileLine); //reads dairy file line to the revised text file
                        fprintf(fprWriteDairyText, "%d", fileLine);
                    }


                    //interchanging last columns
                    fscanf(fprFruitText, "%d", &fileLine);
                    fprintf(fprWriteDairyText, "%d", fileLine);


                    fscanf(fprDairyText, "%d", &fileLine);
                    fprintf(fprFruitText, "%d", fileLine);
                }

                //file closing

                fclose(fprFruitText);
                fclose(fprWriteDairyText);
                fclose(fprWriteFruitText);
                fclose(fprDairyText);


            }
        }




int main(int argc, char *argv[]) {
    if (argc == 1) //checks whether the command line is empty
        printf("No Argument!! Error!");
    else if (argc == 2) //checks command line argument
        printf("HAS ONLY ONE FILE INPUTTED ERROR!");
    else fruitDiaryFile(argv[1], argv[2]); //calls the count line file
    return 0;

    
}
