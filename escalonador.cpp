#include "escalonador.hpp"

void FCFS(const Processo *processos, int numero_de_processos){

    float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;

	std::vector<Processo> proc; // fila de prontos

	int ciclo = 0;

	while(retorno != 0){ 

		for (int i= 0; i < numero_de_processos; i++){

			if(ciclo == processos[i].tempo_de_chegada){
				proc.push_back(processos[i]);
			}

		}
		

		Processo first = proc[0];
		proc.erase(proc.begin());
		retorno--;
		
		ciclo += first.duracao_do_processo;

		tempo_de_retorno  += ciclo - first.tempo_de_chegada;
		tempo_de_resposta += ciclo - first.tempo_de_chegada;
		tempo_de_espera   += ciclo - first.tempo_de_chegada;
	}


	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout<<"FCFS" << " " << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera <<std::endl;

}


bool comparar(const Processo& p1, const Processo& p2){

	return (p1.tempo_de_chegada < p2.tempo_de_chegada);

}

void SJF(const Processo *processos, int numero_de_processos){

    float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;

	std::vector<Processo> proc; // fila de prontos

	int ciclo = 0;

	while(retorno != 0){ 

		for (int i= 0; i < numero_de_processos; i++){

			if(ciclo == processos[i].tempo_de_chegada){
				proc.push_back(processos[i]);
			}

		}
	
		std::sort(proc.begin(), proc.end(), comparar);		
		Processo first = proc[0];
		proc.erase(proc.begin());
		retorno--;
		

		tempo_de_retorno  += ciclo - first.tempo_de_chegada;
		tempo_de_resposta += ciclo - first.tempo_de_chegada;

		ciclo += first.duracao_do_processo;

		tempo_de_espera   += ciclo - first.tempo_de_chegada;
	}


	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout<<"SJF" << " " << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera <<std::endl;

}


/*void RR(const Processo *processos, int numero_de_processos){

    float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;
	
	std::vector<Processo> proc;

	for (int i= 0; i < numero_de_processos; i++){proc.push_back(processos[i]);

	while(!proc.empty()){

		if(retorno == 0){
			break;}
	}	

	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::"RR" << " " << tempo_de_retorno << " " << tempo_de_resposta << " " << tempo_de_espera <<std::endl;
}*/
