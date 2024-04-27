#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sPerson_ {
    int age;
    struct sPerson_* next;
}sPerson;


sPerson* getNewPerson (const int age){
    sPerson* newPerson = NULL;
    newPerson = (sPerson*)malloc(sizeof(sPerson));
    if (newPerson != NULL)
    {
        newPerson->age = age;
        newPerson->next = NULL;
        printf("created new person at %p\n", newPerson);
    }
    else
    {
        printf("Allocation Failure!! \n");
    }
    return newPerson;
}

void PrintPerson (sPerson *varName, char *comment){
    if(varName == NULL)
    {
        printf("%s is NULL\n", comment);
    }
    else
    {
        printf("%s: age:%d, address:%p next:%p\n",
            comment,
            varName->age,
            varName,
            varName->next);
    }
}

void PrintList (sPerson *list)
{
    printf("Printing List:\n");
    sPerson *t;
    t = list;
    if (t == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (t)
        {
            PrintPerson(t, "t");
            t = t->next;
        }
    }
}

void CleanUp (sPerson *list)
    {
        sPerson *next;
        while(list)
        {
            next = list->next;
            printf("Cleaning %d\n", list->age);
            free(list);
            list = next;
        }
    }

int main (int argc, char **argv) {

    sPerson* first = NULL;
    sPerson* added = NULL;

    char command[64];
    int age;

    while(1)
    {
        printf("Enter a command or value: ");
        fgets(command, 64, stdin);
        if (strcmp("q\n", command) == 0)
        {
            printf("Quitting...\n");
            break;
        }
        else if (strcmp("print\n", command) == 0)
        {
            printf("Printing..\n");
            PrintList(first);
        }
        else if(sscanf(command, "%d", &age) != 0)
        {
            printf("Adding %d\n", age);
            if (first == NULL)
            {
                first = getNewPerson(age);
                if (first != NULL)
                {
                    added = first;
                }
            }
            else
            {
                added->next = getNewPerson(age);
                if (added->next != NULL)
                {
                    added = added->next;
                }
            }
        }
    }

    CleanUp(first);

    first = NULL;
    added = NULL;

    return 0;
}