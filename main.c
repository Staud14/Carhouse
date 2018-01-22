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



int main()
{
    TIMETABLE *current;
/*#ifdef TEST_THINGS
    ///Adding two example functions to the Time Table
    current = malloc(sizeof(TIMETABLE));
    current->next = malloc(sizeof(TIMETABLE));
    current->next->next=current;        //Making the list Circular
    current->next->funktion=fact;
    current->funktion=fibonacci;
    ///END Test things
#endif // TEST_THINGS
*/
    current = initTimeTable(showMenu);
//    insertInTimeTable(current, fact);
    loopTimeTable(current);
    return 0;
}



