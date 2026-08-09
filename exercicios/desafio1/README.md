Exercício 1

Nesta parte do desafio, temos um cenário fictício onde precisamos gerenciar a entrada e consumo de clientes no bistrô L'Art Culinaire. Para isso, deve-se utilizar uma lista duplamente encadeada (esta será a lista de clientes) junto de listas simplesmente encadeadas (está será a lista de consumo de um cliente, ou seja, cada cliente terá sua própria lista).

Precisamos implementar três funções neste exercício:
- Adicionar cliente: Essa função adiciona um nó ao fim da lista duplamente encadeada e associa um código ao nó, sendo ele sempre de 100 em 100.
- Registrar consumo do cliente: Essa função acessa a lista simplesmente encadeada de um determinado cliente e adiciona um nó ao fim dela.
- Excluir cliente: Essa função lista todo o consumo de um cliente, remove os nós da lista simplesmente encadeada um por um e depois remove o nó cliente da lista duplamente encadeada. Se a lista de consumo do cliente estiver vazia, o nó cliente é removido da lista.