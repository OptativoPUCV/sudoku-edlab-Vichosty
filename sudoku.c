#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

bool  comp_cuadrante(Node* n){
  int z[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(int k=0;k<9;k++){
    for(int p=0;p<9;p++){
      
      int i = 3*((k/3) + (p/3));
      int j = 3*((k%3) + (p%3));
      if ((z[n->sudo[i][j]]-1 != 0)) {
        return false;
      }else{
        z[n->sudo[i][j] - 1] = 1;
      }
    }
  }  
  return true;
}


int is_valid(Node* n){
  int i;
  int j;
  int x[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int y[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if ((x[n->sudo[i][j]]-1 != 0)) {
        return 0;
      }else{
        x[n->sudo[i][j] - 1] = 1;
      }
      
    }  
  }
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        if ((y[n->sudo[j][i]]-1 != 0)) {
          return 0;
        }else{
        y[n->sudo[i][j] - 1] = 1;
      }
    }
  }    
  if(comp_cuadrante(n)==false){
    return 0;
  }
  
return 1;
}



List* get_adj_nodes(Node* n){
  List* lista=createList();
  int i,j;
  int num;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){

      if(n->sudo[i][j]==0){
        for(num=1; num <=9; num++){
          n->sudo[i][j]=num;
          if(is_valid(n)){
            Node* aux = copy(n);
            pushBack(lista, aux);
          }
        }
        n->sudo[i][j] = 0;
        return lista;
        }
      }
    }
  return lista;
}


int is_final(Node* n){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        return 0;
        }
      }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
/*
  Stack* S = createStack();
  push(S,initial);
  if(S == NULL){
    return NULL;
  }else{
    while(get_size(S)!= 0){
      if(is_final(initial)){
        return initial;
      }
      pop(S);
    
      List* adj = get_adj_nodes(initial);
      Node* aux = first(adj);
      while(aux){
        printf("a");
        push(S,aux);
        aux=next(adj);
      }
    
      free(initial);
    } 
  }
 */

  return NULL;

}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/