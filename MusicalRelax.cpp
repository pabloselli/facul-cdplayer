#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Registro para as faixas
typedef struct {
       int codigo;
       char nome[30];
}FAIXA;
       
typedef struct list {
       FAIXA faixas;		// dados do registro
       char titulo[30];
       char cantor[30];
       struct list* prox;	// ponteiro para o próximo registro
}CD;

void    entrada_dados  ( CD* aux ); // leitura dos dados de entrada

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	printf("------ Musical Relax ------");
	printf("1 - Incluir CD.");
	printf("2 - Excluír CD.");
	printf("3 - Escolha de um CD para ser tocado e escolha da música.");
	printf("4 - Mostra todos os CDs e as respectivas músicas.");
	printf("5 - Mostrar e tocar TOP 10.");
	printf("0 - Sair.");
}

void entrada_dados( CD* aux )
{ 
    printf( "\n\n Digite a Título do CD: " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome do autor: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );

    aux->prox = NULL;    // não aponta
}



















