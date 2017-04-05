
void FCFS(const Processo *processos, int numero_de_processos){

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

	std::"FCFS" << " " << tempo_de_retorno << " " << tempo_de_resposta << " " << tempo_de_espera <<std::endl;

}

void SJF(const Processo *processos, int numero_de_processos){

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

	std::"SJF" << " " << tempo_de_retorno << " " << tempo_de_resposta << " " << tempo_de_espera <<std::endl;
}

void RR(const Processo *processos, int numero_de_processos){

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
}

bool comparar(const Processo& p1, const Processo& p2){

	return (p1.tempo_de_chegada < p2.tempo_de_chegada);

}