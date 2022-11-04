#ifndef LOADING_H
#define LOADING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structers.h"

int* loadDimensions(FILE *fp, char maps[]);

char** openFile(FILE *fp, char maps[], int dime[]);//reads and loads all the values from file and loads pretty map , int dime[]

maping loadedMap(FILE *kl);

FILE* createMapFile(char inName[]);

plInfo playerInfoLoad(maping save, int nP);


#endif // LOADING_H
