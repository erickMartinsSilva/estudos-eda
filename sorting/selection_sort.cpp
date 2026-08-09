// O programa ordena o array de cinco elementos [3, 5, 1, 4, 2] em ordem crescente utilizando do algoritmo de Selection Sort
#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
    int menor, aux;
    for(int i = 0; i < size; i++) {
        menor = i; // elemento i considerado o menor valor
        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[menor]) { // se houver um elemento j menor que o elemento i, o elemento j é o novo menor valor
                menor = j;
            }
        }
        if(menor != i) { // se houver mudança no menor valor, a troca é feita
            aux = arr[i];
            arr[i] = arr[menor];
            arr[menor] = aux;
        }
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[5] = {3, 5, 1, 4, 2};
    selectionSort(arr, 5);
    printArray(arr, 5);
    return 0;
}
