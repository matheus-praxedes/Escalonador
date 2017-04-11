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

void FCFS(const Processo *processos, int numero_de_processos){

	float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;
	int   ciclo                   = 0;
  
	std::vector<Processo> prontos; // fila de prontos
	std::vector<Processo> novos; // fila de novos	

	for (int i= 0; i < numero_de_processos; i++){

		novos.push_back(processos[i]);
				
	}		
	
	while(retorno != 0){ 


		for (int i = 0; i < novos.size(); i++){

			if( novos[i].tempo_de_chegada <= ciclo){
				
				prontos.push_back(novos[i]);
				novos.erase (novos.begin()+i);
				i--;
			}
		}

		Processo first = prontos[0];
		retorno--;
		prontos.erase(prontos.begin());
		
		
		tempo_de_espera   += ciclo - first.tempo_de_chegada;  
		tempo_de_resposta += ciclo - first.tempo_de_chegada; 
		
		ciclo += first.duracao_do_processo;
	
		tempo_de_retorno  += ciclo - first.tempo_de_chegada; 
	}


	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout << std::fixed << std::setprecision(1);
	std::cout <<"FCFS" << " " << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera <<std::endl;

}


bool comparar1(const Processo& p1, const Processo& p2){

	return (p1.duracao_do_processo <= p2.duracao_do_processo);

}

void SJF(const Processo *processos, int numero_de_processos){


	float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;
	int   ciclo                   = 0;
	 
	std::vector<Processo> prontos; // fila de prontos
	std::vector<Processo> novos; // fila de novos	

	for (int i= 0; i < numero_de_processos; i++){

		novos.push_back(processos[i]);
				
	}		
	
	while(retorno != 0){ 

		for (int i = 0; i < novos.size(); i++){

			if( novos[i].tempo_de_chegada <= ciclo){
				
				prontos.push_back(novos[i]);
				novos.erase (novos.begin()+i);
				i--;
			}
			
		}

		std::sort(prontos.begin(),prontos.end(),comparar1);	

		Processo first = prontos[0];
		retorno--;
		prontos.erase(prontos.begin());
		
		
		tempo_de_espera   += ciclo - first.tempo_de_chegada;  
		tempo_de_resposta += ciclo - first.tempo_de_chegada; 
		
		ciclo += first.duracao_do_processo;
		tempo_de_retorno  += ciclo - first.tempo_de_chegada; 

	}

	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);
    
    std::cout << std::fixed << std::setprecision(1);
	std::cout<<"SJF" << " " << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera <<std::endl;

}

bool comparar2(const Processo& p1, const Processo& p2){

	return (p1.tempo_de_chegada < p2.tempo_de_chegada);

}

void RR(const Processo *processos, int numero_de_processos){


	float tempo_de_resposta       = 0;
	float tempo_de_retorno        = 0;
	float tempo_de_espera         = 0;
	float tempo_medio_de_resposta = 0;
	float tempo_medio_de_retorno  = 0;
	float tempo_medio_de_espera   = 0;
	int   retorno                 = numero_de_processos;
	int   ciclo                   = 0;
	int   quantum                 = 2;
	bool  back_to_ready 		  = false;

	std::vector<Processo> prontos; // fila de prontos
	std::vector<Processo> novos; // fila de novos	
	Processo first;


	for (int i= 0; i < numero_de_processos; i++){

		novos.push_back(processos[i]);
		
	}	

	while(retorno != 0){ 	
		
		for (int i = 0; i < novos.size(); i++){

			if( novos[i].tempo_de_chegada == ciclo){
				
				prontos.push_back(novos[i]);
				novos.erase (novos.begin()+i);
				i--;
				
			}else if( novos[i].tempo_de_chegada < ciclo){
				
				tempo_de_espera += ciclo - novos[i].tempo_de_chegada;
				prontos.push_back(novos[i]);
				novos.erase (novos.begin()+i);
				i--;
				
			}	
		}	

		if(back_to_ready){
			prontos.push_back(first);
			back_to_ready = false;
		}

		first = prontos[0];
		prontos.erase(prontos.begin());
		
		if(first.tempo_restante == first.duracao_do_processo)
			tempo_de_resposta += ciclo - first.tempo_de_chegada;

		ciclo += quantum;
		first.tempo_restante -= quantum;
		tempo_de_espera   += quantum * prontos.size();  
		
		if(first.tempo_restante > 0){
			back_to_ready = true;
		}
		
		if(first.tempo_restante <= 0){
			retorno--;
			
			ciclo += first.tempo_restante;
			tempo_de_espera += (first.tempo_restante * int(prontos.size()));
			tempo_de_retorno  += ciclo - first.tempo_de_chegada;
		}	

	}	
    
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout << "RR" << " "  << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera << std::endl;
}
