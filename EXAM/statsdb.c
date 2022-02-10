#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statsdb.h"

#define BUFFER_SIZE 128
/*
 * Function that creates the stats database
 * filename: my file name
 */
struct stats_db *create_stats_db(const char *filename) {
    FILE *fs;
    struct stats_db *db;
    size_t i;
    char buf[BUFFER_SIZE];
    
    db = malloc(sizeof (struct stats_db)); //allocates the memory
    if (db == NULL) { //checks if the database is empty
        perror("malloc"); //prints a descriptive error message of the allocated memory
        return NULL; //then return it empty
    }

    fs = fopen(filename, "r"); //to open and read the file
    if (fs == NULL) { //checksa if my file is empty
        perror("fopen"); //prints an error that file wasn't opened well
        free(db); //dealllocates the memory previously allocated
        return NULL;
    }

    if (fgets(buf, BUFFER_SIZE, fs) == NULL) {
        perror("fgets");
        fclose(fs);
        free(db);
        return NULL;
    }

    db->count = (size_t)strtoul(buf, NULL, 10);
    if (db->count == 0U) {
        fprintf(stderr, "%s: Invalid format\n", filename);
        fclose(fs);
        free(db);
        return NULL;
    }

    db->creatures = calloc(db->count, sizeof (struct creature));
    if (db->creatures == NULL) {
        perror("calloc");
        fclose(fs);
        free(db);
        return NULL;
    }

    for (i = 0U; i < db->count; ++i) {
        struct creature *c = &db->creatures[i];

        if (fgets(buf, BUFFER_SIZE, fs) == 0) {
            perror("fgets");
            fclose(fs);
            destroy_stats_db(db);
            return NULL;
        }

        if (sscanf(buf, "%99s %d %u %u %u",
                   c->name, &c->initiative,
                   &c->armour, &c->attack, &c->challenge) < 5) {
            fprintf(stderr, "%s: Invalid format\n", filename);
            fclose(fs);
            destroy_stats_db(db); //destroy the database
            return NULL;
        }
    }

    fclose(fs);
    return db;
}
/*
 * Function to destroy the stats database
 * database: is the pointer of the database referenced
 */
void destroy_stats_db(struct stats_db *db) {
    if (db != NULL) { //checks if the database is empty
        free(db->creatures); //assign  the database to the creature
        free(db); //then deallocates the memory
    }
}
/*
 * It is the pointer of the creature to enable to get the creature database and the creature name as parameter
 * and returns the creature statistics for the named creature
 */
const struct creature *get_creature(const struct stats_db *db,
                                    const char *name) {
    size_t i;

    for (i = 0U; i < db->count; ++i) {
        const struct creature *c = &db->creatures[i];

        if (strcmp(c->name, name) == 0)
            return c; //it returns the creature statistics
    }

    return NULL;
}

/*
 * Function that calculates the average challenge
 * db: pointer to the database
 * It returns the average challenge rating of the creature in the database
 */
double average_challenge(const struct stats_db *db) {
    size_t i;
    unsigned int total = 0U;

    for (i = 0U; i < db->count; ++i) {
        total += (unsigned int)db->creatures[i].challenge;
    }

    return (double)total / (double)db->count;
}

/*
 * Function that prints the creature statistics
 * creature: pointer to the creature
 */
void print_creature_stats(const struct creature *creature) {

    //prints out to the console the statistics of the creature in a neat and timely manner
    printf("%s, Init: %d, Armor: %u, Attack: %u, Challenge Rating: %u\n",
           creature->name, creature->initiative,
           creature->armour, creature->attack, creature->challenge);
}
