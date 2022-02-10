#ifndef STATSDB_H
#define STATSDB_H

#include <stddef.h>

#define NAME_SIZE 100

struct creature {
    char name[NAME_SIZE];
    int initiative;
    unsigned int armour;
    unsigned int attack;
    unsigned int challenge;
};

struct stats_db  {
    size_t count;
    struct creature *creatures;
};

struct stats_db *create_stats_db(const char *filename);
void destroy_stats_db(struct stats_db *db);
const struct creature *get_creature(const struct stats_db *db,
                                    const char *name);
double average_challenge(const struct stats_db *db);
void print_creature_stats(const struct creature *creature);

#endif
