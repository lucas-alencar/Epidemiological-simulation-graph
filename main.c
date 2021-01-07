#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "inout.h"
#include <unistd.h>

/*!
* \author Lucas Henrique de Alencar Rodrigues.
* \since 08/12/20
* \version 1.0
*/

int main(int argc, char const *argv[]){
    int teste1=0,teste2=0,teste3=0;
    char string_suporte[15];
    char titulo[30];
    strcpy(titulo,"entrada.txt");

    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-te") == 0){
            strcpy(titulo,argv[i+1]);
        }
    }

    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-c1") == 0){
            teste1 = 1;
        }
        if(strcmp(argv[i],"-c2") == 0){
            teste2 = 1;
        }
        if(strcmp(argv[i],"-c3") == 0){
            teste3 = 1;
        }
    }

    if(teste1 ==0 && teste2 == 0 && teste3 ==0){
        teste1 = 1;
        teste2 = 1;
        teste3 = 1;
    }

    /*!
    * \brief Add the default name of the output files
    */
    int printa = 0;
    char nome1[20],nome2[30],nome3[30];
    strcpy(nome1,"cenario_base.csv");
    strcpy(nome2,"cenario_distanciamento.csv");
    strcpy(nome3,"cenario_atendimento.csv");
    
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-n1") == 0)
            strcpy(nome1,argv[i+1]);
    }

    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-n2") == 0)
            strcpy(nome2,argv[i+1]);
    }

    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-n3") == 0)
            strcpy(nome3,argv[i+1]);
    }
    


    /*!
    * \brief checks whether the -s argument is valid
    */
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-s") == 0)
            printa = 1;
    }



    dados_ini dados; /**< struct that stores the initial data and the first calculations*/
    separa(titulo);/**< Separates the names of the items written in the document from the data*/


    /*!
    \return the struct 'dados_ini' or terminates the program
    */
    printf("\nDados lidos com sucesso!");
    dados = ler_arq_ini();
        


    
    int quant_dados = dados.dias*24/dados.h; /**< Defines the size of the data that will be dynamically allocated by the variables s,i,r*/

    float *s,*i,*r,*morte; /**< Main variables */
    s = (float *) calloc(quant_dados,sizeof(float));
    i = (float *) calloc(quant_dados,sizeof(float));
    r = (float *) calloc(quant_dados,sizeof(float));
    morte = (float *) calloc(quant_dados,sizeof(float));

    s[0] = dados.s_0;
    i[0] = dados.i_0;
    r[0] = dados.r_0;
    morte[0] = dados.r_0*2/100;

   char titulo_grafico[30];
    if(teste1 == 1){
        preenche_cenario_base(dados, quant_dados, s, i, r,morte,printa); //!< Fill the strings with the calculated values (without writing to the file)
        printf("\ncalculando resultados e escrevendo");
        escreve_sir(dados,quant_dados,s,i,r,morte,nome1); //!< Escreve no arquivo, utilizando-se das variáveis s,i,r e calcula novamente o tempo
        printf("\nEscrevendo documento");


        strcpy(string_suporte,"suporte1.plt");
        strcpy(titulo_grafico,"Cenario base");
        escreve_suporte(nome1,string_suporte,titulo_grafico);
    }
        
    if(teste2 == 1){
        preenche_cenario_distanciamento(dados, quant_dados, s, i, r,morte,printa); //!< Preenche as strings com os valores calculados (sem escrever no arquivo)
        printf("\ncalculando resultados e escrevendo");
        escreve_sir(dados,quant_dados,s,i,r,morte,nome2); //!< Escreve no arquivo, utilizando-se das variáveis s,i,r e calcula novamente o tempo
        printf("\nEscrevendo documento");


        strcpy(string_suporte,"suporte2.plt");
        strcpy(titulo_grafico,"Cenario de distanciamento");
        escreve_suporte(nome2,string_suporte,titulo_grafico);
    }

    if(teste3 == 1){
        preenche_cenario_atendimento(dados, quant_dados, s, i, r,morte,printa); //!< Preenche as strings com os valores calculados (sem escrever no arquivo)
        printf("\ncalculando resultados e escrevendo");
        escreve_sir(dados,quant_dados,s,i,r,morte,nome3); //!< Escreve no arquivo, utilizando-se das variáveis s,i,r e calcula novamente o tempo
        printf("\nEscrevendo documento");


        strcpy(string_suporte,"suporte3.plt");
        strcpy(titulo_grafico,"cenario de atendimento");
        escreve_suporte(nome3,string_suporte,titulo_grafico);

    }


    free(s);//!< Libera o espaço de memória alocado pela variável s
    free(i);//!< Libera o espaço de memória alocado pela variável i
    free(r);//!< Libera o espaço de memória alocado pela variável r
    printf("\nliberando memoria");
    printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("planilha preenchida com sucesso!");
    printf("\nfinalizando aplicacao");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"-p") == 0){

        
            if(teste1 == 1){
                system("suporte1.plt");
            }
            if(teste2 == 1){
                system("suporte2.plt");
            }
            if(teste3 == 1){
                system("suporte3.plt");
            }
        }
    }
    remove("temp.txt");
return 0;
}
