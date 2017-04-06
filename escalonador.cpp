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
	std::vector<Processo> novos; // cópia do array de processos	

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
			// else{
			// 	break;
			// }
		}

		/*std::cout<<" \n Prontos ";
		for (int i= 0; i < prontos.size(); i++){

			std::cout<<prontos[i].duracao_do_processo<< " | ";
			
		}

		std::cout<<"\n Novos ";
		for (int i= 0; i < novos.size(); i++){

			std::cout<<novos[i].duracao_do_processo<< " | ";
			
		}*/
		

		Processo first = prontos[0];
		retorno--;
		prontos.erase(prontos.begin());
		
		
		tempo_de_espera   += ciclo - first.tempo_de_chegada;  
		tempo_de_resposta += ciclo - first.tempo_de_chegada; 
		
		ciclo += first.duracao_do_processo;
		//std::cout<<"ciclo:"<<ciclo<<std::endl;

		tempo_de_retorno  += ciclo - first.tempo_de_chegada; 

		
	}


	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout << std::fixed << std::setprecision(1);
	std::cout <<"FCFS" << " " << tempo_medio_de_retorno << " " << tempo_medio_de_resposta << " " << tempo_medio_de_espera <<std::endl;

}


bool comparar(const Processo& p1, const Processo& p2){

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
	std::vector<Processo> novos; // cópia do array de processos	

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

		std::sort(prontos.begin(),prontos.end(),comparar);	

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

	std::vector<Processo> prontos; // fila de prontos
	std::vector<Processo> novos; // cópia do array de processos	

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

		std::cout<<" \n\n Prontos ";
		for (int i= 0; i < prontos.size(); i++){

			std::cout<<prontos[i].pid<< " | ";
			
		}
		//std::cout<<"\nciclo "<<ciclo;*/


		Processo first = prontos[0];
		prontos.erase(prontos.begin());
		
		tempo_de_espera   += ciclo - first.tempo_de_chegada;  
		
		if(first.tempo_restante == first.duracao_do_processo){

			std::cout<<"\n\ntr "<<first.tempo_restante;
			std::cout<<"\ntd "<<first.duracao_do_processo;
			
			std::cout<<"\nciclo "<<ciclo;
			std::cout<<"\ntch "<<first.tempo_de_chegada;
			tempo_de_resposta += ciclo - first.tempo_de_chegada;

		}
		ciclo += quantum;
		first.tempo_restante -= quantum;
		

		if(first.tempo_restante > 0){
			
			prontos.push_back(first);
		}
		if(first.tempo_restante <= 0){
			retorno--;
			ciclo += first.tempo_restante;
			tempo_de_retorno  += ciclo - first.tempo_de_chegada;
		}	

		 
	}	
    
	tempo_medio_de_resposta = tempo_de_resposta / float(numero_de_processos);
	tempo_medio_de_retorno = tempo_de_retorno / float(numero_de_processos);
	tempo_medio_de_espera = tempo_de_espera / float(numero_de_processos);

	std::cout<<"RR" << " " << tempo_de_retorno << " " << tempo_de_resposta << " " << tempo_de_espera <<std::endl;
}
