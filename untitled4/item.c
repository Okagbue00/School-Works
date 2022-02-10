/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * MIDTERM QUESTION 1 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "randomindex.h"
#include "items.h"


/*
 * Function that creates a random loot list and takes a parameter as n to be number of items
 * it returns loots of the base pointer of the array
 */
Loot *create_random_loot_list(const int n){
    int base_case; //base type name
    int suffice_case; //suffice name
    int prefix_case; //prefix name
    const int total = 0; //my total of the random list

    size_t size_prefix; //size of object in prefix
    size_t size_suffixes; //size of object in suffixes
    size_t size_base; //size of unsigned integral base

    char *itemName; //my name of the loot
    Loot *loots; //pointer of the loot

    //dynamically allocate memory
    loots = malloc((n + 1 ) * sizeof(Loot ));
    if (loots == USER_ADDR_NULL){ //checks if the loot is empty
        printf("Error in the file"); // print out on the console Empty file
    }


    for (int z = 0; z < n; z++) {//iterate over the loop
        prefix_case = random_index(NUM_PREFIXES); //prefix case to get the random index
        suffice_case = random_index(NUM_SUFFIXES); //suffice case to get the random index of the suffixes
        base_case = random_index(NUM_BASE_TYPES); //base case to get the random index of the number base types

        loots[z].base_type_name = base_types[base_case]; //for the base case
        loots[z].rarity = random_index(NUM_RARITIES); //for num Rarities

        size_prefix = strlen(prefixes[prefix_case]); //checks the length of the string for the prefixes
        size_suffixes = strlen(suffixes[suffice_case]); //checks the length of the string for the suffice
        size_base = strlen(base_types[base_case]); //checks the length of the string for the base types

        itemName = malloc(size_prefix + 1 + size_suffixes + 1 + size_base + 1); //dynamically allocates the memory and increase the size by 1
        if (itemName == USER_ADDR_NULL) //checks if the name of the loot is empty
            printf("Error in the file"); //prints on the console Error in the file

        strncpy(itemName, prefixes[prefix_case], size_prefix); //it copies the prefix to by item name to the size of the prefix.


        loots[z].name=itemName;//displays the itemname of the loot; assigns the name of the item

    }

    return loots;


}


int print_loot(Loot *Loots){
    /*
     * Function to print a description of the item in my console
     * Takes parameter to be a pointer in Loots
     */
    printf("%s\n", Loots -> name); //prints out on the console; the Loots name
    printf("%s\n",rarity[Loots -> rarity]); //prints out on the console; the rarity name of the loots
    printf("%s\n", Loots -> base_type_name); //prints out on the console; the base type name of the loot item
}

int destroy_random_loot(Loot *_loot){
    /*
     * Function to destroy the random loot
     *  Takes a parameter _loot to be a pointer to first element of dynamically array loot structure
     */
    int arr_loot = 0; //stores my array loot

    for (arr_loot = 0; _loot[arr_loot].base_type_name != USER_ADDR_NULL; arr_loot++)//iterates through the loop
        //it checks if the name of the base type is Null; increment the array loot
        /*free(_loot -> base_type_name);*/
        free(_loot[arr_loot].name); //frees dynamically allocated memory of the name
    free(_loot); //it frees all the dynamically allocated memory of the array[deallocate]
}