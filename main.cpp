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

#include "escalonador.hpp"

int main (int argc, char* argv[]){

	
	std::ifstream entrada(argv[1]);
	std::string linha;
	int numero_de_processos = 0;

	while(!entrada.eof()){
		std::getline(entrada, linha);
		numero_de_processos++;
	}
	
	entrada.close();
	entrada.open(argv[1]);
	
	
	Processo *processos = new Processo[numero_de_processos]; 

	for(int i = 0; i < numero_de_processos; i++){

		processos[i].pid = i;
		entrada >> processos[i].tempo_de_chegada >> processos[i].duracao_do_processo;
		processos[i].tempo_restante = processos[i].duracao_do_processo;
		
		if(processos[i].duracao_do_processo == 0){

			numero_de_processos = numero_de_processos - 1; 
		}	
	}

	std::stable_sort(processos, processos + numero_de_processos, comparar2);
	//std::sort(processos, processos + numero_de_processos, comparar2);

	FCFS(processos, numero_de_processos);
	SJF(processos, numero_de_processos);
	RR(processos, numero_de_processos);

	delete[] processos; //destrutor
	return 0; 
}