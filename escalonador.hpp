#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <deque>

typedef struct{

	int pid = 0;
	int duracao_do_processo = 0;
	int tempo_de_execucao = 0;
	int tempo_de_chegada = 0;
	int tempo_restante;
	
}Processo;

void FCFS(const Processo *processos, int numero_de_processos);
void SJF(const Processo *processos, int numero_de_processos);
void RR(const Processo *processos, int numero_de_processos);
bool comparacao(const Processo& p1, const Processo& p2);



#endif


