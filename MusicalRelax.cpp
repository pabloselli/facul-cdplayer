#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define numeroDeMusicas 2
// Registro para as faixas
struct topdez{
       int quantidade;
       char nome[30];
       struct FAIXA* prox;
}FAIXA;

typedef struct list {
       char faixas[30];
       char matrizDeFaixas[10][30];
	   int  code;
       char titulo[30];
       char cantor[30];
       struct list* prox;	// ponteiro para o pr�ximo registro
}CD;

void    entrada_dados  ( CD* aux ); // leitura dos dados de entrada
void    cria_lista     ( CD** cd ); // inicia a lista
void    incluir_cd     ( CD** cd );
CD*     procura_nodo   ( CD* cd, int code );

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	CD* cd;
	CD* topTen;
	cria_lista(&cd);
	cria_lista(&topTen);
	
	while(1){
		system("cls");
		printf("\n------ Musical Relax ------");
		printf("\n1 - Incluir CD.");
		printf("\n2 - Exclu�r CD.");
		printf("\n3 - Escolha de um CD para ser tocado e escolha da m�sica.");
		printf("\n4 - Mostra todos os CDs e as respectivas m�sicas.");
		printf("\n5 - Mostrar e tocar TOP 10.");
		printf("\n0 - Sair.");
		printf("\nDigite a op��o desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				incluir_cd( &cd );
				break;
			case 2:
				//Excluir
				break;
			case 3:
				//Escutar
				break;
			case 4:
				//Mostrar cds
				break;
			case 5:
				//Mostar top 10
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("Op��o inv�rlida");
				break;
		}
	}
}

void cria_lista( CD** l ){
    *l = NULL;
}

void entrada_dados( CD* aux ){
	printf( "\n\n Digite o c�digo do CD: " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->code);
	
	printf( "\n\n Digite a T�tulo do CD: " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->titulo);

    printf( "\n Digite o nome do cantor: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->cantor );    
    for(int i = 0;i<=numeroDeMusicas;i++){
		printf("T�tulo da faixa:");
		gets(aux->faixas);
		strcpy(aux->matrizDeFaixas[i],aux->faixas);
	}
	
	printf("\nFim do entrada de dados, enter para voltar ao menu.");
	aux->prox = NULL;    // n�o aponta
	getchar();
}

void incluir_cd( CD** cd ){
    CD* p; // ponteiro auxiliar

    CD* no =  ( CD * ) malloc ( sizeof( CD ) ); // aloca novo espaco em memoria
    if( no != NULL ){                            // verifica se conseguiu alocar memoria para o novo registro
             entrada_dados( no );                // le dados
             if( *cd == NULL )                    // lista vazia
                 *cd= no;                         // insere o primeiro registro
             else {
                  p = *cd;                        // percorre a lista at� encontrar o ultimo registro
                  while( p->prox != NULL )
                        p = p->prox;
                  p->prox = no;                  // ultimo aponta para o novo registro
                  printf( "\n Registro incluido!" );                  
                  }
        }
    else
        printf( "\n Lista cheia!" );
}

CD* procura_nodo( CD* p, int code ){ 
    while( ( p->code != code ) && ( p->prox != NULL ))// anda pela lista at� o final ou at� encontrar codigo desejado
             p = p->prox;                                   // passa para o proximo
    return p; // nodo de referencia
}


















