#include "check.h"
#include <time.h>
// read file and recognize own tag, name and points
//compares older version map with new and checks the number of differences
//function that will measure the number of own penguins on the board, the function that checks if board is changed

//checks the number of tiles with own penguins, and if the number is equal to the nP parameter, place them all in array

bool isPlacement(int TNP, int ownTag, maping boardInfo)
{
    int a,b;
    int counter = 0;
    int help;
    char aux[1];
    help = ownTag;
    sprintf(aux, "%d", help);

    for(a = 0; a < boardInfo.dime[0]; a++)
    {
        for(b = 0; b < (boardInfo.dime[1] * 2); b += 2)
        {
            if(boardInfo.loader[a][b + 1] == aux[0] )
            {
                counter++;
                //printf("\nCounting: %d\n", counter);Debug
            }
        }
    }
    if(counter == TNP)
    {
        //printf("\nNow should be Movement Phase\n"); Debug
        return false;
    }

    else if(counter < TNP)
    {
        //printf("\nPlacement phase should be conducted\n");Debug
        return true;
    }
    else
    {
        printMessage(wrongCounting);
        exit(wrongCounting);
    }

}

int countOwnPenguins(int ownTag, maping maper)
{
    int TNP = 0;
    int a,b;
    int help;
    int counter = 0;
    char aux[1];
    help = ownTag;
    sprintf(aux, "%d", help);

    //printf("\nImportant: char %c int %d\n", aux[0], aux[0]);Debug

    for(a = 0; a < maper.dime[0]; a++)
    {
        for(b = 0; b < (maper.dime[1] * 2); b += 2)
        {
            if(maper.loader[a][b + 1] == aux[0] )
            {
                counter++;
                //printf("\nCounting: %d\n", counter);Debug
                //printf("\n%c%c\n", maper.loader[a][b],maper.loader[a][b+1]);Debug
            }
        }
    }
    TNP = counter;

    return TNP;
}


penguins* ownPenguins(maping boardInfo, int TNP, int ownTag)
{
    penguins* penguins;

    int a,b;
    int help;
    char aux[1];
    help = ownTag;
    sprintf(aux, "%d", help);
    int i = 0;
    penguins = malloc(sizeof(penguins) * TNP);

    for(a = 0; a < boardInfo.dime[0]; a++)
    {
        for(b = 0; b < (boardInfo.dime[1] * 2); b += 2)
        {
            if(boardInfo.loader[a][b + 1] == aux[0])
            {
                penguins[i].height = a;
                penguins[i].width = b;
                penguins[i].wwidth = b + 1;
                i++;
            }
        }
    }



    return penguins;
}

int sumOfArray(int arr[], int siz)
{
    int result = 0;
    int a;

    for(a = 0; a < siz; a++)
    {
        result = result + arr[a];
    }
    return result;
}


save movingAI(penguins* mover, maping board, int TNP)
{
    //printf("Works?");Debug
    save moved;
    int m = 0,n = 0,k = 0,l = 0,g = 0, j = 0;
    //int a; For Debug
    int ran,ra,r;
    int Hthree[64];
    int Wthree[64];
    int Htwo[64];
    int Wtwo[64];
    int Hone[64];
    int Wone[64];
    int checker = 0;

    /*for(a = 0; a < TNP; a++)Debug
    {
        printf("\n%d Coords  Height: %d Width: %d Wwidth: %d \n", a, mover[a].height, mover[a].width, mover[a].wwidth);
    }*/

    srand(time(0));
    ran = 0;
    int height = mover[ran].height;
    int width = mover[ran].width;
    int wwidth = mover[ran].wwidth;

    int up[board.dime[0]];
    int down[board.dime[0]];
    int left[board.dime[1] * 2];
    int right[board.dime[1] * 2];
    int u, dow, lef, righ;
    int aux,z,x = 0,c = 0,v = 0;
    char tag[1];
    char points[1];
    char cow,coww;
    int count;

    strcpy(tag + 0, *(board.loader + height) + wwidth );

    while((height + 1 + m) < board.dime[0] && board.loader[height + 1 + m][width] != '0') //down
    {
        aux = *(*(board.loader + height + 1 + m) + width);
        down[m] = aux - 48;
        m++;
    }

    while((height - 1 - n) >= 0 && board.loader[height - 1 - n][width] != '0') //up
    {
        aux = *(*(board.loader + height - 1 - n) + width);
        up[n] = aux - 48;
        n++;
    }

    while((width + 2 + l) < board.dime[1]*2 && board.loader[height][width + 2 + l] != '0') //right
    {
        aux = *(*(board.loader + height) + width + 2 + l);
        right[g] = aux - 48;
        l += 2;
        g++;
    }

    while((width - 2 - k) >= 0 && board.loader[height][width - 2 - k] != '0') //left
    {
        aux = *(*(board.loader + height) + width - 2 - k );
        left[j] = aux - 48;
        k += 2;
        j++;
    }

    //printf("\nCoords no.:%d Up: %d Down: %d Right: %d Left: %d\n",ran, n,m,g,j);Debug

    u = sumOfArray(up, n);
    dow = sumOfArray(down, m);
    lef = sumOfArray(left, j);
    righ = sumOfArray(right, g);

    //printf("\nU: %d Dow: %d Lef: %d Righ: %d\n", u, dow, lef, righ);Debug

    if(u == 0 && dow == 0 && lef == 0 && righ == 0)
    {
        while(u == 0 && dow == 0 && lef == 0 && righ == 0 && (checker != 256))
        {
            r = (rand() % ((TNP - 1) - 0 + 1)) + 0;
            height = mover[r].height;
            width = mover[r].width;
            wwidth = mover[r].wwidth;
            m = 0, n = 0, l = 0, k = 0, g = 0, j = 0;

            while((height + 1 + m) < board.dime[0] && board.loader[height + 1 + m][width] != '0') //down
            {
                aux = *(*(board.loader + height + 1 + m) + width);
                down[m] = aux - 48;
                m++;
            }


            while((height - 1 - n) >= 0 && board.loader[height - 1 - n][width] != '0') //up
            {
                aux = *(*(board.loader + height - 1 - n) + width);
                up[n] = aux - 48;
                n++;
            }

            while((width + 2 + l) < board.dime[1]*2 && board.loader[height][width + 2 + l] != '0') //right
            {
                aux = *(*(board.loader + height) + width + 2 + l);
                right[g] = aux - 48;
                l += 2;
                g++;
            }

            while((width - 2 - k) >= 0 && board.loader[height][width - 2 - k] != '0') //left
            {
                aux = *(*(board.loader + height) + width - 2 - k );
                left[j] = aux - 48;
                k += 2;
                j++;
            }
            u = sumOfArray(up, n);
            dow = sumOfArray(down, m);
            lef = sumOfArray(left, j);
            righ = sumOfArray(right, g);


            checker++;
        }
    }
    if(checker == 256)
    {
        printMessage(noMovesLeft);
        exit(noMovesLeft);
    }
    height = mover[r].height;
    width = mover[r].width;
    wwidth = mover[r].wwidth;
    m = 0, n = 0, l = 0, k = 0, g = 0, j = 0;

    while((height + 1 + m) < board.dime[0] && board.loader[height + 1 + m][width] != '0') //down
    {
        aux = *(*(board.loader + height + 1 + m) + width);
        down[m] = aux - 48;
        m++;
    }

    while((height - 1 - n) >= 0 && board.loader[height - 1 - n][width] != '0') //up
    {
        aux = *(*(board.loader + height - 1 - n) + width);
        up[n] = aux - 48;
        n++;
    }

    while((width + 2 + l) < board.dime[1]*2 && board.loader[height][width + 2 + l] != '0') //right
    {
        aux = *(*(board.loader + height) + width + 2 + l);
        right[g] = aux - 48;
        l += 2;
        g++;
    }

    while((width - 2 - k) >= 0 && board.loader[height][width - 2 - k] != '0') //left
    {
        aux = *(*(board.loader + height) + width - 2 - k );
        left[j] = aux - 48;
        k += 2;
        j++;
    }
    u = sumOfArray(up, n);
    dow = sumOfArray(down, m);
    lef = sumOfArray(left, j);
    righ = sumOfArray(right, g);
    //printf("\nU: %d Dow: %d Lef: %d Righ: %d\n", u, dow, lef, righ);Debug

    if(u != 0 && u > dow && u > lef && u > righ)
    {
        //printf("\nUP %d\n", u);Debug
        for(z = 0; z < n; z++)
        {
            if(board.loader[height - 1 - z][width] == '3')
            {
                Hthree[x] = height - 1 - z;
                Wthree[x] = width;
                x++;
            }
            else if(board.loader[height - 1 - z][width] == '2')
            {
                Htwo[c] = height - 1 - z;
                Wtwo[c] = width;
                c++;
            }
            else if(board.loader[height - 1 - z][width] == '1')
            {
                Hone[v] = height - 1 - z;
                Wone[v] = width;
                v++;
            }
        }
    }

    else if(dow != 0 && dow > u && dow > lef && dow > righ)
    {
        //printf("\nDOWN %d\n", dow);Debug
        for(z = 0; z < m; z++)
        {
            if(board.loader[height + 1 + z][width] == '3')
            {
                Hthree[x] = height + 1 + z;
                Wthree[x] = width;
                x++;
            }
            else if(board.loader[height + 1 + z][width] == '2')
            {
                Htwo[c] = height + 1 + z;
                Wtwo[c] = width;
                c++;
            }
            else if(board.loader[height + 1 + z][width] == '1')
            {
                Hone[v] = height + 1 + z;
                Wone[v] = width;
                v++;
            }
        }
    }

    else if(lef != 0 && lef > u && lef > dow && lef > righ)
    {
         //printf("\nLEFT %d\n", lef);Debug
        for(z = 0; z < k; z+=2)
        {
            if(board.loader[height][width - 2 - z] == '3')
            {
                Hthree[x] = height;
                Wthree[x] = width - 2 - z;
                x++;
            }
            else if(board.loader[height][width - 2 - z] == '2')
            {
                Htwo[c] = height;
                Wtwo[c] = width - 2 - z;
                c++;
            }
            else if(board.loader[height][width - 2 - z] == '1')
            {
                Hone[v] = height;
                Wone[v] = width - 2 - z;
                v++;
            }
        }
    }

    else if(righ != 0 && righ > u && righ > dow && righ > lef)
    {
         //printf("\nRIGTH %d\n", righ);Debug
        for(z = 0; z < l; z+=2)
        {
            if(board.loader[height][width + 2 + z] == '3')
            {
                Hthree[x] = height;
                Wthree[x] = width + 2 + z;
                x++;
            }
            else if(board.loader[height][width + 2 + z] == '2')
            {
                Htwo[c] = height;
                Wtwo[c] = width + 2 + z;
                c++;
            }
            else if(board.loader[height][width + 2 + z] == '1')
            {
                Hone[v] = height;
                Wone[v] = width + 2 + z;
                v++;
            }
        }
    }

    else
    {
        if(righ != 0)
        {
            //printf("\nALWAYS RIGTH %d\n", righ);Debug
            for(z = 0; z < l; z+=2)
            {
                if(board.loader[height][width + 2 + z] == '3')
                {
                    Hthree[x] = height;
                    Wthree[x] = width + 2 + z;
                    x++;
                }
                else if(board.loader[height][width + 2 + z] == '2')
                {
                    Htwo[c] = height;
                    Wtwo[c] = width + 2 + z;
                    c++;
                }
                else if(board.loader[height][width + 2 + z] == '1')
                {
                    Hone[v] = height;
                    Wone[v] = width + 2 + z;
                    v++;
                }
            }
        }
        else if(righ == 0)
        {
            if(lef != 0)
            {
                //printf("\nALWAYS LEFT %d\n", lef);Debug
                for(z = 0; z < k; z+=2)
                {
                    if(board.loader[height][width - 2 - z] == '3')
                    {
                        Hthree[x] = height;
                        Wthree[x] = width - 2 - z;
                        x++;
                    }
                    else if(board.loader[height][width - 2 - z] == '2')
                    {
                        Htwo[c] = height;
                        Wtwo[c] = width - 2 - z;
                        c++;
                    }
                    else if(board.loader[height][width - 2 - z] == '1')
                    {
                        Hone[v] = height;
                        Wone[v] = width - 2 - z;
                        v++;
                    }
                }
            }
            else if(lef == 0)
            {
                if(u != 0)
                {
                    //printf("\nALWAYS UP %d\n", u);Debug
                    for(z = 0; z < n; z++)
                    {
                        if(board.loader[height - 1 - z][width] == '3')
                        {
                            Hthree[x] = height - 1 - z;
                            Wthree[x] = width;
                            x++;
                        }
                        else if(board.loader[height - 1 - z][width] == '2')
                        {
                            Htwo[c] = height - 1 - z;
                            Wtwo[c] = width;
                            c++;
                        }
                        else if(board.loader[height - 1 - z][width] == '1')
                        {
                            Hone[v] = height - 1 - z;
                            Wone[v] = width;
                            v++;
                        }
                    }
                }
                else if(u == 0)
                {
                    if(dow != 0)
                    {
                        //printf("\nDOWN %d\n", dow);Debug
                        for(z = 0; z < m; z++)
                        {
                            if(board.loader[height + 1 + z][width] == '3')
                            {
                                Hthree[x] = height + 1 + z;
                                Wthree[x] = width;
                                x++;
                            }
                            else if(board.loader[height + 1 + z][width] == '2')
                            {
                                Htwo[c] = height + 1 + z;
                                Wtwo[c] = width;
                                c++;
                            }
                            else if(board.loader[height + 1 + z][width] == '1')
                            {
                                Hone[v] = height + 1 + z;
                                Wone[v] = width;
                                v++;
                            }
                        }
                    }
                    else if(dow == 0)
                    {
                        printMessage(noMovesOrWrong);
                        exit(noMovesOrWrong);
                    }
                }
            }
        }
    }
    /*printf("\nNumber of threes: %d \n", x); Debug
    printf("\nNumber of twos: %d \n", c );
    printf("\nNumber of ones: %d \n", v);*/

    if(x > 0)
    {
        ra = (rand() % ((x - 1) - 0 + 1)) + 0;
        //printf("%d %d %d", ra, Hthree[ra], Wthree[ra]);Debug
        cow = board.loader[Hthree[ra]][Wthree[ra]];
        coww = board.loader[Hthree[ra]][Wthree[ra] + 1];

        //printf("\n%c %c\n", board.loader[Hthree[ra]][Wthree[ra]], board.loader[Hthree[ra]][Wthree[ra] + 1]);Debug
        points[0] = board.loader[Hthree[ra]][Wthree[ra]];

        count = *points + 0;
        cow = '0';
        coww = tag[0];

        moved.points = count - 48;

        board.loader[Hthree[ra]][Wthree[ra]] = cow;
        board.loader[Hthree[ra]][Wthree[ra] + 1] = coww;

        moved.updated = board.loader;

        //printf("\n%c %c\n", board.loader[Hthree[ra]][Wthree[ra]], board.loader[Hthree[ra]][Wthree[ra] + 1]);//Debug

        //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

        board.loader[height][wwidth] = '0';

        //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

        moved.dimensions[0] = board.dime[0];
        moved.dimensions[1] = board.dime[1];

    }
    else if(x == 0)
    {
        if(c > 0)
        {
            ra = (rand() % ((c - 1) - 0 + 1)) + 0;
            //printf("%d %d %d", ra, Htwo[ra], Wtwo[ra]);Debug
            cow = board.loader[Htwo[ra]][Wtwo[ra]];
            coww = board.loader[Htwo[ra]][Wtwo[ra] + 1];

            //printf("\n%c %c\n", board.loader[Htwo[ra]][Wtwo[ra]], board.loader[Htwo[ra]][Wtwo[ra] + 1]);Debug
            points[0] = board.loader[Htwo[ra]][Wtwo[ra]];

            count = *points + 0;
            cow = '0';
            coww = tag[0];

            moved.points = count - 48;

            board.loader[Htwo[ra]][Wtwo[ra]] = cow;
            board.loader[Htwo[ra]][Wtwo[ra] + 1] = coww;

            moved.updated = board.loader;

            //printf("\n%c %c\n", board.loader[Htwo[ra]][Wtwo[ra]], board.loader[Htwo[ra]][Wtwo[ra] + 1]);//debbugDebug

            //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

            board.loader[height][wwidth] = '0';

            //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

            moved.dimensions[0] = board.dime[0];
            moved.dimensions[1] = board.dime[1];

        }
        else if(c == 0)
        {
            if(v > 0)
            {
                ra = (rand() % ((v - 1) - 0 + 1)) + 0;
                //printf("%d %d %d", ra, Hone[ra], Wone[ra]);Debug
                cow = board.loader[Hone[ra]][Wone[ra]];
                coww = board.loader[Hone[ra]][Wone[ra] + 1];

                //printf("\n%c %c\n", board.loader[Hone[ra]][Wone[ra]], board.loader[Hone[ra]][Wone[ra] + 1]);Debug
                points[0] = board.loader[Hone[ra]][Wone[ra]];

                count = *points + 0;
                cow = '0';
                coww = tag[0];

                moved.points = count - 48;

                board.loader[Hone[ra]][Wone[ra]] = cow;
                board.loader[Hone[ra]][Wone[ra] + 1] = coww;

                moved.updated = board.loader;

                //printf("\n%c %c\n", board.loader[Hone[ra]][Wone[ra]], board.loader[Hone[ra]][Wone[ra] + 1]);//Debug

                //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

                board.loader[height][wwidth] = '0';

                //printf("\n%c %c\n", board.loader[height][width],board.loader[height][wwidth]);Debug

                moved.dimensions[0] = board.dime[0];
                moved.dimensions[1] = board.dime[1];
            }
            else if(v == 0)
            {
                printMessage(noMovesOrWrong);
                exit(noMovesOrWrong);
            }
        }
    }

    //printf("\nPOINTS HERE %d %c\n", moved.points, points[0]);Debug

    return moved;
}
