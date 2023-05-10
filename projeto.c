#include <stdio.h> // Biblioteca de comunica�ao com o user 
#include <stdlib.h> // biblioteca alaca�ao de espa�o em memoria
#include <locale.h> // biblioteca de alaca�ao de texto por regiao 
#include <string.h> // biblioteca para consultar a string

int Registro() // fun��o responsavel por cadastrar os usuarios no sistsema
{
	// inicio da cria�ao de variaves/string
	char arquivo [40];
    char CPF [40];           
    char nome [40];
    char sobrenome[40];
    char urgencia [5];
    // final da cria�ao de variaves/string
    
    printf("Digite o CPF do novo paciente:"); // colletando informa�ao do ususrio
    scanf("%s", CPF); //%s refere-se a string 
    
    strcpy(arquivo, CPF); // Responsavel por copiar os valores da string
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo o "w" siginica escrever
    fprintf(file,CPF); // salvo o valor da variavel
    fclose(file); // fecho o arquivo 
    
    file = fopen(arquivo, "a"); // pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file,"," ); // colocando uma , no arquivo para a divisao
    fclose(file);
    
    printf("Digite o nome  do novo paciente:");// colletando informa�ao do ususrio
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file, " "); // colocando um espa�o no arquivo para a divisao
    fclose(file);
    
    printf("Digite o Sobrenome do novo paciente:");// colletando informa�ao do ususrio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file, " -> "); // colocando "->" no arquivo para a divisao
    fclose(file);
    
    printf("Digite a Urgencia do paciente:");// colletando informa�ao do ususrio
    scanf("%s",urgencia);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informa�oes
    fprintf(file,urgencia);
    fclose(file);  
    
    system("pause"); // pausando o sistema para o user ler
    
    
}
int Localizar() //fun��o responsavel por registrar os usuarios no sistsema
{
    setlocale(LC_ALL, "portuguese"); //Definindo um idioma 
    
    char CPF[40];
    char conteudo[200];
    
    printf("DIgite o CPF do paciente: ");// colletando informa�ao do ususrio
    scanf("%s", CPF);
    
    FILE *file;
    file = fopen(CPF, "r");// pedindo para o programa abrir e ler o aquivo com as informa�oes
    
    if(file == NULL)
    {
    	printf("Paciente n�o encontrado, tente novamente!!. \n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas s�o as informa�oes do paciente:\n "); // mostrando informa�oes para o user
    	printf("%s", conteudo); // salavando as informa�oes em string
    	printf("\n\n ");
	}
     
     system("pause");
     
}

int Deletar() //fun��o responsavel por deletar os usuarios do sistsema
{
    char CPF[40];
    
    printf("Digite o CPF do paciente a ser deletado: ");// colletando informa�ao do ususrio
    scanf("%s", CPF);
    
    remove(CPF); // removendo o arquivo solicitado

    
    FILE* file;
    file = fopen(CPF, "r");
    
    if(file == NULL) // caso nao encontre nenhum arquivo ele vai dizer para o usuario qeu nao foi encontrado
    {
    	printf("Paciente n�o se encontra no sistema!!\n");
    	system("pause");
	}



}


int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	   system("cls");
	    
    	setlocale(LC_ALL, "portuguese"); //Definindo um idioma 
	
        printf("### Banco de dados, pacientes Unimed ### \n\n"); // inicio do menu
    	printf("Selecione uma op��o:\n\n");
       	printf("\t1 Registrar paciente\n");
	   	printf("\t2 Localizar paciente\n");
		printf("\t3 Deletar paciente\n\n"); 
			
	    printf("Op��o:");// final do menu
			
	    scanf("%d", &opcao); //Armazenando a escolha do uisuario
	
	    system("cls"); // responsalvel por limpara tela
	
	    switch(opcao)
	    {
	    	case 1:
	        Registro(); // chamada das fun�oes
	    	break;
	    	
	    	case 2:
	        Localizar();
    	    break;    
    	        
    	    case 3:
    	    Deletar();
	        break;
			
			default:
			printf("Essa op��o nao existe!\n\n\n");
		    system("pause");
			break;
		} // final do menu
    } 		
}
