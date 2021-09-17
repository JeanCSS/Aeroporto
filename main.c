#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};

typedef struct Node node;

int tamFilaDec, tamFilaAte;

void inicia(node *FILA);
int vazia(node *FILA);
node *aloca(int IdAviao);
void insere(node *FILA, int IdAviao);
node *retira(node *FILA);
int mandarPraPista(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);


int main(void)
{
    int AvioesPousando, AvioesDecolando, pista1 = 0, pista2 = 0, pista3 = 0, IdAviDeco = 2, IdAviAter = 1;

    // aloquei duas filas do tipo node, uma pra decolagem e outra pra pouso //
	node *FILAdecolagen = (node *) malloc(sizeof(node));
	node *FILAaterrissagem = (node *) malloc(sizeof(node));
    //======================================================================//
	node *tmp;

	if(!FILAdecolagen || !FILAdecolagen){   //se não for possivel alocar uma das duas filas o programa para
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{

	    inicia(FILAaterrissagem);
        inicia(FILAdecolagen);



        do{
            //gera os valores aleatorios de 0 a 3 para representar a quantidade de avioes pra pouso e decolagem a cada rodada/
            srand(time(NULL));
            AvioesDecolando = rand() % 4;
            AvioesPousando = rand() % 4;
            //===============================================================================================================/



            system("cls");
            system("COLOR 09");
            printf("|Solicitacao de Pouso: %d |Solicitacao de decolagem: %d | \n\n", AvioesPousando, AvioesDecolando);

            int i;

            //==========================================================================
            for(i = 0; i < AvioesDecolando; i++){  // pega a quantidade de aviao e faz o loop

                insere(FILAdecolagen, IdAviDeco); // insere o aviao na fila passando por parametro o nome da fila e o ID do avião

                IdAviDeco+=2;        // o primeiro aviao é identificado pelo n° 2 depois 4 6 8 ... n

            }
            for(i = 0; i < AvioesPousando; i++){

                insere(FILAaterrissagem, IdAviAter);

                IdAviAter+=2;  // esse começa com o n° 1 depois 3 5 7 ... n, impar sempre acrescentando 2 em 2 de acordo com numero de avioes que chega

            }
            //=======================================================================



            exibe(FILAaterrissagem);

            exibe(FILAdecolagen);

            /// ///////////////////   Imprimir as pistas/////////////////////////////////////////////////



            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 201);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);


            char aviao = '-';
            if(pista1 != 0){
                if(pista1 % 2 == 0)// se o ID do avião for par
                    aviao = 174;// a variavel aviao recebe o codigo ASCII equivalente a '<<'
                if(pista1 % 2 == 1)
                    aviao = 175; // recebe '>>'
            }

            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c - - - - %c - - - - - - - %d\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186, aviao, pista1);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);

            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);


            aviao = '-';
            if(pista2 != 0){
                if(pista2 % 2 == 0)
                    aviao = 174;
                if(pista2 % 2 == 1)
                    aviao = 175;
            }

            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c - - - - %c - - - - - - - %d\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186, aviao, pista2);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);

            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);

            aviao = '-';
            if(pista3 != 0){
                if(pista3 % 2 == 0)
                    aviao = 174;
                if(pista3 % 2 == 1)
                    aviao = 175;
            }

            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c - - - - %c - - - - - - - %d\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,186, aviao, pista3);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);


            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c       ", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176,176, 186);


            /// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            /// ////////////////////////////////////////////////////
            /// /          teste de prioridades              ///////
            /// ////////////////////////////////////////////////////

            if(tamFilaDec != 0 && tamFilaAte != 0){ //se nenhuma fila tiver vasia

                if(tamFilaDec >= 2*tamFilaAte){ // se a pista de decolagem for maior ou igual ao dobro
                                                // da pista de aterrisagem, libera 2 pistas p decolagem
                    pista1 = mandarPraPista(FILAaterrissagem);
                    pista2 = mandarPraPista(FILAdecolagen);
                    pista3 = mandarPraPista(FILAdecolagen);
                }

                else{ // senao, duas pistas p ra pouso
                    pista1 = mandarPraPista(FILAaterrissagem);
                    pista2 = mandarPraPista(FILAaterrissagem);
                    pista3 = mandarPraPista(FILAdecolagen);
                }
            }
            else{// se alguma fila tiver vasia.

                if(tamFilaDec == 0){ //se a fila de decolagem estiver vasia. Tres pistas Para Aterrisagem
                    pista1 = mandarPraPista(FILAaterrissagem);
                    pista2 = mandarPraPista(FILAaterrissagem);
                    pista3 = mandarPraPista(FILAaterrissagem);
                }
                else{//senao. Tres pistas Para decolagem
                    pista1 = mandarPraPista(FILAdecolagen);
                    pista2 = mandarPraPista(FILAdecolagen);
                    pista3 = mandarPraPista(FILAdecolagen);
                }
            }
            getch();




        }while(2 + 2 == 4);

        free(FILAaterrissagem);
        free(FILAdecolagen);

        return 0;
	}
}

void inicia(node *FILA)
{
	FILA->prox = NULL;
	tamFilaAte = 0;
	tamFilaDec = 0;
}

int vazia(node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca(int IdAviao)
{
	node *novo=(node *) malloc(sizeof(node));

	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{

		novo->num = IdAviao;

		return novo;
	}
}

void insere(node *FILA, int IdAviao)
{
	node *novo = aloca(IdAviao);

	novo->prox = NULL;

	if(vazia(FILA))
		FILA->prox=novo;
	else{
		node *tmp = FILA->prox;

		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}

		tmp->prox = novo;
	}

	// se o aviao for par aumenta a fila de decolagem
    if(IdAviao % 2 == 0)
            tamFilaDec++;
    else
            tamFilaAte++;
}


node *retira(node *FILA)
{
	if(FILA->prox == NULL){
		printf("Fila ja esta vazia\n");
		return NULL;
	}else{

        // aqui retira o primeiro elemento da fila
		node *tmp = FILA->prox;
		FILA->prox = tmp->prox;

		// se o aviao a ser retirado for par diminue a fila de decolagem
	if(tmp->num % 2 == 0)
        tamFilaDec--;
    else
        tamFilaAte--;
		return tmp;
	}
}

void exibe(node *FILA)
{
    //rescebe o nome da fila, imprime todos os elementos da fila
	if(vazia(FILA)){
		printf("Fila vazia!\n\n");
		return ;
	}
	node *tmp;

	tmp = FILA->prox;

    //aqui é só pra diferenciar qual fila que é
    //como estaamos trabalhandoo com duas filas, uma de numeros pares e outra de impares

    if(tmp -> num % 2 == 0) // se o primeiro n° for par. Imprime isso.
        printf("Fila de decolagem com %d avioes: ",tamFilaDec);

    else //senao. Imprime isso.
        printf("Fila de aterrissagem com %d avioes: ",tamFilaAte);

    // agora imprime todos os elementos da fila
	while(tmp != NULL){
		printf("%d ", tmp->num);
		tmp = tmp->prox;
	}

	printf("\n\n");
}
int mandarPraPista(node *FILA)
{
    //essa função é baseada na funçao exibir com algumas modifiacoes, essa retorna o primeiro elemento pra pista e depois apaga da fila

    int pista;

	if(vazia(FILA)){
		return 0;
	}
	node *tmp;

    // pista recebe o primeiro avião da fila
	tmp = FILA->prox;
    pista = tmp -> num;


    //retira da fila
    retira(FILA);

	return pista;
}

/*void libera(node *FILA)
{
    // essa funçao nao faz nada nesse programa
	if(!vazia(FILA)){

		node *proxNode, *atual;

		atual = FILA->prox;

		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}*/
