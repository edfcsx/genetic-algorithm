/**********************************************************************************
// Main (Arquivo de Origem)
//
// Cria��o:     15 Out 2022
// Atualiza��o: 15 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Esse programa consiste na resolu��o do problema de otimiza��o, onde existe uma determinada mochila
//				que comporta no m�ximo 20kgs de objetos, o programa consiste em tentar encontrar
//				os objetos que somem o maior valor poss�vel, mas sem extrapolar sua capacidade de peso.
//				cada objeto possui um peso e um valor associado.
//
//				PS: Esse programa foi encomendado por Arsene Lupin o maior dos ladr�es.
//
**********************************************************************************/

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include "./Binary.h"
#include "./Genetic.h"
#include "./Random.h"
#include "./Types.h"
#include "./Constants.h"

using namespace std;

struct Object {
	uint weight;
	uint value;
};

struct SolutionSummary {
	ushort num;
	bitset<16> binary;

	int weight;
	int value;
} typedef SolutionSummary;

/*
	Retorna o n�mero de revolu��es, as revolu��es indicam quantas repeti��es
	ser�o feitas pela procura da melhor otimiza��o.
*/
uint getRevolutions();

/*
	Retorna um vetor de inteiros positivos de 16 bits, que ser�o as solu��es
	inicias, a partir delas outras ser�o buscadas.
*/
vector<ushort> getInitialSolutions();

/*
	Retorna um vetor com a lista de objetos que poder�o ser incluidos na mochila.
*/
vector<Object> makeObjectsList();

/*
	Recebe um inteiro de 16 bits como solu��o e a lista de objetos poss�veis,
	assim fazendo a soma de todos os objetos presentes na solu��o e retornando
	um SolutionSummary contendo todas as informa��es de verifica��o da solu��o.
*/
SolutionSummary evaluateSolution(ushort solution, vector<Object> objects);

/*
	Imprime no console a lista de solu��es com o resultado da avalia��o
*/
void printSolutions(vector<SolutionSummary> solutions);

/*
	Receber um vetor com uma lista de solu��es e retornas as solu��es promissoras
	sendo as que n�o excedem o valor de 20 kgs.
*/
vector<SolutionSummary> extractBestSolutions(vector<SolutionSummary> solutions);

int main(int argc, char* argv[])
{
	system("chcp 1252 > nul");
	system("cls");

	uint revolutions = getRevolutions();
	vector<Object> objects = makeObjectsList();
	vector<SolutionSummary> starterSummarySolutions = {};

	for (ushort solution : getInitialSolutions()) {
		starterSummarySolutions.push_back(evaluateSolution(solution, objects));
	}

	printSolutions(starterSummarySolutions);
	cout << "\tEsses s�o os resultados das solu��es iniciais";

	vector<SolutionSummary> solutions = extractBestSolutions(starterSummarySolutions);
	vector<SolutionSummary> lastSolutions = {};
	SolutionSummary bestSolution = solutions[0];


	for (int i = 0; i <= (int) revolutions; i++) {
		vector<ushort> tempSolutions = {};

		for (SolutionSummary s : solutions) {
			tempSolutions.push_back(s.num);
			tempSolutions.push_back(Genetic::simpleMutation(s.num));
			tempSolutions.push_back(Genetic::doubleMutation(s.num));
			tempSolutions.push_back(Genetic::singlePointCrossing(solutions[0].num, solutions[1].num));
			tempSolutions.push_back(Genetic::ArithmeticCrossing(solutions[0].num, solutions[1].num));
		}

		vector<SolutionSummary> tempSummary = {};
		for (ushort valuateSolution : tempSolutions) {
			tempSummary.push_back(evaluateSolution(valuateSolution, objects));
		}
		
		solutions = extractBestSolutions(tempSummary);
		lastSolutions = tempSummary;

		if (solutions[0].value > bestSolution.value) {
			bestSolution = solutions[0];
		}
	}

	cout << endl << "\t�ltimos resultados antes do veredito final";
	printSolutions(lastSolutions);

	cout << endl << "\tA melhor solu��o encontrada foi" << endl;
	vector<SolutionSummary> result = { bestSolution };
	printSolutions(result);

	return 0;
}

SolutionSummary evaluateSolution(ushort solution, vector<Object> objects)
{
	SolutionSummary s = {};
	s.num = solution;
	s.binary = bitset<16>(solution);

	for (int pos = 0; pos <= 15; pos++) {
		if (Binary::bitState(solution, pos)) {
			s.value += objects[pos].value;
			s.weight += objects[pos].weight;
		}
	}
	
	return s;
}

vector<Object> makeObjectsList()
{
	vector<Object> v = {};

	v.push_back({ .weight = 12, .value = 4 });
	v.push_back({ .weight = 3,	.value = 4 });
	v.push_back({ .weight = 5,	.value = 8 });
	v.push_back({ .weight = 4,	.value = 10 });
	v.push_back({ .weight = 9,	.value = 15 });
	v.push_back({ .weight = 1,	.value = 3 });
	v.push_back({ .weight = 2,	.value = 1 });
	v.push_back({ .weight = 3,	.value = 1 });
	v.push_back({ .weight = 4,	.value = 2 });
	v.push_back({ .weight = 1,	.value = 10 });
	v.push_back({ .weight = 2,	.value = 20 });
	v.push_back({ .weight = 4,	.value = 15 });
	v.push_back({ .weight = 5,	.value = 10 });
	v.push_back({ .weight = 2,	.value = 3 });
	v.push_back({ .weight = 4,	.value = 4 });
	v.push_back({ .weight = 1,	.value = 12 });

	reverse(v.begin(), v.end());

	return v;
}

uint getRevolutions()
{
	cout << "Informe o n�mero de revolu��es: ";
	uint revolutions{ 0 };
	cin >> revolutions;

	return revolutions;
}

vector<ushort> getInitialSolutions()
{
	cout << "Informe 6 solu��es iniciais que sejam inteiros positivos (digite qualquer caractere para finalizar a entrada de dados):\n";
	vector<ushort> startSolutions = {};
	ushort input;

	while (cin >> input) {
		startSolutions.push_back(input);
	}

	return startSolutions;
}

void printSolutions(vector<SolutionSummary> solutions)
{
	cout << endl << endl;

	cout << "\tResultado da Avalia��o" << endl;
	cout << "\t----------------------" << endl;

	for (SolutionSummary s : solutions) {
		cout << "\t";
		cout << right; cout.width(5); cout << s.num;
		cout << " - ";
		cout << "$" << s.value;
		cout << " - ";
		cout << s.weight << "Kg";
		cout << " - ";
		
		if (s.weight > 20)
			cout << red << "X" << default;
		else
			cout << green << "OK" << default;

		cout << endl;
	}

	cout << endl << endl;
}

vector<SolutionSummary> extractBestSolutions(vector<SolutionSummary> solutions)
{
	vector<SolutionSummary> v = {};

	for (SolutionSummary s : solutions) {
		if (s.weight <= 20)
			v.push_back(s);
	}

	sort(v.begin(), v.end(), [](SolutionSummary& x, SolutionSummary& y) { return x.value > y.value; });

	if (v.size() > 2)
		return vector<SolutionSummary>{v[0], v[1]};

	return v;
}
