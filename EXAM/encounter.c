#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encounter.h"
#include "randomindex.h"


/*
 * The function generates a random encounter
 * db: is pointer of the creature database
 * name: descriptive name of the encounter
 * count: no of creatures selected for encounter
 * crt: name of each creature in the encounter
 */
struct encounter *generate_encounter(const struct stats_db *db,
                                     const char *name, unsigned int count,
                                     unsigned int crt) {
    
    struct encounter *en;

    en = malloc(sizeof (struct encounter));
    if (en == NULL) { //checks if the encounter is empty
        perror("malloc"); //prints a descriptive error of the allocated memory
        return NULL;
    }

    en->creatures = calloc(count, sizeof (char *)); //it points the encounter to the creature
    if (en->creatures == NULL) {
        perror("calloc"); //it prints a descriptive error of the allocated memory if need be.
        //calloc --- allocates the memory and then returns a pointer
        free(en); //deallocates the memory of the encounter
        return NULL;
    }

    strncpy(en->name, name, (size_t)(NAME_SIZE - 1)); //it copies character from the string
    en->name[NAME_SIZE - 1] = '\0'; //reference the encounter to the name of the encounter

    en->total = 0U;

    for (en->count = 0U; en->count < count; ++en->count) {
        const struct creature *c;

        if (en->total > crt) //checks if the allocated memory is greater than each of the creature
            break; //then breaks out of the if statement

        c = &db->creatures[random_index(db->count)]; //is the max no of creatures to add to the encounter

        en->creatures[en->count] = strdup(c->name);
        if (en->creatures[en->count] == NULL) { //checks if is empty
            perror("strdup");
            destroy_encounter(en); //destroy the previously allocated memory of the encounter.
            return NULL;
        }

        en->total += c->challenge; //is the challenge rating threshold
    }

    return en; //it returns the pointer of the encounter
}
/*
 * Function that prints the descriptive name of the encounter followed by a number list of monsters
 */
void print_encounter(const struct encounter *en, const struct stats_db *db) {
    unsigned int i;

    printf("%s:\n", en->name);

    for (i = 0U; i < en->count; ++i) {
        const struct creature *c = get_creature(db, en->creatures[i]);

        printf("Monster #%u: ", i); //prints the monster statistics
        if (c != NULL) //checks if is empty
            print_creature_stats(c);
        else //it then writes a line in the newline
            puts("Not in the database!"); //it then writes a line to the output
    }

    //it prints the total challenge rating of the encounter
    printf("Total challenge rating: %u\n", en->total);
}
/*
 * It is a function destroys the encounter
 */
void destroy_encounter(struct encounter *en) {
    size_t i;

    for (i = 0U; i < en->count; ++i)
        free(en->creatures[i]);

    free(en->creatures); //reference the encounter to the creature
    free(en); //deallocates the memory previously assigned to the encounter
}
