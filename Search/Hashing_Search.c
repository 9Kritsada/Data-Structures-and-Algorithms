// Hashing Search(Dynamic Chaining method)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#define MaxData 100
#define Lo 1

int Data[MaxData];
int N, M, key, Addr, Times;
bool result;

typedef struct Node {
  int info;
  struct Node *link;
} Node;

struct Node *Start[MaxData], *H1, *p;

Node *Allocate() {
  struct Node *temp;
  temp = (Node*)malloc(sizeof(Node));
  return temp;
}

bool Duplicate(int i, int Data1);
void PrepareRawKey(int N);
void DispKey(int N);
void CreateHead(int Head);
void CreateHashTable(int N);
void DispHashTable();
bool SearchHash(int key);

int main() {
  printf("HASHING SEARCH(DYNAMIC CHAINING)\n");
  printf("================================================================\n");
  N = 32;
  M = N * 0.5; // Let M = 50% of N
  PrepareRawKey(N);
  printf("Raw Key:\n");
  DispKey(N);
  printf("----------------------------------------------------------------\n");
  CreateHead(M);
  CreateHashTable(N);
  while(key != -999) {
    DispHashTable();
    printf("----------------------------------------------------------------\n");
    printf("\nEnter Key for Search(-999 for EXIT) = ");
    scanf("%d", &key);
    if(key != -999) {
      result = SearchHash(key);
      printf("Key Address : %d\n", Addr);
      printf("Searching time : %d\n", Addr);
      printf("Result...");
      if(result)
        printf("FOUND\n");
      else {
        Beep(600, 600);
        printf("NOT FOUND!!!\n");
      } 
      printf("-----------------------------------------------Search Finished\n");
    } // end if
  } // end while
  return 0;
}

bool Duplicate(int i, int Data1) {
  int j;
  for(j = 1; j <= i; j++) {
    if(Data1 == Data[j])
      return(true);
  }
  return(false);
}

void PrepareRawKey(int N) {
  int i, j, temp;
  srand(time(NULL));
  for(i = 1; i <= N; i++) {
    temp = (rand() % 89) + 10;
    while(Duplicate(i - 1, temp))
      temp = (rand() % 89) + 10;
    Data[i] = temp;
  }
}

void DispKey(int N) {
  int i;
  for(i = 1; i <= N; i++)
    printf("(%2d)", i);
  printf("\n");
  for(i = 1; i <= N; i++)
    printf(" %2d ", Data[i]);
  printf("\n");
}

void CreateHead(int Head) {
  int i;
  struct Node *p;
  for(i = 1; i <= Head; i++) {
    p = Allocate();
    p->info = '\0';
    p-> link = NULL;
    Start[i] = p;
  }
}

void CreateHashTable(int N) {
  int i;  
  struct Node *H1, *p;
  for(i = 0; i < N; i++) {
    Addr = Data[i] % M + Lo;
    H1 = Start[Addr];
    if(H1->info == '\0')
      H1->info = Data[i];
    else {
      while(H1->link != NULL)
        H1 = H1->link;
      p = Allocate();
      p->info = Data[i];
      p->link = NULL;
      H1->link = p;
    }
  } // end for
}

void DispHashTable() {
  int i;
  struct Node *H1;
  for(i = 1; i <= M; i++) {
    H1 = Start[i];
    printf("\nAddress %2d : ", i);
    while(H1 != NULL) {
      printf("%3d ", H1->info);
      H1 = H1->link; // Skip next Node
    } // end while
  } // end for
  printf("\n");
}

bool SearchHash(int key) {
  struct Node *H1;
  Addr = key % M + Lo;
  H1 = Start[Addr];
  Times = 0;
  while(H1 != NULL) {
    Times++;
    if(H1->info == key)
      return (true);
    else
      H1 = H1->link;
  }
  return (false);
}
