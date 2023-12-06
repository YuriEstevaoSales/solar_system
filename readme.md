# Solar System Sort
Repositório dedicado ao solar system sort, um algoritmo de ordenação de sistemas solares desenvolvido em C, semelhante a um QuickSort, ranqueado por uma lista de interesses. O projeto não tem o objetivo de fazer sentido astronômico, apenas computacional.

## Introdução

Na terra da Computação, os avanços tecnológicos estão a todo vapor. Os cientistas desenvolveram um novo dispositivo, capaz de identificar estrelas: o telescoptero. Como se trata de um dispositivo muito simples e divertido de usar, ele passou a ser amplamente adotado pelos computistas. O problema? Com a constante descoberta de novos sistemas solares, os cientistas não sabem por quais astros eles devem começar seus estudos. No entanto, existe um consenso entre os astrônomos das características que tornam um sistema interessante. A tarefa é, ordenar os sistemas solares recém descobertos com base nessas características.

## Ordem de interesse

O consenso entre os cientistas é que um sistema solar A é MAIS interessante que um sistema solar B, se:
1. O raio do sol do sistema A é maior que o raio do sol do sistema B.
2. O sistema A possui mais planetas que o sistema B.
3. O maior planeta do sistema A é maior que o maior planeta do sistema B.
4. O sistema A possui mais luas que o sistema B.
5. A maior lua do sistema A é maior que a maior lua do sistema B.
6. O tempo de descoberta de A é menor que o de B.

## Entrada

Primeiro você deve ler a quantidade de sistemas solares, N . Depois você deve ler o tempo de descoberta do sistema Ti, nome do sistema Si, o raio do seu sol Ri, e a quantidade de planetas que ele possui Pi, tudo em uma linha. Em seguida, é a hora de ler os planetas daquele sistema: o nome do planeta, pi,j , o raio do planeta ri,j e a quantidade de luas, Li,j . Por fim, você deve ler as luas daquele planeta: o nome da lua ℓi,j,k e seu raio qi,j,k. Perceba que assim que você terminar de ler as luas de um planeta, você vai ler o próximo planeta e suas luas. O mesmo vale para os sistemas: primeiro você lê tudo que tem em um sistema (seus planetas e luas) e depois lê o próximo sistema.
A entrada possui as seguintes restrições. 

- 1 ≤ N ≤ 1000000.
- 1 ≤ Ti ≤ 1000000 para todo i.
- todos os nomes têm pelo menos 1 e no máximo 100 caractere s.
- todos os raios são no máximo de tamanho 10000.
- cada sistema tem no máximo 100 planetas e cada planeta tem no máximo
100 luas.

A entrada usa tabs (’\t’) para facilitar a distinção do que é estrela, planeta,
ou lua, como se fosse um código em C. Estrelas não possum nenhum tab na
frente, planetas apenas 1 e luas, duas tabulações

### Exemplo de entrada

```cpp

6                                         // # Sistemas Solares
3 X1dhcdfx35 557 0                        // Sistema #1 | Raio | # Planetas
1 nmok0lee2 257 2                         // Sistema #2 | Raio | # Planetas
    4V8VP5P 743 2                         // Planeta #1 | Raio | # Luas
       SKZJqLg 538                        // Lua #1 | Raio
       23VFgWcFM3 978                     // Lua #2 | Raio
    ueJSO 805 1                           // Planeta #2 | Raio | # Luas
       phuVmf 484                         // Lua #1 | Raio
2 jW2Ol 889 1                             // Sistema #3 | Raio | # Planetas
    LUTmBvC8C 901 1                       // ...
       zzMpnv 636
20 wP30Hu 944 3
    nBSykm3G 187 1
       Hbf1J58 932
    1pUA1xD1wO 980 4
       bfFx 357
       0MkEM 438
       cSLdX 222
       XHbj8C 137
    60yzYmj 316 3
       WZepWXuYaW 471
       u4Fz2 418
       kqYsyi 9
11 kNahmOcQLr 298 3
    71wIO 468 3
       Ryl4D3A 358
       QBPGgLD 659
       6bsIGvPap 311
    8ke2ice 348 0
    YxjJRC 645 4
       r6TwFh 873
       u8bBOSu 736
       3dxmIJWNT 377
       ih6PPWGt 611
40 9YRGgCqY 453 1
    t7ipn3 207 1
       8CwDd 268

```

### Saída esperada

```cpp

wP30Hu                                     // Maior tamanho
X1dhcdfx35                                 // Segundo maior tamanho
jW2Ol                                      // Empate no tamanho e # de planetas , mas planeta MAIOR
9YRGgCqY                                   // Empate no tamanho e # de planetas , mas planeta menor
kNahmOcQLr                                 // Empate no tamanho , mas mais planetas
nmok0lee2                                  // Empate no tamanho , mas menos planetas

```
