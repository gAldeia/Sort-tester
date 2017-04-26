#include <stdio.h>
#include <iostream>
#ifndef _ORDENACAO_H

#define _ORDENACAO_H

namespace ED {
    
    // classe que contem os metodos de ordenação
    template <typename T>
    class Ordenacao {
        public:
            static void heapsort(T *vet, int n);
            static void quicksort(T *vet, int ini, int fim);
            static void mergesort(T *vet, int n);
        private:
            static void heapify(T *vet, int pai, int heapsize);
            static void m_sort(T *vet, T *aux, int esq, int dir);
            static void mergenator(T *vet, T *aux, int esq, int meio, int dir);
    };



    // abaixo o algoritmo de ordenação Heapsort
    template <typename T>
    void Ordenacao<T>::heapify(T *vet, int pai, int heapsize) {
        int fl, fr, imaior;
        fl = (pai << 1) + 1;
        fr = fl + 1;
        while (true) {
            if ((fl < heapsize) && (vet[fl] > vet[pai])) imaior = fl;
            else imaior = pai;
            if ((fr < heapsize) && (vet[fr] > vet[imaior])) imaior = fr;
            if (imaior != pai){
                T aux = vet[pai];
                vet[pai] = vet[imaior];
                vet[imaior] = aux;
                pai = imaior;
                fl = (pai << 1) + 1;
                fr = fl + 1;
            }
            else break;
        }
    }

    template <typename T>
    void Ordenacao<T>::heapsort(T *vet, int n) {
        int i;
        for (i=(n>>1)-1; i>=0; i--) heapify(vet, i, n);
        for (i=n-1; i > 0; i--) {
        T aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        heapify(vet, 0, i);
        }
    }
    
    
    
    // abaixo o algoritmo de ordenação Quicksort
    template <typename T>
    void Ordenacao<T>::quicksort(T *vet, int ini, int fim){
    
        if (fim<=ini)
            return;
    
        T pivo = vet[ (ini+fim)/2 ];
        int i = ini;
        int j = fim;
        T aux;
        
        while (i<=j){
            while (vet[j]>pivo) j--;
            while (vet[i]<pivo) i++;
            if (i<=j) {
                aux = vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
                i++;
                j--;
            }
        }
        
        if (ini<j)
            quicksort(vet, ini, j);
        if (i<fim)
            quicksort(vet, i, fim);
    }
    
    // abaixo o algoritmo do mergesort
    template <typename T>
    void Ordenacao<T>::mergenator(T *vet, T *aux, int esq, int meio, int dir) {
        int i, j, k;
        i = k = esq; j = meio+1;
        while ((i <= meio) && (j <= dir)) {
            if (vet[i] < vet[j]) aux[k++] = vet[i++];
            else aux[k++] = vet[j++];
        }
        while (i <= meio) aux[k++] = vet[i++];
        while (j <= dir) aux[k++] = vet[j++];
        while (esq<=dir) vet[esq] = aux[esq++];

    }

    template <typename T>
    void Ordenacao<T>::m_sort(T *vet, T *aux, int esq, int dir) {
        if (dir <= esq) return;
        int meio = (dir + esq) >> 1;
        m_sort(vet, aux, esq, meio); // Primeira chamada
        m_sort(vet, aux, meio+1, dir); // Segunda chamada
        if (vet[meio]<=vet[meio+1]) return;
        mergenator(vet, aux, esq, meio, dir); // Intercala as metades
    }

    template <typename T>
    void Ordenacao<T>::mergesort(T *vet, int n) {
        T *aux = new T[n]; // Alocação do vetor auxiliar
        m_sort(vet, aux , 0, n-1);
        delete aux;
    }
    
}
#endif
