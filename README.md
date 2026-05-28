link github: https://github.com/richard-247/projeto-conversao-de-bases

Alunos de Ciência da Computação da UFLA - Universidade Federal de Lavras

Alunos: Luis Fellipe Dias Teodoro e Nycollas Richard Pereira dos Santos

Turma: 10A

Linguagem utilizada: C++

Instruções de execução: No main.cpp, foram puxadas todas as funções propostas no trabalho, a nível de teste, com valores fixos

Exemplos de uso: O programa pode ser usado pra fazer conversões entre todas as bases numéricas, e além disso, possui o modo passo a 
passo que imprime o caminho das operações, o modo quiz que testa o conhecimento do usuário, o modo batch que pega informações de um arquivo
e gera um arquivo de saída com os resultados das conversões, e por fim, possui uma calculadora de máximos, que calcula o valor máximo que
pode ser obtido com n bits de todas as bases.

Limitações conhecidas: O programa não suporta números muito grandes, com precisão maior que 16, por exemplo. Ademais, utiliza a função
pow() da biblioteca cmath, que realiza potenciação, e gera um valor double, isso causa alguma limitação quanto a precisão do número.

URL do video no youtube: https://youtu.be/AR0w1O9M8Qs

| Nº | Conversão             | Entrada | Resultado Esperado |
| -- | --------------------- | ------- | ------------------ |
| 1  | Decimal → Binário     | 10      | 1010               |
| 2  | Decimal → Octal       | 10      | 12                 |
| 3  | Decimal → Hexadecimal | 10      | A                  |
| 4  | Decimal → Binário     | 255     | 11111111           |
| 5  | Decimal → Octal       | 255     | 377                |
| 6  | Decimal → Hexadecimal | 255     | FF                 |
| 7  | Decimal → Binário     | 10.5    | 1010.1             |
| 8  | Decimal → Octal       | 10.5    | 12.4               |
| 9  | Decimal → Hexadecimal | 10.5    | A.8                |
| 10 | Binário → Decimal     | 1010    | 10                 |
| 11 | Binário → Octal       | 1010    | 12                 |
| 12 | Binário → Hexadecimal | 1010    | A                  |
| 13 | Binário → Decimal     | 1010.1  | 10.5               |
| 14 | Binário → Octal       | 1010.1  | 12.4               |
| 15 | Binário → Hexadecimal | 1010.1  | A.8                |
| 16 | Octal → Decimal       | 12      | 10                 |
| 17 | Octal → Binário       | 12      | 001010             |
| 18 | Octal → Hexadecimal   | 12      | A                  |
| 19 | Octal → Decimal       | 12.4    | 10.5               |
| 20 | Octal → Binário       | 12.4    | 001010.100         |
| 21 | Octal → Hexadecimal   | 12.4    | A.8                |
| 22 | Hexadecimal → Decimal | A       | 10                 |
| 23 | Hexadecimal → Binário | A       | 1010               |
| 24 | Hexadecimal → Octal   | A       | 12                 |
| 25 | Hexadecimal → Decimal | A.8     | 10.5               |
| 26 | Hexadecimal → Binário | A.8     | 1010.1000          |
| 27 | Hexadecimal → Octal   | A.8     | 12.4               |
| 28 | Decimal → Binário     | 0       | 0                  |
| 29 | Decimal → Octal       | 0       | 0                  |
| 30 | Decimal → Hexadecimal | 0       | 0                  |
