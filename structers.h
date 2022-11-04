#ifndef STRUCTERS_H_INCLUDED
#define STRUCTERS_H_INCLUDED

struct mapState
{
    char** loader;
    int dime[2];
};
typedef struct mapState maping;

struct players
{
    char playerName[9][32];
    int playerPoints[9];
    char playerTag[9];
    int nop;
    int ownTag;
    int ownPoints;
    int check;
};
typedef struct players plInfo;

struct update
{
    int dimensions[2];
    char** updated;
    int points;
};
typedef struct update save;

struct coords
{
    int height;
    int width;
    int wwidth;
};
typedef struct coords penguins;


#endif // STRUCTERS_H_INCLUDED
