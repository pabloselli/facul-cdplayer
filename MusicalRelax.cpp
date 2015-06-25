#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define numeroDeMusicas 2
// Registro para o top dez
typedef struct topdez {
       int codigo;
	   int quantidade;
       char nome[255];
       struct topdez* prox;
}FAIXA;

//Registro do cd
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
void    cria_topdez( FAIXA** topdez );
void    incluir_cd     ( CD** cd );
void    exclui_cd      ( CD** cd ); // exclui
CD*     procura_nodo   ( CD* cd, int code );
void    escolher_musica( CD** cd, FAIXA** top);
CD*     procura_nodo   ( CD* cd, int code );
void    mostrar_cds    ( CD* aux ); // visualizacao da lista em tela
void	primeira_escolha( CD aux );
void	segunda_escolha( CD aux );
void    inclui_ordenado( FAIXA** top,char nome );
void	mostrar_top	   (FAIXA* top);

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int op;
	CD* cd;
	FAIXA* topdez;
	cria_lista(&cd);
	cria_topdez(&topdez);

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
				escolher_musica( &cd, &topdez);
				break;
			case 4:
				mostrar_cds( cd );
				break;
			case 5:
				mostrar_top( topdez );
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
//Cria a lista do cd
void cria_lista( CD** cd ){
    *cd = NULL;
}
//cria a lista top dez
void cria_topdez( FAIXA** topdez ){
    *topdez = NULL;
}

//Entra os dados do cd e das músicas
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
	aux->prox = NULL; // não aponta
	getchar();
}

void incluir_cd( CD** cd ){
    CD* p; // ponteiro auxiliar

    CD* no =  ( CD * ) malloc ( sizeof( CD ) );   // aloca novo espaco em memoria
    if( no != NULL ){                             // verifica se conseguiu alocar memoria para o novo registro
             entrada_dados( no );                 // le dados
             if( *cd == NULL )                    // lista vazia
                 *cd= no;                         // insere o primeiro registro
             else {
                  p = *cd;                        // percorre a lista até encontrar o ultimo registro
                  while( p->prox != NULL )
                        p = p->prox;
                  p->prox = no;                   // ultimo aponta para o novo registro
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

void mostrar_cds  ( CD* aux ){			//Função para mostrar todos os cds e as faixas
	fflush( stdin );
      if( aux == NULL )					//Se for vazia, imprime lista vazia
        printf( "\n Lista vazia!" );
    else {
         printf("\n\n ---- Lista De Musicas ---- ");
         while( aux != NULL ){    // ponteiro auxiliar para a lista
                printf( "\n Titulo..: %s", aux->titulo );  //Mostra o título da música
                printf( "\n Cantor: %s", aux->cantor );    //Mostra o cantor do cd
				for(int j=0;j<=numeroDeMusicas;j++){ //Itera as faixas
					printf( "\n Faixa: %s", aux->matrizDeFaixas[j] ); 
				}
                aux = aux->prox;  // aponta para o proximo registro da lista
         }
    }
    getchar();
}
//Lista os cds
void primeira_escolha( CD* aux ){
	fflush( stdin );
	if( aux == NULL )
		printf( "\n Lista vazia!" );
	else {
		printf("\n\n ---- Lista De CDs ---- ");
		while( aux != NULL ){    // ponteiro auxiliar para a lista
			printf(" \n Código: %d",aux->code);
			printf( "\n Titulo..: %s", aux->titulo );
			printf( "\n Cantor: %s", aux->cantor );
			aux = aux->prox;
		}
	}
    getchar();
}
// lista as faixas de um cd expecífico
void segunda_escolha( CD* aux ){
	fflush( stdin );
    printf("\n\n ---- Lista De Musicas ---- ");
	for(int j=0;j<=numeroDeMusicas;j++){
		printf( "\n Faixa: %s", aux->matrizDeFaixas[j] );
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
	getchar();
}

/*
	int quantidade;
	char nome[30];
	struct topdez* prox;
*/

void inclui_ordenado( FAIXA** top,char nome[255] )
{
    FAIXA* p; 
    FAIXA* ant;           // ponteiros auxiliares para percorrer a lista 
/*
   int codigo;
   int quantidade;
   char nome[255];
   struct topdez* prox;
*/
    FAIXA* no =  ( FAIXA * ) malloc ( sizeof( FAIXA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                                    // verifica se conseguiu alocar memoria para o novo registro
			strcpy(no->nome,nome);
			no->quantidade++;
            p = *top;                                      // possiciona ponteiro auxiliar no inicio para percorrer a lista 
			
            while( ( p != NULL ) && ( no->quantidade > p->quantidade ) ){ //faz o laco ate achar a posicao ou o final da lista (no caso em que e a maior codigo)
                  ant = p;                         // guarda a posicao do anterior, para fazer ajuste dos ponteiros ao final
                  p   = p->prox;                   // percorre a lista
            } // fim while( ( p != NULL ) && ( no->info.codigo > p->info.codigo ) )

            if( p == *top )      // verifica se auxiliar aponta para o inicio da lista
                *top = no;       // inicio da lista aponta para novo registro
            else   
                ant->prox = no;// ajuste de ponteiro para inserir na posicao ordenada
            no->prox = p;      // ajuste de ponteiro, inserido de forma ordenada por codigo
    } // fim if( no != NULL )
    else
    	printf("Não tem mais memória.");
}

void escolher_musica( CD** cd,FAIXA** top){
	int cod,val;
	CD* no;
	FAIXA* p;
	char nomeFaixa[255];
	
	
	primeira_escolha(*cd);
	printf("\nQual o código do cd: ");
	scanf("%d",&cod);
	no = procura_nodo(*cd,cod);
	if(no != NULL){
		segunda_escolha(*no);
		printf("Digite a posição da faixa:");
		scanf("%d",&cod);
		val = cod-1;
		if(val<=numeroDeMusicas && val>=0){
			printf("Tocando musica...");
			printf( "\n Faixa: %s", no->matrizDeFaixas[val]);
			strcat(nomeFaixa,no->titulo);
			strcat(nomeFaixa," - ");
			strcat(nomeFaixa,no->matrizDeFaixas[val]);
			
			printf("\nNome faixa: %s\n",nomeFaixa);
			
			if(top == NULL){
				strcpy((*top)->nome,nomeFaixa);
				(*top)->quantidade = 1;
			}else{
				inclui_ordenado(top,nomeFaixa);
			}
		}else
			printf("Álbum não contem esta faixa");
	}else
		printf("CD não encontrado");
	getch();
}

void mostrar_top  ( FAIXA* top ){			//Função para mostrar todos os cds e as faixas
	fflush( stdin );
      if( top == NULL )					//Se for vazia, imprime lista vazia
        printf( "\n Lista vazia!" );
    else {
         printf("\n\n ---- TOP DEZ  ---- ");
         while( top != NULL ){    // ponteiro auxiliar para a lista
                printf( "\n Titulo..: %s", top->nome);  //Mostra o título da música
				
                top = top->prox;  // aponta para o proximo registro da lista
         }
    }
    getchar();
}








