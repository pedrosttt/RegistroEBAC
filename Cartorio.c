#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bilioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelo funcionamento das strings

int registrar() //fun��o respons�vel por cadastrasr os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	//coletando informa��o do usu�rio
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); // "w" criar o arquivo
	fprintf(file,cpf); //salvar o valor da vari�vel
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
		printf("\nArquivo n�o localizado.\n\n");
	}
	
	else
	{
		while(fgets(conteudo, 200, file) != NULL);
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
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

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usu�rio foi deletado ou n�o se encontra no sistema.\n\n");
        system("pause");
    }
}

int erro()
{
	printf("Essa op��o n�o existe.\n\n");
	system("pause");
}


int main() //fun��o principal
{
	int opcao=0; //int declarar vari�vel de valor inteiro
	int laco=1;
	
	for(laco=1;laco=1;) //executar um bloco de c�digo repetidamente
	{
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definir o idioma
			
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1- Registrar nomes\n"); // \t usado para espa�ar e \n para pular linhas
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenar a escolha do usu�rio
		
		system("cls");
		
		switch(opcao) //executar blocos de c�digo com base no valor de uma express�o
		{
			case 1: 
			registrar(); //chamar a fun��o
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




