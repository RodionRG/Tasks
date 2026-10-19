#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "modul.h"


//Для 9_447
//Проверка является ли число совершенным
//num - число дл проверки на совершенное
int isPerfNum(int num){ 
    unsigned int sum = 0;
    for (unsigned int i = 1; i < num; i++){
        if (num % i == 0){
            sum+=i;
        }
    }
    if (num == sum){
        return 1;
    }
    else{
        return 0;
    }
}



//Для удобного ввода в массив int
//  promt - вводное предложение; arr - указатль на массив; name - название массива; size - размер массива;
void VvodMasInt(const char *promt, int arr[], const char *name, unsigned int size){ //Транслитом не желательно
    if (!(promt == "")){printf("%s\n",promt);}
    for (unsigned int i = 0; i<size;i++){
        printf("%s[%u] = ",name,i+1);
        scanf("%d",&arr[i]);
    }    
}




// Для 9_692d

//Для создания матрицы float
//         rows и cols - кол-во строк и столбцов
//Возвращает матрицу float
float** CreMatrFloat(int rows, int cols){       
    float** matrix = (float**)malloc(rows * sizeof(float*));
    for (unsigned int i = 0; i<cols; i++){
        matrix[i] = (float*)malloc(cols*sizeof(float));
    }
    return matrix;
}




//Для ввода в матрицу float
//promt вводное предложение;  arr - указатль на массив;  name - название массива; 
// rows - кол-во строк; cols -  кол-во столбцов;
void VvodMatrFloat(const char *promt, float** arr, const char *name, unsigned int rows, unsigned int cols){ 
    if (!(promt == "")){printf("%s\n",promt);} 
     for (unsigned int i = 0; i<rows;i++){
         for (unsigned int j = 0; j<cols;j++){
            printf("%s[%u][%u] = ",name,i+1,j+1);
            scanf("%f", &arr[i][j]);
         }
     }
}




//Для освобождения памяти от матрици float
//arr - указатель на матрицу; rows - кол-во строк;
void freeMatrFloat(float** arr,unsigned int rows){ 
    for (unsigned int i = 0; i<rows;i++){
        free(arr[i]);
    }
    free(arr);
}




//Поиск элементов в заштрихованной области
//matrix - Указатель на матрицу; rows и cols - кол-во строк и кол-во столбцов; 
//length - указатель на переменную, хранящую кол-во найденых чисел чисел 
//Возвращает массив выбранных элементов
float* MassElemMatr(float** matrix,unsigned int rows,unsigned int cols, unsigned int *length){

    unsigned int c = 0;       // Переменная для сокращения количества проверяемых елементов по краям матрицы
    float* arr = NULL;
    for(unsigned int i = 0; i<(int)ceil(rows/2.0);i++){
        for (unsigned int j = 0+c; j<cols-c ;j++){
            (*length)++;
            arr = realloc(arr,*length*sizeof(float));
            arr[*length-1] = matrix[i][j];
            
        }
        c++;
     }
    c--;
    for(unsigned int i = ((int)floor(rows/2.0)) ; i<rows ;i++){
        for (unsigned int j = 0+c; j<cols-c;j++){
            (*length)++;
            arr = realloc(arr,*length*sizeof(float));
            arr[*length-1] = matrix[i][j];
        }
        c--;
    }
    return arr;
}




//Поиск наибольшего числа в массиве
//arr - указатель на  массив; size - размер массива
//Возвращает максимальное float
float MaxFloat(float* arr,unsigned int size){ 
    float max = arr[0];
    for(unsigned int i = 0; i<size; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}




//списки
//Для 12_136d
//Для создания списка
//Возвращает структуру List
struct List* create_list(){
    struct List* list = malloc(sizeof(struct List));
    if (list==NULL){return NULL;}
    list->head=NULL;
    list->tail=NULL;
    list->size = 0;
    return list;
}



//для создания нового узла
//value - данные записываемые в узел
//Возвращает новый созданный узел
struct Node* new_node(float value){
    struct Node* node = malloc(sizeof(struct Node));
    if (node==NULL){return NULL;}

    node->value = value;
    node->next = NULL;
    return node;
}



//для добавления с конца
//List - структура хранящая данные о списке (голову, хвост, размер)
//List - указатель на список; value - данные передаваемые в новый узел;
void AddNodeBack(struct List* list, float value){ 
    struct Node* node = new_node(value);
    if (node == NULL){return;}

    if(list->head==NULL){
        list->head=node;
    }
    else{
        list->tail->next=node;              //Так более эффективно     
    }
    list->tail=node;
    list->size++;
}



//Освобождение списка
//List - указатель на список
void free_list(struct List* list){
    struct Node* current = list->head;
    while(current!=NULL){
        struct Node* temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}



//Для 12_533b

//Создания двусвязного списка
//Возвращает созданный двусвязный список
struct dList* create_dlist(){
    struct dList* list = malloc(sizeof(struct dList));
    if (list==NULL){return NULL;}
    list->head=NULL;
    list->tail=NULL;
    list->size = 0;
    return list;
}



//для создания нового узла
//Возвращает созданный двусвязный узел
struct dNode* new_dnode(float value){
    struct dNode* node = malloc(sizeof(struct dNode));
    if (node==NULL){return NULL;}

    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}



//для добавления узла с конца
//dList - структура хранящая данные о списке (голову, хвост, размер)
//dList - указатель на список; value - данные
void dAddNodeBack(struct dList* list, float value){
    struct dNode* node = new_dnode(value);
    if (node == NULL){return;}

    if(list->head==NULL){
        list->head=node;
    }
    else{
        list->tail->next=node;
        node->prev=list->tail;
        
    }
    list->tail=node;
    list->size++;
}




//для освобождения памяти
//dList - указатель на структуру dList
void free_dlist(struct dList* list){
    struct dNode* current = list->head;
    while(current!=NULL){
        struct dNode* temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}



//Переносить чётные числа из файла in в файл out
//in - ссылка на файл in; out - ссылка на файл out
void EvenNum(char in[200], char out[200]){
    FILE *filein = fopen(in,"r"); //изначальный файл
    FILE *fileout = fopen(out,"w");//конечный файл
    int num;
    int i = 0;

    while (fscanf(filein,"%d",&num)==1)  //читает числа и проверяет чётны ли они.  
    {                                    //scanf как и fscanf после выполнения возыращает количество получивших им переменных
        if (num %2 == 0){               
            fprintf(fileout,"%d  ",num);
            i++;
            if (i%10==0){
                fputs("\n",fileout);
            }
        } 
    }
    fclose(filein);
    fclose(fileout); //Для проверки соответствия данных в оперативной и постоянной памяти 
}






//Для файлов 10_507 номера
//Проверяет есть ли в в каком-нибудь классе однофамильци
//URL - ссылка на файл с данными учеников
void NamesakesInClass(char URL[200]){
    FILE *filestud = fopen(URL,"r");
    char name[30];     
    char surname[30];
    char addsurname[30];
    char add1surname[30];
    char class[4];
    char tname[30];    // | 
    char tsurname[30]; //  } для проверки фамилии и класса
    char tclass[4];    // |
    int check = 0;          //для проверки наличия однофамильца в классе
    int allcheck = 0;       //для проверки хотябы одного такого класса
    int len;                
    unsigned int pos=0;     //для cравнения женской версии фамилии с мужской


    while (fscanf(filestud,"%29s %29s %3s",&name,&surname,&class)==3)            //считывает Имя фамилию и класс
    {
        len = strlen(surname);                                                   //создаёт жескую и мужскую версию фамилии
        strcpy(addsurname,surname);
        strcpy(add1surname,surname);
        addsurname[len-1]='\0'; //Обрезает а в конце(мужская версия фамилии)
        add1surname[len]='а';    //Добавляет а в конце(женская версия фамилии)
        add1surname[len+1]='\0';


        FILE *temp = fopen(URL,"r");                                    //повторно открывает файл и сравнивает все фамилии и классы 
        for (unsigned int i = 0; i < pos; i++){                                  //до позиции текущей фамилии
            fscanf(temp,"%29s %29s %3s",&tname,&tsurname,&tclass);
            if ((strcmp(class,tclass)==0)&&((strcmp(surname,tsurname)==0)||(strcmp(addsurname,tsurname)==0)||(strcmp(add1surname,tsurname)==0))){
                check = 1;
                allcheck = 1;
            }
        }
        fclose(temp);
        if (check){
            printf("В классе %s есть однофамильцы\n", class);
        }
        check = 0;
        pos++;
    }

    if (!allcheck){
        printf("Ни в одном классе нет однофамильцев\n", class);
        }


    fclose(filestud);

}