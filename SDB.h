#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

#include "STD.h"

typedef struct SimpleDb{
    Uint32 Student_ID;
    Uint32 Student_year;
    Uint32 Course1_ID;
    Uint32 Course1_grade;
    Uint32 Course2_ID;
    Uint32 Course2_grade;
    Uint32 Course3_ID;
    Uint32 Course3_grade;
}student;

#define MAX_STUDENTS 10

Bool SDB_isFull();
Uint8 SDB_GetUsedSize();
Bool SDB_AddEntry();
Bool SDB_DeleteEntry(Uint32);
Bool SDB_IsIdExist(Uint32);
Bool ReadEntry(Uint32);
void SDB_GetList(Uint8*, Uint32*);




#endif // SDB_H_INCLUDED
