#include "car_Christian_Schrefl.h"

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
