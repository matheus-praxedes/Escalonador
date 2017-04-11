/******************************************
*Universidade Federal da Paraíba - UFPB
*Centro de Informática - CI
*
*Sistemas Operacionais 1 - 2016.2
*
*Aluno: Matheus Maranhão Rêgo Praxedes
*Matrícula: 11403744
*
*Trabalho 1
*Data de entrega: 13/04/2017
*******************************************/

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
bool comparar1(const Processo& p1, const Processo& p2);
bool comparar2(const Processo& p1, const Processo& p2);



#endif


