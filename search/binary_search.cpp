// algoritmo de busca binária para encontrar elementos num array ordenado

#include <iostream>
#define SIZE 10

using namespace std;

void printArray(int array[]) {
    cout << "[";
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE-1) {
            cout << array[i] << "]" << endl;
        }
        else {
            cout << array[i] << ", ";
        }
    }
}

// algoritmo de busca que consiste em divisões sucessivas de um array para encontrar um elemento específico
bool binarySearch(int array[], int alvo) {
    int esq = 0, dir = SIZE-1, mid;
    // loop while repete o processo até o número ser encontrado ou não houver mais elementos para analisar
    while(esq <= dir) {
        mid = (esq+dir)/2;

        if(array[mid] == alvo) { 
            // se o número for encontrado, seu índice é exibido no console e a função retorna true
            cout << "Número encontrado! Índice: " << mid+1 << endl;
            return true;
        } else if (array[mid] < alvo) {
            // desconsidera a parte esquerda do array, devido ao alvo ser maior que o valor do meio, e refaz a busca
            esq = mid+1;
        } else {
            // desconsidera a parte direita do array, devido ao alvo ser menor que o valor do meio, e refaz a busca
            dir = mid-1;
        }
    }
    // retorna false se o número não for encontrado
    return false; 
}

int main() {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, alvo, resultado;
    // exibição do array inicial no console
    printArray(array); 
    // definição de um número a ser buscado pela função binarySearch
    cout << "Insira o numero que deseja buscar no array: ";
    cin >> alvo; 
    // execução da função binarySearch para buscar o alvo no array
    resultado = binarySearch(array,alvo);
    // exibe uma mensagem de erro na tela caso o número não tenha sido encontrado
    !(resultado) && cout << "Número não encontrado" << endl;
    
    return 0;
}