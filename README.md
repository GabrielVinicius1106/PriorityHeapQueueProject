# Priority Heap Queue Project

**Visão Geral**

Este projeto consiste na implementação de uma Fila de Prioridade (Priority Queue) utilizando a estrutura de dados Max-Heap na linguagem C. O sistema é capaz de ler milhares de registros a partir de um arquivo CSV, inseri-los na estrutura mantendo a propriedade do Max-Heap, e realizar testes de performance e alocação dinâmica de memória.

**Estrutura do Repositório**

```
app.py: Script auxiliar em Python.
```

```
dataset.csv: Base de dados contendo os registros a serem carregados no Heap.
```

```
main.c: Ponto de entrada para a execução do programa principal.
```

```
performance.c: Módulo dedicado à execução de baterias de testes de estresse e performance da estrutura.
```

```
main.sh / performance.sh: Scripts Bash automatizados para compilação e execução do código.
```

```
src/: Diretório contendo as implementações e cabeçalhos:
```

```
struct.h: Definição das estruturas de dados base (ex: Item).
```

```
heap.c / heap.h: Implementação da estrutura Heap, inserção, remoção e operação de sift-up.
```

```
arq.c / arq.h: Funções de leitura de CSV, manipulação de arquivos e utilitários.
```

**Pré-requisitos**

Para compilar e executar este projeto, o seu ambiente deve conter:

- Sistema Operacional baseado em Unix (Linux, macOS) ou WSL no Windows.

- Compilador GCC (GNU Compiler Collection).

- Interpretador de linha de comando Bash para execução dos scripts.

**Como Compilar e Executar**

O projeto possui scripts de automação que cuidam da compilação, geração do executável e limpeza de arquivos temporários.

1. Para executar o programa principal:
No terminal, conceda permissão de execução ao script (se necessário) e execute:

```
chmod +x main.sh
./main.sh
```

2. Para executar os testes de performance:
Para validar a complexidade computacional empírica da estrutura sob diferentes cargas de dados:

```
chmod +x performance.sh
./performance.sh
```

**Análise em Python**

A aplicação em Python exige a criação do arquivo *dataset_result.csv*, criada na execução do arquivo *performance.c*

Para executar o código em Python

- Criar Ambiente Virtual

```
python3 -m venv venv
```

- Iniciar Ambiente Virtual

```    
source venv/bin/activate
```

- Instalar Dependências:

```
pip install numpy matplotlib pandas
```

- Executar Aplicação

```
python3 app.py
```

- Esta aplicação cria as figuras: *analise001.png* e *analise002.png*

- Para sair do Ambiente Virtual: *exit*