#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "Site.h"
#include "Cadastro.h"
#include "LimparBuffer.h"
#include "Pause.h"
#include "FuncaoEnter.h"
#include "AtualizarCatalogo.h"
#include "ListarFilmes.h"
#include "AutenticarLogin.h"
#include "AvaliacaoDupla.h"
#include "VerificarFilme.h"
#include "AtualizarMedia.h"
#include "AvaliarFilme.h"
#include "ExibirAvaliacoes.h"
#include "AvaliacoesFilme.h"
#include "Top5Melhores.h"
#include "Top5Piores.h"
#include "AlterarMedia.h"
#include "AlterarAvaliacao.h"



int main() {
    int opcao;
    Login reg;
    Filme filme;
    Avaliacoes user;
    FILE *ptr,*ftp,*arq, *bin;

    do {
        Exibir_Titulo_Site();
        // ====================================================================
        // OPÇÕES DO MENU CENTRALIZADAS (SEM CAIXA)
        // ====================================================================
        // Espaços adicionais para manter o alinhamento central
        printf("                                 				-- M E N U --\n");
        printf("                                 				--------------- \n\n");

        // As opções agora são listadas usando um marcador simples (>>), mantendo o alinhamento
        printf("                             				>> 1 - Cadastrar Login\n");
        printf("\n                             				>> 2 - Adicionar Filme ao Catalogo\n");
        printf("\n                             				>> 3 - Listar Filmes do Catalogo\n");
        printf("\n                             				>> 4 - Exibir Avaliacoes de um Filme\n");
        printf("\n                             				>> 5 - Ver Top 5 Melhores Filmes\n");
        printf("\n                             				>> 6 - Ver Top 5 Piores Filmes\n");
        printf("\n                             				>> 7 - Exibir Avaliacoes de 1 Usuario\n");
        printf("\n                             				>> 8 - Avaliar um Filme (requer login)\n");
        printf("\n                             				>> 9 - Alterar Avaliacao de Usuario (requer login)\n");
        printf("\n                             				>> 0 - Sair do Sistema\n\n");

        // ====================================================================
        // ENTRADA DO USUÁRIO
        // ====================================================================
        printf("                              				>>> Escolha uma opcao e pressione ENTER: ");

        if (scanf("%d", &opcao) != 1) {
            // Limpa o buffer de entrada em caso de falha na leitura (caractere inválido)
            while (getchar() != '\n');
            opcao = -1; // Define como inválido para cair no default
        }


        // ====================================================================
        // AÇÕES (Simuladas)
        // ====================================================================
        printf("\n");

        switch(opcao) {
            case 1:
                 printf("                              				 Opcao Escolhida: Cadastrar Login... (Opcao 1)\n");
            Funcao_Enter();
            Cadastrar_Usuario(&reg);
			 break;
            case 2:
                 printf("                              				 Opcao Escolhida: Adicionar Filme ao Catalogo... (Opcao 2)\n");
			Funcao_Enter();
            Atualizar_Catalogo(&filme);
			break;
            case 3:
                 printf("                              				 Exibindo o Catalogo de Filmes... (Opcao 3)\n");
			Funcao_Enter();
            Listar_Filmes(&filme);
			 break;
            case 4:
                 printf("                              				 Exibindo Avaliacoes de um Filme... (Opcao 4)\n");
            Funcao_Enter();
            Exibir_Avaliacoes_Filme(ptr,&filme);
			 break;
            case 5:
                 printf("                              				 Exibindo Top 5 Melhores Filmes... (Opcao 5)\n");
            Funcao_Enter();
			Top5_Melhores(ptr,&filme);
			 break;
			 case 6:
			      printf("                             				 Exibindo Top 5 Piores Filmes... (Opcao 6)\n");
			 Funcao_Enter();
			 Top5_Piores(ptr,&filme);
			 break;
            case 7:
                 printf("                              				 Exibindo avaliações do usuário... (Opcao 7)\n");
            Funcao_Enter();
            int encontrar = Autenticar_Login(arq,&reg);
            if (encontrar == 1){
            	Exibir_Avaliacoes(&user,&reg,ftp);
			}
			break;
            case 8:
                 printf("                              				 Redirecionando para Autenticacao de Login... (Opcao 8)\n");
			Funcao_Enter();
            int encontrou;
            encontrou = Autenticar_Login(arq,&reg);
            if (encontrou == 1){
            	Avaliar_Filme(ptr,ftp,&user,&reg,&filme);
			}
			 break;
            case 9: 
            	printf("                              				 Opcao Escolhida: Alterar Avaliacao... (Opcao 9)\n");
            	limpar_buffer();
            	int usuario = Autenticar_Login(arq,&reg);
            	if (usuario == 1){
            		Alterar_Avaliacao(ftp,&user,&reg);
				}
                break;
            case 0:
                 printf("                              				 Obrigado por usar o CINENOTE. Ate a proxima!\n"); 
				 break;
            default:
			 printf("                              				 Opcao **inválida**! Por favor, escolha um número de 1 a 9.\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

