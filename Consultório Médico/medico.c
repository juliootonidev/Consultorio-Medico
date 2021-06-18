
//Componentes
//Giovanny Kenzo Salata Sato 
//RA: 1430482021013
//------------------
//Julio Gabriel Profeta Otoni
//RA: 1430482021011
//------------------
//Samuel Silva Perumalswamy
//RA: 1430482011010

// consulta.c

#include "medico.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Fução cadastrar médico
void CadastrarMedico()
{
    FILE * arq; // Para a manipulação de arquivo médico
    medico md; // Chama a estrutura do médico e deixa a sigla 'md' para uso padrão na função

    // Se o arquivo for nulo, mostrar a mensagem de erro, não abre o arquivo
    if ((arq = fopen(NOME_ARQ_MED, "ab")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_MED);
        return;
    }

    // Solicita o cadastro de um novo médico
    printf("\n\nNovo Medico\n");
    fseek(arq, 0, SEEK_END); // Para registrar o cadastro do médico 
    md.cod_medico = ftell(arq) / sizeof(medico) + 1; // Gera o código automático 
    printf("Cod.: %d\n", md.cod_medico);

    printf("Nome: ");
    scanf(" %41[^\n]", md.nome);

    printf("Especialidade: ");
    scanf(" %31[^\n]", md.especialidade);

    fwrite(&md, sizeof(medico), 1, arq); // Escreve no arquivo o registro do médico.
    fclose(arq); // Fecha o arquivo aberto no if logo acima 
    printf("\n Medico cadastrado com sucesso!\n");

}

// Função para listar os médicos cadastrados
void ListarMedico()
{
    FILE * arq; // Para a manipulação de arquivo médico
    medico md; // Chama a estrutura do médico e deixa a sigla 'md' para uso padrão na função

    // Se não estiver registro dos médicos no arquivo, mostrar a mensagem de erro, não abre o arquivo
    if ((arq = fopen(NOME_ARQ_MED, "rb")) == NULL) {
        printf("\nNao ha nenhum medico cadastrado\n");
        return;
    }

    // Mostra a lista de médicos
    printf("\n\nListagem de medicos\n");
    printf("-----------------------------------------------------------\n");
    printf("   Cod     Nome                     Especialidade              \n");
    printf("-----------------------------------------------------------\n");
    while (fread(&md, sizeof(medico), 1, arq) > 0) {  // Verifica o registro do médico.
        printf( "    %02d     %-25.25s %-18.20s\n", md.cod_medico, md.nome, md.especialidade);
    }
    printf("-----------------------------------------------------------\n");
    fclose(arq); // Fecha o arquivo aberto no if logo acima 
}