#ifndef AIGAMEPLAY_H_INCLUDED
#define AIGAMEPLAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "loadingMap.h"
#include "check.h"
#include "structers.h"

void graficMap(char** grafic, int dime[], plInfo show);

void saveState(save State, plInfo gamers, char outer[]);

save placingAI(maping tiles, int tag);

save AIgameplay(FILE* po, maping loaded, plInfo gamer, int TNP, char outName[], int checker);


#endif // AIGAMEPLAY_H_INCLUDED
