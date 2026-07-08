# detetive.c
Trabalho da Faculdade _ ADS

Nível Novato 1.0 

# 🔍 Detective Quest - Nível Novato: Mapa da Mansão

Bem-vindo ao **Detective Quest**, um jogo de mistério onde o jogador explora uma mansão para encontrar pistas e desvendar crimes. Neste primeiro nível, o foco é a estrutura fundamental de navegação do jogo: o **Mapa da Mansão**.

## 🎯 Objetivo do Nível Novato
Implementar a estrutura de dados de uma **Árvore Binária** para representar os cômodos da mansão. O sistema permite que o jogador navegue entre salas através de decisões direcionais (esquerda e direita), utilizando alocação dinâmica de memória.

## ⚙️ Funcionalidades Implementadas
* **Estrutura Hierárquica:** A mansão é modelada como uma árvore binária onde cada `Sala` (nó) possui um nome e dois possíveis caminhos (ponteiros `esq` e `dir`).
* **Navegação Recursiva:** O motor de exploração utiliza recursividade para permitir o movimento contínuo do jogador pelos cômodos.
* **Mapa Estático:** A estrutura da mansão é definida automaticamente na inicialização, criando um cenário imutável para a exploração.
* **Segurança de Navegação:** Verificação de caminhos (`NULL`) para impedir tentativas de mover-se para salas inexistentes.

## 🚀 Como Executar
1. Compile o código-fonte via terminal:
   ```bash
   gcc detetive.c -o detetive

   Execute o jogo:

Bash
./detetive
Utilize as teclas e (esquerda), d (direita) e s (sair) para navegar.

🛠️ Tecnologias Utilizadas
Linguagem: C

Estrutura de Dados: Árvore Binária

Gestão de Memória: Alocação dinâmica (malloc)

Lógica: Recursividade e Ponteiros

----------------------------------------------------------------------------------------------------------