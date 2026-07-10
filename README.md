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

Nível Aventureiro/Mestre 2.0

# 🔍 Detective Quest - Nível Mestre

Bem-vindo ao **Detective Quest**, a versão final do sistema de investigação da Enigma Studios. Este projeto consolida todos os conceitos de estruturas de dados avançadas para criar uma experiência de jogo de mistério completa.

## 🎯 Objetivo do Nível Mestre
O objetivo deste nível foi implementar um sistema completo de dedução lógica. O jogador explora uma mansão (Árvore Binária), coleta evidências (BST) e utiliza um sistema de indexação (Tabela Hash) para relacionar provas a suspeitos e realizar um julgamento final.

## ⚙️ Funcionalidades Implementadas
* **Navegação Inteligente:** Exploração da mansão via árvore binária com busca de pistas em tempo real.
* **Sistema de Arquivamento (BST):** Todas as pistas encontradas são armazenadas em uma Árvore de Busca Binária, garantindo organização alfabética automática.
* **Dossiê Criminal (Tabela Hash):** Associação eficiente de pistas a suspeitos através de uma tabela hash com tratamento de colisões por encadeamento.
* **Sistema de Julgamento:** Lógica de verificação que valida a acusação do jogador baseada na quantidade de evidências (mínimo de duas pistas para condenação).

## 🚀 Tecnologias Utilizadas
* **Linguagem:** C
* **Estruturas:** Árvores Binárias (Mapa e Pistas), Tabela Hash.
* **Alocação:** Dinâmica (`malloc`/`free`).
* **Lógica:** Recursividade e Algoritmos de Busca.

## 🛠️ Como Executar
1. Compile todos os arquivos (ou o arquivo único):
   ```bash
   gcc detective_quest.c -o detective_quest

   Execute o jogo:

   ./detective_quest

   Desenvolvido por Lucas para o desafio técnico da Enigma Studios.