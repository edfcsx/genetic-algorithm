#include <vector>
#include "Genetic.h"
#include "Binary.h"
#include "Random.h"

ushort Genetic::singlePointCrossing(ushort solution1, ushort solution2)
{
    ushort root{ 0 };

    for (int i = 0; i <= 7; i++) {
        if (Binary::bitState(solution2, i))
            root = Binary::turnOnBit(root, i);
    }

    for (int w = 8; w <= 15; w++) {
        if (Binary::bitState(solution1, w))
            root = Binary::turnOnBit(root, w);
    }

    return root;
}

ushort Genetic::ArithmeticCrossing(ushort solution1, ushort solution2)
{
    return Binary::AND(solution1, solution2);
}

ushort Genetic::simpleMutation(ushort solution)
{
    uint mutationBitPosition = Random::randomUINT(0, 15);
    
    if (Binary::bitState(solution, mutationBitPosition))
        solution = Binary::turnOffBit(solution, mutationBitPosition);
    else
        solution = Binary::turnOnBit(solution, mutationBitPosition);

    return solution;
}

ushort Genetic::doubleMutation(ushort solution)
{
    std::vector<uint> mutationsPositions = Random::randomBatchUINT(0, 15, 2);

    for (uint mutationPosition : mutationsPositions) {
        if (Binary::bitState(solution, mutationPosition))
            solution = Binary::turnOffBit(solution, mutationPosition);
        else
            solution = Binary::turnOnBit(solution, mutationPosition);
    }

    return solution;
}
