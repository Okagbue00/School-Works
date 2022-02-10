/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>
#include <string.h> //for strdup()
#include <stdlib.h> //for malloc()
#define STATION_CODE_LENGTH 4 //the identifier is replaced with int literal 4


typedef struct _station{
    char code [STATION_CODE_LENGTH];
    struct _station *next;

}   Station; //holds station three letter code as in code txt and points to next station


typedef struct _route{
    Station *first_station;
    unsigned int num_stations;
}   Route; //holds pointer to first station & total number of stations

//function that reads the codes file and return pointer dynamically
Route* read_stations(FILE *fpr){
    unsigned int assigned_stations = 0;
    Route *route = (Route*) malloc (sizeof(Route));
    Station *fprstation;
    fprstation = (Station*) malloc (sizeof(Station));
    fscanf(fpr, "%s", fprstation -> code);
    route -> first_station = fprstation;
    assigned_stations = assigned_stations + 1;

    while (!feof(fpr)){
        fprstation = (Station*)malloc(sizeof(Station));
        fscanf(fpr, "%s", fprstation -> code);
        fprstation -> next = route -> first_station;
        route -> first_station = fprstation;
        assigned_stations = assigned_stations + 1;
    }

    route -> num_stations = assigned_stations;
    free(fprstation);
    return route;







}

//function that takes a pointer to a route structure
void display(Route *pRoute){
    Station *fprStation = pRoute -> first_station;
    printf("%s\n", fprStation -> code);
    fprStation = fprStation -> next;
    for (int k = 1; k < pRoute -> num_stations; k++){
        printf("%s\n", fprStation -> code);
        fprStation = fprStation -> next;
    }
}

//function that search the code and searches if the code c matches the search and it displays the position number of station
void search(Route *pRoute, char c[STATION_CODE_LENGTH]){ //c -- is a three character station represented as a string
    Station *fprStation = pRoute -> first_station;
    int total = 0;


    for (int k = 0; k < pRoute -> num_stations; k++){

        if (strcmp(c, fprStation -> code) == 0){
            total = 1;

            printf("Code Position in the txt:- %d\n", k);
            printf("Next 2 Codes in the txt:- \n");

            if (fprStation -> next == USER_ADDR_NULL){
                printf("End of Line.\n");
                printf("End of Line. ");
            }

            else {
                printf("%s", fprStation->next->code);

                if (fprStation -> next -> next == USER_ADDR_NULL){
                    printf("End of line. \n");
                } else {
                    printf("%s", fprStation-> next -> next -> code);
                }
            }
        }

        else if (fprStation -> next == USER_ADDR_NULL & total == 0){
                    printf("Code not found.");
                }

                fprStation = fprStation -> next;
            }
        }

//Main program here

int main(){
    FILE *fpr = fopen("/Users/francis/CLionProjects/assignment5/code.txt", "r");
    if (fpr == USER_ADDR_NULL){
        printf("Empty file.");

    }

    Route *list0fCode = read_stations(fpr);
    display(list0fCode);
    char code[STATION_CODE_LENGTH];
    printf("Please enter the Code you want to search for in your file:- ");
    scanf("%s", code);

    search(list0fCode, code);

    free(list0fCode);
    fclose(fpr);
    return 0;
}





