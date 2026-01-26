#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

#include "AlterarMedia.h"

void Atualizar_Media_Filme(int *nota_antiga, Avaliacoes *user){
	Filme f;
	FILE *ptr = fopen("Catalogo.dat","r+b");
	for(;;){
		fread(&f,sizeof(Filme),1,ptr);
		if(feof(ptr)) break;
		if (strcmp(f.titulo,user->titulo) == 0){
			f.soma_notas = f.soma_notas - *nota_antiga + user->avaliacao;
			f.media = f.soma_notas / f.numavaliadores;
			fseek(ptr,(long) -sizeof(Filme),SEEK_CUR);
			fwrite(&f,sizeof(Filme),1,ptr);
			fclose(ptr);
			return;
		}
	}
}

