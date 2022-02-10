/* OKAGBUE ONYEKA FRANCIS
 * CMPT 214
 * MIDTERM QUESTION 1 */



#include "items.h"


/*
 * This function contains my main program
 * And is going to execute the program
 */
int main(){

    static int N = 5; //it creates an array of five random loot elements

    int arr = 0;
    Loot *_loots;

    _loots = create_random_loot_list(N);
    for (int arr = 0; arr < N; arr++) {
        print_loot(&_loots[arr]);

    destroy_random_loot(_loots);


        return 1;

    }
}


