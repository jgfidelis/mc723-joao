# Exercício 02
## João Guilherme Daros Fidelis
## RA 136242

Utilizei o trace *176.gcc.f2b*.

### Cache L1

Primeiro, tentamos achar uma versão otimizada para a cache L1.

![Grafico1](/exercicio2/imagens/miss-x-cachesize.png "Fig 1")

Neste gráfico, vemos o desempenho do miss rate para cache de instrução e de dados, de acordo com o crescimento do tamanho total da cache. Se o tamanho é de 64K, então estava sendo utilizado 32K para instrução e 32K para dados.

Noto que estava usando o valor de 16 bytes para o tamanho de bloco de ambas as caches. Todas as outras opções como associatividade, getch policy, etc, foram deixadas o default.

Fiz apenas até 64KB no total pois apesar de continuar havendo ganho para caches maiores, 64KB já é um valor bem grande para uma cache L1 no mercado atual, não vi sentido em colocar valores que no mercado não serão utilizados.

Depois, fixamos o tamanho total em 64KB e variamos apenas o tamanho do bloco.

![Grafico2](/exercicio2/imagens/miss-x-block-l1.png "Fig 2")

Vemos que começamos em 16 bytes e obtivemos ganho até 128. De 128 para 256 já aumentou o miss rate na cache de dado. Novamente, os testes foram realizados com outros valores como associatividade e fetch policy no padrão.

Então, fixamos o tamanho de bloco em 128 para ambos e variamos a associatividade.

![Grafico3](/exercicio2/imagens/miss-x-assoc-l1.png "Fig 3")

Primeiramente, o valor da associatividade não fez diferença na cache de instruções, que manteve desempenho quase constante (variando entre 0.0068 e 0.0067), por isso não foi colocado no gráfico. Com esse gráfico, notamos que o miss rate decai a medida que a associatividade cresce, até associatividade 12 onde há um ganho no miss rate em relação a associativade 8. Logo, o melhor valor para associatividade foi 8.

Finalmente, também fixamos a associatividade em 8 para ambas as caches e variamos a fetch policy.

![Grafico4](/exercicio2/imagens/miss-x-fetch-l1.png "Fig 4")

Vemos que o melhor desempenho foi da Subblock.

Também checamos o desempenho para diferentes replacement policy.

![Grafico5](/exercicio2/imagens/miss-x-repl-l1.png "Fig 5")

Vemos que o melhor desempenho ocorreu com a LRU.

Então, chegamos o melhor desempenho da cache L1 foi obtido com tamanho total 64KB (32KB de instrução e 32KB para dados), tamanho de bloco de 128 bytes para a cache de dados e 256 para cache de bloco, associatividade 8 para ambas, fetch policy de Subblock e replacement policy de LRU.

### Cache L2

![Grafico6](/exercicio2/imagens/miss-x-totalcache-l2.png "Fig 6")

Mais uma vez, assim como na L1, quanto maior o tamanho da cache, menor o miss rate. Porém, limitei o valor para 2MB total (1MBpara cada), pois ja seria um valor muito grande para o mercado.

Como 2MB seria muito grande, fixei o valor em 1MB no total (512KB para cada).

![Grafico7](/exercicio2/imagens/miss-x-block-l2.png "Fig 7")

Nesse gráfico, vemos que o tamanho de bloco não importou para valores baixos na cache de instruções. Vemos que no valor de 2MB houve piora no desempenho em relação a 1MB para cada.

Com base nisso, fixei o valor ddo tamanho de bloco para dados e instruções em 1MB.

![Grafico8](/exercicio2/imagens/miss-x-assoc-l2.png "Fig 8")

Vemos mais uma vez que houve perda de desempenho do 12 para 8 na cache de dados.

Fixamos então o valor da associatividade para 8 em ambas.

![Grafico9](/exercicio2/imagens/miss-x-fetch-l2.png "Fig 9")

Pelo gráfico, o melhor foi o subblock.

Grafico 9 replacement policy

![Grafico10](/exercicio2/imagens/miss-x-repl-l2.png "Fig 10")

Vemos novamente que o melhor foi o LRU.

A melhor configuração para a cache L2 ficou em tamanho total 1MB, com 512KB para dados e instrução, tamanho de bloco em 1MB para ambas, associatividade em 8 para ambas, fetch policy em subblock para ambas e replacement policy em LRU para ambas.