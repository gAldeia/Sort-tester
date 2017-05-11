#include "ordenacao.hpp"
#include "ticktock.hpp"

#include <iostream>
#include <random>

#include <time.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>

using namespace std;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void randomizer (float *v, int n, mt19937 rng, uniform_int_distribution <int32_t> uidist){

    for (int i=0; i<n; i++){
        v[i]=uidist(rng);
    }
}

int main() {
    int tmili;

    int seed[6] = {4, 81, 151, 1601, 2307, 4207};
    int qte[9] = {10000, 30000, 90000, 270000, 810000,
                  2430000, 7290000, 21870000, 65610000};
	string alg[5] = {"HeapSort: ", "QuickSort: ", "MergeSort: ", "SortC++: ", "QuickSortC: "};

    float *v = new float[65610000];

    uniform_int_distribution <int32_t> uidist;
    mt19937 rng;

    for(int k=0; k<5; k++){
        cout << alg[k] << endl;
        
        for(int i=0; i<6; i++){ // casos sementes

            rng.seed(seed[i]);
            //cout << "Para seed " << seed[i] << endl;

            for (int size=0; size<9; size++){ // casos numero s de elementos
                int n = qte[size];



                randomizer (v, n, rng, uidist);

                switch (k){
                    case 0: //calculo do tempo heapsort

                        tick();
                        ED::Ordenacao<float>::heapsort(v, n-1);
                        tmili = tock();
                        cout << tmili << ", ";
                        break;

                    case 1: //calculo do tempo quicksort

                        tick();
                        ED::Ordenacao<float>::quicksort(v, 0, n-1);
                        tmili = tock();
                        cout << tmili << ", ";
                        break;

                    case 2: //calculo do tempo mergesort

                        tick();
                        ED::Ordenacao<float>::mergesort(v, n);
                        tmili = tock();
                        cout << tmili << ", ";
                        break;


                    case 3: //calculo do tempo sort c++

                        tick();
                        sort(v, v+qte[size]);
                        tmili = tock();
                        cout << tmili << ", ";
                        break;

                    case 4: //calculo do tempo quicksort c

                        tick();
                        qsort (v, n, sizeof(float), cmpfunc);
                        tmili = tock();
                        cout << tmili << ", ";

                        break;

                    default:
                        cout << "SWITCH NAO SELECIONOU UM CASO!!!" << endl;
                        break;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    delete v;
}
