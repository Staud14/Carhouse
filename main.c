/******************************************************************************************************************************************
 * Created by Christian Schrefl, Lukas Zens and Patrik Staudenmayer
 *
 *  Managment program for a car seller
 *
 *
 *******************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "console.h"
#include "car_Patrik_Staudenmayer.h"
#include "car_Christian_Schrefl.h"


///TEST THINGS!!
int fibonacci();
int fibonacci()     //An example function which is calculatin and printing out fibonacht funktions
{
    static unsigned int i = 0, d = 1,c = 0;
    int tmp = i+d;
    printf("Fibonacci nr:%d = %d\n",c++,i);
    i=d;
    d=tmp;
    if(tmp > 1000000)
        return KILL;
    return KEEP;
}
int fact();
int fact()
{
    static unsigned long int i = 1, c = 1;
    printf("Factorial of %ld = %ld\n",c,i);
    i*=c;
    c++;
    if(i > 1000000)
        return KILL;        //if the result gets to big the funktion call gets removed from the time table
    return KEEP;
}
///END TEST THINGS


int main()
{
    TIMETABLE *current;
    ///Test things!
    ///Adding two example functions to the Time Table
    current = malloc(sizeof(TIMETABLE));
    current->next = malloc(sizeof(TIMETABLE));
    current->next->next=current;        //Making the list Circular
    current->next->funktion=fact;
    current->funktion=fibonacci;
    ///END Test things

    loopTimeTable(current);

    return 0;
}



