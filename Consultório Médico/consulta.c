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

#include "consulta.h"
#include "paciente.h"
#include "medico.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Função para agendar a consulta do paciente com o médico
void AgendarConsulta()
{
    FILE * arq; // Para a manipulação de arquivo 
    consulta co; // Chama a estrutura da consulta e deixa a sigla 'co' para uso padrão na função
    medico md; // Chama a estrutura do médico e deixa a sigla 'md' para uso padrão na função
    paciente pc; // Chama a estrutura do paciente e deixa a sigla 'pc' para uso padrão na função

    int codPaci;
    int codMedi;
    int codCons;


    //abre o arquivo do medico, se for nulo mostra o erro 
    if ((arq = fopen(NOME_ARQ_MED, "r+b")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_MED);
        return;
    }

    //solicita o id do medico
    printf("\n\nNova Consulta\n");
    printf("\n\nInsira o id do medico\n");
      
      //pesquisa o id do medico
        int idMed;
        printf("Id: ");
        scanf("%d", &idMed);
        fseek(arq, (idMed - 1) * sizeof(medico), SEEK_SET);
        fread(&md, sizeof(medico), 1, arq);
        if (idMed < 1 || feof(arq)) 
        {
            printf("\nErro: Id do medico nao encontrado (%d)!\n", idMed);
            return;
        }  
        printf("Nome do Medico: %s \n", md.nome);
        codMedi = idMed; //insere o valor do id pesquisado na variavel para usar na consulta

        //abre o arquivo do paciente, se der nulo mostra a mensagem 
        if ((arq = fopen(NOME_ARQ_PAC, "r+b")) == NULL) 
        {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_PAC);
        return;
        }
        //solicita o id do paciente
        printf("\n\nInsira o id do paciente\n");     

        //pesquisa o id do paciente 
        int idPac;
        printf("Id: ");
        scanf("%d", &idPac);
        fseek(arq, (idPac - 1) * sizeof(paciente), SEEK_SET); // Realiza a leitura do arquivo
        fread(&pc, sizeof(paciente), 1, arq);

        // Faz uma varredura para encontrar o id do paciente
        if (idPac < 1 || feof(arq)) 
        {
            printf("\nErro: Id do Paciente nao encontrado (%d)!\n", idPac);
            return;
        }  

        printf("Nome do Paciente: %s \n\n", pc.nome);
        codPaci = idPac; //insere o valor do id pesquisado na variavel para usar na consulta

        //abre o arquivo da consulta
        if ((arq = fopen(NOME_ARQ_CON, "r+b")) == NULL) 
        {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_CON);
        return;
        }

        co.cod_medico = codMedi;
        co.cod_paciente = codPaci;
      
        // Solicita a data da consulta gravando no arquivo
        fseek(arq, 0, SEEK_END);
        co.num_prontuario = ftell(arq) / sizeof(consulta) + 1;
        printf("Num Prontuario.: %d\n", co.num_prontuario);

        printf("Data (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &co.data_consulta.dia, &co.data_consulta.mes, &co.data_consulta.ano);
    
        printf("Horario (hh:mm): ");
        scanf(" %d:%d", &co.hora_consulta.hora, &co.hora_consulta.minuto);

        
        fwrite(&co, sizeof(consulta), 1, arq); // Escreve no arquivo o registro do paciente
        fclose(arq); // Fecha o arquivo aberto no if logo acima
        printf("\n Consulta agendada com sucesso!\n");
              
}

// Função para listar as consultas agendadas em modo de pesquisa por id do médico e por data
void ListarConsulta()
{  
    FILE * arq; // Para a manipulação de arquivo
    consulta co1; // Chama a estrutura da consulta e deixa a sigla 'co1' para uso padrão na função

    //abre arquivo do consulta, se for nulo mostra a mensagem de erro
    if ((arq = fopen(NOME_ARQ_CON, "rb")) == NULL) 
    {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_CON);
        return;
    }
    //solicita o id do medico
    printf("\n\nNova Consulta\n");
    printf("\n\nInsira o id do medico\n");

    
      //pesquisa o id do medico
        int idMed;
        printf("Id: ");
        scanf("%d", &idMed);
        fseek(arq, (idMed - 1) * sizeof(consulta), SEEK_SET);
        fread(&co1, sizeof(consulta), 1, arq);
        if (idMed < 1 || feof(arq)) 
        {
            printf("\nErro: Nao ha nenhuma consulta agendada para esse medico com id: (%d)\n", idMed);
            return;
        }  
            //puxar nome medico

            //abre o arquivo do medico
            medico md3; // Chama a estrutura da médico e deixa a sigla 'md3' para uso padrão na função
                                 
            //abre o arquivo do medico, se for nulo mostra a mensagem de erro                   
            if ((arq = fopen(NOME_ARQ_MED, "r+b")) == NULL) 
            {
                fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_MED);
                return;
            }
                                            
            fseek(arq, (idMed - 1) * sizeof(medico), SEEK_SET);
            fread(&md3, sizeof(medico), 1, arq);
            if (idMed < 1 || feof(arq)) 
            {
                printf("\nErro: Id do medico nao encontrado (%d)!\n", idMed);
                return;
            }  
            printf("Nome do Medico: %s \n", md3.nome);
                                            

        //abre o arquivo do consulta, se for nulo mostra a mensagem de erro
        if ((arq = fopen(NOME_ARQ_CON, "rb")) == NULL) 
        {
            fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s!\n", NOME_ARQ_CON);
            return;
        }

        int dia;
        int mes;
        int ano;
        
        // Mostra as consultas agendadas pela data cadastrada
        printf("\n\nInsira o dia da consulta (dd)/(mm)/(aaaa):\n");      
        scanf(" %20d/%20d/%d", &dia, &mes, & ano);
        

       printf("\n\nListagem de Consultas do Medico: %s - id:%02d para a data:(%02d/%02d/%d)\n",  md3.nome, idMed, dia, mes, ano);
       printf("-----------------------------------------------------------------------------------\n");
       printf("Cod. Prontu    Data           Id Medico     Horario     Id Paciente\n");
       printf("-----------------------------------------------------------------------------------\n");
       while (fread(&co1, sizeof(consulta), 1, arq) > 0) // Verifica o registro da consulta
       {

        // Realiza as comparações das datas para ver se realmente existe
         if ( dia == co1.data_consulta.dia && co1.data_consulta.mes == mes && co1.data_consulta.ano == ano && co1.cod_medico == idMed)  
         {
             printf(" %03d          %02d/%02d/%d       %03d        %02d:%02d             %03d  \n", co1.num_prontuario, 
             co1.data_consulta, co1.cod_medico, co1.hora_consulta,  co1.cod_paciente);                
             printf("-----------------------------------------------------------------------------------\n");
         }

         // Realiza as comparações das datas para ver se nao existe nenhuma data agendada   
         if ( dia != co1.data_consulta.dia && co1.data_consulta.mes != mes && co1.data_consulta.ano != ano && co1.cod_medico != idMed)  
         {
            printf("Nao ha consultas nessa data com esse cod do medico");
            return;
         }
         
                                     
       }
    fclose(arq); // Fecha o arquivo aberto
        
        //transforma em .txt
        int ope;
        do
        {
            printf("Deseja transformar essa lista de consultas em arquivo (.txt)?\n");
            printf("<1>SIM\n");
            printf("<2>NAO\n");
            printf("Opcao:");
            scanf("%d", &ope);

            if (ope == 1)
            {
                FILE * in, * out; // Para a manipulação de arquivo
                consulta cs2; // Chama a estrutura da consulta e deixa a sigla 'cs2' para uso padrão na função

                //verifica se o arquivo foi criado para consulta
                if ((in = fopen(NOME_ARQ_CON, "rb")) == NULL) 
                {
                    printf("\nNao ha consultas agendadas");
                    return;
                }

                //verifica se o arquivo foi criado para escrita
                if ((out = fopen(NOME_ARQtxt, "w")) == NULL) 
                {
                    printf("\nErro: Nao foi possivel criar o arquivo %s\n, " NOME_ARQtxt);
                    fclose(in);
                    return;
                }

                fprintf(out,"\n\nListagem de Consultas do Medico: %s - id:%02d para a data:(%02d/%02d/%d)\n",  md3.nome, idMed, dia, mes, ano);//escreve no arquivo as informações
                fprintf(out, ".....................................................................................\n");
                fprintf(out,"Cod. Prontu    Data           Id Medico     Horario     Id Paciente\n");//escreve no arquivo as informações
                fprintf(out,"-------------------------------------------------------------------\n");
                while (fread(&cs2, sizeof(consulta), 1, in) > 0)//faz a varredura do arquivo consulta
                {
                    // Realiza as comparações das datas para ver se realmente existe
                    if ( dia == cs2.data_consulta.dia && cs2.data_consulta.mes == mes && cs2.data_consulta.ano == ano && cs2.cod_medico == idMed)  
                    {
                        fprintf(out, " %03d          %02d/%02d/%d       %03d        %02d:%02d             %03d  \n", cs2.num_prontuario, 
                        cs2.data_consulta, cs2.cod_medico, cs2.hora_consulta,  cs2.cod_paciente);                
                        fprintf(out,"-----------------------------------------------------------------------------------\n");
                    }
                    
                    // Realiza as comparações das datas para ver se nao existe nenhuma data agendada
                    if ( dia != cs2.data_consulta.dia && cs2.data_consulta.mes != mes && cs2.data_consulta.ano != ano && cs2.cod_medico != idMed)  
                    {
                        printf("Nao ha consultas nessa data com esse cod do medico");
                    }
                }
                fclose(in); //fecha o arquivo NOME_ARQ_CON
                fclose(out); //fecha o arquivo NOME_ARQtxt
                printf("\nArquivo %s gerado com sucesso!\n", NOME_ARQtxt); //mensagem de arquivo gerado
            }
            if (ope == 2)
            {
                return;
            }
        } while (ope != 1 && ope != 2);  // Verifica a escolha do usuário
}
    
// Função para realizar uma consulta simples dos agendados
void ListarConsultaSimples()
{
    FILE * arq; // Para a manipulação de arquivo
    consulta co; // Chama a estrutura da consulta e deixa a sigla 'co' para uso padrão na função

    //verifica se o arquivo foi criado para consulta
    if ((arq = fopen(NOME_ARQ_CON, "rb")) == NULL)
    {
       printf("\nNao foi possivel abrir o arquivo \n");
    }

    //Mostra a lista das consultas de modo simplificado
    printf("\n\nListagem de Consultas\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Cod. Prontu    Data           Horario     Id Medico     Id Paciente\n");
    printf("-----------------------------------------------------------------------------------\n");
    while (fread(&co, sizeof(consulta), 1, arq) > 0) //faz a varredura do arquivo consulta
    {
        printf(" %03d          %02d/%02d/%d       %02d:%02d        %03d             %03d \n", co.num_prontuario, co.data_consulta, co.hora_consulta, 
        co.cod_medico, co.cod_paciente);
        
    }
    printf("-----------------------------------------------------------------------------------\n");
    

    fclose(arq); // Fecha o arquivo aberto
}

// Função para gerar o arquivo txt das consultas
void gerarArqConsultatxt()
{
    FILE * in, * out; // Para a manipulação de arquivo
    consulta cs2; // Chama a estrutura da consulta e deixa a sigla 'co2' para uso padrão na função

    //verifica se o arquivo foi criado para consulta
    if ((in = fopen(NOME_ARQ_CON, "rb")) == NULL)
    {
        printf("\nNao ha consultas agendadas");
        return;
    }

    //verifica se o arquivo foi criado para consulta
    if ((out = fopen(NOME_ARQtxt, "w")) == NULL)
    {
        printf("\nErro: Nao foi possivel criar o arquivo %s\n, " NOME_ARQtxt);
        fclose(in);
        return;
    }

    fprintf(out, "Consultas agendadas\n");//escreve no arquivo as informações
    fprintf(out, "Cod. Prontu    Data           Horario     Id Medico     Id Paciente\n");//escreve no arquivo as informações

    while (fread(&cs2, sizeof(consulta), 1, in) > 0) //faz a varredura do arquivo consulta
    {
        fprintf(out, " %03d          %02d/%02d/%d       %02d:%02d        %03d             %03d \n", cs2.num_prontuario, cs2.data_consulta, cs2.hora_consulta, 
        cs2.cod_medico, cs2.cod_paciente);//escreve no arquivo as informações
    }
    fclose(in);//fecha o arquivo NOME_ARQ_CON
    fclose(out);//fecha o arquivo NOME_ARQtxt
    printf("\nArquivo %s gerado com sucesso!\n", NOME_ARQtxt);//mensagem de arquivo gerado
    
}