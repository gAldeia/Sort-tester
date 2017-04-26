#include <stdlib.h>
#include <time.h>

using namespace std;

struct tempo{
    int start;
    
};

struct tempo t;

void tick(){
    t.start = clock();
}

int tock(){
    return (int)((clock()-t.start)*1000/CLOCKS_PER_SEC);
}