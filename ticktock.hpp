#include <stdlib.h>
#include <time.h>

using namespace std;

//Simple functions to measure the time of execution.
//To use:
//	-Start the timer with tick();
//	-Get the time since the tick() call with tock().

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
