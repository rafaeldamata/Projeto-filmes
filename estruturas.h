#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct login{
    char nome[20]; // nome do usuario
    char senha[10]; // senha do usuario
}Login;


typedef struct filme{
    char titulo[100]; // Titulo do filme
    char resumo[250]; // Resumo do filme
    float soma_notas; // Soma das notas recebidas
    int numavaliadores; // Numero de avaliacoes
    int numcomentarios; // Numero de comentarios
    float media; // Media das notas recebidas
}Filme;


typedef struct avaliacoes{
    char titulo[100];
    char nome[20];
    int avaliacao;
    char comentario[80];
}Avaliacoes;

#endif
