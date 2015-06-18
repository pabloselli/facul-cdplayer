#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define numeroDeMusicas 2
// Registro para as faixas
typedef struct topdez {
       int codigo;
	   int quantidade;
       char nome[30];
       struct topdez* prox;
}FAIXA;

typedef struct list {
	   int  code;
       char faixas[30];
       char matrizDeFaixas[10][30];
       char quantidadeTocadas[10];
       char titulo[30];
       char cantor[30];
       struct list* prox;	// ponteiro para o próximo registro
}CD;

void    entrada_dados  ( CD* aux ); // leitura dos dados de entrada
void    cria_lista     ( CD** cd ); // inicia a lista
void    incluir_cd     ( CD** cd );
void    exclui_cd      ( CD** cd ); // exclui
CD*     procura_nodo   ( CD* cd, int code );
void    escolher_musica( CD** aux, FAIXA** top);
CD*     procura_nodo   ( CD* cd, int code );
void    mostrar_cds    ( CD* aux ); // visualizacao da lista em tela

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
		printf("\n2 - Excluír CD.");
		printf("\n3 - Escolha de um CD para ser tocado e escolha da música.");
		printf("\n4 - Mostra todos os CDs e as respectivas músicas.");
		printf("\n5 - Mostrar e tocar TOP 10.");
		printf("\n0 - Sair.");
		printf("\nDigite a opção desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				incluir_cd( &cd );
				break;
			case 2:
				exclui_cd( &cd );
				break;
			case 3:
				//verSeCadastrou( cd );
				break;
			case 4:
				mostrar_cds( cd );
				break;
			case 5:
				//Mostar top 10
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("Opção inválida");
				break;
		}
	}
}

void cria_lista( CD** cd ){
    *cd = NULL;
}

void entrada_dados( CD* aux ){
	printf( "\n Digite o código do CD:   " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->code);
	
	printf( " Digite o título do CD:   " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets(aux->titulo);

    printf( " Digite o nome do cantor: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->cantor );
	printf("\n");
    for(int i = 0;i<=numeroDeMusicas;i++){
		printf("Título da faixa %d: ",i+1);
		gets(aux->faixas);
		strcpy(aux->matrizDeFaixas[i],aux->faixas);
	}
	
	printf("\nFim do entrada de dados, enter para voltar ao menu.");
	aux->prox = NULL;    // não aponta
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
                  p = *cd;                        // percorre a lista até encontrar o ultimo registro
                  while( p->prox != NULL )
                        p = p->prox;
                  p->prox = no;                  // ultimo aponta para o novo registro
                  printf( "\n CD incluído. Let's Play!!" );                  
             }
    }
    else
        printf( "\n Não há espaço disponível!" );
}

CD* procura_nodo( CD* p, int code ){ 
    while( ( p->code != code ) && ( p->prox != NULL ))// anda pela lista até o final ou até encontrar codigo desejado
             p = p->prox;                                   // passa para o proximo
    return p; // nodo de referencia
}

void mostrar_cds  ( CD* aux ){
	fflush( stdin );
      if( aux == NULL )
        printf( "\n Lista vazia!" );
    else {
         printf("\n\n ---- Lista De Musicas ---- ");
         while( aux != NULL ){    // ponteiro auxiliar para a lista
                printf( "\n Titulo..: %s", aux->titulo );
                printf( "\n Cantor: %s", aux->cantor );
				for(int j=0;j<=numeroDeMusicas;j++){
					printf( "\n Faixa: %s", aux->matrizDeFaixas[j] );
				}
                aux = aux->prox;  // aponta para o proximo registro da lista
         }
    }
    getchar();
}

void exclui_cd( CD** cd ){
    int cod;      // codigo a ser excluido 
    CD* aux;     // ponteiro auxiliar para percorrer a lista 
    CD* no;    // ponteiro auxiliar para a codigo de referencia

    printf("\nCódigo do CD: ");
    fflush( stdin );                        // limpa buffer do teclado e faz a entrada de dados
    scanf( "%d", &cod );              
    if( *cd != NULL ){                       // verifica se a lista esta vazia 
        no = procura_nodo( *cd, cod );       // procura codigo de referencia, a ser excluida
        if(( cod == no->code) && ( no != NULL )){ // verifica se encontrou a codigo na lista
            aux = *cd;                         // ponteiro auxiliar aponta para o inicio da lista
            if( aux == no )                   // verifica se o registro apontado pelo auxiliar e o registro que sera excluido
                *cd = aux->prox;               // faz o inicio da lista apontar para o proximo registro, visto que o primeiro sera excluido
            else {
                 while( aux->prox != no )     // procura registro anterior ao que sera excluido
                        aux = aux->prox;
                 aux->prox = no->prox;        // faz o registro anterior apontar para um registro após o excluido - para onde este esta apontando
        	}
             free( no ); // libera o espaco de memoria que estava sendo ocupado pelo registro que foi excluido
             printf( "\n CD excluído do CD-Player!" );
        } 
        else
             printf("\nCD não encontrado, por favor, digite um novo código!");
    }  
    else
        printf("\nNão há CD's disponíveis. Por favor, cadastre um novo CD!");
}
    
