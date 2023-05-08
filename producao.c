#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    // Cria o arquivo para a saida do programa
    FILE* modelagem = fopen("modelagem.lp", "w+");
    
    if (!modelagem){
        perror("Arquivo para a modelagem nao foi criado.\n");
    }
    
    int n,m = 0;        // n = quantidade de produtos, m = quantidade de compostos
    float lucro = 0;    // Variavel auxiliar para o lucro da funcao de maximizacao
    float p_valores[n]; // Valores de cada produto
    float c_custos[m];  // Custos dos compostos
    float c_limites[m]; // Limites dos compostos
    float matriz[n][m]; // Matriz quantidade de cada composto por produto

    // ----- LEITURA DOS DADOS DE ENTRADA ----- 
    // Quantidades de produtos e compostos
    scanf("%d %d", &n, &m);

    // Valores dos produtos
    for(int i = 0; i < n ; i++)
        scanf("%f", &p_valores[i]);
    
    // Custos e limites dos compostos
    for(int i = 0; i < m ; i++) 
        scanf("%f %f", &c_custos[i], &c_limites[i]);
    
    // Quantidades de compostos por produtos
    for(int i = 0; i < m ; i++)
        for(int j = 0; j < m ; j++)
            scanf("%f", &matriz[i][j]);


    // ----- ESCRITA NO ARQUIVO DE SAIDA -----
    // Escrita da funcao de maximizacao
    fprintf(modelagem, "%s", "max : ");
    for(int i = 0; i < n ; i++) {
        lucro = p_valores[i];
        for(int j = 0; j < m ; j++)
            lucro -= matriz[i][j] * c_custos[j];
        fprintf(modelagem, "%.2f", lucro);
        fprintf(modelagem, "%s", "x");
        fprintf(modelagem, "%d", i+1);
        if(i < n-1)
            fprintf(modelagem, "%s", " + ");
        else
            fprintf(modelagem, "%s", ";\n");
    }
    
    // Escrita das restricoes
    for(int j = 0; j < m ; j++) {
        for(int i = 0; i < n ; i++) {
            fprintf(modelagem, "%.2f", matriz[i][j]);
            fprintf(modelagem, "%s", "x");
            fprintf(modelagem, "%d", i+1);
            if(i < n-1)
                fprintf(modelagem, "%s", " + ");
            else
                fprintf(modelagem, "%s", " <= ");
        }
        fprintf(modelagem, "%.2f", c_limites[j]);
        fprintf(modelagem, "%s", ";\n");
    }

    fclose(modelagem);
    return 0;

}