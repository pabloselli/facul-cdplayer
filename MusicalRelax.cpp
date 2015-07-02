#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define numeroDeMusicas 9
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
void    cria_topdez    ( FAIXA** topdez );
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
void    ordena_lista( FAIXA** top );
void 	inverte( FAIXA** top );
int 	conta(FAIXA** top);

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
				escolher_musica( &cd, &topdez);
				break;
			case 4:
				mostrar_cds( cd );
				break;
			case 5:
				ordena_lista( &topdez );
				inverte( &topdez );
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
		printf(" Título da faixa %d: ",i+1);
		gets(aux->faixas);
		strcpy(aux->matrizDeFaixas[i],aux->faixas);
	}
	
	printf("\n Fim do entrada de dados, enter para voltar ao menu.");
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

FAIXA* procura_nodo_faixa( FAIXA* p, char nome[255] ){ 
    while( strcmp(p->nome,nome)!= 0 && p->prox != NULL) // anda pela lista até o final ou até encontrar codigo desejado
        p = p->prox;                                    // passa para o proximo
    return p; // nodo de referencia
}


void mostrar_cds  ( CD* aux ){			//Função para mostrar todos os cds e as faixas
	fflush( stdin );
	if( aux == NULL )					//Se for vazia, imprime lista vazia
		printf( "\n Lista vazia!" );
	else {
		printf("\n\n ---- Lista De CDS ---- ");
		while( aux != NULL ){    // ponteiro auxiliar para a lista
			printf( "\n Titulo..: %s", aux->titulo );  //Mostra o título da música
			printf( "\n Cantor: %s", aux->cantor );    //Mostra o cantor do cd
			for(int j=0;j<=numeroDeMusicas;j++){ //Itera as faixas
				printf( "\n Faixa %d: %s", j, aux->matrizDeFaixas[j] ); 
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
}
// lista as faixas de um cd expecífico
void segunda_escolha( CD* aux ){
	fflush( stdin );
    printf("\n\n ---- Lista De Musicas ---- ");
	for(int j=0;j<=numeroDeMusicas;j++){
		printf( "\n Faixa %d: %s",j+1, aux->matrizDeFaixas[j] );
	}
}

void exclui_cd( CD** cd ){
    int cod;      // codigo a ser excluido 
    CD* aux;     // ponteiro auxiliar para percorrer a lista 
    CD* no;    // ponteiro auxiliar para a codigo de referencia

    printf("\n Código do CD: ");
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
             printf("\n CD não encontrado, por favor, digite um novo código!");
    }  
    else
        printf("\n Não há CD's disponíveis. Por favor, cadastre um novo CD!");
	getchar();
}

void inclui_fim( FAIXA** top,char nome[255] )
{
    FAIXA* p; // ponteiro auxiliar

    FAIXA* no =  ( FAIXA * ) malloc ( sizeof( FAIXA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                            // verifica se conseguiu alocar memoria para o novo registro
			strcpy(no->nome,nome);
			no->quantidade = 1;
             if( *top == NULL )                    // lista vazia
                 *top = no;                        // insere o primeiro registro
             else {
                  p = *top;                        // percorre a lista até encontrar o ultimo registro
                  while( p->prox != NULL )
                        p = p->prox;
                  p->prox = no;                  // ultimo aponta para o novo registro
                  printf( "\n Registro incluido!" );                  
                  } // fim if ( *l == NULL ) 
        } // fim if( no != NULL )
    else
        printf( "\n Lista cheia!" );
}

void escolher_musica( CD** cd,FAIXA** top){
	int cod,val;
	CD* no;
	FAIXA* p;
	char nomeFaixa[255];
	
	primeira_escolha(*cd);
	printf("\n Qual o código do cd: ");
	scanf("%d",&cod);
	no = procura_nodo(*cd,cod);
	if(no != NULL){
		segunda_escolha(no);
		printf("\n Digite a posição da faixa:");
		scanf("%d",&cod);
		val = cod-1;
		if(val<=numeroDeMusicas && val>=0){
			printf("\n Tocando musica...");
			printf( "\n Faixa: %s", no->matrizDeFaixas[val]);
			strcpy(nomeFaixa,no->titulo);
			strcat(nomeFaixa," - ");
			strcat(nomeFaixa,no->matrizDeFaixas[val]);

			if(top == NULL){
				strcpy((*top)->nome,nomeFaixa);
				(*top)->quantidade = 1;
			}else{
				p = *top;
				while(p!=NULL){
					if(strcmp(p->nome,nomeFaixa)!=0)
						p = p->prox;
					else{
						p->quantidade++;
						break;
					}
				}
				if(p==NULL)
					inclui_fim(top,nomeFaixa);
			}
		}else
			printf("\n Álbum não contem esta faixa");
	}else
		printf("\n CD não encontrado");
	getch();
}

void mostrar_top  ( FAIXA* top ){			//Função para mostrar todos os cds e as faixas
	fflush( stdin );
	
	int qtt = 0;
	
	if( top == NULL )					//Se for vazia, imprime lista vazia
		printf( "\n Lista vazia!" );
	else {
		printf("\n\n ---- TOP DEZ  ---- ");
		while( top != NULL || qtt>=10 ){    // ponteiro auxiliar para a lista
			printf( "\n Titulo..: %s ", top->nome);  //Mostra o título da música
			printf( "Quantidade..: %d", top->quantidade);  //Mostra quantidade de vezes tocado
			printf(" Tocando...");
			top = top->prox;  // aponta para o proximo registro da lista
		}
	}
	getchar();
}

void ordena_lista( FAIXA** top )
{
    FAIXA* p;
    FAIXA* ant; 
    FAIXA aux;  // auxiliar para a troca de dados
     
    if( *top == NULL ) // verifica se a lista esta vazia 
        printf( "\n Lista vazia!" );
    else {
          ant = *top;        // posiciona ponteiro auxiliar para anterior no início da lista
          p   = ant->prox; //posiciona ponteiro auxiliar que irá caminhar pela lista para comparar com ant
          while( ant->prox != NULL ){ // enquanto não for final de lista 
               while ( p != NULL ){   // enquanto não compara ant com todos posteriores
                    if( p->quantidade < ant->quantidade ){
                        	strcpy(aux.nome,p->nome);
                        	aux.quantidade = p->quantidade;
                        
                        	strcpy(p->nome,ant->nome);
                        	p->quantidade = ant->quantidade;
                        	
                        	strcpy(ant->nome,aux.nome);
                        	ant->quantidade = aux.quantidade;
                         } // fim if( p->info.codigo < ant.info.codigo )
                     p= p->prox;
                    } // fim while ( p != NULL )  
                ant= ant->prox; // atualiza ponteiros
                p= ant->prox;  
               } // fim while ( ant->prox != NULL )        
          printf( "\nLista ordenada!" );                 
         } // fim else
}

void inverte( FAIXA** top )
{
    FAIXA* p; 
    FAIXA* q;           // ponteiros auxiliares para percorrer a lista 
	FAIXA* t;           // ponteiros auxiliares para percorrer a lista 
    
    if( *top == NULL )    // verifica se a lista esta vazia 
        printf( "\n Lista vazia!" );
    else {
         p = *top;        // inicializa os ponteiros auxiliares
         if( p->prox == NULL ) // verifica se so tem um elemento
             printf( "\n Lista com apenas 1 elemento!" );
         else {
              q = p->prox;        // inicializa os ponteiros auxiliares
              t = q->prox;
              while( t != NULL ){ // inverte o sentido do apontamento de cada registro, ate chegar ao ultimo
                     q->prox = p;
                     p = q;       // anda pela lista
                     q = t;
                     t = t->prox;
              } // while( t != NULL )
              q->prox = p;        // altera o ponteiros do último
              p = *top;             // primeiro aponta para NULL
              p->prox = NULL;
              *top = q;             // inverte o inicio da lista
              printf( "\n Lista invertida!" );
         } // if( p->prox == NULL )
    } // if( *l == NULL ) 
}



