#pragma once

//Для 9_447
int isPerfNum(int num);
void VvodMasInt(const char *promt, int arr[], const char *name, unsigned int size);

// Для 9_692d
float** CreMatrFloat(int rows, int cols);
void VvodMatrFloat(const char *promt, float** arr, const char *name, unsigned int rows, unsigned int cols);
void freeMatrFloat(float** arr,unsigned int rows);
float* MassElemMatr(float** arr,unsigned int rows,unsigned int cols, unsigned int *length);
float MaxFloat(float* arr,unsigned int size);


//Списки для 12
struct Node //
{
    float value;
    struct Node * next;   
};

struct List {
    struct Node * head;
    struct Node * tail;
    int size;
};

struct List* create_list();
struct Node* new_node(float value);
void AddNodeBack(struct List* list, float value);
void free_list(struct List* list);

struct dNode
{
    float value;
    struct dNode * next;
    struct dNode * prev;   
};

struct dList {
    struct dNode * head;
    struct dNode * tail;
    int size;
};
struct dList* create_dlist();
struct dNode* new_dnode(float value);
void dAddNodeBack(struct dList* list, float value);
void free_dlist(struct dList* list);


void NamesakesInClass(char URL[200]);