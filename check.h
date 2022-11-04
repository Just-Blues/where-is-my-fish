#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "loadingMap.h"
#include "AIgameplay.h"
#include "structers.h"
#include "returnReaction.h"

save movingAI(penguins* mover, maping board, int TNP);

int sumOfArray(int arr[], int siz);

bool isPlacement(int TNP, int ownTag, maping boardInfo);

int countOwnPenguins(int ownTag, maping maper);

penguins* ownPenguins(maping boardInfo, int TNP, int onwTag);


#endif // CHECK_H_INCLUDED
