#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MaxData 100

int Data[MaxData];
int i, N;

void PrepareRawData(int N);
void DispData(int N);
void swap(int a, int b);
void QuickSort(int f, int r);

int main() {
  printf("ASCENDING QUICK SORT\n");
  printf("==============================\n");  
  N = 12;
  PrepareRawData(N);
  printf("Raw Data...");
  DispData(N);
  printf("Processing Data...\n");
  printf(" F   R ");
  for(i = 1; i<= N; i++)
    printf(" (%2d)", i);
  printf("\n");
  QuickSort(1, N);
  printf("----------------------------------------------------------------\n");
  printf("Sorted Data : ");
  DispData(N);
  getch();
  return (0);
} // End Fn.

void PrepareRawData(int N) {
  int i;
  srand(time(NULL));
  for(i = 1; i <= N; i++)
    Data[i] = 10 + rand() % 89;
} // End Fn.

void DispData(int N) {
  int i;
  for(i = 1; i <= N; i++)
    printf(" %3d ", Data[i]);
  printf("\n");
} // End Fn.
 
void swap(int a, int b) {
  int temp;
  temp = Data[a];
  Data[a] = Data[b];
  Data[b] = temp;
} // End Fn.

void QuickSort(int f, int r) {
  int f1, r1;
  bool direction;
  f1 = f; r1 = r; 
  direction = true;
  while(f != r) {
    if(Data[f] > Data[r]) { // 72 > 36
      printf("%2d  %2d :", f, r);
      DispData(N);
      swap(f, r); 
      printf("%2d  %2d :", f, r);
      DispData(N);
      direction = !direction;
    } // End if
    if(direction)
      r--;
    else
      f++;
  } // End while
  printf("k1=[%2d]--------------------------------------------------------\n", Data[f]);
  // ด้านซ้าย
  if((f > f1) && (f - 1 != f1))
    QuickSort(f1, f - 1);
  // ข้อมูลด้านขวา
  if((r < r1) && (r +  1 != r1))
    QuickSort(r + 1, r1);
} // End Fn.


