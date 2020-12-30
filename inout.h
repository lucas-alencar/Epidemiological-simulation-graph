#ifndef FUNC_ENTRADA_SAIDA
#define FUNC_ENTRADA_SAIDA


/*!
* define a estrutura dados_iniciais
*/
typedef struct dados_iniciais{
float s_0;
float b;
float k;
float i_0;
float r_0;
float h;
float n_b;
float t_b;
float s_b0;
float i_b0;
float m_k;
float n_k;
float t_k;
int dias;
float tptb;
float tptk;
float ntb;
float ntk;
}dados_ini;
/*!
* define a todas as funções do programa
*/
dados_ini ler_arq_ini();
void calculos_iniciais(dados_ini *dados);
void preenche_cenario_base(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte,int printa);
void escreve_sir(dados_ini dados,int tamanho_vetor, float *s, float *i, float *r,float *morte,char nome[]);
void leitura_arg(int quant_ent, char *argsv[50],dados_ini prioridade);
void separa(char titulo[]);
void preenche_cenario_distanciamento(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte,int printa);
void preenche_cenario_atendimento(dados_ini dados, int tamanho_vetor, float *s, float *i, float *r,float *morte, int printa);
void escreve_suporte(char nome[],char titulo[],char titulo_grafico[]);

#endif ///FUNC_ENTRADA_SAIDA