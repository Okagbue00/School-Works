/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */


#include "stdio.h"

int main() {
    FILE *fp; //fp is to the file pointer

    /**
     * a: it allows to append the value at the end of the file
     * if not created, will write the file
     */
    fp = fopen("/Users/francis/CLionProjects/untitled/treasure_journal.txt", "a");
    if (fp == NULL){ //checks if the file is empty
        printf("No FILE");
        return 0;
    }

    int treasureInt; // to collect treasure int entered by user
    printf("Enter an integer value for the treasure: ");
    scanf("%d", &treasureInt);
    while (treasureInt > 0) {

        // reads input from user and move the file pointer

        fprintf(fp, "%d\n", treasureInt); //fprintf--- contains the text to be written to the file
        scanf("%d", &treasureInt);
    }


    // closes file
    fclose(fp);
    return 0;
}
