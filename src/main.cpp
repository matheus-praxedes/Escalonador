#include "escalonador.hpp"

int main (int argc, char* argv[]){

	// Início da seção de leitura de arquivos
	std::ifstream entrada(argv[1]);
	std::string linha;
	int numero_de_processos = 0;

	while(!input.eof()){
		std::getline(entrada, linha);
		numero_de_processos++;
	}
	

	input.close();
	input.open(argv[1])
	// Fim da seção de leitura de arquivos
	
	Processo *processos = new Processo[numero_de_processos]; // precisa de destrutor ou desalocador ?

	for(int i = 0; i < numero_de_processos; i++){

		processos[i].id = i;
		entrada >> processos[i].tempo_de_chegada >> processos[i].duracao_do_processo;

		if(processos[i].duracao_do_processo == 0){

			numero_de_processos = numero_de_processos - 1; // desconsidera um processo
		}	
	}

	FCFS(processos, numero_de_processos);
	SJF(processos, numero_de_processos);
	RR(processos, numero_de_processos);


	return 0; 
}