#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AtualizarMedia.h"

void Atualizar_Media_Filmes(FILE *ptr, Avaliacoes *user, Filme *f,int *comentou){
	ptr = fopen("Catalogo.dat","r+b");
	if (ptr == NULL){
        printf("                                                 Erro ao abrir arquivo!\n");
	}
	for(;;){
		fread(f,sizeof(Filme),1,ptr);
		if (feof (ptr)) break;
		if (strcmp (f->titulo, user->titulo) == 0){
				f->soma_notas += user->avaliacao;
				f->numavaliadores++;
				f->media = f->soma_notas / f->numavaliadores;
				if (*comentou == 1)
                    f->numcomentarios++;

				fseek(ptr,(long) -sizeof(Filme),SEEK_CUR);
				fwrite(f,sizeof(Filme),1,ptr);
				fclose(ptr);
				return;
		}
	}
}
