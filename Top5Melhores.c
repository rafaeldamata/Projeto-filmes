#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "Site.h"
#include "Pause.h"

#include "Top5Melhores.h"

void Top5_Melhores(FILE *ptr, Filme *f){
	int TAM = 20;
	Filme reg[TAM];
	int cont = 0;
	ptr = fopen("Catalogo.dat","rb");
	for(;;){
		fread(f,sizeof(Filme),1,ptr);
		if (feof(ptr)) break;
		strcpy(reg[cont].titulo,f->titulo);
		reg[cont].media = f->media;
		cont++;
	}
	Filme aux;
	for(int i = 0; i < TAM; i++){
		for(int j = i + 1; j < TAM; j++){
			if(reg[i].media < reg[j].media){
				aux = reg[i];
				reg[i] = reg[j];
				reg[j] = aux;
			}
		}
	}
	Exibir_Titulo_Site();
	printf("                                 		-- T O P  5  M E L H O R E S  F I L M E S --\n");
    printf("                                 		-------------------------------------------- \n\n");
	printf("                           Ordem                               Media                              Filme\n");
	for(int c = 0; c < 5; c++){
		printf("\n                             %d ",c + 1);
		printf("                                 %.1f",reg[c].media);
		printf("                              %s",reg[c].titulo);
	}
	Funcao_Pause();
	return;
}

