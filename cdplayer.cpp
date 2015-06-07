#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {          // registro para uma pessoa
       int  codigo;
       char nome[30];
} INFORMACAO;
       
typedef struct list {
       INFORMACAO info;   // dados do registro
       struct list* prox; // ponteiro para o próximo registro
} LISTA; 

void    entrada_dados  ( LISTA* aux ); // leitura dos dados de entrada
void    imprime_lista  ( LISTA* aux ); // visualizacao da lista em tela
void    cria_lista     ( LISTA** l );  // inicializa lista com NULL
void    inclui_fim     ( LISTA** l );  // inclui um novo registro no final da lista
void    inclui_inicio  ( LISTA** l );  // inclui um novo registro no inicio da lista
LISTA*  procura_nodo   ( LISTA* l, int cod ); // procura na lista por uma codigo
void    exclui_nodo    ( LISTA** l );  // exclui um regitro por codigo 
void    ordena_lista   ( LISTA** l );  // ordena lista por codigo
void    inclui_ordenado( LISTA** l );  // inclui registro na lista ordenado por codigo
void    inverte        ( LISTA** l );  // inverte referencia dos registros
void    consulta_nome  ( LISTA* l );   // consulta por um nome
void    inserir_antes  ( LISTA** l );  // inserir um registro antes de uma codigo de referencia
void    conta_nodo     ( LISTA** l );  // contar o numero de registros existentes na lista

int main( void )
{
    int op;   // opcao do menu                               
    LISTA* l; // declaracao da lista // variavel do tipo lista = lista de ponteiros

    cria_lista( &l );
    while( 1 ){
         printf( "\n /----------------------------------------------------/" ); 
         printf( "\n Teste2 do Ronaldo                                     " );
         printf( "\n [1]   Cria lista                                      " );
         printf( "\n [2]   Inclui registro no final da lista               " );
         printf( "\n [3]   Inclui registro no inicio da lista              " );
         printf( "\n [4]   Exclui registro                                 " );
         printf( "\n [5]   Ordena lista                                    " );
         printf( "\n [6]   Inlcui ordenado                                 " );
         printf( "\n [7]   Inverte lista                                   " );         
         printf( "\n [8]   Consulta nome                                   " );         
         printf( "\n [9]   Inserir antes                                   " );           
         printf( "\n [10]  Conta registros                                 " );           
         printf( "\n [11]  Imprime lista                                   " );         
         printf( "\n [0]   Para sair do programa                           " );
         printf( "\n /----------------------------------------------------/" );      
         printf( "\n Opcao: " );
         scanf("%d", &op); // tecla de opcao do menu
         

         switch( op ) {
            case 1: // rotina cria lista       
                    //cria_lista( &l );
                    break;
                                
            case 2:  // rotina inclui registro no final da lista
                    inclui_fim( &l );    
                    break;
          
            case 3:  // rotina inclui registro no inicio da lista
                    inclui_inicio( &l );
                    break;
                
            case 4:  // rotina exclui registro da lista
                    exclui_nodo( &l );
                    break;
                  
            case 5:  // rotina ordena lista
                    ordena_lista( &l );
                    break;

            case 6:  // rotina inclui ordenado
                    inclui_ordenado( &l );
                    break;
                                                                                   
            case 7: // rotina inverte lista                 
                    inverte( &l ); 
                    break;                                
                    
            case 8: // rotina consultar por um nome                 
                    consulta_nome( l ); 
                    break;             

            case 9: // rotina inserir antes de um codigo                 
                    inserir_antes( &l ); 
                    break; 
                                                           
            case 10: // rotina contar o numero de registros na lista                 
                    conta_nodo( &l ); 
                    break; 

            case 11: // rotina imprime lista                 
                    imprime_lista( l ); 
                    break;                    
                    
            case 0: // término do programa                                                 
                    exit( 1 ); 
                    break;
                
            default : 
                    printf( "\n Digite uma opcao!" );
                    break;
         } // switch( op )
 
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
     } // fim do while( 1 )
     

} // fim do programa principal

void entrada_dados( LISTA* aux )
{ 
    printf( "\n\n Digite a codigo: " ); 
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );     // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  
    aux->prox = NULL;    // não aponta
}

void imprime_lista( LISTA* aux )
{
    if( aux == NULL )
        printf( "\n Lista vazia!" );
	else {
	     printf("\n\n ---- Relatorio Geral ---- ");
         while( aux != NULL ){    // ponteiro auxiliar para a lista
                printf( "\n Nome..: %s", aux->info.nome );
                printf( "\n Codigo: %d", aux->info.codigo );
                aux = aux->prox;  // aponta para o proximo registro da lista
		 } // fim while( aux != NULL )
	} // fim if( aux == NULL )
}

void cria_lista( LISTA** l )
{
    *l = NULL; // lista criada, inicio nao aponta
}

void inclui_fim( LISTA** l )
{
    LISTA* p; // ponteiro auxiliar

    LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                            // verifica se conseguiu alocar memoria para o novo registro
             entrada_dados( no );                // le dados
             if( *l == NULL )                    // lista vazia
                 *l= no;                         // insere o primeiro registro
             else {
                  p = *l;                        // percorre a lista até encontrar o ultimo registro
                  while( p->prox != NULL )
                        p = p->prox;
                  p->prox = no;                  // ultimo aponta para o novo registro
                  printf( "\n Registro incluido!" );                  
                  } // fim if ( *l == NULL ) 
        } // fim if( no != NULL )
    else
        printf( "\n Lista cheia!" );
}

void inclui_inicio( LISTA* *l )
{
    
    LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                            // verifica se conseguiu alocar memoria para o novo registro
             entrada_dados( no );                // le dados
             no->prox = *l;                      // novo aponta para o primeiro existente ou para Null
             *l = no;                            // inicio aponta para o novo registro
             printf( "\n Registro incluido!" );
        } // fim if( no != NULL )
    else
        printf( "\n Lista cheia!" );
}

LISTA* procura_nodo( LISTA* p, int cod )
{ 
    while( ( p->info.codigo != cod ) && ( p->prox != NULL ))// anda pela lista até o final ou até encontrar codigo desejado
             p = p->prox;                                   // passa para o proximo   
             
    return p; // nodo de referencia
}

void exclui_nodo( LISTA** l )
{
    int cod;      // codigo a ser excluido 
    LISTA* p;     // ponteiro auxiliar para percorrer a lista 
    LISTA* no;    // ponteiro auxiliar para a codigo de referencia

    printf( "\n codigo de referencia: " );
    fflush( stdin );                        // limpa buffer do teclado e faz a entrada de dados
    scanf( "%d", &cod );              
    
    if( *l != NULL ){                       // verifica se a lista esta vazia 
        no = procura_nodo( *l, cod );       // procura codigo de referencia, a ser excluida
        if(( cod == no->info.codigo) && ( no != NULL )){ // verifica se encontrou a codigo na lista
            p = *l;                         // ponteiro auxiliar aponta para o inicio da lista
            if( p == no )                   // verifica se o registro apontado pelo auxiliar e o registro que sera excluido
                *l = p->prox;               // faz o inicio da lista apontar para o proximo registro, visto que o primeiro sera excluido
            else {

                 while( p->prox != no )     // procura registro anterior ao que sera excluido
                        p = p->prox;
                 p->prox = no->prox;        // faz o registro anterior apontar para um registro após o excluido - para onde este esta apontando
                 } // fim if( p == no )

             free( no ); // libera o espaco de memoria que estava sendo ocupado pelo registro que foi excluido
             printf( "\n Registro excluido!" );
        } // fim (( cod == no->info.codigo) && ( no != NULL ))
        else
             printf( "\n Nodo nao encontrado!");
    } // fim if( *l != NULL )    
    else
        printf( "\n Lista vazia!" );
}

void ordena_lista( LISTA** l )
{
    LISTA* p;
    LISTA* ant; 
    INFORMACAO aux;  // auxiliar para a troca de dados
     
    if( *l == NULL ) // verifica se a lista esta vazia 
        printf( "\n Lista vazia!" );
    else {
          ant = *l;        // posiciona ponteiro auxiliar para anterior no início da lista
          p   = ant->prox; //posiciona ponteiro auxiliar que irá caminhar pela lista para comparar com ant
          while( ant->prox != NULL ){ // enquanto não for final de lista 
               while ( p != NULL ){   // enquanto não compara ant com todos posteriores
                    if( p->info.codigo < ant->info.codigo )
                        {
                         aux      = p->info; // faz a troca (algoritmo de ordenação Bolha)
                         p->info  = ant->info;
                         ant->info= aux;
                         } // fim if( p->info.codigo < ant.info.codigo )
                     p= p->prox;
                    } // fim while ( p != NULL )  
                ant= ant->prox; // atualiza ponteiros
                p= ant->prox;  
               } // fim while ( ant->prox != NULL )        
          printf( "\nLista ordenada!" );                 
         } // fim else
}


void inclui_ordenado( LISTA** l )
{
    LISTA* p; 
    LISTA* ant;           // ponteiros auxiliares para percorrer a lista 
    
    LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                                    // verifica se conseguiu alocar memoria para o novo registro
            entrada_dados( no );                         // le dados
            p = *l;                                      // possiciona ponteiro auxiliar no inicio para percorrer a lista 

            while( ( p != NULL ) && ( no->info.codigo > p->info.codigo ) ){ //faz o laco ate achar a posicao ou o final da lista (no caso em que e a maior codigo)
                  ant = p;                         // guarda a posicao do anterior, para fazer ajuste dos ponteiros ao final
                  p   = p->prox;                   // percorre a lista
            } // fim while( ( p != NULL ) && ( no->info.codigo > p->info.codigo ) )

            if( p == *l )      // verifica se auxiliar aponta para o inicio da lista
                *l = no;       // inicio da lista aponta para novo registro
            else   
                ant->prox = no;// ajuste de ponteiro para inserir na posicao ordenada
            no->prox = p;      // ajuste de ponteiro, inserido de forma ordenada por codigo
    } // fim if( no != NULL )
}

void inverte( LISTA** l )
{
    LISTA* p; 
    LISTA* q;           // ponteiros auxiliares para percorrer a lista 
    LISTA* t;           // ponteiros auxiliares para percorrer a lista 
    
    if( *l == NULL )    // verifica se a lista esta vazia 
        printf( "\n Lista vazia!" );
    else {
         p = *l;        // inicializa os ponteiros auxiliares
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
              p = *l;             // primeiro aponta para NULL
              p->prox = NULL;
              *l = q;             // inverte o inicio da lista
              printf( "\n Lista invertida!" );
         } // if( p->prox == NULL )
    } // if( *l == NULL ) 
}

void consulta_nome( LISTA* l )
{
    char aux_nome[ 30 ];// auxiliar do nome de consulta
    LISTA* p;           // ponteiro auxiliar para percorrer a lista 
    
    if( l == NULL )    // verifica se a lista esta vazia 
        printf( "\n Lista vazia!" );
    else {
         printf( "\n Nome para consulta: " ); // le nome de consulta
         fflush(stdin);
         gets( aux_nome );
         
         p = l;  // posiciona ponteiro auxiliar
         while( ( strcmp( p->info.nome, aux_nome ) != 0) && ( p->prox != NULL )) // anda pela lista até o final ou até encontrar nome desejado
                 p = p->prox;                                                    // passa para o proximo   
         
         if( strcmp( p->info.nome, aux_nome ) == 0 ){ // verifica se achou o nome procurado
             printf( "\n Nome.....: %s", p->info.nome );
             printf( "\n Codigo: %d", p->info.codigo );
             } // if( strcmp( p->info.nome != aux_nome )
         else
             printf( " Nome nao encontrado!" );
         } // if( *l == NULL )
}

void inserir_antes( LISTA** l )
{
    int cod;      // codigo de referencia 
    LISTA* p;     // ponteiro auxiliar
    LISTA* ant;   // ponteiro auxiliar

    LISTA* no =  ( LISTA * ) malloc ( sizeof( LISTA ) ); // aloca novo espaco em memoria
    if( no != NULL ){                             // verifica se conseguiu alocar memoria para o novo registro
              entrada_dados( no );                // le dados     
                   
              if( *l != NULL ){                  // verifica se a lista esta vazia 
                  printf( "\n Codigo de referencia: " );
                  fflush( stdin );               // limpa buffer do teclado e faz a entrada de dados
                  scanf( "%d", &cod );     
                  
                  p = *l; // posiciona auxiliar
                  while( ( p->info.codigo != cod ) && ( p->prox != NULL ) ){ // procura por codigo de referencia
                           ant = p;     // guarda anterior
                           p = p->prox; // anda pela lista                      
                  } // while( ( p->info.codigo != cod ) && ( p != NULL ) )
                  
                  if( p->info.codigo == cod ){                  
                      no->prox = p;
                      if( p == *l ) // sera o primeiro registro
                          *l = no;                          
                      else
                           ant->prox = no; 
                      printf( "\n Registro incluido!" );                    
                  } // if( p->info.codigo == cod )
                  else
                      printf( "\n Codigo de referencia nao encontrado!" );
              } // if( *l != NULL )   
        } // if
        else
             printf( "\n Problema na entrada de dados!" );
}

void conta_nodo( LISTA** l )
{
     LISTA* aux;    // ponteiro auxiliar para percorrer a lista
     int conta = 0;  // contador
     
     if( *l == NULL )// verifica se a lista esta vazia
         printf( "Lista vazia!" );
     else{
          aux = *l;  // posiciona o ponteiro auxiliar no inicio da lista
          while( aux != NULL ){
                 conta++;
                 aux = aux->prox; // passa para o proximo registro
          } // while( aux != NULL )
                 
          printf( "\n Numero de registro(s) na lista: %d", conta );
     } // fim if( *l == NULL )
}
