#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MaxData 100

int Data1[MaxData], Data2[MaxData];
int N;

void PrepareRawData(int N);
void DispData(int Data[], int out);
void swap(int a, int b);
int Maximum(int a, int b);
void AdjustTree(int LastNode);
void CreateHeapTree();

int main() {
  printf("ASCENDING HEAP SORT\n");
  printf("--------------------------------------------------------------\n");
  N = 12;
  PrepareRawData(N);
  printf("Raw Data : ");
  DispData(Data1, N + 1);
  printf("---------------------------------------------Raw Data Finisged\n");
  printf("Create Heap Tree...\n");
  CreateHeapTree();
  printf("Sorted Data is : ");
  DispData(Data2, 1);
  printf("----------------------------Sort Finished \n");
  getch();
  return (0);
}

void PrepareRawData(int N) {
  int i;
  srand(time(NULL));
  for(i = 1; i <= N; i++)
    Data1[i] = (rand() % 89) + 10;
}

void DispData(int Data[], int out) {
  int i;
  for(i = 1; i <= N; i++) {
    if(i < out)
      printf(" %3d  ", Data[i]);
    else  
      printf("[%2d]  ", Data[i]);
  } // End for
  printf("\n");
}

void swap(int a, int b) {
  int temp;
  temp = Data2[a];
  Data2[a] = Data2[b];
  Data2[b] = temp;
}

int Maximum(int a, int b)  {
  if(a > b)
    return (a);
  else
    return (b);
}

void AdjustTree(int LastNode) { 
  int i, Max, lson, rson, son;
  bool result;
  i = 1;
  result = false;
  while(!result) {
    lson = (2 * i ); // Calculate Lson
    rson = (2 * i + 1); // Calulate Rson 
    son = 0; // Set Default Son
    if(lson == LastNode) {
      son = 1;
      if(Data2[i] < Data2[lson]) {
        swap(i, lson);
        DispData(Data2, LastNode + 1);
      }
      result = true; // Finish AdjustTree
    } // End if
    if(rson <= LastNode) { 
      son = 2;
      Max = Maximum(Data2[lson], Data2[rson]); 
      if(Data2[i] < Max) { 
        if(Max == Data2[lson]) { 
          swap(i, lson); 
          DispData(Data2, LastNode + 1);
          if(rson == LastNode) 
            result = true;
          else
            i = lson;
        } else {
          swap(i, rson); 
          DispData(Data2, LastNode + 1);
          if(rson == LastNode) 
            result = true;
          else
            i = rson; 
        } // End if else
      } // End if
      else
        result = true;
    } // End if
    if(son == 0)
      result = true;
  } // End while
  printf("---------------------------------Adjust Tree Finished at N=%d \n", LastNode);
}


void CreateHeapTree() {
  int i, j, k, father;
  bool result;
  //Craete Heap Tree
  Data2[1] = Data1[1];
  DispData(Data2, N + 1);
  for(i = 2; i <= N; i++) { 
    Data2[i] = Data1[i];
    DispData(Data2, N + 1);
    result = true;
    j = i; 
    while(result) { 
      father = j / 2; 
      if((Data2[j] > Data2[father]) && (j > 1)) { 
        swap(j, father); 
        DispData(Data2, N + 1);
        j = father; 
        result = true;
      } else 
        result = false;
    } // End while
  } // End for
  printf("-----------------------------------Create Heap Tree Finished \n");
  for(k = 1; k <= N; k++)
    printf(" (%d)  ", k);
  printf("\n");
  for(i = N; i > 1; i--) {
    swap(1, i); 
    DispData(Data2, i);
    AdjustTree(i - 1);
  } // End for
} // End Fn.