#include "loadingMap.h"
#include "returnReaction.h"

FILE * createMapFile(char inFile[]) //I have to find a way to stop this function from calling itself more than once!!!
{
    FILE *fptr1, *fptr2;
    char c;

    fptr1 = fopen(inFile, "r");
    if (fptr1 == NULL)
    {
        printMessage(inputFileCorrupted);
        exit(inputFileCorrupted);
    }

    fptr2 = fopen("secret.txt", "w");
    if (fptr2 == NULL)
    {
        printMessage(inputFileCorrupted);
        exit(inputFileCorrupted);
    }

    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    FILE* gh = fopen("secret.txt", "r+");
    if(gh == NULL)
    {
        printMessage(fileIsEmpty);
        exit(fileIsEmpty);
    }

    fclose(fptr1);
    fclose(fptr2);
return gh;
}

int* loadDimensions(FILE *fp, char maps[])
{
    static int dimensions[2];
    fscanf(fp, "%d %d[^\n]", &dimensions[0], &dimensions[1]);
return dimensions;
}

//I need to implement fool-proof functions, like when file is badly constructed (empty spaces at the end of the lines)
char** openFile(FILE *fp, char maps[], int dime[])
{
    int j;
    int a, b;
    int height, width;
    height = dime[0];
    width = (dime[1] * 2);
    char loading[height][width];
    char** wholeMap;
    wholeMap = malloc(sizeof(char *) * height);

    for(j = 0; j < height; j++)
    {
       wholeMap[j] = malloc(sizeof(char *) * width);
    }

    fseek(fp, 7, SEEK_SET); // MUST MAKE IT UNIVERSAL!!!
        for(a = 0; a < height; a++)
        {
            for(b = 0; b < width; b += 2)
            {
                fscanf(fp, "%c%c ", &loading[a][b], &loading[a][b+1]);
                wholeMap[a][b] = loading[a][b];
                wholeMap[a][b+1] = loading[a][b+1];
            }
        }

 return wholeMap;
}

//function for reading player names, player points and recognizing own custom ID
plInfo playerInfoLoad(maping save, int nP) // only for the first time load
{
    plInfo players;
    int count = 0;
    FILE* pko;
    int help, nob;
    char aux[2];
    pko = fopen("secret.txt","r");
    if(pko == NULL)
    {
        printMessage(inputFileCorrupted);
        exit(inputFileCorrupted);
    }
    char line[128];
    char tag[nP];
    int points[nP];
    char playerID[nP][32];
    int i = 0, l = 0;
    const char* name = "BlueAI";
    int h;
    int nln = save.dime[0];
    while(fgets(line, sizeof(line), pko) != NULL)
    {
    if(count + 1 == nln)
        {
                players.nop = 0;
                //printf("\nI'm first player\n"); DEBUG
                players.ownTag = players.nop + 1;

                help = players.ownTag;
                sprintf(aux, "%d", help);
                players.playerTag[players.ownTag - 1] = aux[0];
                players.ownPoints = 0;
                strcpy(*(players.playerName + (players.ownTag - 1) ), name);
                l = 12;
                break;
        }
    else if (count == nln)
    {
        while(!feof(pko))
        {
            fscanf(pko, "%s %c %d", *(playerID + i), &tag[i], &points[i]);
            i++;
            if(feof(pko))
            {
                nob = i - 1;
                players.nop = nob;
                for(h = 0; h < players.nop; h++)
                    {
                        players.playerTag[h] = tag[h];
                        players.playerPoints[h] = points[h];
                        strcpy(*(players.playerName + h), *(playerID + h));

                        if(!strcmp(*(players.playerName + h), "BlueAI") )
                        {
                            players.ownTag = players.playerTag[h];
                            players.ownPoints = players.playerPoints[h];
                            l = 42;
                        }
                        else if((h + 1) == players.nop && l == 0)
                        {
                            players.ownTag = players.nop;
                            help = players.ownTag;
                            sprintf(aux, "%d", help);
                            players.playerTag[players.ownTag - 1] = aux[0];
                            players.ownPoints = 0;
                            strcpy(*(players.playerName + (players.ownTag - 1) ), name);
                        }
                    }
                } break;
            }
        }
        else
        {
            count++;
        }
    }
    players.check = l;
    fclose(pko);

return players;
}

maping loadedMap(FILE* kl)
{
    maping loaded;
    char maps[2048];
    int i;
    int* dimi;
    dimi = loadDimensions(kl, maps);
    int aux[2];

    for(i = 0; i < 2; i ++)
    {
        loaded.dime[i] = *(dimi+i);
        aux[i] = loaded.dime[i];
    }

    openFile(kl, maps, aux);
    loaded.loader = openFile(kl, maps, aux);

    fclose(kl);

return loaded;
}
