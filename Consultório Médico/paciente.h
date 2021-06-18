//Componentes
//Giovanny Kenzo Salata Sato 
//RA: 1430482021013
//------------------
//Julio Gabriel Profeta Otoni
//RA: 1430482021011
//------------------
//Samuel Silva Perumalswamy
//RA: 1430482011010

// paciente.h define o tipo paciente e o protótipo de suas operações.


#ifndef _PACIENTE_H
#define _PACIENTE_H

#define NOME_ARQ "trabalho2.dat"
#define NOME_ARQ_PAC "trab2pac.dat"

typedef struct 
{
    int cod_paciente;
    char nome[41];
    char sexo[20]; 
    int idade;
} paciente;

/* função para cadastrar um paciente */
void CadastrarPaciente(void);

/* função para listar todos os pacientes */
void ListarPaciente(void);

#endif