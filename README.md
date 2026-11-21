Estrutura dos arquivos:
```text
Trabalho_Prog1_Final/
├── Makefile
├── README.md
├── include/
│ ├── lista_dupla.h
│ ├── pilha.h
│ ├── fila.h
│ ├── ingredientes.h
├── src/
│ ├── main.c
│ ├── lista_dupla.c
│ ├── pilha.c
│ ├── fila.c
│ ├── ingredientes.c
└── 
```
Felipe 10/11

 Criado estrutura das pastas e arquivos, Makefile, lista simples e menu de opções para o usuário.

12//11/26

Kojima-Inicio da implementação das estacoes e das receitas e a finalização do header da lista simples encadeada.

14/11/26

Kojima - começo da criação das estruturas da lista encadeada simples(chamamos de ingredientes)

16/11/59

Kojima - Continuação da implementação das funções da lista encadeada simples

20/11/26

Felipe - Deixei a estrutura da pasta mais organizada, corrigi makefile, e *importante* mudei alguns nomes dos parametros e structs da lista simples porque quando compilava dava erro nos argumentos e no tipo das funções, então ficou:

Nó da lista simples: ingrediente
Lista simples em si: lista_simples
Argumentos nas funções: estoque(Kojima:eu tava me dando gasight achando que eu tinha trocado o nome sem saber)

21/11/26 

Felipe - Coloquei o address sanitizer no makefile, implementei lista dupla e pilha com a maioria das suas funções, atualizei o menu, e comecei a fazer a fila.

Kojima - Termino da implementação da lista simples colocando a checagem da lista vazia onde importava