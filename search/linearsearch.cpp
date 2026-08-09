// algoritmo de busca linear / sequencial para encontrar elementos em arrays não ordenados

#include <iostream>
#define SIZE 10

using namespace std;

void printArray(int arr[]) {
    cout << "[";
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE-1) {
            cout << arr[i] << "]" << endl;
        }
        else {
            cout << arr[i] << ", ";
        }
    }
}

bool linearSearch(int arr[], int alvo) {
    int i = 0;
    // loop for que percorre o array até o número ser encontrado ou até não houver mais elementos para analisar
    for(int i = 0; i < SIZE; i++) {
        if(arr[i] == alvo) {
            // exibe o índice do número e retorna true se ele for encontrado no array
            cout << "Número encontrado! Índice: " << i+1 << endl;
            return true;
        }
    }
    // retorna false se o número não for encontrado no array
    return false;
}

int main() {
    int alvo, resultado, array[SIZE] = {72, 39, 8, 56, 91, 23, 65, 4, 19, 88};
    // exibição do array
    printArray(array);
    // escolha de um número alvo para a busca
    cout << "Insira um numero para buscar: ";
    cin >> alvo;
    // busca pelo número alvo no array e armazena o resultado na busca numa variável
    resultado = linearSearch(array,alvo);
    // se o número não for encontrado no array, uma mensagem de erro é exibida no console
    !(resultado) && cout << "Número não encontrado" << endl;
    
    return 0;
}
