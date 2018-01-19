#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "console.h"
#include "car_Patrik_Staudenmayer.h"
#include "car_Christian_Schrefl.h"

void addCar (CAR *head, CAR (*readCar)(void))
{
    while(head->next != NULL)
    {
        head->next = head->next->next;
    }

    head->next = malloc(sizeof(CAR));
    *(head->next) = (*readCar)();
}

CAR readUser(void)
{
    CAR readC;
    char letter;

    //Brand
    printf("Ihre Marke Bitte (max. 20 Zeichen): ");
    scanf("%s",readC.brand);

    //Identifier
    printf("Ihre Autobezeichnung (max. 20 Zeichen): ");
    scanf("%s",readC.identifier);

    //colour
    printf("Bitte geben sie ihre Farbe ein: \n");
    printf("y = Gelb, b = Blau, s = Schwarz, w = Weiss, r = Rot, g = Grün \n");
    letter = getch();

    switch(letter)
    {
        case 'y':   readC.colour = YELLOW;   break;
        case 'b':   readC.colour = BLUE;     break;
        case 's':   readC.colour = BLACK;    break;
        case 'w':   readC.colour = WHITE;    break;
        case 'r':   readC.colour = RED;      break;
        case 'g':   readC.colour = GREEN;    break;
    }

    //Price
    printf("Bitte geben sie ihren Preis ein: ");
    scanf("%d",&(readC.price));

    //Returning
    return readC;
}

CAR* readLocalFile(void (*decryption)(char *string_to_decrypt, char key, int len))
{
    FILE *fcar;
    int x;
    CAR localCar, *currentPos, *head = NULL;
    char che;


    fcar = fopen("save.csf","r");
    if( fcar != NULL )
    {

        do
        {
            //Read identifier
            for(x=0; x < CAR_STRING_LENGHT; x++)
            {
                localCar.identifier[x] = fgetc(fcar);

                if(localCar.identifier[x] == EOF)
                    break;
            }

            //Check Data for corruption
            M_DataCorruption                //This is a macro so no semicolon is needed

            //Read brand
            for(x=0; x < CAR_STRING_LENGHT; x++)
            {
                localCar.brand[x] = fgetc(fcar);
                if(localCar.brand[x] == EOF)
                    break;
            }

            //Check Data for corruption
            M_DataCorruption                //This is a macro so no semicolon is needed

            //Read colour
            localCar.colour = fgetc(fcar);
            if(localCar.colour == EOF)
                break;

            //Check Data for corruption
            M_DataCorruption                //This is a macro so no semicolon is needed

            //Read price
            fscanf(fcar,"%d",&localCar.price);
            if(localCar.price == EOF)
                break;

            //Setting next
            localCar.next = NULL;

            //Decrypting Car
            Cryption(localCar.identifier, SECURE_KEY, ( ( sizeof(CAR) - sizeof(CAR *) ) / sizeof(char) ) ) ;

            if(head == NULL)
            {
                head = malloc(sizeof(CAR));
                *head = localCar;
                currentPos = head;
            }
            else
            {
                currentPos->next = malloc(sizeof(CAR));
                currentPos = currentPos->next;
                *currentPos = localCar;
            }


        }while(1);



        //Closing File
        fclose(fcar);
    }
    else
    {
        printf("File not accesable\n");
        return NULL;
    }




    return head;
}
