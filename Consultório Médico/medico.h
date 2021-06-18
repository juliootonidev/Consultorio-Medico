
// medico.h dedinição do tipo medico e protótipo de suas operações.

#ifndef _MEDICO_H
#define _MEDICO_H

#define NOME_ARQ "trabalho2.dat"
#define NOME_ARQ_MED "trab2med.dat"

typedef struct 
{  
  int cod_medico;
  char nome[41];
  char especialidade[31];
} medico;

/* função para cadastrar um novo medico */
void CadastrarMedico(void);

/* função para listar todos os médicos */
void ListarMedico(void);

#endif