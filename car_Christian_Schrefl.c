#include "car_Christian_Schrefl.h"
#include <stdio.h>

TIMETABLE* initTimeTable(int (*funktion)())
{
    TIMETABLE *TT;
    TT = malloc(sizeof(TIMETABLE));
    TT->funktion = funktion;
    TT->next=TT;
    return TT;
}
void insertInTimeTable(TIMETABLE *current, int (*funktion)())
{
    TIMETABLE *tmp;
    tmp=current->next;
    current->next=malloc(sizeof(TIMETABLE));
    current->next->funktion = funktion;
    current->next->next = tmp;
}

void loopTimeTable(TIMETABLE *current)
{
    ///Looping through the Time Table
    while(current!=NULL)
    {
        if(current->next->funktion()==KILL) //Deleting the function from list
        {
            TIMETABLE *temp;
            temp=current->next;
            if(current==current->next)
            {
                current=NULL;
                free(temp);
                return 0;
            }
            else
            {
                current->next=current->next->next;
            }
            free(temp);
        }
        current=current->next;
    }
}

void Cryption(char *in, char key, int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        *in^=key;
    }
}
