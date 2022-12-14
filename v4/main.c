// C program for the above approach
// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;

//Summatory
float Array_sum(float array[] , int n)
{
    //Read an array and return the sum
    float sum = 0;
     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Função Média
float Array_media(float array[] , int n)
{
    //read an avarage and return the mean beetween values into
    float media = 0;
    float sum = Array_sum(array, n);
    media = sum / n;
    return media;
}

//Rearranjo da array - Falta testar essa
void Array_sort(int *arr , int n)
{
    //Receive an pointer to array and reorder this 


    // Declarando vari�veis locais
    int i=0 , j=0 , temp=0;


    // Comando FOR para reposicionar os elementos da array:
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp        = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }

}

void Array_sort_desc(int *arr , int n)
{
    //Receive an pointer to array and reorder this 


    // Declarando vari�veis locais
    int i=0 , j=0 , temp=0;


    // Comando FOR para reposicionar os elementos da array:
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp        = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }

}

// Função MEDIANA:
float Find_median(float array[] , int n)
{
    //Receive an array and find the median
    float median=0;

    // se o número de elementos da array for par
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // se o número de elementos for impar
    else
        median = array[n/2];

    return median;
}

//Função VARIANCIA
float Array_variance( float array[], int n )
{
    float sum = 0.0;
    float dev = 0.0;
    float med = Array_media( array, n );
    int i = 0;

    for( i = 0; i < n; i++ )
    {
        dev = array[i] - med;
        sum += (dev * dev);
    }

    return sum / n;
}

//Função DESVIO PADRAO - Falta testar essa
float Array_deviation(float variance)
{
    float std_deviation = 0;


    std_deviation = sqrt(variance);
    return std_deviation;
}

// Driver Code
int main()
{
  setlocale(LC_ALL, "Portuguese");
  Market estruturadados[5126];
  
	char nomearquivo[100];
  char pasta[100] = "";
    
  printf("Digite o nome do csv: ");
  scanf("%s", nomearquivo);
  strcat(pasta, nomearquivo);

  FILE* arquivo = fopen(pasta,"r");

	if (!arquivo)
		printf("Can't open file\n");

	else {
		
		char buffer[5125];

		int row = 0;
		int column = 0;
    int contador = 0;
    float valorf = 0;

		while (fgets(buffer, sizeof(buffer), arquivo)) {
			column = 0;
      row++;
			if (row == 5) // Se quiser printar o .csv todo no caso o csv (A.csv), digite: 5126
				break;

      if (row == 1) continue;
      
			char* value = strtok(buffer, ", ");

			while (value) {
			
				printf("\t%s", value);
        
        if (contador == 0){
          strcpy(estruturadados[row-1].date , value);
        }
        if (contador == 1){
          valorf = strtof(value,NULL);
          estruturadados[row-1].open = valorf;
        }
        if (contador == 2){
          valorf = strtof(value,NULL);
          estruturadados[row-1].high = valorf;
        }
        if (contador == 3){
          valorf = strtof(value,NULL);
          estruturadados[row-1].low = valorf;
        }
        if (contador == 4){
          valorf = strtof(value,NULL);
          estruturadados[row-1].close = valorf;
        }
        if (contador == 5){
          valorf = strtof(value,NULL);
          estruturadados[row-1].adjclose = valorf;
        }
        if (contador == 6){
          valorf = strtof(value,NULL);
          estruturadados[row-1].volume = valorf;
        }
				value = strtok(NULL, ", ");
        contador++;
			}
      column++;
      contador = 0;
			printf("\n");
		}
    
  int i;
  float soma=0;
  printf("ROW:%d",row);
  float sumf[row-2];
    
  for(i = 1; i <= row-2; i++) { // Aqui é um exemplo de codigo isolando a coluna open do .csv
    sumf[i] = estruturadados[i].open;
    soma = soma + sumf[i];
    printf("\nOPEN %d: %f",i,sumf[i]);
    }
  
  printf("\nSOMA: %f",soma);


  }
	fclose(arquivo);
	return 0;
}
