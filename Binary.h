/**********************************************************************************
// Binary (Arquivo de Cabeçalho)
//
// Criação:     14 Out 2022
// Atualização: 14 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   define métodos padrões para operações com bits;
//
**********************************************************************************/

#ifndef BINARY_H
#include "Types.h"

namespace Binary {
	/*
		turnOnBit - recebe um valor inteiro de 16bits e a posição do bit a ser ligado,
		retornando um valor inteiro de 16bits como resultado da modificação do bit.
	*/
	ushort turnOnBit(ushort byte, uint position);

	/*
		turnOffBit - recebe um valor inteiro de 16 bits e a posição do bit a ser desligado,
		retornando um valor inteiro de 16 bits como resultado da modificação do bit.
	*/
	ushort turnOffBit(ushort byte, uint position);

	/*
		bitState - recebe um valor inteiro de 16 bits e a posição do bit a ser testado,
		retornando um booleano para indicar se o bit está ligado ou não.
	*/
	bool bitState(ushort byte, uint position);

	/*
		AND - recebe dois valores inteiros de 16 bits e retorna um inteiro de 16 bits representando o
		resultado da operação AND bit a bit entre os números recebidos.
	*/
	ushort AND(ushort byteX, ushort byteY);

	/*
		OR - recebe dois valores inteiros de 16 bits e retorna um inteiro de 16bits representando o
		resultado da operação OR bit a bit entre os números recebidos.
	*/
	ushort OR(ushort byteX, ushort byteY);
	
	/*
		getLowBits - recebe um valor inteiro de 16 bits e retorna os 8 primeiros bits (bits de baixa ordem),
		sendo os bits da posição 0 a 7 em um inteiro de 16 bits desligando todos os bits do 8 a 15.
	*/
	ushort getLowBits(ushort byte);

	/*
		getHighBits - recebe um valor inteiro de 16 bits e retorna os 8 últimos bits (bits de alta ordem),
		sendo os bits da posição 8 a 15 em um inteiro de 8 bits.
	*/
	ushort getHighBits(ushort byte);
}

#endif // !BINARY_H
