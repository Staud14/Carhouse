#ifndef CAR_CHRISTIAN_SCHREFL_H_INCLUDED
#define CAR_CHRISTIAN_SCHREFL_H_INCLUDED
#include "console.h"

//Return Value Encodings
#define KEEP 1
#define KILL 0


typedef struct TimeTable
{
    int (*funktion)();          //Pointer to a Function returning an integer
    struct TimeTable *next;     //Next Element on the circular List
} TIMETABLE;
int count(TIMETABLE *current);

void loopTimeTable(TIMETABLE *current);

TIMETABLE* initTimeTable(int (*funktion)(TIMETABLE *TT));

void insertInTimeTable(TIMETABLE *current, int (*funktion)(TIMETABLE *TT));


void showMenu(TIMETABLE *current);


void Cryption(char *in, char key, int len);     /// Encrypts a generic byte length

#endif // CAR_CHRISTIAN_SCHREFL_H_INCLUDED
