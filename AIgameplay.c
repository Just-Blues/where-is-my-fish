#include "AIgameplay.h"
#include <time.h>

//same for interactive mode but I need a function that updates map in console
void graficMap(char** grafic, int dime[], plInfo show)//must receive info about players so it can show their names, tags and points
{
    //printf("\nPlease work\n"); Debug
    int a,b,i;
    //printf("True dimensions: %d %d\n", dime[0], dime[1]); Debug

    for(i = 0; i < dime[1]; i++)
    {
        printf("\t%d", i);
    }
    printf("\n");
    for(a = 0; a < dime[0]; a++)
    {
        printf("%d\t", a);
        for(b = 0; b < dime[1]*2; b += 2)
        {
            if('0' == grafic[a][b])
            {
                if(grafic[a][b+1] == '0')
                {
                    printf("~~      ");
                }
                else if(grafic[a][b+1] == '1')
                {
                    printf("P1      ");
                }
                else if(grafic[a][b+1] == '2')
                {
                    printf("P2      ");
                }
                else if(grafic[a][b+1] == '3')
                {
                    printf("P3      ");
                }
                else if(grafic[a][b+1] == '4')
                {
                    printf("P4      ");
                }
                else if(grafic[a][b+1] == '5')
                {
                    printf("P5      ");
                }
                else if(grafic[a][b+1] == '6')
                {
                    printf("P6      ");
                }
                else if(grafic[a][b+1] == '7')
                {
                    printf("P7      ");
                }
                else if(grafic[a][b+1] == '8')
                {
                    printf("P8      ");
                }
                else if(grafic[a][b+1] == '9')
                {
                    printf("P9      ");
                }

            }
            else if ('1' == grafic[a][b])
            {
                printf("[1]     ");
            }
            else if ('2' == grafic[a][b])
            {
                printf("[2]     ");
            }
            else if ('3' == grafic[a][b])
            {
                printf("[3]     ");
            }
        }
        printf("\n\n");
    }
    printf("\n\n");
}

void saveState(save State, plInfo gamers, char outer[])
{
    FILE* saver;
    int a,b,i = 0;
    //int j; Debug
    saver = fopen(outer, "wb+");
    fprintf(saver, "%d %d\n", State.dimensions[0], State.dimensions[1]);
    int sum = gamers.ownPoints + State.points;
    gamers.playerPoints[gamers.ownTag - 49] = sum;
    //printf("\nOVERALL BLUE'S POINTS: State: %d Loaded Points: %d Sum: %d", State.points, gamers.ownPoints, sum); Debug
    //printf("\n%d\n", gamers.ownTag - 49); Debug

    for(a = 0; a < State.dimensions[0]; a++)
    {
        for(b = 0; b < State.dimensions[1]*2; b+=2)
        {
            fprintf(saver,"%c%c ", State.updated[a][b], State.updated[a][b+1]);
        }

        fprintf(saver, "\n");
    }
    if(gamers.check == 42)
    {
        for(i = 0; i < gamers.nop; i++)
        {
            if(*(gamers.playerName + i) == NULL)
            {
                break;
            }
            else
            {
                if(i == gamers.ownTag - 49)
                {
                    fprintf(saver, "%s %c %d\n", *(gamers.playerName + gamers.ownTag - 49), gamers.playerTag[gamers.ownTag - 49], sum);
                }
                else
                {
                    fprintf(saver, "%s %c %d\n", *(gamers.playerName + i), gamers.playerTag[i], gamers.playerPoints[i]);
                }
            }
        }

    }
    else if(gamers.check == 12)
    {
        gamers.playerPoints[gamers.nop] = State.points + gamers.ownPoints;
        for(i = 0; i < gamers.nop + 1; i++)
        {
            if(*(gamers.playerName + i) == NULL)
            {
                break;
            }
            else
            {
                fprintf(saver, "%s %c %d\n", *(gamers.playerName + i), gamers.playerTag[i], sum);
            }
        }

    }
    else
    {
        printMessage(fatalInternalError);
        exit(fatalInternalError);
    }
    fclose(saver);
}

save placingAI(maping tiles, int tag)
{
    save update;
    char coW, coWW;
    char chosen;
    int hiddenCount;
    int aux;
    char aaau[2];
    int m,n;

    int Hthree[64];
    int Wthree[64];
    int Htwo[64];
    int Wtwo[64];
    int Hone[64];
    int Wone[64];

    char compare[4] = {'0','1','2','3'};

    int k = 0; //three
    int h = 0; //two
    int l = 0; //one
    int ran;

    //printf("\ncomapre: %c %c %c %c \n", compare[0], *(compare + 1), compare[2], *(compare + 3)); Debug

    for(m = 0; m < tiles.dime[0]; m++)
    {
        for(n = 0; n < tiles.dime[1] * 2; n += 2)
        {
            if(tiles.loader[m][n] == compare[3] && tiles.loader[m][n + 1] == compare[0] )
            {
                Hthree[k] = m;
                Wthree[k] = n;
                k++;
            }
            else if(tiles.loader[m][n] == compare[2] && tiles.loader[m][n + 1] == compare[0])
            {
                Htwo[h] = m;
                Wtwo[h] = n;
                h++;
            }
            else if(tiles.loader[m][n] == compare[1] && tiles.loader[m][n + 1] == compare[0])
            {
                Hone[l] = m;
                Wone[l] = n;
                l++;
            }
        }
    }

    /*printf("\nNumber of threes: %d %c\n", k, compare[3]); DEBUG
    printf("\nNumber of twos: %d %c\n", h , compare[2]);
    printf("\nNumber of ones: %d %c\n", l, compare[1]);*/

    srand(time(0));
    if(k > 0)
    {
        ran = (rand() % ((k - 1) - 0 + 1)) + 0;
        //printf("%d %d %d", ran, Hthree[ran], Wthree[ran]); Debug
        coW = tiles.loader[Hthree[ran]][Wthree[ran]];
        coWW = tiles.loader[Hthree[ran]][Wthree[ran] + 1];

        //printf("\n%c %c\n", tiles.loader[Hthree[ran]][Wthree[ran]], tiles.loader[Hthree[ran]][Wthree[ran] + 1]); Debug
        chosen = tiles.loader[Hthree[ran]][Wthree[ran]];

        hiddenCount = atoi(&chosen);
        coW = '0';
        aux = tag;
        sprintf(aaau, "%d", aux);
        coWW = aaau[0];

        update.points = hiddenCount;

        tiles.loader[Hthree[ran]][Wthree[ran]] = coW;
        tiles.loader[Hthree[ran]][Wthree[ran] + 1] = coWW;

        update.updated = tiles.loader;

        //printf("\n%c %c\n", tiles.loader[Hthree[ran]][Wthree[ran]], tiles.loader[Hthree[ran]][Wthree[ran] + 1]);//Debug
        //printf("\n %d %d", Hthree[ran], Wthree[ran]);//Debug

        update.dimensions[0] = tiles.dime[0];
        update.dimensions[1] = tiles.dime[1];
    }
    else if (k == 0)
    {
        if(h > 0)
        {
            ran = (rand() % ((h - 1) - 0 + 1)) + 0;
            //printf("%d %d %d", ran, Htwo[ran], Wtwo[ran]);Debug
            coW = tiles.loader[Htwo[ran]][Wtwo[ran]];
            coWW = tiles.loader[Htwo[ran]][Wtwo[ran] + 1];

            //printf("\n%c %c\n", tiles.loader[Htwo[ran]][Wtwo[ran]], tiles.loader[Htwo[ran]][Wtwo[ran] + 1]);Debug
            chosen = tiles.loader[Htwo[ran]][Wtwo[ran]];

            hiddenCount = atoi(&chosen);
            coW = '0';
            aux = tag;
            sprintf(aaau, "%d", aux);
            coWW = aaau[0];

            update.points = hiddenCount;

            tiles.loader[Htwo[ran]][Wtwo[ran]] = coW;
            tiles.loader[Htwo[ran]][Wtwo[ran] + 1] = coWW;

            update.updated = tiles.loader;

            //printf("\n%c %c\n", tiles.loader[Htwo[ran]][Wtwo[ran]], tiles.loader[Htwo[ran]][Wtwo[ran] + 1]);//Debug

            //printf("\n %d %d", Htwo[ran], Wtwo[ran]);//Debug

            update.dimensions[0] = tiles.dime[0];
            update.dimensions[1] = tiles.dime[1];
        }
        else if(h == 0)
        {
            if(l > 0)
            {
                ran = (rand() % ((l - 1) - 0 + 1)) + 0;
                //printf("%d %d %d", ran, Hone[ran], Wone[ran]);Debug
                coW = tiles.loader[Hone[ran]][Wone[ran]];
                coWW = tiles.loader[Hone[ran]][Wone[ran] + 1];

                //printf("\n%c %c\n", tiles.loader[Hone[ran]][Wone[ran]], tiles.loader[Hone[ran]][Wone[ran] + 1]);Debug
                chosen = tiles.loader[Hone[ran]][Wone[ran]];

                hiddenCount = atoi(&chosen);
                coW = '0';
                aux = tag;
                sprintf(aaau, "%d", aux);
                coWW = aaau[0];

                update.points = hiddenCount;

                tiles.loader[Hone[ran]][Wone[ran]] = coW;
                tiles.loader[Hone[ran]][Wone[ran] + 1] = coWW;

                update.updated = tiles.loader;

                //printf("\n%c %c\n", tiles.loader[Hone[ran]][Wone[ran]], tiles.loader[Hone[ran]][Wone[ran] + 1]);//Debug

                //printf("\n %d %d", Hone[ran], Wone[ran]);//Debug

                update.dimensions[0] = tiles.dime[0];
                update.dimensions[1] = tiles.dime[1];
            }
            else if(l == 0)
            {
                printf("\nImpossible Operation\n");
                exit(1);
            }
        }
    }

    //printf("POINTS PLACEMENT: %d", update.points);Debug

    return update;
}

save AIgameplay(FILE* po, maping loaded, plInfo gamer, int TNP, char outName[], int checker)
{

    //printf("Whatever\n");Debug
    save nowState;
    penguins* mover;
    if(checker == 1)
    {
            //printf("\nPlacement phase\n");Debug
            graficMap(loaded.loader, loaded.dime, gamer);
            nowState = placingAI(loaded, gamer.ownTag);
            //printf("OwnTag: %d", gamer.ownTag);Debug
            graficMap(nowState.updated, loaded.dime, gamer);
            saveState(nowState, gamer, outName);
        /*if(isPlacement(TNP,gamer.ownTag,loaded) == true)
        {
            //printf("\nPlacement phase\n");Debug
            graficMap(loaded.loader, loaded.dime, gamer);
            nowState = placingAI(loaded, gamer.ownTag);
            //printf("OwnTag: %d", gamer.ownTag);Debug
            graficMap(nowState.updated, loaded.dime, gamer);
            saveState(nowState, gamer, outName);
        }
        else if(isPlacement(TNP,gamer.ownTag,loaded) == false)
        {
            graficMap(loaded.loader, loaded.dime, gamer);
            mover = ownPenguins(loaded, TNP, gamer.ownTag);
            nowState = movingAI(mover, loaded, TNP);
            graficMap(nowState.updated, loaded.dime, gamer);
            saveState(nowState, gamer, outName);
        }*/
    }
    else if(checker == 2)
    {
        //printf("\nMovement phase\n");Debug
        graficMap(loaded.loader, loaded.dime, gamer);
        mover = ownPenguins(loaded, TNP, gamer.ownTag);
        nowState = movingAI(mover, loaded, TNP);
        graficMap(nowState.updated, loaded.dime, gamer);
        saveState(nowState, gamer, outName);
    }

    return nowState;
}
