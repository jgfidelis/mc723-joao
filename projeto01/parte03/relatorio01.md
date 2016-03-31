# Relatório Projeto 1
### João Guilherme Daros Fidelis
### RA 136242
## Introdução

Neste projeto, diversos grupos escolheram diferentes aplicações para desenvolverem benchmarks, isto é, recordar o desempenho dessas aplicações em diferentes computadores com o objetivo de avaliar as melhores máquinas.

## Condições Experimentais

Eis a lista de máquinas, seus donos e suas especificações:

Número   | Nome do Dono | Especificações
:------: | :------------: | :------------------------------:
3 |	Mateus Ruivo |	Intel(R) Core(TM) i3-3110M CPU @ 2.40GHz 3072 KB Cache, 4GB RAM DDR3, 5400rpm SATA
4|	Pedro Meireles|	Intel® Core™ i5-4590 CPU @ 3.30GHz × 4;  Memory 8 GiB;  64-bit graph: Intel® Haswell Desktop , Gnome: Version 3.18.2; Disk 216.9 GB; Fedora 23
5|	Klaus Rollman|	Intel(R) Core(TM) i7-3610QM CPU 4 cores, 8 threads @ 2.30GHz @ L1 256 KB / L2 1024 KB / L3 6144 KB
6|	yk0 - Yugo Kuno	|AMD PhenonII, 4 cores, 3.2MHz; 10GB, ddr3, 1.333 MHz; hdd sata3, 7200rpm, 32MB buffer
7|	Cygnus X-1|	Intel® Core™ i7 × 4;  Memory 8 GiB;  
8	|Luiz Sekijima|	Intel® Core™2 Duo CPU T6500 @ 2.10GHz × 2, 4GB RAM
9	|IC-legiao|	Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43 
10	|Renan Gomes|	Intel® Core™ i7-4702MQ CPU @ 2.20GHz × 8 (64 bits) Memory 8 GiB; Graphics Intel® Haswell Mobile ; Ubuntu 14.04
11	|Bruno Hori - Mamonas|	Intel(R) Core(TM)2 Quad CPU    Q8400  @ 2.66GHz
12	|debios|	 Intel(R) Core(TM) i7-3612QM CPU @ 2.10GHz x 4, 8 threads, 8GB, 64-bit, SSD 32GB, HDD1TB (5400rpm), Debian
13	|Gabriel Bueno|	Intel(R) Core(TM) i7-4510U CPU @ 2.00GHz x 2, 4 threads, 64-bit; Memory 8 GB DDR3; HD SATA 5400rpm;Ubuntu  15.10
14	|Renan Castro|	Intel(R) Core(TM) i7-3740QM CPU @ 2.70GHz @ 2 CORES @ Virtual Machine
15	|Gabriel Magalhães|	Intel® Core™ i7-3612QM CPU @ 2.10GHz × 8; Memory 8GB, SSD Kingston 240GB V300 Sata III;  Ubuntu 15.04 
16	|Victor Souza|	Intel(R) Core(TM)2 Quad CPU Q8400  @ 2.66GHz; Memory 4GB, Fedora release 21
17	|IC301-Titan|	Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43, 3.8GB RAM
18	|João Fidélis|	Intel Core i7-Intel(R) Core(TM) i7-4700HQ CPU @ 2.40GHz x 4, 16GB DDR3, Ubuntu 14.04LTS, HD: WD10S21X-24R1BTO / 7200RPM / Sata III
19	|floyd|	Intel(R) Core(TM)2 Quad CPU    Q8400  @ 2.66GHz, Memory 4GB
20	|Rodrigo Silva|	Intel(R) Core(TM) i5-2450M @ 2.5GHZ; Memory 6GB
21|	IC-sepultura|	Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43 × 3.8GB RAM
22	|Pedro Grijó|	Intel(R) Core(TM) i7-2670QM CPU @ 2.20GHz x4, 8GB DDR 1333Mhz ,Ubuntu 14.04LTS 32bits,HDD: SAMSUNG HN-M101MBB / 5400 RPM/ Sata III
23|	Pedro Vasconcellos|	Raspberry Pi, 900MHz quad-core ARM Cortex-A7 CPU, 1GB RAM, 32GB SD Card
24|	Wendrey	|Intel Core i5-5200U CPU 2.20GHz x 4 L1 32KiB L2 256KiB L3 3MiB Memory 8GiB DDR3 Disk 1TB WDC WD10JPVX-22J Ubuntu 14.04 LTS
25	|Matheus Figueiredo	|Intel Core i7-4700HQ CPU @ 2.4GHz, 16GB DDR3, Ubuntu 14.04LTS, HDD 5400RPM
26	|Titouan Thibaud|	Intel® Core™ i5-4590 CPU @ 3.30GHz × 4;  Memory 8 GiB;  64-bit graph: Intel® Haswell Desktop , Gnome: Version 3.18.2; Disk 216.9 GB; Fedora 23
27	|Titouan Thibaud|	Intel Core i7-2630QM CPU @2.00GHz Memory 4GiB Linux Mint
28|	Rafael Faria|	Intel(R) Core(TM) i7-4750HQ CPU @ 2.00GHz; Memory 8 GB 1600 MHz DDR3; Mac OS X El Capitan (version 10.11.4)
29|	João Paulo|	Intel(R) Core(TM) i7-4510U CPU @ 2.00GHz; Memory 16 GB; Ubuntu 14.04.4
30|	Matheus Pinheiro|	Intel® Core™ i5-4200U CPU @ 1.60GHz × 4 ; Memory 3,8 GiB; Ubuntu 15.04 64-bit; 
31|	Gustavo Basso|	Intel Core i7 @ 2.3GHz; 8 GB 1600 MHz DDR3
32|	Netbook - Felipe Emos|	Intel Atom Processor D4xx/D5xx/N4xx/N5xx DMI Bridge

## Metodologia de Pesquisa

Cada pessoa foi colocada num grupo e teria que rodar e anotar os valores de três benchmarks em uma planilha, para depois compararmos os desempenhos.

Eis os benchmarks e o que medem:

Grupo   | Benchmark | Medições
:------: | :------------: | :----------:
1 | Genetic | Tempo de execução e tempo de escrita no disco
2 | ffmpeg | Tempo de execução, page faults, stalled cycles e misses na cache L1
3 | convolução | Tempo de execução, tempo de escrita no disco e tempo de leitura no disco
4 | gnuplot | Tempo de execução, CPU clocks, mem-stores e bus-cycles
5 | ordenação | Tempos de execução para BubbleSort  e tempos de execução para QuickSort
6 | imagemagick | Tempo de execução, task clock, ciclos e instruções
7 | tcc | Tempo de execução
8 | fftw | Tempo de execução com diferentes entradas

## Análise de Resultados

### Genetic

![Benchmark1](/imagens/genetic-both.png "Fig 1")

Como podemos ver, tirando a Raspberry Pi do Pedro, todas as outras máquinas tiveram desempenho de tempo de execução muito semelhantes. O tempo de escrita em disco variou um pouco mais que entre os computadores, com as medições ficando entre 50 MB/s e 100MB/s, excluindo a placa Raspberry Pi.
Como podemos ver, a melhor performance ficou com o Pedro Meireles, o que pode ser explicado pelo seu processador Intel i5 com clock em 3.3GHz, que superou outros Intel i7 (de uma nova geração) mas que tem clocks menores (por volta de 2.4GHz). a placa Raspberry Pi era de se esperar ao ficar em último, pois seu processador é muito mais simples, com clock de 900MHz. O computador do Luiz Sekijima, o segundo pior, também apresenta um clock abaixo da média, em torno de 2.1GHz, o que mostra uma correlação com a frequência do clock do processador com o tempo de execução, o que faz sentido.
Não podemos avaliar muito os desempenhos de disco pois poucas pessoas colocaram seus HDs na planilha.

### ffmpeg

![Benchmark2](/imagens/ffmpeg-time.png "Fig 2")

Mais uma vez, os processadores mais potentes, com mais clock, se saíram melhores, o melhor sendo um Intel i7-4700HQ @ 2.4GHz o melhor. Já o Intel Core 2 Duo @ 2.1GHz foi o pior. É importante ressaltar que essa aplicação utiliza processamento paralelo, o que beneficiou os processadores com mais núcleos e threads, que são os mais modernos.

![Benchmark3](/imagens/ffmpeg-pagefaults.png "Fig 3")
![Benchmark4](/imagens/ffmpeg-cachemisses.png "Fig 4")

Vemos que não há muita relação com o número de cache miss e pagefaults com o desempenho. Vemos que o João Fidelis, que teve o melhor desempenho de tempo, teve um dos maiores índices de cache miss e page fault, o que indica que uma boa arquitetura (como bom HD e um processador moderno) conseguem superar esses atrasos.



### tcc

![Benchmark5](/imagens/tcc-time.png "Fig 5")

Esse resultado foi bastante interessante, os dois melhores computadores são Intel Core i7 com clocks de 2.4GHz e 2.2GHz. Já os três piores tem processadores Intel Core 2 Quad com 2.66GHz de clock. Apesar do clock maior, processadores mais antigos se saíram muito piores.

### Convolução

![Benchmark6](/imagens/convolucao-time.png "Fig 6")

Os tempos ficaram próximos, com exceção dos útlimos. O Victor Souza tem um processador que não é muito novo e o Renan Castro está rodando o SO numa máquina virtual, o que pode explicar esse tempo maior, apesar de ter um processador mais novo.

### Gnuplot

![Benchmark7](/imagens/gnuplot-time.png "Fig 7")

Mais uma vez a Raspberry Pi se saiu a pior máquina, o que é compreensível, tendo em vista suas claras limitações de processamento.
O Pedro Grijo colocou dados errados na planilha e por isso seu tempo ficou muito menor se comparado com os outros. Outros que se saíram mal, também tem processadores piores, como o Matheus Pinheiro com um Intel Core i5 @ 1.6GHz e e o Felipe Emos que tem um Intel Atom.

### Ordenação

![Benchmark8](/imagens/ordenacao-bubble.png "Fig 8")
![Benchmark9](/imagens/ordenacao-quick.png "Fig 9")

Vemos mais uma vez os processadores mais potentes e novos com mais velocidade. É interessante notar como o algoritmo faz muita diferença, já que o BubbleSort, conhecido pela simplicidade, tem uma grande diferença entre as médias do pior caso com as médias do melhor caso, enquanto o QuickSort teve médias semelhantes.

### Imagemagick

![Benchmark10](/imagens/imagemagick-time.png "Fig 10")
![Benchmark11](/imagens/imagemagick-inst.png "Fig 11")

É notável como os tempos variaram de iteração para iteração. Também podemos ver que quanto maior o IPC menor o tempo de execução, o que faz muito sentido, já que executando mais instruções por ciclo, mais comandos conseguem ser processador mais rápido.

### FFTW

![Benchmark12](/imagens/fftw-time.png "Fig 12")

Achei estranho o fato de em quase todos a execução com parâmetro de 3.000.000 ter sido maior que a de 70.000.000 com exceção do Mateus Ruivo que deu muito maior o de 70.000.000. O alto desvio padrão da amostra do Mateus indica, talvez, que em alguma execução ocorreu algo de diferente que aumentou o tempo de execução daquela amostra específica, como a média está sendo feita com apenas 5 execuções, uma fora do padrão pode fazer muita diferença.

### Conclusão

Concluímos que os processadores mais novos tem um desempenho melhor em várias aplicações, sendo afetados principalmente, pelo frequência do clock e outros detalhes que não tivemos muito acesso como tamanho da cache, etc. Notamos que a maior diferença apareceu na aplicação FFMPEG que se utilizou de processamento paralelo, uma tendência no mercado, e que é bastante afetada por processadores com mais núcleos e threads (geralmente, mais novos).
É importante ressaltar que nesses testes havia muitas variáveis como integração de diferentes componentes do computador (diferentes fabricantes de memória RAM ou HD, por exemplo), diferentes SO, não sabemos se a pessoa rodou a aplicação com o computador executando outras tarefas. Assim, os resultados não são tão precisos, mas dão indícios claros que processadores mais modernos tem desempenhos melhores.