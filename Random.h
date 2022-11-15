/**********************************************************************************
// Types (Arquivo de Cabe�alho)
//
// Cria��o:     14 Out 2022
// Atualiza��o: 15 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define m�todos padr�es que ser�o utilizados para se obter resultados
//				rand�micos.
//
**********************************************************************************/
#include <vector>
#include "Types.h"

#ifndef RANDOM_H
#define RANDOM_H

namespace Random {
	/*
		Retorna um inteiro positivo rand�mico entre o intervalo de minNum e maxNum.
	*/
	uint randomUINT(uint minNum, uint maxNum);

	/*
		Retorna um vetor de inteiros positivos rand�micos entre o intervalo de minNum e maxNum;
		O tamanho do vetor � definido pelo atributo batchLength, caso o n�mero seja maior que o
		intervalo entre minNum e maxNum, ser� retornado o intervalo completo entre esses valores.
	*/
	std::vector<uint> randomBatchUINT(uint minNum, uint maxNum, uint batchLength);
}

#endif // !RANDOM_H
