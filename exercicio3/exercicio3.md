# Exercício 3
## João Guilherme Daros Fidelis
## RA 136242

### Hellow World

Fiz um programa simples, que apenas imprimia "Hello World" na tela pelo comando printf.

Adicionei um contador a ser incrementado na função ac_behavior(add) e que é printado em ac_behavior(end).

Ao mandar o simulador executar o hello.mips, vemos que não houve nenhuma chamada para a função add, o que é esperado pois nenhuma soma é feita no programa.

Após isso, para tentar fazer a função add aparecer, coloquei as linhas (após o printf):

    int a = 2;
    int c = -1;
    int b = 0;
    b = a + c;

Ao simularmos esse novo hello.mips, vemos que ainda nenhuma função de add foi chamada. Investigando a saída do objdump vemos:

    00000128 <main>:
     128:   27bdffd8    addiu   sp,sp,-40
     12c:   afbf0024    sw  ra,36(sp)
     130:   afbe0020    sw  s8,32(sp)
     134:   03a0f021    move    s8,sp
     138:   3c020000    lui v0,0x0
     13c:   24446cf0    addiu   a0,v0,27888
     140:   0c0000b7    jal 2dc <puts>
     144:   00000000    nop
     148:   24020002    li  v0,2
     14c:   afc20010    sw  v0,16(s8)
     150:   2402ffff    li  v0,-1
     154:   afc20014    sw  v0,20(s8)
     158:   afc00018    sw  zero,24(s8)
     15c:   8fc30010    lw  v1,16(s8)
     160:   8fc20014    lw  v0,20(s8)
     164:   00000000    nop
     168:   00621021    addu    v0,v1,v0
     16c:   afc20018    sw  v0,24(s8)
     170:   00001021    move    v0,zero
     174:   03c0e821    move    sp,s8
     178:   8fbf0024    lw  ra,36(sp)
     17c:   8fbe0020    lw  s8,32(sp)
     180:   27bd0028    addiu   sp,sp,40
     184:   03e00008    jr  ra
     188:   00000000    nop

Não vemos nenuma chamada a add, apenas a addu. Fiz vários testes e não consegui fazer com que fosse utilizada a função add, ele sempre utiliza a função addu pois essa ignora flags de overflow.

Após simular o hello.mips, seu total de instruções foi de 2,689.

Com 1,033 instruções de memória, 285 branches e 1371 restantes.
O total de ciclos calculado então foi de 12,556 ciclos.

### Benchmarks

Como meu RA é 136242, tive que analisar os benchmarks susan, adpcm encoder e dijkstra.

#### Susan

Simulei o Susan com o comando:
mips.x --load=susan input_large.pgm output_large.smoothing.pgm -s

A simulação teve um total de 395,746,851 de instruções.

Sendo 77,366,310 de memória, 28,198,789 de branches e as outras são no total 290,181,752 instruções.
Fazendo as contas temos 804,268,572 ciclos.

#### ADPCM Encoder

Simulei o adpcm encoder com o comando:
mips.x --load=rawcaudio < ../data/small.pcm > ../output_small.adpcm

Obtivemos um total de 35,739,019 instruções.

Sendo 2,403,149 de memória, 9,117,921 branches e 24,217,949 compões o resto.
Fazendo as contas, o total de ciclos ficou em 122,606,606.

#### Dijkstra

Simulei o Dijkstra com o comando:
mips.x --load=dijkstra_small input.dat > output_small.dat

Obtivemos um total de 49,165,606 instruções.

Sendo 13,994,129 de memória, 10,835,651 branches e 24,335,826 compões o resto.
Fazendo as contas, o total de ciclos ficou em 174,674,723.
