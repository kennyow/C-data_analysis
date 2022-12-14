// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

//Data Struct usada para armazenamento
typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;

//Somatoria
float Array_sum(float array[] , int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Media
float Array_media(float array[] , int n)
{
    float media = 0;
    float sum = Array_sum(array, n);
    media = sum / n;
    return media;
}

//Ordenação crescente
void Array_sort_cres(int *arr , int n)
{
    int i=0 , j=0 , temp=0;
  
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

//Ordenação decrescente
void Array_sort_descres(int *arr , int n)
{
    int i=0 , j=0 , temp=0;

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

//Mediana
float Find_median(float array[] , int n)
{
    float median=0;

    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    else
        median = array[n/2];
    return median;
}

//Variancia
float Array_variance( float array[], int n)
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

//Desvio Padrao
float Array_deviation(float variance)
{
    float std_deviation=0;

    std_deviation = sqrt(variance);
    return std_deviation;
}

//Análise geral
float Analise_geral(float arrayf[], int n){
  int i;
  float resultsoma = Array_sum(arrayf, n);
    printf("\nSOMA: %f",resultsoma);
    
    float resultmedia = Array_media(arrayf, n);
    printf("\nMEDIA: %f",resultmedia);
    
    float resultmediana = Find_median(arrayf, n);
    printf("\nMEDIANA: %f",resultmediana);
    
    float resultvariancia = Array_variance(arrayf, n);
    printf("\nVARIANCIA: %f",resultvariancia);
    
    float resultdesvio = Array_deviation(resultvariancia);
    printf("\nDESVIO: %f",resultdesvio);

    printf("\nDados Crescentes: ");
    Array_sort_cres(arrayf, n);
    for(i = 0; i <= n-1; i++){
      //printf("%f, ",arrayf[i]);
    }
    printf("\nDados Decrescentes: ");
    Array_sort_descres(arrayf, n);
    for(i = 0; i <= n-1; i++){
      //printf("%f, ",arrayf[i]);
    }
  }


int main()
{
  setlocale(LC_ALL, "Portuguese");
  
  Market estruturadados[10000];
	char nomearquivo[1000];
  char pasta[1000] = "";
    
  printf("\nDigite o nome do arquivo .csv: ");
  scanf("%s", nomearquivo);
  strcat(pasta, nomearquivo);

  FILE* arquivo = fopen(pasta,"r");

	if (!arquivo){
		printf("O arquivo .csv não foi encontrado\n");
    getchar();
    return 0;
    }
	else {
		char buffer[100];
		int row = 0;
		int column = 0;
    int contador = 0;
    float valorf = 0;
    int resp = 0;
    int numcoluna = 0;
    int rowmax = 0;
    do{
      printf("\nDigite o número correspondente a coluna a ser analisada\n");
      printf("1-OPEN\n");
      printf("2-HIGH\n");
      printf("3-LOW\n");
      printf("4-CLOSE\n");
      printf("5-ADJ CLOSE\n");
      printf("6-VOLUME\n");
      printf("7-SAIR\n");
      printf("->");
      scanf("%d",&numcoluna);

      if (numcoluna == 7)
          return 0;
  
      printf("\nDigite o número máximo de dados a serem tratados:");
      scanf("%d", &rowmax);
      
      while (fgets(buffer, sizeof(buffer), arquivo)) {
  			column = 0;
        row++;
        
  			if (row == rowmax)
  				break;
  
        if (row == 1) continue;
        
  			char* value = strtok(buffer, ", ");
  
  			while (value) {
          
          if (numcoluna== 0){
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
  		}
      
    int i;
    float arrayf[row-2];
    switch(numcoluna){
      case 1:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].open;
          printf("%.2f" ,arrayf[i-1]);
          }
        Analise_geral(arrayf, row-2);
        break;
      case 2:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].high;
          }
        Analise_geral(arrayf, row-2);
        break;
      case 3:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].low;
          }
        Analise_geral(arrayf, row-2);
        break;
      case 4:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].close;
          }
        Analise_geral(arrayf, row-2);
        break;
      case 5:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].adjclose;
          }
        Analise_geral(arrayf, row-2);
        break;
      case 6:
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].volume;
          }
        Analise_geral(arrayf, row-2);
        break;
      default:
        printf("\nNúmero inválido...");
        break;
      }
    }while(resp == 0);
  return 0;
  }
}
