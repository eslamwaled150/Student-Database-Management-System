
#include "SDBAPP.h"
void SDB_action(Uint8);

void SDB_APP(){
    Uint8 choice;

    // Options
    printf("        AMIT LEARNING   \n\n");
    printf("1. To add entry, enter 1\n");
    printf("2. To get used size in database, enter 2\n");
    printf("3. To read student data, enter 3\n");
    printf("4. To get the list of all student IDs, enter 4\n");
    printf("5. To check is ID is existed, enter 5\n");
    printf("6. To delete student data, enter 6\n");
    printf("7. To check is database is full, enter 7\n");
    printf("8. To exit enter 0\n");
    printf("***************************************   \n\n");

    do{
        printf("Enter an option: ");
        scanf("%d", (int*)&choice);


        if(choice < 0 || choice > 7){
            printf("This choice is not exist in options.\n");
            choice = 1;
        }
        else if (choice == 0) continue;
        else SDB_action(choice);

    }while(choice > 0 && choice <= 7);
}

void SDB_action (Uint8 choice){
    int i;
    switch (choice)
    {
        case 1:{
            if(SDB_AddEntry())
                printf("Student added successfully.\n");
            else
                printf("Incorrect data or the database is full.\n");
            break;
        }
        case 2:{
            Uint8 dbSize = SDB_GetUsedSize();

            if(!dbSize)
                printf("No students have been added yet.\n");
            else
                printf("There is %d student/students in the database.\n", dbSize);

            break;
        }
        case 3:{
            Uint32 id;
            printf("Enter student id to print his data: ");
            scanf("%u", &id);
            if(!ReadEntry(id))
                printf("No user with that id.\n");
            break;
        }
        case 4:{
            Uint8 count;
            Uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of ids: [ ");
            for(i = 0; i < count ; i++){
                printf("%u", list[i]);
                if(i != count - 1)
                    printf(", ");
            }
            printf(" ]\n");
            break;
        }
        case 5:{
            Uint32 id;
            printf("Enter Student_id to check whether it is exist or not: ");
            scanf("%u", &id);
            if(SDB_IsIdExist(id))
                printf("This id is exist.\n");
            else
                printf("This id is not exist.\n");
            break;
        }
        case 6:{
            Uint32 id;
            printf("Enter Student_id to be deleted: ");
            scanf("%u", &id);
            if(SDB_DeleteEntry(id))
                printf("Deleted Successfully\n");
            break;
        }
        case 7:
            printf("%s", SDB_isFull() == True? "Database is full\n" : "Database is not full.\n");
            break;

        default:
            return;
    }
}
