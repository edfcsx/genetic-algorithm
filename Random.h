/**********************************************************************************
// Types (Arquivo de Cabeçalho)
//
// Criação:     14 Out 2022
// Atualização: 15 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Define métodos padrões que serão utilizados para se obter resultados
//				randômicos.
//
**********************************************************************************/
#include <vector>
#include "Types.h"

#ifndef RANDOM_H
#define RANDOM_H

namespace Random {
	/*
		Retorna um inteiro positivo randômico entre o intervalo de minNum e maxNum.
	*/
	uint randomUINT(uint minNum, uint maxNum);

	/*
		Retorna um vetor de inteiros positivos randômicos entre o intervalo de minNum e maxNum;
		O tamanho do vetor é definido pelo atributo batchLength, caso o número seja maior que o
		intervalo entre minNum e maxNum, será retornado o intervalo completo entre esses valores.
	*/
	std::vector<uint> randomBatchUINT(uint minNum, uint maxNum, uint batchLength);
}

#endif // !RANDOM_H
