#include <stdio.h>  //biblioteca de comunicação com o usuário.
#include <stdlib.h>  //biblioteca de alocação de espaço em memória.
#include <locale.h>  //biblioteca de alocação de texto por região.
#include <string.h>  //biblioteca resposável por cuidar das strings.

 int Registrar()  //Função resposável por cadastrar os usuarios no sistema.
{
	//inicio da seleção de variáveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da seleção de variáveis/string.
	
	printf("Digite o CPF que deseja cadastrar: ");  //Coletando informações do usuario. (CPF).
	scanf("%s", cpf);  //Armazena as Variáveis - %s refere-se a string.
	
	strcpy(arquivo, cpf);  //Responsável por copiar os valores das strings.
	
	FILE* file;  //Cria o arquivo no banco de dados.
	file = fopen(arquivo, "w");  //Cria um novo arquivo, o (w) significa escrever.
	fprintf(file,cpf);  //salva o valor da vairiável, (CPF).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo. (a) - Inserir nova informação.
	fprintf(file,",");  //Cria o arquivo (,) a nova infromação.
	fclose(file);  //fecha o arquivo.
	
	printf("Digite o nome que deseja cadastrar: ");  //Coletando Informções do usuario.
	scanf("%s", nome);  //Armazenando as variáveis. (nome).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,nome);  //salvando o valor da variável (nome).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	printf("Digite o sobrenome que deseja cadastrar: ");  //Coletando Informções do usuario.
	scanf("%s", sobrenome);  //Armazenando as variáveis. (sobrenome).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,sobrenome);  //salva os valores da variável. (sobrenome).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	printf("Digite o cargo que deseja cadastar: ");  //Coletando Informções do usuario.
	scanf("%s", cargo);  //Armazenando as variáveis. (cargo).
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,cargo);  //salva os valores da variável. (cargo).
	fclose(file);  //fecha o arquivo.
	
	file = fopen(arquivo,"a");  //Abre o arquivo, insere novas informações.
	fprintf(file,",");  //Cria o arquivo novo. (,)
	fclose(file);  //Fecha o arquivo.
	
	system("pause");  //Pausa o programa.
		
}

 int Consultar()  //Função Resposável por Consultar os Dados dos alunos no sistema.
{
   setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem.
	
   //inicio da seleção de variáveis/string.
   char cpf[40];
   char conteudo[200];
   //fim da seleção de variáveis/string.
   
   printf("Digite o CPF que deseja consultar: ");  //Coletando Informções do usuario.
   scanf("%s",cpf);  //Armazenando as variáveis. (cpf).
   
   FILE *file;  //Abre ou consulta o arquivo.
   file = fopen(cpf,"r");  //Abre o arquivo, (r) lê o arquivo (cpf).
   
   if(file == NULL)  //Criando validação.
   {
   	  printf("CPF não localizado, CPF sem cadastro!\n");  //Comunicando ao usuário.
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //Função criada para buscar o arquivo salvo.
	{
	   printf("\nEssas são as informações do usuário: ");  //Comunicando ao usuário.
	   printf("%s", conteudo);  //Salvando o conteúdo.
	   printf("\n\n");
	}
	
	system("pause");
}

 int Deletar()  //Função Resposável por Deletar Dados dos alunos no sistema.
{
	//inicio da seleção de variáveis/string.
	char cpf[40];
	//fim da seleção de variáveis/string.
	
	printf("Digite o CPF do aluno que deseja deletar: ");  //Coletando Informações do usuario.
	scanf("%s",cpf);  //Armazena as variavéis. (CPF QUE DESEJA APAGAR).
	
	remove(cpf);  //Função responsável por apagar a variavél (CPF).
		
	FILE *file;  //Abre ou consulta o arquivo.
	file = fopen(cpf,"r");  //Abre o arquivo, (r) lê o arquivo (cpf).
	
	if(file == NULL)  //validação.
	{
		printf("CPF deletado com sucesso, CPF não encontrado no sistema! \n");  //Comunicando ao usuario.
		system("pause");  //pausa o programa.
	}	
}

int main()
{
	int opcao=0; //Definindo Variáveis.
	int laco =1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls");//Resposável por limpar a tela.
	   
	   setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem.
	
	   printf("     Boas Vindas ao Cartório de Alunos da EBAC     \n\n"); //Início do menu.
	   printf("Digite o número referente a opção desejada no menu:\n\n");
	   printf("\t1 - Cadastrar Aluno!\n");
	   printf("\t2 - Consultar Aluno Cadastrado!\n");
	   printf("\t3 - Deletar Aluno Cadastrado!\n\n"); 
	   printf("Opção: "); //Final do menu.
	
	   scanf("%d", &opcao); //Armazenando a Escolha do Usuário.
	
	   system("cls");//Responsável por limpar a tela.
	   
	   switch(opcao)//ínicio das seleções do menu.
	   {
	   	case 1:
        Registrar();//Chamada de funções.
		break;
		
		case 2:
		Consultar();
		break;
		
		case 3:
		Deletar();
		break;
		
		default:
		printf("Opção Indisponível!\n"); //Fim da Seleção.
	    system("pause");
		break;	
	   	}
	}
}


