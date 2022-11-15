/**********************************************************************************
// Genetic (Arquivo de Cabe�alho)
//
// Cria��o:     14 Out 2022
// Atualiza��o: 14 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define m�todos padr�es para a utiliza��o de algoritmos geneticos.
//
//				Um algoritmo gen�tico � uma t�cnica de busca utilizada na ci�ncia da computa��o
//				e em investiga��o operacional para achar solu��es aproximadas em problemas de otimiza��o e busca.
//
**********************************************************************************/

#include "Types.h"

namespace Genetic {
	/*
		Recebe dois valores inteiros de 16 bits representando as solu��es e 
		retorna um valor inteiro de 16 bits representando o cruzamento de ponto �nico entre as solu��es;

		o cruzamento tipo ponto �nico gera uma nova solu��o a partir de duas
		solu��es existentes, copiando parte dos bits da primeira solu��o e o restante da
		segunda solu��o.

		Solu��es em 16 bits:
		A = 11101100 | 01011000
		B = 01100001 | 10101000
		Nova = 11101100 + 10101000

		copiando uma parte da primeira solu��o com uma outra parte da segunda solu��o assim formando
		uma nova solu��o.
	*/
	ushort singlePointCrossing(ushort solution1, ushort solution2);

	/*
		Recebe dois valores inteiros de 16 bits representando as solu��es e 
		retorna um valor inteiro de 16 bits representando o cruzamento aritm�tico entre as solu��es;

		o cruzamento tipo aritm�tico gera uma nova solu��o a partir de
		duas existentes, usando o bit 1 nas posi��es em que ambas solu��es iniciais sejam 1
		e 0, caso contr�rio.

		Solu��es em 16 bits:
		A = 0011000000101001
		B = 1001010010100110
		Nova = 0001000000100000
	*/
	ushort ArithmeticCrossing(ushort solution1, ushort solution2);

	/*
		Recebe um valor inteiro de 16 bits representando uma solu��o e retorna um 
		valor inteiro de 16 bits representando a muta��o simples da solu��o.

		A muta��o simples modifica um bit de uma solu��o existente, obtendo
		assim uma nova solu��o, o bit modificado deve ser randomico.
	*/
	ushort simpleMutation(ushort solution);

	/*
		Recebe um valor inteiro de 16 bits representando uma solu��o e retorna um valor
		inteiro de 16 bits representando a muta��o dupla da solu��o.

		A muta��o dupla tem o mesmo comportamento da simples, mas a nova
		solu��o tem dois bits modificados, no lugar de apenas um, os bits modificados devem ser randomicos.
	*/
	ushort doubleMutation(ushort solution);
}
