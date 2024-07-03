#include <stdio.h> // bilioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de memoria
#include <locale.h> // biblioteca de textos
#include <string.h> // biblioteca de manipulação de strings

int registro(){
    // Função para registrar usuários no sistema | Declaração de variáveis
    char arquivo[40]; // Nome do arquivo que será criado, baseado no CPF do usuário
    char cpf[40]; // Variável para armazenar o CPF do usuário
    char nome[40]; // Variável para armazenar o nome do usuário
    char sobrenome[40]; // Variável para armazenar o sobrenome do usuário
    char cargo[40]; // Variável para armazenar o cargo do usuário
    
    // Coleta de informações
    printf("Informe um cpf para cadastro: ");
    scanf("%s", cpf); // Solicita e armazena o CPF do usuário
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file;
    file = fopen(arquivo, "w"); // Abre o arquivo com o CPF como nome em modo de escrita
    // Cria um arquivo
    fprintf(file,cpf); // Escreve o CPF no arquivo
    // Salva o valor em uma variável
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo novamente em modo de apêndice (para adicionar mais informações)
    fprintf(file, ","); // Adiciona uma vírgula como delimitador
    fclose(file); // Fecha o arquivo
    
    printf("Informe um nome para cadastro: ");
    scanf("%s", nome); // Solicita e armazena o nome do usuário
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de apêndice novamente
    fprintf(file,nome); // Adiciona o nome ao arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de apêndice novamente
    fprintf(file, ","); // Adiciona uma vírgula como delimitador
    fclose(file); // Fecha o arquivo
    
    printf("Informe o sobrenome para cadastro: ");
    scanf("%s", sobrenome); // Solicita e armazena o sobrenome do usuário
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de apêndice novamente
    fprintf(file,sobrenome); // Adiciona o sobrenome ao arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de apêndice novamente
    fprintf(file, ","); // Adiciona uma vírgula como delimitador
    fclose(file); // Fecha o arquivo
    
    printf("Informe o cargo para cadastro: ");
    scanf("%s", cargo); // Solicita e armazena o cargo do usuário
    
    file = fopen(arquivo, "a"); // Abre o arquivo em modo de apêndice novamente
    fprintf(file,cargo); // Adiciona o cargo ao arquivo
    fclose(file); // Fecha o arquivo
    
    system("pause"); // Pausa o sistema para visualização dos resultados
}

int consulta(){
    
    setlocale(LC_ALL, "Portuguese"); // Define o local para o português
    
    char cpf[40]; // Variável para armazenar o CPF a ser consultado
    char conteudo[200]; // Variável para armazenar o conteúdo do arquivo
    
    printf("Informe o cpf que deseja consultar: ");
    scanf("%s", cpf); // Solicita e armazena o CPF a ser consultado
    
    FILE *file;
    file = fopen(cpf,"r"); // Abre o arquivo com o CPF informado em modo de leitura
    
    if(file == NULL){
        printf("CPF informado nao esta cadastrado no sistema!"); // Se o arquivo não existir, exibe uma mensagem de erro
    }
    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas sao as informacoes do CPF para consulta: ");
        printf("%s", conteudo); // Enquanto houver conteúdo no arquivo, exibe as informações
        printf("\n");
    }
    system("pause"); // Pausa o sistema para visualização dos resultados
    fclose(file); // Fecha o arquivo
}

int deletar(){
    
    char cpf[40]; // Variável para armazenar o CPF do usuário a ser deletado
    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s", cpf); // Solicita e armazena o CPF do usuário a ser deletado

    remove(cpf); // Remove o arquivo com o nome do CPF

    FILE *file;
    file = fopen(cpf, "r"); // Tenta abrir o arquivo com o CPF (após a remoção)

    if(file == NULL){
        printf("O usuário não se encontra no sistema!.\n"); // Se o arquivo não existir, exibe uma mensagem de erro
        system("pause"); // Pausa o sistema para visualização dos resultados
    }else{
        printf("O usuário foi removido com sucesso!\n"); // Se o arquivo existir, exibe uma mensagem de sucesso
        system("pause"); // Pausa o sistema para visualização dos resultados
    }
}

int main(){
    
    int opcao=0;
    int laco=1;
    
    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    
    
    for(laco=1;laco=1;){ 
        
        system("cls");
        
        // Menu de opções para o usuário
        printf("\t~~~~CARTORIO DA EBAC~~~~\n");
        printf("\n  Este Software e de livre uso dos alunos\n\n");
    	printf("\t~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("\tEscolha a opcao desejada:\n\n");
    	printf("\t1- Registrar nomes\n");
    	printf("\t2- Consultar nomes\n");
    	printf("\t3- Deletar nomes\n\n");
    	printf("\t~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	
        printf("\tOpcao: ");
        scanf("%d",  &opcao); // Coletando escolha do usuário
        
        system("cls");
        
        // Função de opções disponíveis para escolha do usuário
        switch(opcao){
            
           case 1:
			registro(); // Chamando função de registro de usuários
			break;
			
			case 2:
			consulta(); // Chamando função de consultar dados do usuário
			break;
		
			case 3:
			deletar(); // Chamando função de deletar dados de um usuário
			break;

            
            default: // Não foi inserida uma opção válida
            printf("\tEssa opcao nao esta disponivel, escolha uma das opcoes que foram exibidas\n");
            system("pause");
            break;
        }
        
        
    }
    return 0;
}