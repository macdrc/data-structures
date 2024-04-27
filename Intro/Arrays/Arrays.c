#include <stdio.h>

int main(int argc, char** argv){

    float samples01[] = {12, 16, 2.4f, 25};
    float samples02[4];

    samples02[0] = samples01[0];
    
    int count1 = sizeof(samples01)/sizeof(float);
    int count2 = sizeof(samples02)/sizeof(float);

    for(int ix; (ix < count1) && (ix < count2); ++ix) {  //a while loop is a for loop without something in the middle
        samples02[ix] = samples01[ix];
    }

    return 0;
}