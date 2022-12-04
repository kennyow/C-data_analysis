#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Create a struct who will contain data from csv
typedef struct{
    char date[100];
    float open, high, low, close, volume;
}Market;

//Driver Code
int main(){

    setlocale(LC_ALL, "English");
    //Botei em inglês para considerar o ponto flutuante como um ponto.
    //ex: 25.35 e não 25,35
    
    FILE *arquivo = fopen("ia.csv","r"); //create pointer to file and read the file
    Market dadosia; //create an variable of type "Market" who is the struct created
    char dadosiastring[1000]; 
    int contador=0;
    int contadorpt=0;
    float valor=0;
    char *pt;

    //Test if is all okay with reading csv file
    if (arquivo != NULL){
    printf("O Arquivo.csv foi identificado com sucesso.\n");
    }
    else{
    printf("O Arquivo.csv não tem dados ou não existe.\n");
    getchar();
    return 0;
    }

    //create a pointer and create a txt file to put data inside of this
    FILE *arquivotxt = fopen("ia.txt","wb");

    //Test if is all okay with creating txt file
    if (arquivotxt != NULL){
    printf("O Arquivo.txt foi identificado com sucesso.\n");
    }
    else{
    printf("O Arquivo.txt não foi identificado.\n");
    getchar();
    return 0;
    }

    //Loop

    while(fgets(dadosiastring,sizeof(dadosiastring),arquivo)){
        if (contador != 0){
            pt = strtok(dadosiastring, ",");
            while(pt){
                
            if (contadorpt == 0){
                strcpy(dadosia.date , pt);
                }
            if (contadorpt == 1){
                valor = strtof(pt,NULL);
                dadosia.open = valor;
                }
            if (contadorpt == 2){
                valor = strtof(pt,NULL);
                dadosia.high = valor;
                }
            if (contadorpt == 3){
                valor = strtof(pt,NULL);
                dadosia.low = valor;
                }
            if (contadorpt == 4){
                valor = strtof(pt,NULL);
                dadosia.close = valor;
                }
            if (contadorpt == 5){
                valor = strtof(pt,NULL);
                dadosia.volume = valor;
                }

            pt = strtok(NULL, ",");
            contadorpt++;
            }
            
            fwrite(&dadosia, sizeof(dadosia), 1, arquivotxt);
            printf("\n---DADOS---\n");
            printf("DATE: %s\n",dadosia.date);
            printf("OPEN: %f\n",dadosia.open);
            printf("HIGH: %f\n",dadosia.high);
            printf("LOW: %f\n",dadosia.low);
            printf("CLOSE: %f\n",dadosia.close);
            printf("VOLUME: %f\n",dadosia.volume);
            printf("---DADOS---\n");
            contadorpt = 0;
        }
        contador++;
    }

    //close files
    fclose(arquivo);
    fclose(arquivotxt);
    getchar();
}