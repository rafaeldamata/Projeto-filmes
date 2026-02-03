Cinenote - Sistema de Avaliação de Filmes 🎬

O Cinenote é um sistema de avaliação de filmes desenvolvido em linguagem C como projeto final da disciplina de Linguagem de Programação I. O software permite que entusiastas do cinema cataloguem, avaliem e compartilhem opiniões sobre obras cinematográficas, promovendo a interação entre usuários por meio de uma base de dados organizada.


📌 Funcionalidades Principais

O sistema foi projetado para oferecer uma navegação intuitiva via menus textuais, com as seguintes capacidades: Cadastro e login com autenticação por nome e senha, consulta de 20 filmes com exibição paginada (10 títulos por vez), avaliação obrigatória de filmes (notas de 1 a 5), adição de comentários opcionais de até 80 caracteres, recálculo automático da média de avaliação a cada novo registro, top 5 filmes mais bem avaliados e os 5 piores, visualização de avaliações por filme específico ou histórico de um usuário determinado e alteração de avaliação (notas e comentários) realizada pelo usuário.

🛠️ Especificações Técnicas

 Criação de bibliotecas locais de funções para deixar o código mais organizado, armazenamento em arquivos binários para persistência de dados, estrutura modular utilizando funções separadas para garantir fácil manutenção, tratamento de erros de entrada e validação de dados para prevenir falhas no armazenamento e utilização de structs e ponteiros.


📂 Estrutura de arquivos

O sistema utiliza structs e tabelas para organizar as informações em três arquivos principais:

Filmes - Campos principais: Título, resumo, n° de avaliadores, n° de comentários, média e soma de notas.

Cadastro - Campos principais:  Nome e senha do usuário

Avaliações - Campos principais: Título do filme, nome do usuário, nota (1 até 5) e comentário

🚀 Como Executar

Certifique-se de ter um compilador C (como GCC) instalado.

-> Clone o repositório:

Bash
git clone https://github.com/rafaeldamata/Projeto-filmes.git

-> Compile o projeto:

Bash
gcc main.c -o cinenote

-> Execute o programa:

Bash
./cinenote

