#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "inout.h"


/*!
*Faz os cálculos de k e b
*/
void calculos_iniciais(dados_ini *dados){
    (*dados).k = ((*dados).m_k)/((*dados).n_k * (*dados).t_k);
    (*dados).b = ((*dados).n_b)/((*dados).t_b * (*dados).s_b0 * (*dados).i_b0);
}


/*!
*calcula o valor dos pontos das variáveis s,i,r para o cenário base e preenche os vetores com os resultados
*/
void preenche_cenario_base(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte,int printa){
    calculos_iniciais(&dados); //!< Calcula os valores K e B
    printf("\nrealizando calculos iniciais");
    float dia=0;
    float arred_s,arred_i,arred_r;
    float s_anterior,i_anterior,r_anterior;
    for(int x=1; x<tamanho_vetor; x++){
        s_anterior = s[x-1];
        i_anterior = i[x-1];
        r_anterior = r[x-1];
        s[x] = s_anterior - (dados.h * dados.b * s_anterior * i_anterior);
        i[x] = i_anterior + (dados.h * ((dados.b * s_anterior * i_anterior)-(dados.k * i_anterior)));
        r[x] = r_anterior + (dados.h * dados.k * i_anterior);
        morte[x] = r[x]*2/100;

        if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
        }
        dia += dados.h;
    }
    if(printa){
            printf("%f,%f,%f,%f,%f\n",s[tamanho_vetor-1],i[tamanho_vetor-1],r[tamanho_vetor-1],morte[tamanho_vetor-1],dia);
    }

}

void preenche_cenario_distanciamento(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte, int printa){
    if(dados.tptb == -1 || dados.ntb == -1){
        printf("dados insuficientes para o cenario de distanciamento");
        exit(1);
    }

    calculos_iniciais(&dados); //!< Calcula os valores K e B
    printf("\nrealizando calculos iniciais");
    int x=1;
    float dia=0;
    float arred_s,arred_i,arred_r;
    float s_anterior,i_anterior,r_anterior;
    for(x=1; x<(tamanho_vetor*dados.tptb)/100; x++){
        s_anterior = s[x-1];
        i_anterior = i[x-1];
        r_anterior = r[x-1];
        s[x] = s_anterior - (dados.h * dados.b * s_anterior * i_anterior);
        i[x] = i_anterior + (dados.h * ((dados.b * s_anterior * i_anterior)-(dados.k * i_anterior)));
        r[x] = r_anterior + (dados.h * dados.k * i_anterior);
        morte[x] = r[x]*2/100;
        if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
        }
        dia += dados.h;
    }

    dados.t_b = dados.ntb;
    calculos_iniciais(&dados); //!< Calcula os valores K e B
    printf("\nrealizando calculos iniciais");

    for(x;x<tamanho_vetor;x++){
        s_anterior = s[x-1];
        i_anterior = i[x-1];
        r_anterior = r[x-1];
        s[x] = s_anterior - (dados.h * dados.b * s_anterior * i_anterior);
        i[x] = i_anterior + (dados.h * ((dados.b * s_anterior * i_anterior)-(dados.k * i_anterior)));
        r[x] = r_anterior + (dados.h * dados.k * i_anterior);
        morte[x] = r[x]*2/100;
        if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
        }
        dia += dados.h;
    }
    if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
    }

}


void preenche_cenario_atendimento(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte, int printa){
    if(dados.tptk == -1 || dados.ntk == -1){
        printf("dados insuficientes para o cenario de distanciamento");
        exit(1);
    }

    calculos_iniciais(&dados); //!< Calcula os valores K e B
    printf("\nrealizando calculos iniciais");
    int x=1;
    float dia=0;
    float arred_s,arred_i,arred_r;
    float s_anterior,i_anterior,r_anterior;
    for(x=1; x<(tamanho_vetor*dados.tptk)/100; x++){
        s_anterior = s[x-1];
        i_anterior = i[x-1];
        r_anterior = r[x-1];
        s[x] = s_anterior - (dados.h * dados.b * s_anterior * i_anterior);
        i[x] = i_anterior + (dados.h * ((dados.b * s_anterior * i_anterior)-(dados.k * i_anterior)));
        r[x] = r_anterior + (dados.h * dados.k * i_anterior);
        dia += dados.h;
        if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
        }
    
    }

    dados.t_k = dados.ntk;
    calculos_iniciais(&dados); //!< Calcula os valores K e B
    printf("\nrealizando calculos iniciais");

    for(x;x<tamanho_vetor;x++){
        s_anterior = s[x-1];
        i_anterior = i[x-1];
        r_anterior = r[x-1];
        s[x] = s_anterior - (dados.h * dados.b * s_anterior * i_anterior);
        i[x] = i_anterior + (dados.h * ((dados.b * s_anterior * i_anterior)-(dados.k * i_anterior)));
        r[x] = r_anterior + (dados.h * dados.k * i_anterior);
        dia += dados.h;
        if(printa){
            printf("%f,%f,%f,%f,%f\n",s[x-1],i[x-1],r[x-1],morte[x-1],dia);
        }
    }

}