#include <stdio.h>
#include <math.h>

void decimalToBinary(int decimal) {
  int binary[32];
  int index = 0;

  while(decimal > 0) {
    binary[index] = decimal % 2;
    decimal /= 2;
    index++;      
  }

  printf("Binary is : ");
  for(int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }
}

int main() {
  int decimal;

  printf("Input decimal : ");
  scanf("%d", &decimal);
  decimalToBinary(decimal);

  return 0;
}