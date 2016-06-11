João Guilherme Daros Fidelis
RA 136242

Exercício 4

Na aplicação, criei um ponteiro volatile int para o endereço 0x6410000. Escolhi esse endereço pois ele é maior que 1024*1024*100, ou seja, o roteador fará com que valores escritos nesse endereço sejam enviados para o periférico.

No periférico, criei uma variável de classe privada, chamada valor. Essa variável é inicializada com zero no construtor, é modificada com o valor passado a ela no writedm e na leitura (em readm), ela é mudada para um.

Depois em main.cpp, instanciei o segundo processador, o inicializei e o conectei ao roteador.

Minha aplicação, que está em helloworld.c, faz a soma de um vetor.

(Tentei fazer uma aplicação mais complexa mas tive muitos erros, suspeito que de memória. Não da para debuggar com printf pois ele causa problemas no código, ou da crash ou o programa trava.)