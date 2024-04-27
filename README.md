<h1 align="center">- Simples algoritmo de ordenação -</h1>

<div align="center">
    <a href="#" style="cursor: none;">
		<img src="https://s13.gifyu.com/images/SCGkS.gif" alt="Radix sort" border="0"/>
	</a>
</div>

# Push_swap

Push_swap é um projeto em C que implementa um algoritmo de ordenação utilizando duas pilhas. O objetivo é ordenar uma sequência de números passada como entrada para o programa.

## Funcionalidades

O projeto Push_swap utiliza as seguintes funcionalidades:

- Estrutura de lista duplamente encadeada: Cada nó contém um índice e um valor, representando os números a serem ordenados.
- Makefile: Arquivo de script utilizado para compilar o código fonte e criar o executável do programa push_swap.
- Algoritmo de ordenação semelhante ao radix: O algoritmo faz a ordenação bit a bit, movendo os números para a pilha B de acordo com o valor de bits específicos, e depois retorna os números para a pilha A.
- Movimentos disponíveis:
  - `sa`: Troca os 2 primeiros elementos no topo da pilha A.
  - `sb`: Troca os 2 primeiros elementos no topo da pilha B.
  - `ss`: Executa `sa` e `sb` ao mesmo tempo.
  - `pa`: Move o primeiro elemento no topo da pilha B para o topo da pilha A.
  - `pb`: Move o primeiro elemento no topo da pilha A para o topo da pilha B.
  - `ra`: Rotaciona para cima todos os elementos da pilha A. O primeiro elemento se torna o último.
  - `rb`: Rotaciona para cima todos os elementos da pilha B. O primeiro elemento se torna o último.
  - `rr`: Executa `ra` e `rb` ao mesmo tempo.
  - `rra`: Rotaciona para baixo todos os elementos da pilha A. O último elemento se torna o primeiro.
  - `rrb`: Rotaciona para baixo todos os elementos da pilha B. O último elemento se torna o primeiro.
  - `rrr`: Executa `rra` e `rrb` ao mesmo tempo.

## Compilando e Executando

Para compilar o projeto, você pode usar o Makefile fornecido. Basta executar o comando `make` no terminal no diretório do projeto. Isso irá compilar o código fonte e criar o executável `push_swap`.

Para executar o programa, basta passar a sequência de números como argumento:

```bash
./push_swap [números]
```
