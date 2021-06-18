//Componentes
//Giovanny Kenzo Salata Sato 
//RA: 1430482021013
//------------------
//Julio Gabriel Profeta Otoni
//RA: 1430482021011
//------------------
//Samuel Silva Perumalswamy
//RA: 1430482011010

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "medico.h"
#include "paciente.h"
#include "consulta.h"

// Função principal para o usuário escolher sua opção
int main()
{
    int op;
    do
    {
        printf("\n\nConsultorio Medico\n");
        printf("<1> Cadastrar Medico\n");
        printf("<2> Listar Medico\n");

        printf("<3> Cadastrar Paciente\n");
        printf("<4> Listar Paciente\n");

        printf("<5> Agendar Consulta\n");
        printf("<6> Listar Consulta\n");
        printf("<7> Listar Consulta Simples\n");

        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        CadastrarMedico(); // Se escolher o número um, chama a função cadastrar médico.
         break;

         case 2:
        ListarMedico(); // Se escolher o número dois, chama a função listar médico.
        break;

        case 3:
        CadastrarPaciente(); // Se escolher o número três, chama a função cadastrar paciente.
         break;

         case 4:
        ListarPaciente(); // Se escolher o número quatro, chama a função listar paciente.
         break;

         case 5:
         AgendarConsulta();// Se escolher o número cinco, chama a função para agendar a consulta.
         break;

        case 6:
        ListarConsulta(); // Se escolher o número seis, chama a função listar as consultas agendadas atraves da pesquisa por id do médico e data.
        break;

        case 7:
        ListarConsultaSimples(); // Se escolher o número sete, chama a função listar consulta todas as consultas.
        break;
    

        default:
            break;
        }


    } while (op != 0); // Caso for zero sai dp programa.
    return 0;
}