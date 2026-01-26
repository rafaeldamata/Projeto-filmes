#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pause.h"
#include "estruturas.h"
#include "Site.h"

#include "AvaliacoesFilme.h"

void Exibir_Avaliacoes_Filme(FILE *ptr, Filme *f){
	Exibir_Titulo_Site();
	char titulo_filme[100];
	printf("                                 				-- A V A L I A C O E S --\n");
    printf("                                 				------------------------- \n\n");
    printf("                                 		     	>>> Insira o Titulo do Filme: ");
    fgets(titulo_filme,sizeof(titulo_filme),stdin);
    ptr = fopen("Catalogo.dat","r+b");
    for(;;){
    	fread(f,sizeof(Filme),1,ptr);
    	if(feof(ptr)) break;
    	if(strcmp(titulo_filme, f->titulo) == 0){
    		
    		printf("\n                                 			>> Titulo: %s\n",f->titulo);
    		printf("                                 			>> Resumo: %s\n",f->resumo);
    		printf("                                 			>> Numero de Avaliacoes: %d\n",f->numavaliadores);
    		printf("\n                                 			>> Numero de Comentarios: %d\n",f->numcomentarios);
    		printf("\n                                 			>> Media das Notas Recebidas: %.1f\n",f->media);
    		Funcao_Pause();
    		fclose(ptr);
    		return;

		}
	}
}

