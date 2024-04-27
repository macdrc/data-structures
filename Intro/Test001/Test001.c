//#include <stdio.h>

typedef struct _point {  //struct allows you to make your own datatype
    double x;
    double y;
} Point;

typedef struct _point Point;  // learn what typedef is

typedef unsigned int uint32;

int add(int x, int y) {
    int result = x + y;
    return result;

}

int main(int argc, char**argv){
    Point a1;

    int a = 9;
    int b = 10;
    int c = add(a, b);
    uint32 d = 9;
    int size = sizeof(Point);

    return 0;
}