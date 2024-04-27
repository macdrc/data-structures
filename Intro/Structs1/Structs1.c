//return the distance from the origin for a point using structs
//how to use a structure as an argument
//how to access members inside an argument
#include <stdio.h>
#include <math.h>


typedef struct _point {
    int x;
    int y;
} Point;

int distance(Point point){
    return sqrt(point.x * point.x + point.y * point.y);
}

int main (int argc, char** argv){
    Point a1;
    a1.x = 9;
    a1.y = 20;
    printf("%d\n", distance(a1));
    return 0;
}