#include "returnReaction.h"

void printMessage(int result)
{
    switch(result)
        {
            case legalMove: printf("Legal Move\n"); break;
            case noMovesLeft: printf("The penguins can't move\n"); break;
            case inputFileCorrupted: printf("Check your input/output file\n"); break;
            case fatalInternalError: printf("Unknown error, program will crash soon\n"); break;
            case fileIsEmpty: printf("The file is empty. Please reload the game\n"); break;
            case boardLoadFailure: printf("The board can't be loaded\n"); break;
            case boardLoadSucces: printf("Board loaded successfully\n"); break;
            case loadingDataFailure: printf("There was problem when loading data from o/i file\n"); break;
            case loadingDataSuccess: printf("The data was successfully read and loaded\n"); break;
            case wrongCmdParameters: printf("Please input correct parameters\n"); break;
            case placementIllicit: printf("Illicit placement\n"); break;
            case placementLegal: printf("Legal placement\n"); break;
            case overMaxNumber: printf("Unfortunately I was programmed to operate using 0-9 penguins per player\n"); break;
            case wrongCounting: printf("The program encountered the problem during tiles counting\n"); break;
            case noMovesOrWrong: printf("There is no possible moves left or program made terrible mistake while counting\n"); break;
            case easterEgg: printf("Not for the want of trying - The BlueAI (Program created by Abel Niwinski)"); break;
        }
}

