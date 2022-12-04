#include <stdio.h>
#include <locale.h>

//Função SOMA
float Array_sum(float array[] , int n)
{
    float sum;
     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Função MÉDIA
float Array_media(float array[] , int n)
{
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
    // Declarando variáveis locais
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
    float median=0;

    // se o número de elementos da array for ímpar
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // se o número de elementos for par
    else
        median = array[n/2];

    return median;
}

//Função VARIÂNCIA
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

//Função DESVIO PADRÃO
float Array_deviation(float variance)
{
    float std_deviation;


    std_deviation = sqrt(variance);
    return std_deviation;
}


int main()
{

    setlocale(LC_ALL, "Portuguese");

    //Iniciando a Array
    float arr[] = {15.08, 2.00, 4000, 42, 7.50};
    float sum = 0;
    float media = 0;
    float median = 0;
    int n = 0;
    int  i;
    float arr2[n];
    float average, variance, std_deviation, sum3 = 0, sum1 = 0;
    float x[n];


    //Calculando o tamanho da array
    n = sizeof(arr)/sizeof(arr[0]);


    //Copiando todos os elementos da array em outra
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

     //Soma da array:
    sum = Array_sum(arr, n);
    //Média da array:
    media = Array_media(arr, n);

    // Rearranjo da array:
    Array_sort(arr , n);

    //Mediana da array:
    median = Find_median(arr , n);

    //Variância da array:
    variance = Array_variance(arr , n, media, sum);

    //Desvio padrão da array:
    std_deviation = Array_deviation(variance);



    //PRINTS

    printf("A lista principal contém os valores nesta ordem: ");

    for (int i = 0; i < n; i++) {
        printf("%.3f | ", arr2[i]);
    }
    printf("\n");
    printf("O total de itens da lista é %d\n", n);
    printf("O último elemento é %f\n", sizeof(arr2)/sizeof(arr2[0]) - 1);
    printf("A soma de seus elementos é: %.3f\n", sum);
    printf("A média dos elementos é: %.3f\n", media);
    printf("A lista secundária contém os valores rearranjados nesta ordem: ");

    for (int i = 0; i < n; i++) {
        printf("%.3f | ", arr[i]);
    }
    printf("\nA mediana dos elementos é: %.3f\n", median);
    printf("A variância dos elementos é: %.3f\n", variance);
    printf("O desvio padrão dos elementos é: %.3f\n", std_deviation);

    return 0;


}
