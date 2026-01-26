#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AvaliacaoDupla.h"

int Verificar_Duplicidade_Avaliacao(FILE *ftp, char *titulo, Avaliacoes *user, Login *reg){
    ftp = fopen("Avaliacoes.dat","r+b");
    if (!ftp) exit(1);
    for(;;){
        fread(user,sizeof(Avaliacoes),1,ftp);
        if(feof(ftp)) break;
        if (strcmp(reg->nome, user->nome) == 0){
            if (strcmp(titulo, user->titulo) == 0){
                    fclose(ftp);
                return 1;
            }
        }
    }
    fclose(ftp);
    return -1;
}
