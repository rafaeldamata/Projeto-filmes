# Cinenote - Sistema de Avaliação de Filmes 🎬

O **Cinenote** é um sistema de avaliação de filmes desenvolvido na linguagem C como projeto final da disciplina de Linguagem de Programação I do curso de Sistemas de Informação.

O software permite que entusiastas do cinema cataloguem, avaliem e compartilhem opiniões sobre obras cinematográficas, promovendo a interação entre usuários por meio de uma base de dados organizada.

---

# 📌 Funcionalidades Principais

O sistema foi projetado para oferecer uma navegação intuitiva via menus textuais, contendo as seguintes funcionalidades:

- Cadastro e login com autenticação por nome e senha
- Consulta de 20 filmes com exibição paginada (10 títulos por vez)
- Avaliação obrigatória de filmes com notas de 1 a 5
- Adição de comentários opcionais de até 80 caracteres
- Recalculo automático da média de avaliação a cada novo registro
- Exibição do Top 5 filmes mais bem avaliados
- Exibição dos 5 filmes pior avaliados
- Visualização de avaliações de um filme específico
- Consulta do histórico de avaliações de um usuário
- Alteração de avaliações e comentários já realizados pelo usuário

---

# 🛠️ Especificações Técnicas

O projeto foi desenvolvido utilizando:

- Bibliotecas locais de funções para melhor organização do código
- Armazenamento em arquivos binários para persistência de dados
- Estrutura modular utilizando funções separadas
- Tratamento de erros e validação de entradas
- Uso de structs e ponteiros

---

# 📂 Estrutura de Arquivos e Structs

O sistema utiliza structs e tabelas para organizar as informações em três arquivos principais:

## Filmes
Campos principais:
- Título
- Resumo
- Número de avaliadores
- Número de comentários
- Média das notas
- Soma das notas

## Cadastro
Campos principais:
- Nome do usuário
- Senha

## Avaliações
Campos principais:
- Título do filme
- Nome do usuário
- Nota (1 a 5)
- Comentário

---

# 🚀 Como Executar

Certifique-se de possuir um compilador C instalado, como o GCC, a partir do comando: g++ --version. Após isso clone o repositório e execute o comando .\av3-novaversao-lp1.exe
