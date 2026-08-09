// algoritmo de busca binária implementado recursivamente
#include <iostream>
#define SIZE 10

using namespace std;

// função para imprimir o array formatado
void printArray(int arr[]) {
    cout << "[";
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE-1) {
            cout << arr[i] << "]" << endl;
        } else {
            cout << arr[i] << ", ";
        }
    }
}

// função de busca binária
bool binarySearch(int arr[], int inicio, int fim, int alvo) {
    int mid;

    if(inicio <= fim) {
        mid = (inicio+fim)/2;

        // condição de saída 1: número encontrado no array, seu índice é exibido no console e a função retorna true
        if(arr[mid] == alvo) {
            cout << "Número encontrado! Índice: " << mid+1 << endl;
            return true;
        } else if(arr[mid] < alvo) {
            return binarySearch(arr, mid+1, fim, alvo);
        } else {
            return binarySearch(arr, inicio, mid-1, alvo);
        }
    // condição de saída 2: todos os elementos foram analisados (início > fim) e o número não foi encontrado, função retorna false
    } else {
        return false;
    }
}

int main() {
    // declaração e exibição do array principal
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, alvo, resultado;
    printArray(arr);
    // escolha de um número para buscar no array pela entrada do usuário
    cout << "Insira um numero para buscar: ";
    cin >> alvo;

    resultado = binarySearch(arr,0,SIZE-1,alvo);
    // se o resultado da busca der falso, uma mensagem de erro é exibida no console
    !(resultado) && cout << "Número não encontrado" << endl;
}