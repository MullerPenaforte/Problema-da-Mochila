/****************

LAED1 - Problema da Mochila

 Müller Penaforte

Data: 23/02/2021

****************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*void imprimir (int t, int x[][5]){
int i, j;

printf("Elementos da matriz\n");

         for(i=0;i<t;i++){
            for(j=0;j<t;j++){
                printf("%d ", x[i][j]);
            }
        putchar('\n');
        }

} */
int valoresOtimo(int t, int resultado[] , int melhorMochila[], int valores[], int comparacao){

	
	int valorTotal=0;
	int valorTotal2=0;

	for(int i= 0; i<t; i++){
		if(melhorMochila[i] ==1){
			valorTotal += valores[i];
			//printf("ValorTotal1 :  %d , ", valorTotal);
		}


	 if( resultado[i] ==1){
		valorTotal2 += valores[i];
		//printf("ValorTotal2 :  %d  \n", valorTotal2);
	}
	}

	if(valorTotal2==valorTotal){
		++comparacao ;
		//printf("------------comparacao %d-------------\n" , comparacao);
		//printf("Valor total 1 e 2 : %d --- %d \n", valorTotal, valorTotal2);
		return comparacao;		
	}else{
		return comparacao;
	}

}

float* fator ( int t, float fatores[], float itens[] ){ //funcao  divide o peso pelo valor 

	
    int i; 
    int j = 0;
   
    for (i=0; i < t*2; i++){ //percorre o vetor
        fatores[j]= itens[i]/itens[i+1];
        //printf("TODOS FATORES: %f \n", fatores[j]);
        i++;
        j++;
        }
    
    	
    return fatores; //vetor com preço/valor

}

int* preencher(int t, float itens[], int itensMochila[],int resultado[]){  //Encher ItensMochila com os itens do "resultado" 

		int capacidade=  t*2;
		int j = 0;
		int k = 0;
		for (int i=0; i<capacidade;i++){
			if(resultado[j]==1){
				itensMochila[k]= itens[i];

				itensMochila[k+1]= itens[i+1];
				j++;
				i++;
				k+=2;  //faz i incrementar de 2 em 2
			}else{
				
				j++;
				i++; //faz i incrementar de 2 em 2
			}
		}			
		return itensMochila;
}

int* melhorMochila(int t, int capacidade, float fatores[], int valores[], int pesos[], int mochilaOtima[]){ 
   // receber valor do fator, itens e capacidade de mochila

	int c = capacidade;
	
	int j=0;
	float fatorM =0; //menor valor do fator
	int fatorMp=0;
	
	int soma=0;
	int soma2=0;
	int aux=0;
	
	
	fatorM = fatores[0];

	int k =0;
	 j=0;
	while(j<t){
		for (int i =1; i<t; i++){
		if(fatorM >= fatores[i]){
			fatorM = fatores[i];
			fatorMp = i;
			//printf("Na iteração %d do while if -- menor fator : %f\n", j, fatorM);
		}
		}
		
		fatorM = fatores[k+1];
		//printf("valor do fatorM fora: %f\n", fatorM);
		//printf("Fatores = %f \n", fatores[j]);
		
		//printf("Peso da mochila iteração %d :   kg %d \n", j, pesos[fatorMp]);	

			fatores[fatorMp] = 9999999;	
			
			if(c - pesos[fatorMp] >=0){
				c -=pesos[fatorMp];
				//printf("Capcidade da mochila iteração %d :   -- %d \n", j, c);	
				mochilaOtima[fatorMp] = 1;
			}
			j++;
			k++;
			if(k==t){
				k=0;
			}
		
	}

	for (int i=0; i<t; i++){
		if(mochilaOtima[i]==1){
			
			soma+=valores[i];
			soma2+=valores[i];
			aux=i;
		}	
		
	}
   soma2-=valores[aux];
   soma2+=valores[fatorMp-1];
   

	
	if(c - pesos[fatorMp-1] < 0){
				c+=pesos[fatorMp-2];
				//printf("valor de c : %d ----- \n", c );
			}
								
				if((c - pesos[fatorMp-1]>=0) && (soma<soma2)){
					mochilaOtima[fatorMp-2]=0;
					mochilaOtima[fatorMp-1]=1;
				}



		return mochilaOtima;
  //pegar a capacidade e subtrair o valor do peso do itens que tiver melhor fator (menor valor) até encher a mochila.
	// exemplo: 10kg - 2, fator 0,333. 8kg - 4, fator 0,450, 4kg - 3, fator 0,600. Sobrou 1kg, mochila cheia. 

}

int mochilaInviavel(int t, int resultado[], int pesos[], int capacidade){ // compara se o resultado do arquivo é viável (se cabe na mochila)

	int pesoTotal =0;
	for (int i=0; i<t; i++){
		if(resultado[i] == 1){
			pesoTotal += pesos[i];
		}

	} 
	capacidade -= pesoTotal;
	if (capacidade <0){
		return 1;
	}
	else return 0;

}

void comparadorDeMochila(int t, int mochilaOtima[], int resultado[], int pesos[], int capacidade, int k, int comparacao){ //compara a mochilaOtima com o resultado apresentado no arquivo

		int aux=0;
		for(int i = 0; i<t; i++){
			//printf("mochilaotima :  %d \n", mochilaOtima[i]);
			if(mochilaOtima[i] == resultado[i]){ //testa se o resultado é do tipo solucao 2


				aux++;
			}else{
				aux=9999;
			}
		}
		//printf("Compara dentro de melhor: %d ------------------\n", comparacao);
		//printf ( "valor de t: %d   , valor de aux: %d \n", t,aux);
		if((aux == t)||(comparacao==1)){ //testa se o resultado é do tipo solucao 1 ou 2 
			printf("Solucao otima.");
			
		}else
		if( k == 1){
			printf("Solucao inviavel.");
			k=0;
		}else
		{
		printf("Solucao viavel mas nao otima.");
		}
	
}


int main (void){

	char nome[50];	

	printf ("Digite o nome do arquivo: ");
	scanf("%s", nome); // pede nome do arquivo

	FILE *arquivo;
	arquivo = fopen (nome, "r");


	if(arquivo == NULL){  //verificar se consegue ler o arquivo
		printf ("Esse arquivo não pôde ser lido. \n");
		exit(0);
	}

	int info[5000];

	for(int i=0; i<5000; i++){
		fscanf(arquivo,"%d", &info[i]);
	}

	   ////*********

	int capacidade = info[0];
	//printf("valor do info no info: %d \n", capacidade);


	int t = info[1] ;	// total  de itens 	
	//printf("valor do t no info: %d \n", t);
	int posicoes = t*2;  // os itens na mochila e o preço são dispostos em duplas
	//printf("valor do posicoes no info: %d \n", posicoes);
	float itens[posicoes];  //os itens que tem no arquivo e seus preços
	//printf("valor do itens no info: %d \n", itens[1]);
	int resultado[t];  //sequencia de 0 e 1 que estão no arquivo
	//printf("valor de resultado no info: %d \n", resultado[t]);
	for (int i = 0; i<posicoes; i++ ){  // pega os itens e seus valores   **************************
		itens[i]= info[i+2];
		//printf("os itens: %f\n", itens[i]);
	}

	//printf ("%d", itens[0]);
	
	for (int i = 0; i<t; i++){  // pega o resultado a ser avaliado
		resultado[i]= info[posicoes+i+2];
	}



	fclose(arquivo);

	float fatores[t];
	int itensMochila[posicoes];
	int pesos[t];
	int j=0;
	int valores[t];
	int comparacao =0;
	for (int i =0; i<t; i++){ //separa os pesos de cada item

		pesos[i]= itens[j];
		j+=2;
		//printf("Valores dos pesos: %d \n",pesos[i]);
	}
	j=0;
	for (int i =0; i<t; i++){ //separa os valores de cada item

		valores[i]= itens[j+1];
		j+=2;
		//printf("Valores selecionados: %d\n ", valores[i]);
	}

	int mochilaOtima[t];  //vetor da mochila otima

	for (int i= 0; i<t; i++){  // inicializa a mochilaOtima com todos os espaços igual a 0
		mochilaOtima[i] = 0;
	}
			

	fator (  t, fatores, itens );
	preencher(t,  itens,  itensMochila, resultado);
	melhorMochila( t,  capacidade,  fatores,  valores,  pesos,  mochilaOtima);
	int k = mochilaInviavel( t,  resultado,  pesos,  capacidade);
	comparacao = valoresOtimo( t, resultado,  mochilaOtima,  valores, comparacao);

	//printf("Valor comparacao final> %d --------------- " , comparacao);
	comparadorDeMochila( t,  mochilaOtima,  resultado,  pesos, capacidade, k, comparacao);
	
			//printf("Resposta: fileira %d, caixa %d.", ,);
			
    

return (0);




}