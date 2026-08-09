// programa que utiliza listas simplesmente encadeadas e simula um sistema utilizado num bistrô de forma simplificada para gerenciar o fluxo de clientes e seus consumos

#include <iostream>

using namespace std;

struct pedido {
    int codigo;
    struct pedido* prox;
};

struct cliente {
    int codigo;
    struct pedido* p;
    struct cliente* ant;
    struct cliente* prox;
};

typedef struct cliente* clientePtr;
typedef struct pedido* pedidoPtr;

// menu simples para escolher qual tarefa fazer a seguir
int menu() {
    int op;
    cout << "1. Registrar entrada de cliente\n2. Registrar consumo do cliente\n3. Registrar saída do cliente\n4. Sair" << endl;
    cin >> op;
    return op;
}

// verifica se a lista de clientes está vazia ao analisar o topo da lista
bool listaClientesVazia(clientePtr T) {
    if(T) {
        return false;
    } else return true;
}

// verifica se a lista de pedidos de um cliente está vazia ao analisar o topo da lista
bool listaPedidosVazia(pedidoPtr T) {
    if(T) {
        return false;
    } else return true;
}

// remove um cliente da lista
void removerCliente(clientePtr* T, clientePtr* F, clientePtr aux) {
    // se o cliente a ser removido for o topo da lista, o cliente seguinte é o novo topo e o cliente anterior ao novo topo é null
    if(aux == *T) {
        if((*T)->prox != NULL) {
            (*T)->prox->ant = NULL;
        }
        *T = (*T)->prox;
    // se o cliente a ser removido for o fim da lista, o cliente anterior é o novo fim e o cliente seguinte ao novo fim é null
    } else if (aux == *F) {
        if((*F)->ant != NULL) {
            (*F)->ant->prox = NULL;
        }
        *F = (*F)->ant;
    // se o cliente a ser removido estiver entre dois outros clientes:
    } else {
        // o próximo do cliente anterior ao removido passa a apontar para o próximo do cliente a ser removido
        if(aux->ant != NULL) {
            aux->ant->prox = aux->prox;
        }
        // o anterior do cliente seguinte ao removido passa a apontar para o anterior do cliente a ser removido
        if(aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }
    }
    // cliente é removido da lista
    delete aux;
}

// registra a chegada de um cliente além de atribuir um código de identificação a ele
void chegadaCliente(clientePtr* T, clientePtr* F) {
    clientePtr p = new cliente;
    // se a lista de clientes estiver vazia, o cliente é adicionado ao topo e recebe o primeiro código (100)
    if(listaClientesVazia(*T)) {
        p->codigo = 100;
        p->ant = NULL;
        p->prox = NULL;
        *T = p;
        *F = p;
    // se a lista não estiver vazia, o cliente é adicionado ao fim e recebe um código múltiplo de 100 com base no código do cliente anterior
    } else {
        (*F)->prox = p;
        p->ant = *F;
        p->prox = NULL;
        p->codigo = (p->ant->codigo + 100);
        *F = p;
    }
    // exibe mensagem de sucesso e código do cliente adicionado no console
    cout << "Cliente adicionado com sucesso! Codigo: " << p->codigo << endl;
}

// registra o consumo de um cliente por meio do código do produto consumido
void consumoCliente(clientePtr* T) {
    int codigo_cliente, codigo_pedido;
    // exibe uma mensagem de erro se a lista de clientes estiver vazia
    if(listaClientesVazia(*T)) {
        cout << "Erro! Nao ha clientes registrados" << endl;
    } else {
        cout << "Codigo do cliente: ";
        cin >> codigo_cliente;
        // cria uma variável auxiliar com base no topo da lista para percorrer a lista sem alterar o topo original
        clientePtr aux = *T;
        while(aux->prox != NULL && aux->codigo != codigo_cliente) {
            aux = aux->prox;
        }
        // se o cliente for encontrado, é criado um novo pedido e a variável aux2 é utilizada para percorrer a lista de pedidos do cliente
        if(aux->codigo == codigo_cliente) {
           pedidoPtr q = new pedido, aux2 = aux->p;
           // usuário atribui um código ao pedido
           cout << "Codigo do pedido: ";
           cin >> codigo_pedido;
           q->codigo = codigo_pedido;
           // se a lista de pedidos estiver vazia, o novo pedido será o topo da lista
           if(listaPedidosVazia(aux->p)) {
                aux->p = q;
           } else {
           // se a lista já houver elementos, ela é percorrida até o fim e o novo pedido é adicionado ao fim da lista
                while(aux2->prox != NULL) {
                    aux2 = aux2->prox;
                }
                aux2->prox = q;
                q->prox = NULL;
           }
           // exibe código do pedido e código do cliente que fez o pedido no console
           cout << "Pedido de codigo " << codigo_pedido << " adicionado com sucesso a lista do cliente de codigo " << codigo_cliente << endl;
        // se o cliente não for encontrado, exibe uma mensagem de erro
        } else cout << "Erro! Cliente nao encontrado" << endl;
    }
}

// registra a saída de um cliente, exibindo o código dos produtos que consumiu
void saidaCliente(clientePtr* T, clientePtr* F) {
    // exibe uma mensagem de erro no console caso a lista de clientes esteja vazia
    if(listaClientesVazia(*T)) {
        cout << "Erro! Nao ha clientes registrados" << endl;
    } else {
        // a variável aux é utilizada para percorrer a lista de clientes sem alterar o topo original
        clientePtr aux = *T;
        int codigo_cliente;

        cout << "Codigo do cliente: ";
        cin >> codigo_cliente;

        // verifica o código informado e busca a lista pelo código
        while(aux->prox != NULL && aux->codigo != codigo_cliente) {
            aux = aux->prox;
        }
        // se seu código for encontrado, seu consumo é exibido, removido e o cliente é removido da lista de clientes
        if(aux->codigo == codigo_cliente) {
            // remove o cliente sem exibir consumo se ele não houver feito nenhum pedido
            if(listaPedidosVazia(aux->p)) {
                removerCliente(T,F,aux);
            } else {
                // exibe os códigos de pedidos feitos pelo cliente, removendo suas entradas e depois, removendo o cliente da lista de clientes
                cout << "Consumo do cliente de codigo " << aux->codigo << ": ";
                pedidoPtr aux2 = aux->p, ant;
                while(aux2 != NULL) {
                    cout << aux2->codigo << " ";
                    ant = aux2;
                    aux->p = aux->p->prox;
                    aux2 = aux2->prox;
                    delete ant;
                }
                removerCliente(T,F,aux);
                cout << "\nCliente removido com sucesso" << endl;
            }
        // exibe uma mensagem de erro no console se o cliente não for encontrado na lista
        } else cout << "Erro! Cliente nao encontrado" << endl;
    }
}  

int main() {
    // declaração do topo e fim da lista de clientes
    clientePtr T = NULL, F = NULL;
    int op;
    do {
        switch(op = menu()) {
            case 1: chegadaCliente(&T, &F); break; // registra chegada do cliente
            case 2: consumoCliente(&T); break; // registra consumo do cliente
            case 3: saidaCliente(&T, &F); break; // registra saída do cliente
            default: break;
        }
    // encerra o programa se a opção 4 (sair) for escolhida
    } while(op != 4); 
    return 0;
}