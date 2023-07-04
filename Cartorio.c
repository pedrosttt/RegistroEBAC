#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bilioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelo funcionamento das strings

int registrar() //função responsável por cadastrasr os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variáveis/string
	
	//coletando informação do usuário
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); // "w" criar o arquivo
	fprintf(file,cpf); //salvar o valor da variável
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualizar o arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definir o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" ler o arquivo
	
	if(file == NULL)
	{
		printf("\nArquivo não localizado.\n\n");
	}
	
	else
	{
		while(fgets(conteudo, 200, file) != NULL);
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
	
	
	
	system("pause");
	
	
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // definir o idioma

    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usuário foi deletado ou não se encontra no sistema.\n\n");
        system("pause");
    }
}

int erro()
{
	printf("Essa opção não existe.\n\n");
	system("pause");
}


int main() //função principal
{
	int opcao=0; //int declarar variável de valor inteiro
	int laco=1;
	
	for(laco=1;laco=1;) //executar um bloco de código repetidamente
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definir o idioma
			
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1- Registrar nomes\n"); // \t usado para espaçar e \n para pular linhas
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenar a escolha do usuário
		
		system("cls");
		
		switch(opcao) //executar blocos de código com base no valor de uma expressão
		{
			case 1: 
			registrar(); //chamar a função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			erro();
			break;
		}
	}
}




