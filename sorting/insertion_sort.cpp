// O programa ordena o array de cinco elementos [3, 5, 1, 4, 2] em ordem crescente utilizando do algoritmo de Insertion Sort
#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    int j, key, aux;
    for(int i = 1; i < size; i++) { // for começa do 1 pois o primeiro elemento é considerado como já organizado
        key = arr[i]; // valor arr[i] considerado como chave
        j = i-1;
        while(j >= 0 && arr[j] > key) { // move o valor chave para a posição correta enquanto houver valores maiores que o antecedem
            aux = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = aux;
            j--;
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
    insertionSort(arr, 5);
    printArray(arr, 5);
    return 0;
}
