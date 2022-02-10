/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <float.h> //is my floating point that contains a set of various dependent
#include <stdio.h> //STANDARD INPUT OUTPUT
#include <stdlib.h> //STANDARD LIBRARY

struct location { //grid location
    unsigned int row; //grid row assigned as row
    unsigned int column; //grid column assigned as column
};

struct distances { //distance
    unsigned int river; // shortest grid location to the river
    unsigned int factory; //shortest grid location to the factory
    unsigned int mine; //shortest grid location to the mine
};

struct geosurvey { //geosurvey structure
    unsigned int number; //unsigned int of the number
    unsigned int meter; //unsigned int of the meter

    struct distances **grid; //my structure distance allocated to the grid
};
/*
 * Function that takes the name of the geosurvey data file
 * Return: it returns a pointer to the newly allocated of the data structure of the geosurvey data file
 */

struct geosurvey *read_geosurvey(const char *filename) {
    struct geosurvey *gs = malloc(sizeof (struct geosurvey)); //for my memory allocation
    if (gs == USER_ADDR_NULL) { //checks if the geosurvey is empty
        perror("malloc"); //prints a descriptive error message
        return NULL; //it returns nothing
    }

    FILE *fs = fopen(filename, "r"); //to read my filename
    if (fs == USER_ADDR_NULL) { //checks if my file is empty
        perror("fopen"); //prints error descriptive mesage
        free(gs); //it deallocates the memory prviously allocated of the geosurvey
        return NULL; //it then returns null
    }

    if (fscanf(fs, " %u %u", &gs->number, &gs->meter) < 2) { //it reads the formatted input and checks if is less than 2
        fprintf(stderr, "%s: Invalid format\n", filename); //prints formatted output of the stream
        fclose(fs); //closes my file
        free(gs); //deallocates the memory previously allocated from my geosurvey
        return NULL; //it returns null
    }

    gs->grid = calloc(gs->number, sizeof (struct distances *)); //access a memory of the structure
    if (gs->grid == USER_ADDR_NULL) { //checks if the memory referenced is empty
        perror("calloc"); //then prints a descriptive error message
        fclose(fs); //closes the file
        free(gs); //deallocates the memory
        return NULL; //it returns null
    }

    for (unsigned int i = 0U; i < gs->number; ++i) {
        gs->grid[i] = calloc(gs->meter, sizeof (struct distances));
        if (gs->grid[i] == NULL) { //reference the pointer to grid and checks if is empty
            perror("calloc"); //prints a descriptive error message if it is
            fclose(fs); //closes the file
            for (unsigned int j = 0U; j < i; ++j)
                free(gs->grid[j]);
            free(gs->grid); //deallocates the geosurvey pointer previously referenced
            free(gs); //then deallocates the memory from the gs
            return NULL; //it returns null if empty
        }

        for (unsigned int j = 0U; j < gs->meter; ++j) {
            if (fscanf(fs, " %u %u %u",
                       &gs->grid[i][j].river, //checks if the reference pointer of the river, factory and mine is less than 3
                       &gs->grid[i][j].factory,
                       &gs->grid[i][j].mine) < 3) {
                fprintf(stderr, "%s: Invalid format\n", filename);
                fclose(fs); //it closes the file been opened previosuly
                for (unsigned int k = 0U; k <= i; ++k)
                    free(gs->grid[k]);
                free(gs->grid);
                free(gs); //deallocates the memory previously allocated
                return NULL;

            }
        }
    }

    fclose(fs); //close my file

    return gs;
}
/*
 * Function to calculate the optimal location for the mining location
 * returns: it returns the optimal location for the mining camp that minimizes the function
 */
double calculate_s(const struct distances *d) { //pointer to the distance
    return (double)d->river + (double)d->mine + 1.5 * (double)d->factory;
}
/*
 * Function determine the geosurvey data of the grid location that has optimal suitability measure and it communicate the grid location back to the calling function
 * gs: my constant structure of the geosurvey been referenced
 */
struct location *camp_location(const struct geosurvey *gs) {
    struct location *loc = malloc(sizeof (struct location)); //it allocates the memory and then returns a pointer
    if (loc != USER_ADDR_NULL) { //checks the location is empty
        double min_s = DBL_MAX; //is the maximum finite representative floating point number

        for (unsigned int i = 0U; i < gs->number; ++i) {
            for (unsigned int j = 0U; j < gs->number; ++j) {
                double s = calculate_s(&gs->grid[i][j]);

                if (s < min_s) { //checks the memory referenced is less than the max finite of the float
                    min_s = s; //then assigns the referenced pointer to be min_s
                    loc->row = i; //loc is referenced to the pointer of the row assign i
                    loc->column = j; //loc is referenced to the pointer of the column assign j
                }
            }
        }
    }

    return loc; //returns the location
}
/*
 * Function to deallocate the geosurvey memory
 * function does not return a value
 */
void deallocate_geosurvey(struct geosurvey *gs);

/* Function writes the visualization of the geosurvey
 * File; the file referenced
 * filename: my file name
 */
int print_survey_map(const char *filename, FILE *out) {
    int result = EXIT_FAILURE; //assign the result an unsuccessful termination that failed

    struct geosurvey *gs = read_geosurvey(filename);
    if (gs != NULL) { //checks if is empty
        struct location *loc = camp_location(gs);
        if (loc != NULL) { //checks if the loc is empty
            for (unsigned int i = 0U; i < gs->number; ++i) { //iterates over my loop
                for (unsigned int j = 0U; j < gs->meter; ++j) {
                    char c;

                    if (i == loc->row && j == loc->column) //checks if i and j is referenced to the row and column
                        c = '*'; //then c is the optimal location
                    else if (gs->grid[i][j].factory == 0U) //or then referenced the geosurvey to the grid of the factory will be equal to OU
                        c = 'F'; //the assign c is the factory
                    else if (gs->grid[i][j].mine == 0U)
                        c = 'M'; //then c is the mining location
                    else if (gs->grid[i][j].river == 0U) //checks if the river runs through the location
                        c = '='; //then c is the river if it runs through the grid location
                    else
                        c = '.'; //if it contains none of it

                    fputc(c, out);
                }

                fputc('\n', out);
            }

            free(loc);

            result = EXIT_SUCCESS; //it then is a successful termination, success exit
        }

        deallocate_geosurvey(gs); //it deallocates the geosurvey
    }

    return result; //returns my result
}
/*
 * Function that takes a pointer to a geosurvey data structure and deallocates it
 * gs: my geosurvey structure
 */
void deallocate_geosurvey(struct geosurvey *gs) {
    for (unsigned int i = 0U; i < gs->number; ++i)
        free(gs->grid[i]); //deallocates the referenced geosurvey assigned to grid

    free(gs->grid); //deallocates the memory already allocated
    free(gs); //deallocates the memory
}

/*
 * My main function
 */
int main(int argc, char *argv[]) {
    if (argc < 3) { //checks if is the argc is less than 3
        fprintf(stderr, "Usage: %s GEOSURVEY OUTMAP\n", argv[0]);
        return EXIT_FAILURE; //it returns an unsuccessful termination
    }

    FILE *out = fopen(argv[2], "w"); //it opens and writes the file
    if (out == NULL) {//checks if is empty
        perror("fopen"); //prints a descriptive error message
        return EXIT_FAILURE;
    }

    int result = print_survey_map(argv[1], out); //it prints the survey map

    return result;
}
