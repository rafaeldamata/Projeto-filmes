#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "Site.h"
#include "LimparBuffer.h"
#include "Pause.h"
#include "AlterarMedia.h"

#include "AlterarAvaliacao.h"

void Alterar_Avaliacao(FILE *ftp, Avaliacoes *user, Login *reg){
	char titulo[100];
	int opcao,nota_antiga;
	Exibir_Titulo_Site();
	printf("                                 				-- A V A L I A C O E S --\n");
    printf("                                 				------------------------- \n\n");
	printf("\n                                 			>>> Insira o Titulo do Filme: ");
	fgets(titulo,sizeof(titulo),stdin);
	ftp = fopen("Avaliacoes.dat","r+b");
	for(;;){
		fread(user,sizeof(Avaliacoes),1,ftp);
		if(feof(ftp)) break;
		if (strcmp(reg->nome,user->nome) == 0){
			if (strcmp (titulo,user->titulo) == 0){
				nota_antiga = user->avaliacao;
				do{
				
				printf("\n                                 			>>> Insira a Nova Nota: ");
				scanf("%d",&user->avaliacao);
				} while (user->avaliacao < 1 || user->avaliacao > 5);
				printf("\n                                 			>>> Deseja Fazer novo Comentario sobre o Filme (1 = true / 0 = false): ");
				scanf("%d",&opcao);
				limpar_buffer();
				if (opcao == 1){
					printf("\n                                 			>>> Insira o Comentario: ");
					fgets(user->comentario,sizeof(user->comentario),stdin);
				}
				fseek(ftp,(long) -sizeof(Avaliacoes),SEEK_CUR);
				fwrite(user,sizeof(Avaliacoes),1,ftp);
				fclose(ftp);
				Atualizar_Media_Filme(&nota_antiga,user);
				printf("\n                                 			Avaliacao Alterada com Sucesso!\n");
				Funcao_Pause();
				return;
			}
		}
	}
}

