#ifndef CAR_CHRISTIAN_SCHREFL_H_INCLUDED
#define CAR_CHRISTIAN_SCHREFL_H_INCLUDED


//Return Value Encodings
#define KEEP 1
#define KILL 0


typedef struct TimeTable
{
    int (*funktion)();          //Pointer to a Function returning an integer
    struct TimeTable *next;     //Next Element on the circular List
} TIMETABLE;


void loopTimeTable(TIMETABLE *current);

void Cryption(char *in, char key, int len);     /// Encrypts a generic byte length

#endif // CAR_CHRISTIAN_SCHREFL_H_INCLUDED
