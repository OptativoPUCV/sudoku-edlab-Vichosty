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
bool comp_linea_columna(int i,int j,Node*n){
    
  int k;
  int f=0;
  for(k=0;k<9;k++){

    if(n->sudo[i][j]==n->sudo[k][j]){
      f++;
    }

    if(n->sudo[i][j]==n->sudo[i][k]){
      f++;
    }
  }

  if(f<=2){
    return true;
  }
  else{
 
    return false;
  }
}

bool  comp_cuadrante(Node* n){
  int con;
  int k = 4;
  for(int o=0;o<9;o++){
    for(int p=0;p<9;p++){
      
      int i = 3*((k/3) + (p/3));
      int j = 3*((k%3) + (p%3));
      if(n->sudo[i][j]==o){
        con++;
      }
      if(con >1){
      return false;
      }

  
    }
  }  
  return true;
}


int is_valid(Node* n){
  int i;
  int j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){

      if(comp_linea_columna(i,j,n)){
        
        return 1;
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