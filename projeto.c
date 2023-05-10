#include <stdio.h> // Biblioteca de comunicaçao com o user 
#include <stdlib.h> // biblioteca alacaçao de espaço em memoria
#include <locale.h> // biblioteca de alacaçao de texto por regiao 
#include <string.h> // biblioteca para consultar a string

int Registro() // função responsavel por cadastrar os usuarios no sistsema
{
	// inicio da criaçao de variaves/string
	char arquivo [40];
    char CPF [40];           
    char nome [40];
    char sobrenome[40];
    char urgencia [5];
    // final da criaçao de variaves/string
    
    printf("Digite o CPF do novo paciente:"); // colletando informaçao do ususrio
    scanf("%s", CPF); //%s refere-se a string 
    
    strcpy(arquivo, CPF); // Responsavel por copiar os valores da string
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo o "w" siginica escrever
    fprintf(file,CPF); // salvo o valor da variavel
    fclose(file); // fecho o arquivo 
    
    file = fopen(arquivo, "a"); // pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file,"," ); // colocando uma , no arquivo para a divisao
    fclose(file);
    
    printf("Digite o nome  do novo paciente:");// colletando informaçao do ususrio
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file, " "); // colocando um espaço no arquivo para a divisao
    fclose(file);
    
    printf("Digite o Sobrenome do novo paciente:");// colletando informaçao do ususrio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file, " -> "); // colocando "->" no arquivo para a divisao
    fclose(file);
    
    printf("Digite a Urgencia do paciente:");// colletando informaçao do ususrio
    scanf("%s",urgencia);
    
    file = fopen(arquivo, "a");// pedindo para o programa abrir e atualiozar o aquivo com as informaçoes
    fprintf(file,urgencia);
    fclose(file);  
    
    system("pause"); // pausando o sistema para o user ler
    
    
}
int Localizar() //função responsavel por registrar os usuarios no sistsema
{
    setlocale(LC_ALL, "portuguese"); //Definindo um idioma 
    
    char CPF[40];
    char conteudo[200];
    
    printf("DIgite o CPF do paciente: ");// colletando informaçao do ususrio
    scanf("%s", CPF);
    
    FILE *file;
    file = fopen(CPF, "r");// pedindo para o programa abrir e ler o aquivo com as informaçoes
    
    if(file == NULL)
    {
    	printf("Paciente não encontrado, tente novamente!!. \n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas são as informaçoes do paciente:\n "); // mostrando informaçoes para o user
    	printf("%s", conteudo); // salavando as informaçoes em string
    	printf("\n\n ");
	}
     
     system("pause");
     
}

int Deletar() //função responsavel por deletar os usuarios do sistsema
{
    char CPF[40];
    
    printf("Digite o CPF do paciente a ser deletado: ");// colletando informaçao do ususrio
    scanf("%s", CPF);
    
    remove(CPF); // removendo o arquivo solicitado

    
    FILE* file;
    file = fopen(CPF, "r");
    
    if(file == NULL) // caso nao encontre nenhum arquivo ele vai dizer para o usuario qeu nao foi encontrado
    {
    	printf("Paciente não se encontra no sistema!!\n");
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
    	printf("Selecione uma opção:\n\n");
       	printf("\t1 Registrar paciente\n");
	   	printf("\t2 Localizar paciente\n");
		printf("\t3 Deletar paciente\n\n"); 
			
	    printf("Opção:");// final do menu
			
	    scanf("%d", &opcao); //Armazenando a escolha do uisuario
	
	    system("cls"); // responsalvel por limpara tela
	
	    switch(opcao)
	    {
	    	case 1:
	        Registro(); // chamada das funçoes
	    	break;
	    	
	    	case 2:
	        Localizar();
    	    break;    
    	        
    	    case 3:
    	    Deletar();
	        break;
			
			default:
			printf("Essa opção nao existe!\n\n\n");
		    system("pause");
			break;
		} // final do menu
    } 		
}
