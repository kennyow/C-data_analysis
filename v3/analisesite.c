// C program for the above approach
// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;

//Summatory
float Array_sum(float array[] , int n)
{
    //Read an array and return the sum
    float sum;
     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Função Média
float Array_media(float array[] , int n)
{
    //read an avarage and return the mean beetween values into
    float media;
    float sum;

     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
       media = sum/n;
    }
    return media;
}

//Rearranjo da array
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

// Função MEDIANA:
float Find_median(float array[] , int n)
{
    //Receive an array and find the median
    float median=0;

    // se o número de elementos da array for �mpar
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // se o número de elementos for par
    else
        median = array[n/2];

    return median;
}

//Função VARIANCIA
float Array_variance(float array[] , int n, float media, float sum)
{

    float x[n];
    float variance;


    for (int i = 0; i < n; i++)
    {
        sum = sum + pow((array[i] - media), 2);
    }
    variance = sum / (float)n;

    return variance;
}

//Função DESVIO PADRAO
float Array_deviation(float variance)
{
    float std_deviation;


    std_deviation = sqrt(variance);
    return std_deviation;
}

// Driver Code
int main()
{	float matriz[5125][7];
	// Substitute the full file path
	// for the string file_path
	char nomearquivo[100];
    char pasta[100] = "data/stocks/";
    
    printf("Digite o nome do csv: ");
    scanf("%s", nomearquivo);
    strcat(pasta, nomearquivo);

    FILE* arquivo = fopen(pasta,"r");

	if (!arquivo)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,
					1024, arquivo)) {
			column = 0;
			// row++;

			// To avoid printing of column
			// names in file can be changed
			// according to need
			if (row == 2)
				break;

			// Splitting the data
			char* value = strtok(buffer, ", ");

			while (value) {
				printf("\t%s", value);
				float varfloat = atof(value);
				if(row > 0){
					matriz[row][column] = varfloat;
				}
				value = strtok(NULL, ", ");
				column++;
				if(column == 7){
					column = 0;
					break;
				}
			}
			printf("\n");
			row++;
		}

	getchar();
		
	}
	fclose(arquivo);
	printf("\n");
	int i,j = 0;
	for ( i=0; i<2; i++ )
    for ( j=0; j<7; j++ )
    {
      printf ("\nElemento[%d][%d] = %f\n", i, j,matriz[ i ][ j ]);
    }
  
	return 0;
}
