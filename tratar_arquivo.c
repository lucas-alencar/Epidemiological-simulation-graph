#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "inout.h"

void separa(char titulo[]){
    char nome_completo[20];
    FILE* temporario = fopen("temp.txt","w");
    FILE* arquivo1 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
        fscanf(arquivo1,"%s",&nome_completo[0]);
            if(nome_completo[0] == 's' && nome_completo[1] == '0' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo1);
        FILE* arquivo2 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo2,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'i' && nome_completo[1] == '0' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo2);
        FILE* arquivo3 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo3,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'r' && nome_completo[1] == '0' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }

        }
            fclose(arquivo3);
        FILE* arquivo4 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo4,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'h' && nome_completo[1] == '='){
                        printf("%s",nome_completo);
                for(int i=2;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo4);
        FILE* arquivo5 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo5,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'n' && nome_completo[1] == 'b' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo5);
        FILE* arquivo6 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo6,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 't' && nome_completo[1] == 'b' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo6);
        FILE* arquivo7 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo7,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 's' && nome_completo[1] == 'b' && nome_completo[2] == '0' && nome_completo[3] == '='){
                        printf("%s",nome_completo);
                for(int i=4;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo7);
        FILE* arquivo8 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo8,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'i' && nome_completo[1] == 'b' && nome_completo[2] == '0' && nome_completo[3] == '='){
                        printf("%s",nome_completo);
                for(int i=4;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo8);
        FILE* arquivo9 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo9,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'm' && nome_completo[1] == 'k' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo9);
        FILE* arquivo10 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo10,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'n' && nome_completo[1] == 'k' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo10);
        FILE* arquivo11 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo11,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 't' && nome_completo[1] == 'k' && nome_completo[2] == '='){
                        printf("%s",nome_completo);
                for(int i=3;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
                        }
        }
        fclose(arquivo11);
        FILE* arquivo12 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo12,"%s",&nome_completo[0]);
                            if(nome_completo[0] == 'd' && nome_completo[1] == 'i' && nome_completo[2] == 'a' && nome_completo[3] == 's' && nome_completo[4] == '='){
                        printf("%s",nome_completo);
                for(int i=5;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo12);
        FILE* arquivo13 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo13,"%s",&nome_completo[0]);
                            if(nome_completo[0] == 't' && nome_completo[1] == 'p' && nome_completo[2] == 't' && nome_completo[3] == 'b' && nome_completo[4] == '='){
                        printf("%s",nome_completo);
                for(int i=5;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo13);
        FILE* arquivo14 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo14,"%s",&nome_completo[0]);
                            if(nome_completo[0] == 't' && nome_completo[1] == 'p' && nome_completo[2] == 't' && nome_completo[3] == 'k' && nome_completo[4] == '='){
                        printf("%s",nome_completo);
                for(int i=5;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo14);
        FILE* arquivo15 = fopen(titulo,"r");
        for(int i=0;i<16;i++){
                    fscanf(arquivo15,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'n' && nome_completo[1] == 't' && nome_completo[2] == 'b' && nome_completo[3] == '='){
                        printf("%s",nome_completo);
                for(int i=4;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }
        }
        fclose(arquivo15);
        FILE* arquivo16 = fopen(titulo,"r");
        for(int i=0;i<16;i++){            
                    fscanf(arquivo16,"%s",&nome_completo[0]);
                        if(nome_completo[0] == 'n' && nome_completo[1] == 't' && nome_completo[2] == 'k' && nome_completo[3] == '='){
                        printf("%s",nome_completo);
                for(int i=4;i<strlen(nome_completo);i++){
                    fprintf(temporario,"%c",nome_completo[i]);
                }
                fprintf(temporario,"%c",'\n');
            }


        }
    
    fclose(arquivo16);
    fclose(temporario);
}