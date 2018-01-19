#include "car_Christian_Schrefl.h"
#include <stdio.h>

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
