#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "inout.h"

/*!
* Inicializa todas as variaveis de 'dados' com -1, 
* lê os dados do arquivo entrada.txt
* verifica se as variáveis estão corretas 
*/
dados_ini ler_arq_ini(){
    dados_ini dados;
    dados.s_0 = -1;
    dados.i_0 = -1;
    dados.r_0 = -1;
    dados.h = -1;
    dados.n_b = -1;
    dados.t_b = -1;
    dados.s_b0 = -1;
    dados.i_b0 = -1;
    dados.m_k = -1;
    dados.n_k = -1;
    dados.t_k = -1;
    dados.dias = -1;    
    dados.tptb = -1;
    dados.tptk = -1;
    dados.ntk = -1;
    dados.ntb = -1;

    FILE* dadosIni = fopen("temp.txt", "r");
    if(dadosIni != NULL){
        fscanf(dadosIni,"%f",&dados.s_0);
        fscanf(dadosIni,"%f",&dados.i_0);
        fscanf(dadosIni,"%f",&dados.r_0);
        fscanf(dadosIni,"%f",&dados.h);
        fscanf(dadosIni,"%f",&dados.n_b);
        fscanf(dadosIni,"%f",&dados.t_b);
        fscanf(dadosIni,"%f",&dados.s_b0);
        fscanf(dadosIni,"%f",&dados.i_b0);
        fscanf(dadosIni,"%f",&dados.m_k);
        fscanf(dadosIni,"%f",&dados.n_k);
        fscanf(dadosIni,"%f",&dados.t_k);
        fscanf(dadosIni,"%d",&dados.dias);
        fscanf(dadosIni,"%f",&dados.tptb);
        fscanf(dadosIni,"%f",&dados.tptk);
        fscanf(dadosIni,"%f",&dados.ntb);
        fscanf(dadosIni,"%f",&dados.ntk);

        
        if(dados.s_0 < 0 || dados.i_0 < 0 || dados.r_0 < 0 || dados.h < 0 || dados.n_b < 0 || dados.t_b < 0 || dados.s_b0 < 0 || dados.i_b0 < 0 || dados.m_k < 0 || dados.n_k < 0 || dados.t_k < 0 || dados.dias < 0){
            printf("Dados faltando ou invalidos");
            exit(1);
        }
    }

    else{
        printf("entrada nao encontrada");
        exit(1);
    }

    fclose(dadosIni);
    return dados;
}


/*!
*escreve o conteudo calculado em preenche_cenario_base na saida.csv
*/
void escreve_sir(dados_ini dados,int tamanho_vetor, float *s, float *i, float *r,float *morte,char nome[]){
    float tempo =0;
    FILE* arq_saida = fopen(nome,"w");
    for(int x=0;x<tamanho_vetor;x++){
        fprintf(arq_saida,"%f,%f,%f,%f,%f\n", s[x],i[x], r[x],morte[x], tempo);
        tempo += dados.h;
    }
    fclose(arq_saida); 
}

void escreve_suporte(char nome[], char titulo[],char titulo_grafico[]){
FILE* arq_suporte = fopen(titulo,"w");
fprintf(arq_suporte,"reset;\n");
fprintf(arq_suporte,"set datafile separator ',';\n");
fprintf(arq_suporte,"set xlabel 'tempo (h)';\n");
fprintf(arq_suporte,"set ylabel 'quantidade de pessoas';\n");
fprintf(arq_suporte,"set title '%s';\n",titulo_grafico);
fprintf(arq_suporte,"plot '%s' using 5:1 with lines ls 1 smooth csplines title 's', '%s' using 5:2 with lines ls 2 smooth csplines title 'i', '%s' using 5:3 with lines ls 3 smooth csplines title 'r', '%s' using 5:4 with lines ls 3 smooth csplines title 'mortes';",nome,nome,nome,nome);
fclose(arq_suporte);
}