## C data Analysis

### Data Scientists 
  - Kennyo
  - Benn
  - Walker
  - Jafet
  - Pedro
  
#### Objectives

Provide statistical measures to help investors make decisions about buying and selling stocks

#### DataBase
The database is adaptation of : https://www.kaggle.com/datasets/jacksoncrow/stock-market-dataset 
and can be found in : https://drive.google.com/drive/folders/1cp_DhFOfwioHjzSHrHjAWXfpdRx1aJQy?usp=sharing

##### Database Structure
The database we use is located in the directory: data/stocks and has 4 csv files, each with the columns :<br>
Date,Open,High,Low,Close,Adj Close,Volume<br>
Which are data about the stocks of each of the referred companies

#### The code
The last version provides an executable "main.exe", an terminal program who make the follow steps:<br>
1 iteration:<br>
Select the data for a company<br>
2 iteration:<br>
Select the column to be read from a csv<br>
3 iteration:<br>
Select the information the investor wants extracted<br>

##### Market Struct
```
typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;
```
This struct receives the data from database, in this case we are using an CSV as relational database


#### How to use the program?

1- The program will ask for the path of Data. Enter with "Data/Stocks" to openning all options of csv files to reads.<br> 2- The program will ask witch csv file you want to analyse. Enter its name with .csv at the end.<br> 3- The program will ask how much rows you want to see. Enter the desired number.<br> 4- The program will show the values of: open, high, low, close, adjclose and volume of every date of the csv file.


##### How to use the functions of the program?

1- The program will ask witch function you want to use. 2- The functions are: mean, median, variance and deviation. 3- Choose one of the functions and the program will calculate the value for each line except the date.

#### How the program is it organized?
- dsfuncs.h : an header with the processament of analyse
- measures.h : an header with the implementation of statics functions like mean, median, standart deviation, variance, and more
- reading.h  : this module is responsable for read the path of file and say to main it

#### V5 features
1- Version 5 fixes display errors in the terminal for some utf-8 characters, the solution was to translate the source code to English 

2- The user will be able to choose a CSV option within an entire database, and that database will be listed to the user

3- In addition to choosing the lines, you can view the measurements abstracted as structure fields  

4- Modularization of our owner functions

5- User can choose who operation will be done with the column and rows chosen

#### Conclusion
- The exploration of stock data can be greatly expanded through the use of modularization, with low use of computational resources, a typical feature of the language, in the future, expanding the ability to read lines and plot graphs, these topics were beyond the scope of the initial analysis.
- The use of structures allows the elements of the csv file to be read as fields of the csv file, thus significantly reducing the verbosity of the code, and facilitating the abstraction of the data for the programmer

##### PDF version
An pdf relatorie be disponible at: 

