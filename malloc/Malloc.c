
/* Memory Allocation
*/

typedef struct _node {
    char name;
    int id;
} Node_t;       // makes a new datatype called Node_t

#include <stdlib.h>

int main (int argc, char**argv) {

    int* pA = NULL;

    double a = 1.2;
    double b = (int)a;  // converting b to an "int" a

    pA = (int*)malloc(sizeof(int)); // (int*) convert
    *pA = 55;

    Node_t* pN0 = NULL;
    pN0 = (Node_t*)malloc(sizeof(Node_t));
    (*pN0).id = 1;
    (*pN0).name = 'a';

    Node_t* pN1 = NULL;                      //Same thing as above with different syntax
    pN0 = (Node_t*)malloc(sizeof(Node_t));
    pN1->id = 2;
    pN1->name = 'b';

    free(pA, pN0, pN1); //Free all the memory spots

    pA = pN0 = pN1 = NULL



    return 0;
}