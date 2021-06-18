
// consulta.h definição do tipo consulta e protótipo de suas operações.

#ifndef _CONSULTA_H
#define _CONSULTA_H

#include "paciente.h"
#include "medico.h"
#include <stdbool.h>

#define NOME_ARQ "trabalho2.dat"
#define NOME_ARQ_CON "trab2con.dat"
#define NOME_ARQtxt "ListarConsultas.txt"

typedef struct 
{
    int dia;
    int mes;
    int ano;
}data;

typedef struct 
{
    int hora;
    int minuto;
       
}horario;

typedef struct 
 {    
    int num_prontuario;
    data data_consulta;    
    horario hora_consulta;
    int cod_medico;
    int cod_paciente;
} consulta;

/* função para cadastrar uma consulta */
void AgendarConsulta(void);

/* função para mostrar as consultas de um medico numa data/horario */
void ListarConsulta(void);

/* função para consulta uma lista completa de horários */
void ListarConsultaSimples(void);

/* Função para criar arquivo txt*/
void ListarConsultaSimples(void);

#endif