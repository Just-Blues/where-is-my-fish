#include <stdio.h>
#include <stdlib.h>//for functions of memory allocation, process control and conversions
#include <string.h>//for string functions (will be useful during handling with memory functions)
#include <stdbool.h>//for boolean functions
#include <conio.h>//for collecting key output (will be useful when describing controls with keyboard like space for placing penguins/moving and arrow keys for choosing tile)
#include <dirent.h>
#include <ctype.h>
#include "loadingMap.h"
#include "AIgameplay.h"
#include "returnReaction.h"
#include "check.h"

int main(int argc, char* argv[])
{
    char outFileName[maxFileNameLenght];
    char inFileName[maxFileNameLenght];
    int checker;
    int TNP;
    maping loadMap;
    plInfo gamers;
    FILE* pointer;

if(argc == 5 && !strcmp(argv[1],"phase=placement") )
{
        if(!strcmp(argv[2],"penguins=1"))
        {
            TNP = 1;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=2"))
        {
            TNP = 2;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=3"))
        {
            TNP = 3;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=4"))
        {
            TNP = 4;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=5"))
        {
            TNP = 5;
           //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=6"))
        {
            TNP = 6;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=7"))
        {
            TNP = 7;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=8"))
        {
            TNP = 8;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else if(!strcmp(argv[2],"penguins=9"))
        {
            TNP = 9;
            //printf("Number of penguins in this game for player: %d", TNP);Debug
        }
        else
        {
            printMessage(overMaxNumber);
            return overMaxNumber;
        }
        strcpy(outFileName, argv[4]);
        //printf("\nOutput file is: %s\n", outFileName);Debug
        strcpy(inFileName, argv[3]);
        //printf("\nInput file is: %s\n", inFileName);Debug

        checker = 1;
        pointer = createMapFile(inFileName);
        loadMap = loadedMap(pointer);
        gamers = playerInfoLoad(loadMap, maxNumberOfPenguins);
        AIgameplay(pointer, loadMap, gamers, TNP, outFileName, checker);

        free(loadMap.loader);
        if(isPlacement(TNP, gamers.ownTag, loadMap) == true)
        {
            return legalMove;
        }
        else if(isPlacement(TNP, gamers.ownTag, loadMap) == false)
        {
            return noMovesLeft;
        }
}
else if(argc == 4 && !strcmp(argv[1],"phase=movement")  )
{
        strcpy(outFileName, argv[3]);
        //printf("\nOutput file is: %s\n", outFileName);Debug
        strcpy(inFileName, argv[2]);
        //printf("\nInput file is: %s\n", inFileName);Debug

        checker = 2;
        pointer = createMapFile(inFileName);
        loadMap = loadedMap(pointer);
        gamers = playerInfoLoad(loadMap, maxNumberOfPenguins);
        TNP = countOwnPenguins(gamers.ownTag, loadMap);
        //printf("\nTNP: %d\n", TNP);Debug
        AIgameplay(pointer, loadMap, gamers, TNP, outFileName, checker);

        free(loadMap.loader);
        return legalMove;
}
else if(argc == 2 && !strcmp(argv[1],"id") )
{
        printMessage(easterEgg);
        return easterEgg;
}
else
{
        printMessage(wrongCmdParameters);
        return wrongCmdParameters;
}

free(loadMap.loader);
return 90;
}

