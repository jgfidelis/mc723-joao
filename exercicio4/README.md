João Guilherme Daros Fidelis
RA 136242

Exercício 4

Na aplicação, criei um ponteiro volatile int para o endereço 0x6410000. Escolhi esse endereço pois ele é maior que 1024*1024*100, ou seja, o roteador fará com que valores escritos nesse endereço sejam enviados para o periférico.
É importante que a variável seja volátil pois isso garante que o valor da variável seja buscado da memória em toda leitura/escrita dela, não sendo armazenada em cache ou registrador. Assim, garantimos que sempre que tentemos utilizar essa variável, estaremos nos comunicando com o periférico.

No periférico, criei uma variável de classe privada, chamada valor. Essa variável é inicializada com zero no construtor, é modificada com o valor passado a ela no writedm e na leitura (em readm), ela é mudada para um.

Depois em main.cpp, instanciei o segundo processador, o inicializei e o conectei ao roteador.

A aplicação paralela está no arquivo paralelo.c, a versão serial, está em serial.c

Cada core tem seu vetor de 26 posições (uma para cada letra do alfabeto), assim, após os dois acabarem, um core junta os dois histogramas e mostra o histograma final.

Resultados:

Para uma string com tamanho de 1412554, a versão serial levou 1.523s, 1.505s e 1.515s, com uma média de 1.514. Já a versão paralela, após três execuções, levou 0.832s, 0.827s e 0.844s, dando uma média de 0.834s.
Assim, obtivemo um speedup médio de 1.82. Esse valor é quase dois, o que faz sentido, visto que na versão paralela temos 2x mais núcleos que na versão serial.

Ambos mostraram a resposta correta de:
115258 66924 70642 11154 89232 107822 66924 111540 40755 44616 48334 18590 14872 44616 66924 18590 78078 14872 40898 33462 29744 63206 81653 11154 89232 33462


