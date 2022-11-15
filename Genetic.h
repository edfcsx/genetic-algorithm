/**********************************************************************************
// Genetic (Arquivo de Cabeçalho)
//
// Criação:     14 Out 2022
// Atualização: 14 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Define métodos padrões para a utilização de algoritmos geneticos.
//
//				Um algoritmo genético é uma técnica de busca utilizada na ciência da computação
//				e em investigação operacional para achar soluções aproximadas em problemas de otimização e busca.
//
**********************************************************************************/

#include "Types.h"

namespace Genetic {
	/*
		Recebe dois valores inteiros de 16 bits representando as soluções e 
		retorna um valor inteiro de 16 bits representando o cruzamento de ponto único entre as soluções;

		o cruzamento tipo ponto único gera uma nova solução a partir de duas
		soluções existentes, copiando parte dos bits da primeira solução e o restante da
		segunda solução.

		Soluções em 16 bits:
		A = 11101100 | 01011000
		B = 01100001 | 10101000
		Nova = 11101100 + 10101000

		copiando uma parte da primeira solução com uma outra parte da segunda solução assim formando
		uma nova solução.
	*/
	ushort singlePointCrossing(ushort solution1, ushort solution2);

	/*
		Recebe dois valores inteiros de 16 bits representando as soluções e 
		retorna um valor inteiro de 16 bits representando o cruzamento aritmético entre as soluções;

		o cruzamento tipo aritmético gera uma nova solução a partir de
		duas existentes, usando o bit 1 nas posições em que ambas soluções iniciais sejam 1
		e 0, caso contrário.

		Soluções em 16 bits:
		A = 0011000000101001
		B = 1001010010100110
		Nova = 0001000000100000
	*/
	ushort ArithmeticCrossing(ushort solution1, ushort solution2);

	/*
		Recebe um valor inteiro de 16 bits representando uma solução e retorna um 
		valor inteiro de 16 bits representando a mutação simples da solução.

		A mutação simples modifica um bit de uma solução existente, obtendo
		assim uma nova solução, o bit modificado deve ser randomico.
	*/
	ushort simpleMutation(ushort solution);

	/*
		Recebe um valor inteiro de 16 bits representando uma solução e retorna um valor
		inteiro de 16 bits representando a mutação dupla da solução.

		A mutação dupla tem o mesmo comportamento da simples, mas a nova
		solução tem dois bits modificados, no lugar de apenas um, os bits modificados devem ser randomicos.
	*/
	ushort doubleMutation(ushort solution);
}
