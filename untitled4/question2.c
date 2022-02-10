/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * MIDTERM QUESTION 1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * travel log function to store the contents of my input file
 * input_file stores the contents of the array
 */
typedef struct travel_log {
    void *input_file[100]; //contains information about different source city in the txt file
    char *city_name[300]; //stores a list of each city name that can be the source city

} travel_log;

/*
 * Function that reads the cities of the travel-log file
 * and takes a parameter of the file pointer been freshly opened
 */
travel_log *read_cities(FILE *file) {
    const unsigned int cities=0;
    const unsigned int cities_file =0;
    char travelCity[500][500];
    char cityName[100][200];

    /*fscanf(file, "%d %d", &cities_file, &cities); */
    travel_log* _data_structure = (travel_log*) malloc(sizeof(travel_log) * cities);
    if (_data_structure == USER_ADDR_NULL) {
        printf("dynamic allocation is empty!");


        /*or (int k = 0; k < cities_file; k++) {
            fscanf(file, "%s %s", travelCity, cityName);
            for (int y = 0; y < cities; y++) { */


            }
    return _data_structure;


}




int display_cities(struct travel_log *_data_structure){
    /*for (int k = 0; _data_structure[k].city_name != USER_ADDR_NULL; k++) {
        printf("%s\n", _data_structure[k].city_name);
        printf("%s\n", _data_structure[k].input_file); */





    char city;
    char source_city;
    \

    /*for (int k = 0; (struct travel_log *) k < _data_structure; k++) {


    }*/
}



int destroy_data_structure(travel_log *_data_structure){
    free(_data_structure -> input_file);
    free(_data_structure); //deallocates the file of the travel log txt
}




// main function for  running the above function
int main(int argc, char *argv[]){ //the command argument
    if (argc == USER_ADDR_NULL) //checks if the command argument is empty
        printf("Enter two arguments");
    else if (argc == 1){ //checks whether the command line is empty
        printf("Error: enter two arguments");}
    else if( argc < 3 ) {
        printf("Enter two Arguments");}
    else if (argc == 2){ //checks command line argument
        printf("Correct Argument");}

    FILE *fpr; //file pointer
    fpr = fopen("/Users/francis/CLionProjects/untitled4/travel-log.txt", "r"); //read travel-log txt file
    if (fpr == USER_ADDR_NULL){ //checks if my file is empty
        printf("Empty travel-log txt file! Empty"); //prints out on the console is empty
        }

    fclose(fpr);

    /*read_cities();
    display_cities();
    destroy_data_structure(); */
    return 0;



}
