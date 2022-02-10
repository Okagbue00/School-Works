#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "statsdb.h"

struct encounter {
    char name[NAME_SIZE];
    unsigned int total;
    size_t count;
    char **creatures;
};

struct encounter *generate_encounter(const struct stats_db *db,
                                     const char *name, unsigned int count,
                                     unsigned int crt);
void print_encounter(const struct encounter *en, const struct stats_db *db);
void destroy_encounter(struct encounter *en);

#endif
