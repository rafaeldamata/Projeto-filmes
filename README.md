Cinenote - Sistema de Avaliação de Filmes 🎬

O Cinenote é um sistema de avaliação de filmes desenvolvido em linguagem C como projeto final da disciplina de Linguagem de Programação I (Sistemas de Informação - UNEB). O software permite que entusiastas do cinema cataloguem, avaliem e compartilhem opiniões sobre obras cinematográficas, promovendo a interação entre usuários por meio de uma base de dados organizada.

📌 Funcionalidades Principais
O sistema foi projetado para oferecer uma navegação intuitiva via menus textuais, com as seguintes capacidades:


Gestão de Usuários: Cadastro e login com autenticação por nome e senha.


Catálogo de Filmes: Consulta de obras com exibição paginada (10 títulos por vez).

Interatividade:

Avaliação obrigatória de filmes (notas de 1 a 5).

Adição de comentários opcionais de até 80 caracteres.

Estatísticas em Tempo Real:

Recálculo automático da média de avaliação a cada novo registro.

Exibição do Ranking: Top 5 filmes mais bem avaliados e os 5 piores.


Consultas Personalizadas: Visualização de avaliações por filme específico ou histórico de um usuário determinado.

🛠️ Especificações Técnicas

Criação de bibliotecas locais de funções para deixar o código mais organizado.


Armazenamento: Arquivos binários para persistência de dados.


Arquitetura: Estrutura modular utilizando funções separadas para garantir fácil manutenção.


Segurança e Integridade: Tratamento de erros de entrada e validação de dados para prevenir falhas no armazenamento.

Estrutura de Dados

O sistema utiliza structs e tabelas para organizar as informações em três arquivos principais:

Arquivos                       Campos Principais
Filmes                            Título, resumo, n° de avaliadores, n° de comentários, média e soma de notas.
Cadastro                          Nome e senha do usuário
Avaliações                        Título do filme, nome do usuário, nota (1 até 5) e comentário

🚀 Como Executar
Certifique-se de ter um compilador C (como GCC) instalado.

Clone o repositório:

Bash
git clone https://github.com/rafaeldamata/Projeto-filmes.git
Compile o projeto:

Bash
gcc main.c -o cinenote
Execute o programa:

Bash
./cinenote

