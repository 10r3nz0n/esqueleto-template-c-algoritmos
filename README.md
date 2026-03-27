# Esqueleto Template em C para Algoritmos

Material autoral do professor **Valdemar Lorenzon Junior**.

- share do código: https://onlinegdb.com/s1DBBBL5U

## Visão geral

Este repositório reúne um **template base para a disciplina de algoritmos com estudo de caso em C**, com foco em projetos pequenos, reutilização de código e redução de problemas recorrentes de entrada e saída em terminal. A proposta é deslocar a atenção do estudante para a **lógica do problema, o fluxo do programa, a modularização e a criação de funções**, sem deixar que detalhes operacionais de `scanf`, `getchar`, `fgets`, limpeza de buffer e especificadores de formato prejudiquem a aprendizagem logo no início.

O projeto já organiza a aplicação em módulos de apoio geral e de entrada/saída, além de trazer um `main` enxuto como ponto de partida para exercícios, estudos de caso e experimentações em aula. A aplicação principal limpa a tela, exibe um cabeçalho, lê um nome com `scanString`, imprime mensagens no terminal e finaliza com pausa e mensagem de encerramento.

## Objetivo didático

A ideia deste template é oferecer uma base para que o aluno possa:

- estruturar programas em C com **separação entre interface (`.h`) e implementação (`.c`)**
- reaproveitar funções de entrada e saída em diferentes exercícios
- reduzir erros comuns relacionados a:
  - buffer de teclado
  - leitura de tipos básicos
  - leitura de texto
  - mistura entre `scanf`, `getchar` e `fgets`
  - saída formatada em terminal
- praticar **modularização**, **abstração de funções utilitárias** e **organização de pequenos projetos**
- compreender, a partir de código concreto, como a camada mais básica da linguagem lida com **input** e **output** em terminal

Em vez de repetir, a cada exercício, toda a mecânica de leitura e tratamento de entrada, o estudante pode usar um conjunto mínimo de funções auxiliares e concentrar energia no raciocínio algorítmico e na construção da solução. O módulo `ioutils` expõe funções para inteiro, `float`, `double`, `char`, `string` e quebra de linha, enquanto `apputils` concentra utilidades gerais da aplicação, como limpeza de buffer, limpeza de tela, pausa, cabeçalho e mensagem final.

## O que este repositório procura resolver

Em aulas introdutórias de C, é comum que boa parte da dificuldade prática não esteja apenas na lógica, mas em detalhes como:

- qual especificador usar no `scanf` e no `printf`
- quando limpar o buffer
- por que uma leitura de `char` captura o `\n`
- como ler uma frase inteira
- como evitar que a entrada em terminal “quebre” o fluxo do programa
- como organizar melhor funções que se repetem em vários exercícios

Este template foi pensado justamente para **encapsular parte desses problemas** em funções simples, de modo que o estudante possa ler, usar, adaptar e evoluir a base com mais segurança. Ao mesmo tempo, o repositório também serve como **objeto de estudo**, porque mostra como construir esse tipo de abstração usando recursos fundamentais da própria linguagem C. A implementação atual traz leitura recursiva para `int`, laços para `float`, `double` e `char`, leitura de string com `fgets`, funções específicas de impressão e uma função de quebra de linha.

## Estrutura do repositório

### `main.c`

Arquivo principal com um exemplo simples de execução do template. Ele mostra um fluxo básico de programa em terminal: limpeza de tela, exibição de cabeçalho, leitura de nome, saída de mensagens e pausa final. Também reforça a organização do raciocínio com declarações no topo, inicialização de variáveis e uso das funções auxiliares.

### `apputils.h` e `apputils.c`

Módulo com funções utilitárias gerais da aplicação. O header expõe `cabecalho`, `fim`, `pausar` e `limparTela`, enquanto a implementação mostra o propósito de cada uma dessas funções no contexto da interface textual. 

### `ioutils.h` e `ioutils.c`

Módulo voltado para **entrada e saída em terminal**, com funções para leitura e apresentação de tipos básicos, além de utilitários de impressão. O header reúne `limparBuffer`, `printLn`, `printInt`, `scanInt`, `scanFloat`, `printFloat`, `printDouble`, `printChar`, `scanChar`, `printString`, `printStringLn` e `scanString`, e o body implementa a lógica de validação, impressão e limpeza de buffer correspondente. Há também, no código, um bloco comentado com uma alternativa para leitura de string via ponteiro para `char`. 

### `lib.h`
Header voltad a macros define para atender status por palavras, como verdadeiro e falso como `TRUE` e `FALSE` ao invés de 1 e 0, como os inteiros são lógicos em C. Inteiros, mas na verdade 1 e 0 como valores booleanos, mas mesmo assim, todo valor diferente de zero é verdadeiro. Também `SUCESSO` ou `FALHA` para casos como o return de main. Esta lib centraliza este tipo de necessidade para o projeto todo.

## Ideia central da abordagem

O template propõe uma espécie de “camada didática” sobre a E/S da linguagem C. Em vez de fazer o aluno começar diretamente de chamadas isoladas da biblioteca padrão em todo exercício, a proposta é trabalhar com funções nomeadas de forma mais expressiva e com responsabilidades mais claras.

Isso ajuda a:

- enfatizar **o fluxo do programa**
- padronizar leituras e saídas
- minimizar ruídos de sintaxe
- criar um ambiente mais controlado para aprendizagem
- incentivar a reutilização de código
- promover a discussão sobre **projeto de funções** e **qualidade de organização**

Ao mesmo tempo, o código permanece próximo do nível mais baixo da linguagem, permitindo que o estudante entenda **como essas abstrações são construídas** e quais problemas reais elas procuram mitigar. A própria base mostra decisões didáticas importantes, como o uso de `fgets` para leitura de frase, `getchar` para leitura de caractere com confirmação por Enter, e a centralização da limpeza de buffer em uma função utilitária.

## Como compilar

Exemplo com `gcc`:

```bash
gcc main.c apputils.c ioutils.c -o programa
```

## Como executar

No Windows:

```bash
programa.exe
```

Em sistemas Unix-like:

```bash
./programa
```

## Documentação das funções

### Funções de APP

Estas funções têm foco em comportamento geral da aplicação e apoio à interface em terminal.

#### `limparBuffer(void)`
**Propósito:** descartar caracteres restantes na entrada até `\n` ou `EOF`, evitando que leituras posteriores consumam lixo do buffer.

#### `cabecalho(char *titulo)`
**Propósito:** exibir um título no terminal, servindo como abertura visual do programa. 

#### `fim(void)`
**Propósito:** mostrar uma mensagem final de encerramento da execução. 

#### `pausar(void)`
**Propósito:** pausar o fluxo do programa até o usuário pressionar Enter. 

#### `limparTela(void)`
**Propósito:** limpar a tela do terminal com `cls` no Windows ou `clear` em sistemas Unix-like.

---

### Funções de I/O

A seguir, a documentação das funções de entrada e saída do módulo `ioutils`.

#### `printLn(void)`
**O que faz:** imprime uma quebra de linha no terminal.  
**Parâmetros:** nenhum.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
printLn();
```

#### `printInt(const int valor)`
**O que faz:** imprime um valor inteiro sem quebra automática de linha.  
**Parâmetros:** `valor`, inteiro a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
int idade = 20;
printInt(idade);
```

#### `scanInt(const char *mensagem)`
**O que faz:** exibe uma mensagem, tenta ler um inteiro e repete a leitura em caso de erro.  
**Parâmetros:** `mensagem`, texto exibido antes da leitura.  
**Retorno:** o valor inteiro lido.  
**Mini exemplo:**

```c
int idade;
idade = scanInt("Informe a idade");
```

**Observação didática:** nesta implementação, a repetição em caso de erro é feita por recursão.

#### `scanFloat(const char *mensagem)`
**O que faz:** exibe uma mensagem, lê um `float` e repete até a entrada ser válida.  
**Parâmetros:** `mensagem`, texto exibido antes da leitura.  
**Retorno:** o valor `float` lido.  
**Mini exemplo:**

```c
float altura;
altura = scanFloat("Informe a altura");
```

#### `printFloat(const float valor)`
**O que faz:** imprime um valor `float` com duas casas decimais.  
**Parâmetros:** `valor`, número a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
float nota = 8.5f;
printFloat(nota);
```

#### `scanfDouble(const char *mensagem)` / `scanDouble(const char *mensagem)`
**O que faz:** exibe uma mensagem, lê um `double` e repete até a entrada ser válida.  
**Parâmetros:** `mensagem`, texto exibido antes da leitura.  
**Retorno:** o valor `double` lido.  
**Mini exemplo:**

```c
double salario;
salario = scanDouble("Informe o salario");
```

**Observação:** no estado atual do projeto, o header está com `scanfDouble`, enquanto a implementação está com `scanDouble`. Convém padronizar os nomes no código.

#### `printDouble(const double valor)`
**O que faz:** imprime um valor `double` formatado.  
**Parâmetros:** `valor`, número a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
double media = 7.25;
printDouble(media);
```

#### `scanChar(const char *mensagem)`
**O que faz:** exibe uma mensagem, lê um caractere via `getchar` e considera a confirmação por Enter.  
**Parâmetros:** `mensagem`, texto exibido antes da leitura.  
**Retorno:** o caractere lido.  
**Mini exemplo:**

```c
char opcao;
opcao = scanChar("Informe uma letra");
```

**Observação didática:** esta função lê o primeiro caractere digitado na linha e depois limpa o restante do buffer. 

#### `printChar(const char valor)`
**O que faz:** imprime um caractere no terminal.  
**Parâmetros:** `valor`, caractere a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
char opcao = 'A';
printChar(opcao);
```

#### `scanString(const char *mensagem, char *texto, int tamanho)`
**O que faz:** exibe uma mensagem e lê uma linha de texto com `fgets`, respeitando o tamanho máximo do arranjo.  
**Parâmetros:**  
- `mensagem`: texto exibido antes da leitura  
- `texto`: arranjo de caracteres que receberá a string  
- `tamanho`: capacidade máxima do arranjo  

**Retorno:** `1` em caso de sucesso e `0` em caso de falha de leitura.  
**Mini exemplo:**

```c
char nome[20];
scanString("Informe seu nome", nome, 20);
```

**Observação didática:** esta é a versão que melhor se encaixa em programas introdutórios com arranjos locais no `main`.

#### `printString(const char *mensagem)`
**O que faz:** imprime uma string sem quebra automática de linha.  
**Parâmetros:** `mensagem`, texto a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
printString("Ola, mundo");
```

#### `printStringLn(const char *mensagem)`
**O que faz:** imprime uma string com quebra de linha ao final.  
**Parâmetros:** `mensagem`, texto a ser exibido.  
**Retorno:** nenhum.  
**Mini exemplo:**

```c
printStringLn("Fim do programa");
```

## Conteúdos que podem ser explorados com este template

Este material pode apoiar aulas, práticas e estudos de caso envolvendo:

- algoritmos básicos
- estruturas sequenciais
- estruturas condicionais
- estruturas de repetição
- funções
- modularização
- organização de projetos em C
- leitura e escrita em terminal
- tratamento de entrada inválida
- noções de interface textual
- boas práticas iniciais de separação entre `.h` e `.c`

## Exemplo de fluxo de uso

Uma proposta de uso em aula pode seguir esta ideia:

1. começar com o template pronto
2. explicar a função de cada arquivo
3. mostrar como o `main` usa as funções de apoio
4. adaptar o programa para um problema específico
5. evoluir a base com novas funções, validações ou módulos
6. discutir os erros encontrados durante o processo de leitura e entrada de dados

Assim, o repositório não funciona apenas como “código pronto”, mas como **base reutilizável e também como material de estudo sobre decisões de implementação em C**. O `main` atual ilustra essa proposta usando `limparTela`, `cabecalho`, `scanString`, `printLn`, `printString`, `pausar` e `fim` em um fluxo curto e fácil de adaptar.

## Sugestões de uso pedagógico

Este repositório pode ser utilizado como:

- base para listas de exercícios
- ponto de partida para estudos de caso
- esqueleto de pequenos projetos em C
- material de apoio para discutir erros comuns de leitura
- exemplo inicial de modularização
- laboratório para evolução incremental de funções utilitárias

## O que o estudante pode aprender com o repositório

Além de resolver exercícios, o aluno pode observar e discutir:

- por que algumas funções de leitura exigem limpeza de buffer
- por que `string` precisa de cuidados diferentes de tipos escalares
- quando usar `scanf`, `getchar` e `fgets`
- como separar responsabilidades entre módulos
- como tornar o código mais legível e reaproveitável
- como pequenos erros de I/O afetam toda a experiência de execução

## Caráter autoral e acadêmico

Este repositório constitui **material autoral do professor Valdemar Lorenzon Júnior**, desenvolvido com finalidade didática para apoio à disciplina, experimentação em aula e construção de exemplos práticos em C. A proposta é que o material possa ser expandido, ajustado e reutilizado em contextos de ensino, preservando sua natureza formativa e seu compromisso com a clareza conceitual.

## Observação importante

A intenção deste projeto não é “esconder” a linguagem C, mas **tornar o processo de entrada e saída mais controlado e pedagógico**, especialmente no início do percurso. Com isso, o estudante pode compreender melhor os fundamentos sem ficar travado, desde o começo, por detalhes operacionais que depois poderão ser estudados com mais profundidade.

## Autor

**Valdemar Lorenzon Junior**

---

Se este material ajudar no desenvolvimento dos seus estudos ou das suas aulas, adapte, expanda e use como base para construir soluções cada vez mais organizadas, reutilizáveis e didáticas.
