#include "car_Christian_Schrefl.h"
#include <stdio.h>

#define TEST_THINGS

#ifdef TEST_THINGS
int fibonacci(TIMETABLE *current);
int fibonacci(TIMETABLE *current)     //An example function which is calculatin and printing out fibonacht funktions
{
    static unsigned int i = 0, d = 1,c = 0;
    int tmp = i+d;
    printf("Fibonacci nr:%d = %d\n",c++,i);
    i=d;
    d=tmp;
    if(tmp > 1000000)
        return KILL;
    return KILL;
}
int fact(TIMETABLE *current);
int fact(TIMETABLE *current)
{
    static unsigned long int i = 1, c = 1;
    printf("Factorial of %ld = %ld\n",c,i);
    i*=c;
    c++;
    if(i > 1000000)
        return KILL;        //if the result gets to big the funktion call gets removed from the time table
    return KEEP;
}
#endif


void showMenu(TIMETABLE *current)
{
    char c;
    printf("Select one of the following functions: \n");
    //printf("0: \n");
    printf("1: Auto Hinzufügen(fib)\n");
    printf("2: Auto Bearbeiten\n");
    printf("3: Auto Löschen\n");

    ///Temp Bis Sync
    printf("4: Autos Speichern\n");
    printf("5: Autos Laden\n");
    ///End

    c = getch();
    switch(c)
    {
    case '1':     ///Add
        insertInTimeTable(current,fibonacci);
        break;
    case '2':     ///Edit
        //insertInTimeTable(current,);
        break;
    case '3':     ///Delete
        //insertInTimeTable(current,);
        break;

    case '4':     ///Save
        //insertInTimeTable(current,);
        break;
    case '5':     ///Load
        //insertInTimeTable(current,);
        break;
    default:
        printf("Fehleingabe Bitte Neu versuchen\n");
        showMenu(current);
        break;
    }
    return KEEP;
}


TIMETABLE* initTimeTable(int (*funktion)())
{
    TIMETABLE *TT;
    TT = malloc(sizeof(TIMETABLE));
    TT->funktion = funktion;
    TT->next=TT;
    return TT;
}
void insertInTimeTable(TIMETABLE *current, int (*funktion)(TIMETABLE *TT))
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
        if(current->next->funktion(current)==KILL) //Deleting the function from list
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
