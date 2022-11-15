# Algoritmo Genético

Algoritmos Genéticos (GAs: Genetic Algorithms) são algoritmos matemáticos inspirados nos mecanismos de evolução natural e recombinação genética. A técnica de Algoritmos Genéticos fornece um mecanismo de busca adaptativa que se baseia no princípio Darwiniano de reprodução e sobrevivência dos mais aptos.

## Problema da Mochila
O problema consiste em levar em uma mochila os objetos que somem o maior valor possível, mas sem extrapolar sua capacidade de peso. Cada objeto possui um peso e um valor associado.

o problema está totalmente descrito no arquivo <b>challenger.pdf</b>, a implementação não seguiu todas as regras contidas no documento tendo em vista que não sou aluno da universidade onde esse desafio foi proposto.

### Como utilizar?
você deve importar todos os arquivos em um projeto do visual studio code, esse programa não foi testado no linux. 

<i>quais são os parâmetros que devem ser passados para a execução do programa?</i>
<ul>
    <li><b>Número de revoluções</b>: define a quantidade de execuções que serão executadas na busca da melhor solução.</li>
    <li><b>Soluções iniciais</b>: são números que representam soluções que serão o ponto de partida de melhoria/otimização, a partir dessas soluções o programa irá procurar soluções melhores, a quantidade de soluções iniciais vai de acordo com o desejo do usuário, recomenda-se um valor de 6 valores iniciais que podem ser (recomendação):
    <ul>
        <li>60504</li>
        <li>25000</li>
        <li>12329</li>
        <li>38054</li>
        <li>1259</li>
        <li>732</li>
    </ul>esses valores númericos representam os objetos contidos na bolsa, conforme representação da tabela contida no documento <b>challenger.pdf</b>. esses valores podem ser alterados contato que respeitem o valor máximo de 16 bits sem sinal que vai do intervalo 0 até 65535. valores maiores que isso não irão funcionar pois todo o algoritmo foi construido sobre uma arquitetura de valores inteiros de 16 bits.
    </li>
</ul>

todos os arquivos foram codificados utilizando o charset: windows 1252.

# Genetic Algorithm

Genetic Algorithms (GAs: Genetic Algorithms) are mathematical algorithms inspired by the mechanisms of natural evolution and genetic recombination. The Genetic Algorithms technique provides an adaptive search engine that is based on the Darwinian principle of reproduction and survival of the fittest.

## Backpack Problem
The problem is to carry in a backpack the objects that add up to the highest possible value, but without extrapolating their weight capacity. Each object has a weight and an associated value.

the problem is fully described in the <b>challenger.pdf</b> file, the implementation did not follow all the rules contained in the document since I am not a student at the university where this challenge was proposed.

### How to use?
you must import all files into a visual studio code project, this program has not been tested on linux.

<i>what parameters must be passed to run the program?</i>
<ul>
    <li><b>Number of revolutions</b>: defines the number of executions that will be executed in the search for the best solution.</li>
    <li><b>Initial solutions</b>: these are numbers that represent solutions that will be the starting point of improvement/optimization, from these solutions the program will look for better solutions, the amount of initial solutions will depend on the user's wish, a value of 6 initial values ​​is recommended which can be (recommendation):
    <ul>
        <li>60504</li>
        <li>25000</li>
        <li>12329</li>
        <li>38054</li>
        <li>1259</li>
        <li>732</li>
    </ul>these numerical values ​​represent the objects contained in the bag, as represented in the table contained in the document <b>challenger.pdf</b>. these values ​​can be changed as long as they respect the maximum value of 16 unsigned bits that goes from the range 0 to 65535. values ​​greater than this will not work because the entire algorithm was built on an architecture of 16-bit integer values.
    </li>
</ul>

all files were encoded using charset: windows 1252.