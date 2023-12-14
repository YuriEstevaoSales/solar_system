// Código feito por Yuri Estevão - DCC UFMG
#include <stdio.h>
#include <stdlib.h>
// Definição de constantes que representam o número máximo de sistemas, raio, planetas, luas e o máximo de caracteres que os nomes podem ter.
#define MAX_NOME 100
#define MAX_SISTEMAS 100
#define MAX_RAIO 10000
#define MAX_PLANETAS 100
#define MAX_LUAS 100

/* Como cada sistema, planeta e lua possuem vários membros, foram criadas 3 structs para
armazenar os dados inseridos, sendo essas as structs Lua, Planeta e Sistema.*/

// Definição da struct Lua, responsável por armazenar o nome e o raio de cada lua do planeta especificado.
typedef struct
{
    char nome[MAX_NOME + 1];
    int raio;
} Lua;

/* Definição da struct Planeta, responsável por armazenar o nome de cada planeta do sistema
especificado, o raio de cada planeta e a quantidade de luas de cada planeta.*/
typedef struct
{
    char nome[MAX_NOME + 1];
    int raio;
    int qntd_luas;
    Lua *luas;
} Planeta;

/* Definição da struct Sistema, responsável por armazenar o tempo de descoberta do sistema,
 o nome, o raio do seu sol e a quantidade de planetas nesse sistema.*/
typedef struct
{
    int tempo_descoberta;
    char nome[MAX_NOME + 1];
    int raio_sol;
    int qntd_planetas;
    Planeta *planetas;
} Sistema;

/* Função responsável por comparar os sistemas solares de acordo com o quanto um sistema
é interessante em relação ao outro, levando em conta os critérios citados pelos cientistas.*/
int comparaMaisInteressante(const void *a, const void *b)
{
    const Sistema *sistemaA = (const Sistema *)a;
    const Sistema *sistemaB = (const Sistema *)b;

    // Comparação do raio do sol do sistema A e do sistema B, seguindo o critério 1.
    if (sistemaA->raio_sol > sistemaB->raio_sol)
        return -1;
    if (sistemaA->raio_sol < sistemaB->raio_sol)
        return 1;

    // Caso os raios sejam iguais, a quantidade de planetas de cada sistema é comparada, seguindo o critério 2.
    if (sistemaA->qntd_planetas > sistemaB->qntd_planetas)
        return -1;
    if (sistemaA->qntd_planetas < sistemaB->qntd_planetas)
        return 1;

    // Caso os raios e o número de planetas dos dois sistemas sejam iguais, a função compara o raio do maior planeta do sistema A com o raio do maior planeta do sistema B, seguindo o critério 3.
    int maiorRaioPlanetaA = 0, maiorRaioPlanetaB = 0;
    // Laço de repetição responsável por comparar o raio dos planetas do sistema A e armazenando o raio do maior planeta na variável maiorRaioPlaneta.
    for (int i = 0; i < sistemaA->qntd_planetas; i++)
    {
        if (sistemaA->planetas[i].raio > maiorRaioPlanetaA)
        {
            maiorRaioPlanetaA = sistemaA->planetas[i].raio;
        }
    }
    // Laço de repetição que desempenha o mesmo papel do laço anterior, porém em relação ao sistema B.
    for (int i = 0; i < sistemaB->qntd_planetas; i++)
    {
        if (sistemaB->planetas[i].raio > maiorRaioPlanetaB)
        {
            maiorRaioPlanetaB = sistemaB->planetas[i].raio;
        }
    }
    // Comparação do raio do maior planeta de cada sistema.
    if (maiorRaioPlanetaA > maiorRaioPlanetaB)
        return -1;
    if (maiorRaioPlanetaA < maiorRaioPlanetaB)
        return 1;

    // Caso haja empate entre o raio do sol, quantidade de planetas e raio do maior planeta de cada sistema, a quantidade de luas de cada sistema é comparada, seguindo o critério 4.
    int qntd_luasA = 0, qntd_luasB = 0;
    // Laço de repetição responsável por somar a quantidade total de luas do sistema A.
    for (int i = 0; i < sistemaA->qntd_planetas; i++)
    {
        qntd_luasA += sistemaA->planetas[i].qntd_luas;
    }
    // Laço de repetição que desempenha o mesmo papel do laço anterior, porém em relação ao sistema B.
    for (int i = 0; i < sistemaB->qntd_planetas; i++)
    {
        qntd_luasB += sistemaB->planetas[i].qntd_luas;
    }
    // Comparação da quantidade total de luas de cada sistema.
    if (qntd_luasA > qntd_luasB)
        return -1;
    if (qntd_luasA < qntd_luasB)
        return 1;

    // Em caso de empate nos 4 primeiros critérios, o raio da maior lua de cada sistema é comparado, seguindo o critério 5.
    int maiorRaioLuaA = 0, maiorRaioLuaB = 0;
    // Laço duplo que compara o raio de todas as luas do sistema A e armazena o raio da maior lua na variável maiorRaioLuaA.
    for (int i = 0; i < sistemaA->qntd_planetas; i++)
    {
        for (int j = 0; j < sistemaA->planetas[i].qntd_luas; j++)
        {
            if (sistemaA->planetas[i].luas[j].raio > maiorRaioLuaA)
            {
                maiorRaioLuaA = sistemaA->planetas[i].luas[j].raio;
            }
        }
    }
    // Laço duplo que desempenha o mesmo papel do laço anterior, porém em relação ao sistema B.
    for (int i = 0; i < sistemaB->qntd_planetas; i++)
    {
        for (int j = 0; j < sistemaB->planetas[i].qntd_luas; j++)
        {
            if (sistemaB->planetas[i].luas[j].raio > maiorRaioLuaB)
            {
                maiorRaioLuaB = sistemaB->planetas[i].luas[j].raio;
            }
        }
    }
    // Comparação do raio da maior lua de cada um dos dois sistemas.
    if (maiorRaioLuaA > maiorRaioLuaB)
        return -1;
    if (maiorRaioLuaA < maiorRaioLuaB)
        return 1;

    // Se todos os outros critérios empatarem, é feita a comparação do tempo de descoberta de cada sistema, seguindo o critério 6.
    if (sistemaA->tempo_descoberta < sistemaB->tempo_descoberta)
        return -1;
    if (sistemaA->tempo_descoberta > sistemaB->tempo_descoberta)
        return 1;

    return 0;
}

// Função responsável por determinar o pivô do vetor e particionar o vetor em subvetores.
int ritacao(Sistema *sistemas, int l, int r)
{
    // Escolhe o pivô como o último elemento e armazena na variável "q".
    int q = r;

    // Criação dos índices para particionar os elementos.
    int i = l - 1;
    int j = l;

    for (; j < r; j++)
    { // Laço responsável por mover j iterativamente até antes do pivô na posição r-1.
        // Utiliza a função comparaMaisInteressante() para verificar se sistemas[j] é mais interessante que sistemas[q].
        if (comparaMaisInteressante(&sistemas[j], &sistemas[q]) > 0)
        {
            // Incrementa i e troca sistemas[i] com sistemas[j] (A[i] com A[j], como especificado nas orientações).
            i++;
            Sistema temp = sistemas[i]; // Variável temporária feita para preservar o valor de sistemas[i];
            sistemas[i] = sistemas[j];
            sistemas[j] = temp;
        }
    }

    // Após o fim do loop, ocorre a troca de sistemas[q] com sistemas[i + 1] (A[q] com A[i + 1]).
    Sistema temp = sistemas[i + 1]; // Variável temporária para preservar sistemas[i+1].
    sistemas[i + 1] = sistemas[q];
    sistemas[q] = temp;

    // Retorna o índice i + 1 para indicar a fronteira dos dois subvetores repartidos.
    return i + 1;
}

// Função responsável por implementar o BromeroSort, algoritmo de ordenação necessário para o trabalho.
void bromeroSort(Sistema *sistemas, int l, int r)
{
    if (l < r)
    { // Verifica se l e r são respectivamente a primeira e a ultima posição do vetor de sistemas.
        // Utiliza a função ritacao() para particionar os sistemas em subvetores e obter o índice do pivô, armazenando o mesmo na variável "q".
        int q = ritacao(sistemas, l, r);

        // Aplica o algoritmo de forma recursiva nos subvetores "esquerdo" e "direito".
        bromeroSort(sistemas, l, q - 1);
        bromeroSort(sistemas, q + 1, r);
    }
}

// Função responsável por liberar a memória que foi alocada dinamicamente.
void liberaMemoria(Sistema *sistemas, int N)
{
    // Laço de repetição responsável por liberar a memória alocada para os planetas.
    for (int i = 0; i < N; i++)
    {
        // Laço de repetição responsável por liberar a memória alocada para as luas.
        for (int j = 0; j < sistemas[i].qntd_planetas; j++)
        {
            free(sistemas[i].planetas[j].luas);
        }
        free(sistemas[i].planetas);
    }
    // Comando free() para liberar a memória alocada para os sistemas solares.
    free(sistemas);
}

int main()
{
    int N; // Variável que representa a quantidade de sistemas solares que serão armazenados e ordenados.
    scanf("%d", &N);
    if (N <= MAX_SISTEMAS && N >= 1)
    {
        // Alocação dinâmica para os sistemas solares
        Sistema *sistemas = (Sistema *)malloc(N * sizeof(Sistema));
        if (sistemas == NULL)
        { // If que verifica se a memória foi alocada corretamente.
            fprintf(stderr, "Erro na alocação de memória.\n");
            return 1;
        }
        // Laço com o objetivo de ler N sistemas.
        for (int i = 0; i < N; i++)
        {
            // Leitura das informações do sistema solar.
            scanf("%d %s %d %d", &sistemas[i].tempo_descoberta, sistemas[i].nome, &sistemas[i].raio_sol, &sistemas[i].qntd_planetas);
            // Verificador que encerra o programa caso o raio_sol ultrapasse o valor máximo permitido (10000).
            if (sistemas[i].raio_sol > MAX_RAIO)
            {
                liberaMemoria(sistemas, i);
                return 1;
            }
            if (sistemas[i].qntd_planetas > MAX_PLANETAS)
            {
                liberaMemoria(sistemas, i);
                return 1;
            }

            if (sistemas[i].tempo_descoberta >= 1 && sistemas[i].tempo_descoberta <= 1000000)
            { // Verificador que limita o tamanho máximo do tempo de descoberta.
                // Alocação dinâmica para os planetas.
                sistemas[i].planetas = (Planeta *)malloc(sistemas[i].qntd_planetas * sizeof(Planeta));

                // Leitura das informações de cada planeta.
                for (int j = 0; j < sistemas[i].qntd_planetas; j++)
                {
                    scanf("%s %d %d", sistemas[i].planetas[j].nome, &sistemas[i].planetas[j].raio, &sistemas[i].planetas[j].qntd_luas);
                    // Verifica se o raio do planeta está dentro do limite de 10000.
                    if (sistemas[i].planetas[j].raio > MAX_RAIO)
                    {
                        liberaMemoria(sistemas, i);
                        return 1;
                    }
                    // Verifica se o número de luas está dentro do limite de 100.
                    if (sistemas[i].planetas[j].qntd_luas > MAX_LUAS)
                    {
                        liberaMemoria(sistemas, i);
                        return 1;
                    }
                    // Alocação dinâmica para as luas.
                    sistemas[i].planetas[j].luas = (Lua *)malloc(sistemas[i].planetas[j].qntd_luas * sizeof(Lua));

                    // Leitura das informações de cada lua.
                    for (int k = 0; k < sistemas[i].planetas[j].qntd_luas; k++)
                    {
                        scanf("%s %d", sistemas[i].planetas[j].luas[k].nome, &sistemas[i].planetas[j].luas[k].raio);
                        // Verifica se o raio da lua está dentro do limite de 10000.
                        if (sistemas[i].planetas[j].luas[k].raio > MAX_RAIO)
                        {
                            liberaMemoria(sistemas, i);
                            return 1;
                        }
                    }
                }
            }
            else
            { // Caso o valor do tempo de descoberta for inválido, a memória é liberada através da função liberaMemoria() e o programa encerra.
                liberaMemoria(sistemas, i);
                return 1;
            }
        }

        // Ordena os sistemas solares usando o algoritmo BromeroSort.
        bromeroSort(sistemas, 0, N - 1);

        // Imprime os nomes dos sistemas solares ordenados.
        for (int i = N - 1; i >= 0; i--)
        {
            printf("%s\n", sistemas[i].nome);
        }
        // Caso o programa funcione corretamente, a memória alocada é liberada.
        liberaMemoria(sistemas, N);
    }
    return 0;
}