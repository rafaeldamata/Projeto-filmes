#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "Site.h"
#include "LimparBuffer.h"
#include "Pause.h"
#include "AvaliacaoDupla.h"
#include "VerificarFilme.h"
#include "AtualizarMedia.h"

#include "AvaliarFilme.h"

void Avaliar_Filme(FILE *ptr, FILE *ftp, Avaliacoes *user, Login *reg, Filme *f){
	int opcao;
	int Avaliacao_dupla,verificar;
	int comentou = 0;
	char titulo_input[100];
	Exibir_Titulo_Site();
	printf("                                 				-- A V A L I A C A O --\n");
    printf("                                 				----------------------- \n\n");
    printf("                                               >> Nome do Usuario: %s\n",reg->nome);
    printf("                                               >>> Insira o Titulo do Filme: ");
    fgets(titulo_input,sizeof(titulo_input),stdin);

    verificar = Verificar_Filme(ptr,f,titulo_input);
    if (verificar == -1){
       printf("\n                                 		    	Filme nao esta no catalogo!\n");
        Funcao_Pause();
        return;
    }
    Avaliacao_dupla = Verificar_Duplicidade_Avaliacao(ftp,titulo_input,user,reg);
    if (Avaliacao_dupla == 1){
        printf("\n                                 		    	Usuario **ja Avaliou** Anteriormente este Filme\n");
        Funcao_Pause();
        return;
    }

	ftp = fopen("Avaliacoes.dat","a+b");

	strcpy(user->nome,reg->nome);
	strcpy(user->titulo,titulo_input);
	do{
    printf("\n                                 		    	>>> Insira a Nota: ");
    scanf("%d",&user->avaliacao);
    } while (user->avaliacao < 1 || user->avaliacao > 5);

    printf("\n                                 		    	>>> Deseja Fazer um Comentario sobre o Filme (1 = true / 0 = false): ");
    scanf("%d",&opcao);
    limpar_buffer();
    if (opcao == 1){
        printf("\n                                 		    	>>> Insira o Comentario: ");
        fgets(user->comentario,sizeof(user->comentario),stdin);
        comentou = 1;
    }
    else{
        strcpy(user->comentario," ");
    }
    fwrite(user,sizeof(Avaliacoes),1,ftp);
    fclose(ftp);
    Atualizar_Media_Filmes(ptr,user,f,&comentou);


    Funcao_Pause();


    return;

}

