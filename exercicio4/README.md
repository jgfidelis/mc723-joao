João Guilherme Daros Fidelis
RA 136242

Exercício 4

Na aplicação, criei um ponteiro volatile int para o endereço 0x6410000. Escolhi esse endereço pois ele é maior que 1024*1024*100, ou seja, o roteador fará com que valores escritos nesse endereço sejam enviados para o periférico.
É importante que a variável seja volátil pois isso garante que o valor da variável seja buscado da memória em toda leitura/escrita dela, não sendo armazenada em cache ou registrador. Assim, garantimos que sempre que tentemos utilizar essa variável, estaremos nos comunicando com o periférico.

No periférico, criei uma variável de classe privada, chamada valor. Essa variável é inicializada com zero no construtor, é modificada com o valor passado a ela no writedm e na leitura (em readm), ela é mudada para um.

Depois em main.cpp, instanciei o segundo processador, o inicializei e o conectei ao roteador.

Minha aplicação, que está em helloworld.c, computa um histograma a partir de uma string.

Cada core tem seu vetor de 26 posições (uma para cada letra do alfabeto), assim, após os dois acabarem, um core junta os dois histogramas e mostra o histograma final.