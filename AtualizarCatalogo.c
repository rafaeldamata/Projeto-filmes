#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site.h"
#include "Pause.h"

#include "AtualizarCatalogo.h"

void Atualizar_Catalogo(Filme *f){
	Exibir_Titulo_Site();
	FILE *ptr = fopen("Catalogo.dat","a+b");
	printf("                                 				-- C A T A L O G O --\n");
    printf("                                 				--------------------- \n\n");
    printf("                              				>>> Insira o Titulo do Filme: ");
    fgets(f->titulo,sizeof(f->titulo),stdin);
    printf("\n                              				>>> Insira o Resumo do Filme: ");
    fgets(f->resumo,sizeof(f->resumo),stdin);
    f->numavaliadores = 0;
    f->numcomentarios = 0;
    f->soma_notas = 0;
    f->media = 0;
    if(ptr){
    	fseek(ptr,0,SEEK_END);
    	long filmes_atuais = ftell(ptr) / sizeof(Filme);
            if (filmes_atuais >= 20) {
                printf("\n                              				Limite de Filmes Atingido (20 filmes)!\n");
                Funcao_Pause();
                fclose(ptr);
                return;
            }
    	fwrite(f,sizeof(Filme),1,ptr);
    	fclose(ptr);
    	printf("\n\n                              				Filme Adicionado ao Catalogo com Sucesso!\n\n\n");
    	printf("                                              ");
		system("pause");
		}

}

