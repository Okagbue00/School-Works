/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * Student No: 11279373 */

#include <stdio.h>
#include <stdlib.h>
#include "encounter.h"
#include "randomindex.h"

/*
 * My Main Function for the encounter and statsdb module
 * argv: one dimensional array of string
 * argc: is the argument count
 */

int main(int argc, char *argv[]) {
    static const char *const ENCOUNTERS[] = {
        "Dark Cave Encounter",   "Lair Encounter",
        "Deep Forest Encounter", "Mountain Encounter",
        "Graveyard Encounter",   "Slum Encounter",
        "Pirate Bay Encounter"
    };

    struct stats_db *monsters, *players;
    struct encounter *encounter;
    const char *name;
    unsigned int crt;

    if (argc < 3) { //checks if the argument is less than 3
        fprintf(stderr, "Usage: %s MONSTERS PLAYERS\n", argv[0]);
        return EXIT_FAILURE; //it then returns an unsuccessful termination.
    }

    monsters = create_stats_db(argv[1]);
    if (monsters == USER_ADDR_NULL) //checks the monster is empty
        return EXIT_FAILURE; //an unsucccessful termination

    players = create_stats_db(argv[1]);
    if (players == USER_ADDR_NULL) {
        destroy_stats_db(monsters);
        return EXIT_FAILURE;
    }


    name = ENCOUNTERS[random_index(sizeof ENCOUNTERS / sizeof (const char *))];
    crt = (unsigned int)(average_challenge(players) * 2.0); //it generates a random encounter of monsters with a challenge


    encounter = generate_encounter(monsters, name, monsters->count * 5U, crt); //it create a creature database from monster and player
    if (encounter == NULL) { //checks if the database is empty
        destroy_stats_db(monsters); //then destroys the monster
        destroy_stats_db(players); //and destroys the players
        return EXIT_FAILURE;
    }

    print_encounter(encounter, monsters); //prints the number of the random encounter to my console


    // it destroys all my data structure that were created
    destroy_encounter(encounter);
    destroy_stats_db(monsters);
    destroy_stats_db(players);

    return EXIT_SUCCESS;
}
