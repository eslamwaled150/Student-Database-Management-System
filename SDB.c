#include <stdio.h>
#include "STD.h"
#include "SDB.h"

#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

Uint32 i;
Uint32 nOfStds = 0;

student students[MAX_STUDENTS];

Uint8 nextInd = 0;

Bool SDB_isFull(){
    return nextInd == MAX_STUDENTS? True : False;
}

Uint8 SDB_GetUsedSize(){
    return nextInd;
}

Bool validateData(student*);
Bool SDB_AddEntry(){

    if(SDB_isFull())
        return False;

    student* newStd = &students[nextInd];

    printf("Enter these data to add student.\n");

    printf("ID: ");
    scanf("%u", &newStd->Student_ID);

    printf("Year: ");
    scanf("%u", &newStd->Student_year);

    printf("Course1_ID: ");
    scanf("%u", &newStd->Course1_ID);

    printf("Course1_grade: ");
    scanf("%u", &newStd->Course1_grade);

    printf("Course2_ID: ");
    scanf("%u", &newStd->Course2_ID);

    printf("Course2_grade: ");
    scanf("%u", &newStd->Course2_grade);

    printf("Course3_ID: ");
    scanf("%u", &newStd->Course3_ID);

    printf("Course3_grade: ");
    scanf("%u", &newStd->Course3_grade);

    if(!validateData(newStd))
        return False;

    nextInd++;

    return True;
}

// Validation part For AddEntry
Bool isValidGrade(Uint32);
Bool validateData(student* std){
    if(!(isValidGrade(std->Course1_grade) && isValidGrade(std->Course2_grade) && isValidGrade(std->Course3_grade)))
        return False;
    if((int)std->Student_year <= 0 || std->Student_year > 5)
        return False;
    if((int)std->Student_ID < 0 || (int)std->Course1_ID < 0 || (int)std->Course2_ID < 0 || (int)std->Course3_ID < 0)
        return False;
    // Course_ID should be distinct
    if(std->Course1_ID == std->Course2_ID || std->Course1_ID == std->Course3_ID || std->Course2_ID == std->Course3_ID)
        return False;
    // check if there is student with that id
    for( i = 0 ; i < nextInd ; i++)
        if(students[i].Student_ID == std->Student_ID){
            printf("This student_ID already exist.\n");
            return False;
        }

    return True;

}
Bool isValidGrade(Uint32 grade){
    // Convert from unsigned int to int to determine if the grade is negative or not
    return (int) grade < 0 || grade > 1000? False : True;
}

Bool SDB_DeleteEntry(Uint32 id){
    // database is empty
    if(!nextInd){
        printf("Database is empty.\n");
        return False;
    }
    // getting the position of student to remove it
    Uint8 pos = 0;
    for(; pos < nextInd ; pos++)
        if(id == students[pos].Student_ID)
            break;

    // Student not exist
    if(pos == nextInd){
        printf("No student with that id.\n");
        return False;
    }

    // Shifting all elements to the left starting from the removed student
    for(;pos < nextInd - 1;pos++)
        students[pos] = students[pos + 1];

    nextInd--;

    return True;
}
Bool SDB_IsIdExist(Uint32 id){
    for( i = 0 ; i < nextInd ; i++)
        if(id == students[i].Student_ID)
            return True;
    return False;
}

Bool ReadEntry(Uint32 id){
    for( i = 0 ; i < nextInd ; i++)
        if(id == students[i].Student_ID){
            printf("---------------Student Data---------------\n");
            printf("ID: %u.\n",students[i].Student_ID);
            printf("Year: %u.\n",students[i].Student_year);
            printf("Course1_ID: %u.\n",students[i].Course1_ID);
            printf("Course1_grade: %u.\n",students[i].Course1_grade);
            printf("Course2_ID: %u.\n",students[i].Course2_ID);
            printf("Course2_grade: %u.\n",students[i].Course2_grade);
            printf("Course3_ID: %u.\n",students[i].Course3_ID);
            printf("Course3_grade: %u.\n",students[i].Course3_grade);
            return True;
        }
    return False;
}

void SDB_GetList(Uint8* count, Uint32* list){
    *count = SDB_GetUsedSize();
    for( i = 0 ; i < *count ; i++)
        list[i] = students[i].Student_ID;
}
