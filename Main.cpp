/**********************************************************************************
// Main (Arquivo de Origem)
//
// Criação:     15 Out 2022
// Atualização: 15 Out 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Esse programa consiste na resolução do problema de otimização, onde existe uma determinada mochila
//				que comporta no máximo 20kgs de objetos, o programa consiste em tentar encontrar
//				os objetos que somem o maior valor possível, mas sem extrapolar sua capacidade de peso.
//				cada objeto possui um peso e um valor associado.
//
//				PS: Esse programa foi encomendado por Arsene Lupin o maior dos ladrões.
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
	Retorna o número de revoluções, as revoluções indicam quantas repetições
	serão feitas pela procura da melhor otimização.
*/
uint getRevolutions();

/*
	Retorna um vetor de inteiros positivos de 16 bits, que serão as soluções
	inicias, a partir delas outras serão buscadas.
*/
vector<ushort> getInitialSolutions();

/*
	Retorna um vetor com a lista de objetos que poderão ser incluidos na mochila.
*/
vector<Object> makeObjectsList();

/*
	Recebe um inteiro de 16 bits como solução e a lista de objetos possíveis,
	assim fazendo a soma de todos os objetos presentes na solução e retornando
	um SolutionSummary contendo todas as informações de verificação da solução.
*/
SolutionSummary evaluateSolution(ushort solution, vector<Object> objects);

/*
	Imprime no console a lista de soluções com o resultado da avaliação
*/
void printSolutions(vector<SolutionSummary> solutions);

/*
	Receber um vetor com uma lista de soluções e retornas as soluções promissoras
	sendo as que não excedem o valor de 20 kgs.
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
	cout << "\tEsses são os resultados das soluções iniciais";

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

	cout << endl << "\tÚltimos resultados antes do veredito final";
	printSolutions(lastSolutions);

	cout << endl << "\tA melhor solução encontrada foi" << endl;
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
	cout << "Informe o número de revoluções: ";
	uint revolutions{ 0 };
	cin >> revolutions;

	return revolutions;
}

vector<ushort> getInitialSolutions()
{
	cout << "Informe 6 soluções iniciais que sejam inteiros positivos (digite qualquer caractere para finalizar a entrada de dados):\n";
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

	cout << "\tResultado da Avaliação" << endl;
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
