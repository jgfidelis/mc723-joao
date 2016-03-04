João Guilherme Daros Fidelis
========================
###Exercício Um
###Testando o primo.c
Compilando o arquivo primo.c com flags e sem flag:

Todos os tempos nesse relatório foram obtidos pelo comando time. (Exemplo: time ./primo e pegando o valor especificado em **real**).
Tempos
----------
Flag   | First Run (ms) | Second Run (ms) | Third Run (ms) | Average (ms)
------ | :------------: | :-------------: | :------------: | :----------:
Nada   |     302        | 377             | 315            | 331
O0   |     418        | 297             | 297            | 337
O1   |     260        | 326             | 329            | 305
O2   |     295        | 287             | 391            | 324
O3   |     292        | 294             | 369            | 318

A flag -O1 foi a que se saiu melhor.

Mtune faz com que o gcc compile o código otimizando-o à arquitetura do processador especificado.
Na máquina do IC tempos um Intel Core i5.

Flags testadas, por exemplo, -mtune=core2 e compilados sem nenhuma flag de otimização -Ox junto:
Flag   | First Run (ms) | Second Run (ms) | Third Run (ms) | Average (ms)
------ | :------------: | :-------------: | :------------: | :----------:
core2   |     402        | 297             | 305            | 335
native   |     411        | 317             | 339           | 355
intel   |     276        | 334             | 386            | 332
corei7   |     407        | 397             | 297            | 367

Nenhuma flag de mtune deu algum resultado melhor que o compilado sem nada.

###Separando em dois fontes
Os arquivos foram separados em **calcPrimo.c** e **primoMain.c.**
Os arquivos foram compilados com o makefile e o script.
Após separar o arquivo em dois e compilar **sem** flag nenhuma: 
Número de Fontes | First Run (ms) | Second Run (ms) | Third Run (ms) | Average (ms)
 :------------: | :-------------: | :------------: | :----------: | :------:
    2        | 355             | 359            | 354     | 356
  
Após compilar os dois com a flag -O1:
Número de Fontes | First Run (ms) | Second Run (ms) | Third Run (ms) | Average (ms)
 :------------: | :-------------: | :------------: | :----------: | :------:
    2        | 262             | 359            | 326     | 315


A média mostra que separar os arquivos torna o programa mais devagar, se compararmos com o tempo do programa de fonte único que foi de 305ms (com -O1), como esperado, pois acredito que fica mais complexo para o compilador. Mas as amostras são pequenas para dizer algo significativo.

###Calculando de 1 a N números primos
Compilei sem nenhuma flag de otimização.

Valores obtidos com um fonte e dois fontes e o valor de N testado (cem mil).

N   | Número de Fontes | First Run (s) | Second Run (s) | Third Run (s) | Average (s)
------ | :------------: | :-------------: | :------------: | :----------: | :------:
100000   |     2        | 1.34             | 1.35            | 1.36     | 1.35
100000   |     1        | 1.25             | 1.227           | 1.222    | 1.233


Um arquivo fonte continua mais rápido como demonstrado anteriormente, agindo como esperado.

###Melhorando um pouco o programa
Após fazer o programa somente verificar números ímpares, ao compilarmos sem nenhuma flag de otimização temos os tempos:
N   | Número de Fontes | First Run (s) | Second Run (s) | Third Run (s) | Average (s)
------ | :------------: | :-------------: | :------------: | :----------: | :------:
100000   |     2        | 1.291             | 1.188            | 1.197     | 1.22
100000   |     1        | 1.232             | 1.246           | 1.120    | 1.196


###Usando o gprof
Segundo o gprof, com N= 100000, a função primo é chamada 49999 vezes e é responsável por 100% do tempo do programa (como esperado). Em média, ela demora 26.29us para ser executada.

###Paralelizando
Se eu pudesse paralelizar o código, eu paralizaria a função primo, pois cada chamada é independente da outra e não há nenhuma dependencia entre elas, logo, podem ser executadas em paralelo e enquanto um core checa se i é primo, outro pode checar se i+2 é primo sem problema algum.

Após adicionar a linha **"#pragma omp parallel for"** antes do for e **"#pragma omp atomic"** onde a variável do total de primos é somada, ao compilarmos sem flag de otimização, apenas com a flag do openmp e com um arquivo fonte,:
N   | Número de Fontes | First Run (s) | Second Run (s) | Third Run (s) | Average (s)
------ | :------------: | :-------------: | :------------: | :----------: | :------:
100000   |     1        | 0.603             | 0.598            | 0.609     | 0.603

Vemos que tivemos um ganho de quase 2x o que é ótimo.

Após compilarmos com "gcc -o primo primo.c -O1 -fopenmp" e rodando "time ./primo 100000", os tempos ficaram:
N   | Número de Fontes | First Run (s) | Second Run (s) | Third Run (s) | Average (s)
------ | :------------: | :-------------: | :------------: | :----------: | :------:
100000   |     1        | 0.506             | 0.519            | 0.531     | 0.518

###O que melhorar
Podemos melhorar ainda mais o desempenho do programa utilizando uma maneira mais eficiente para descobrir se um número é primo ou não, que não seja a maneira trivial apresentada no código original.
