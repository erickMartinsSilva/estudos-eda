// O programa ordena o array de cinco elementos [3, 5, 1, 4, 2] em ordem crescente utilizando do algoritmo de Bubble Sort
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    int aux;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) { // segundo for passa por todos os elementos posteriores a i
            if(arr[i] > arr[j]) { // se o elemento i for maior que o elemento posterior j, eles trocam de lugar
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
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
    bubbleSort(arr, 5);
    printArray(arr, 5);
    return 0;
}
