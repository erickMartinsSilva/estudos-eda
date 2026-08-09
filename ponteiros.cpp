// Exemplo do funcionamento de ponteiros e suas possíveis saídas
#include <iostream>

using namespace std;

int main() {
    // declaração de uma variável de tipo inteiro (a) e um variável de tipo ponteiro para inteiro (*p)
    int a, *p;

    cout << "*p é um ponteiro para inteiro que aponta para o inteiro a\n" << endl;

    a = 30;
    p = &a; // o ponteiro p aponta para o endereço da variável a

    cout << "Valor de a: " << a << endl; // exibe o valor de a no console (30)
    cout << "Valor de *p: " << *p << endl; // exibe o valor da variável que o ponteiro *p aponta (30)
    cout << "Valor de &a: " << &a << endl; // exibe o endereço de memória onde a variável a está armazenada
    cout << "Valor de p: " << p << endl; // exibe o endereço de memória que o ponteiro *p aponta (nesse caso, o endereço de memória de a)
    cout << "Valor de &p: " << &p << endl; // exibe o endereço de memória onde o ponteiro *p está armazenado 

    // operadores de desreferenciação de ponteiros, exibindo o endereço de memória que o ponteiro *p aponta (endereço de a)
    cout << "Valor de &*p: " << &*p << endl; 
    cout << "Valor de *&p: " << *&p << endl;
}