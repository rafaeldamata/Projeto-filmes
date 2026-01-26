#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "Site.h"
#include "Pause.h"

#include "ExibirAvaliacoes.h"

void Exibir_Avaliacoes(Avaliacoes *user, Login *reg,FILE *ftp){
	ftp = fopen("Avaliacoes.dat","rb");

	Exibir_Titulo_Site();
	printf("                                 				-- A V A L I A C A O --\n");
    printf("                                 				----------------------- \n\n");

	for(;;){
        fread(user,sizeof(Avaliacoes),1,ftp);
        if(feof(ftp)) break;
        if(strcmp(reg->nome,user->nome) == 0){

            printf("\n                                                  >> Usuario: %s",user->nome);
            printf("\n                                                  >> Titulo: %s",user->titulo);
            printf("\n                                                  >> Nota: %d\n",user->avaliacao);
            printf("\n                                                  >> Comentario: %s\n",user->comentario);
            printf("\n");
            }

	}
	Funcao_Pause();
	fclose(ftp);
	return;
	}

