#include <stdio.h>  //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o.
#include <string.h>  //biblioteca respos�vel por cuidar das strings.

 int Registrar()  //Fun��o respos�vel por cadastrar os usuarios no sistema.
{
	//inicio da sele��o de vari�veis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da sele��o de vari�veis/string.
	
	printf("Digite o CPF que deseja cadastrar: ");  //Coletando informa��es do usuario. (CPF).
	scanf("%s", cpf);  //Armazena as Vari�veis - %s refere-se a string.
	
	strcpy(arquivo, cpf);  //Respons�vel por copiar os valores das strings.
	
	FILE* file;  //Cria o arquivo no banco de dados.
	file = fopen(arquivo, "w");  //Cria um novo arquivo, o (w) significa escrever.
	fprintf(file,cpf);  //salva o valor da vairi�vel, (CPF).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo. (a) - Inserir nova informa��o.
	fprintf(file,",");  //Cria o arquivo (,) a nova infroma��o.
	fclose(file);  //fecha o arquivo.
	
	printf("Digite o nome que deseja cadastrar: ");  //Coletando Inform��es do usuario.
	scanf("%s", nome);  //Armazenando as vari�veis. (nome).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,nome);  //salvando o valor da vari�vel (nome).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	printf("Digite o sobrenome que deseja cadastrar: ");  //Coletando Inform��es do usuario.
	scanf("%s", sobrenome);  //Armazenando as vari�veis. (sobrenome).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,sobrenome);  //salva os valores da vari�vel. (sobrenome).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	printf("Digite o cargo que deseja cadastar: ");  //Coletando Inform��es do usuario.
	scanf("%s", cargo);  //Armazenando as vari�veis. (cargo).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,cargo);  //salva os valores da vari�vel. (cargo).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informa��es.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	system("pause");  //Pausa o programa.
		
}

 int Consultar()  //Fun��o Respos�vel por Consultar os Dados dos alunos no sistema.
{
   setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem.
	
   //inicio da sele��o de vari�veis/string.
   char cpf[40];
   char conteudo[200];
   //fim da sele��o de vari�veis/string.
   
   printf("Digite o CPF que deseja consultar: ");  //Coletando Inform��es do usuario.
   scanf("%s",cpf);  //Armazenando as vari�veis. (cpf).
   
   FILE *file;  //Abre ou consulta o arquivo.
   file = fopen(cpf,"r");  //Abre o arquivo, (r) l� o arquivo (cpf).
   
   if(file == NULL)  //Criando valida��o.
   {
   	  printf("CPF n�o localizado, CPF sem cadastro!\n");  //Comunicando ao usu�rio.
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //Fun��o criada para buscar o arquivo salvo.
	{
	   printf("\nEssas s�o as informa��es do usu�rio: ");  //Comunicando ao usu�rio.
	   printf("%s", conteudo);  //Salvando o conte�do.
	   printf("\n\n");
	}
	
	system("pause");
}

 int Deletar()  //Fun��o Respos�vel por Deletar Dados dos alunos no sistema.
{
	//inicio da sele��o de vari�veis/string.
	char cpf[40];
	//fim da sele��o de vari�veis/string.
	
	printf("Digite o CPF do aluno que deseja deletar: ");  //Coletando Informa��es do usuario.
	scanf("%s",cpf);  //Armazena as variav�is. (CPF QUE DESEJA APAGAR).
	
	remove(cpf);  //Fun��o respons�vel por apagar a variav�l (CPF).
		
	FILE *file;  //Abre ou consulta o arquivo.
	file = fopen(cpf,"r");  //Abre o arquivo, (r) l� o arquivo (cpf).
	
	if(file == NULL)  //valida��o.
	{
		printf("CPF deletado com sucesso, CPF n�o encontrado no sistema! \n");  //Comunicando ao usuario.
		system("pause");  //pausa o programa.
	}	
}

int main()
{
	int opcao=0; //Definindo Vari�veis.
	int laco =1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls");//Respos�vel por limpar a tela.
	   
	   setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem.
	
	   printf("     Boas Vindas ao Cart�rio de Alunos da EBAC     \n\n"); //In�cio do menu.
	   printf("Digite o n�mero referente a op��o desejada no menu:\n\n");
	   printf("\t1 - Cadastrar Aluno!\n");
	   printf("\t2 - Consultar Aluno Cadastrado!\n");
	   printf("\t3 - Deletar Aluno Cadastrado!\n\n"); 
	   printf("Op��o: "); //Final do menu.
	
	   scanf("%d", &opcao); //Armazenando a Escolha do Usu�rio.
	
	   system("cls");//Respons�vel por limpar a tela.
	   
	   switch(opcao)//�nicio das sele��es do menu.
	   {
	   	case 1:
        Registrar();//Chamada de fun��es.
		break;
		
		case 2:
		Consultar();
		break;
		
		case 3:
		Deletar();
		break;
		
		default:
		printf("Op��o Indispon�vel!\n"); //Fim da Sele��o.
	    system("pause");
		break;	
	   	}
	}
}


