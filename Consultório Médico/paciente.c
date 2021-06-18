
/* paciente.c */

#include "paciente.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void CadastrarPaciente()
{
    FILE * arq; // Para a manipulação de arquivo do paciente 
    paciente pc; // Chama a estrutura do paciente e deixa a sigla 'pc' para uso padrão na função

    // Se o arquivo for nulo, mostrar a mensagem de erro, não abre o arquivo
    if ((arq = fopen(NOME_ARQ_PAC, "ab")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_PAC);
        return;
    }

    //solicita o cadastro do novo paciente
    printf("\n\nNovo Paciente\n");
    fseek(arq, 0, SEEK_END); // Para registrar o cadastro do paciente
    pc.cod_paciente = ftell(arq) / sizeof(paciente) + 1; // Gera o código automático 
    printf("Cod.: %d \n", pc.cod_paciente);

    printf("Nome:");
    scanf(" %41[^\n]", pc.nome);

    printf("Sexo:");
    scanf(" %20[^\n]", pc.sexo);

    printf("Idade:");
    scanf("%d", &pc.idade);
    

    fwrite(&pc, sizeof(paciente), 1, arq); // Escreve no arquivo o registro do paciente
    fclose(arq); // Fecha o arquivo aberto no if logo acima 
    printf("\n Paciente cadastrado com sucesso!\n");

}
 
// Função para listar o paciente cadastrado
void ListarPaciente()
{
   FILE * arq; // Para a manipulação de arquivo do paciente 
   paciente pc; // Chama a estrutura do paciente e deixa a sigla 'pc' para uso padrão na função

    // Se não estiver registro dos pacientes no arquivo, mostrar a mensagem de erro, não abre o arquivo
    if ((arq = fopen(NOME_ARQ_PAC, "rb")) == NULL)
    {
       printf("\nNão ha nenhum paciente cadastrado \n");
    }

    // Mostra a lista de paciente
    printf("\n\nListagem de pacientes\n");
    printf("-----------------------------------------------------------\n");
    printf("Codigo          Nome                     Sexo     Idade     \n");
    printf("-----------------------------------------------------------\n");
    while (fread(&pc, sizeof(paciente), 1, arq) > 0) // Verifica o registro do paciente
    {
        printf(" %03d            %-24.25s   %s        %d \n", pc.cod_paciente, pc.nome, pc.sexo, pc.idade);
        
    }
    printf("-----------------------------------------------------------\n");
    fclose(arq); // Fecha o arquivo aberto no if logo acima

}