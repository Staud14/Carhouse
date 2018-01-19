#ifndef CAR_PATRIK_STAUDENMAYER_H_INCLUDED
#define CAR_PATRIK_STAUDENMAYER_H_INCLUDED

#define CAR_STRING_LENGHT 20
#define SECURE_KEY 'k'
#define Im_gona_break_free  break;

#define M_DataCorruption    if((che = fgetc(fcar)) == ';')          \
                            {                                       \
                                printf("Data is corrupted\n");      \
                                return NULL;                        \
                            }


//Structures
typedef struct sCar CAR;
struct sCar
{
    //Data
    char identifier[CAR_STRING_LENGHT];
    char brand [CAR_STRING_LENGHT];
    unsigned char colour;
    int price;

    //Pointer for List
    CAR *next;
};

//Prototypes for Call Back functions
CAR readUser(void);
CAR readFile(void);

//Call Back functions for encryption methods
void Cryption(char *in, char key, int len);
void noCrypton(char *in, char key);



//Prototypes for loop functions
void addCar (CAR *head, CAR (*readCar)(void));
CAR* CARsave(void (*decryption)(char *string_to_decrypt, char key, int len));

#endif // CAR_PATRIK_STAUDENMAYER_H_INCLUDED
