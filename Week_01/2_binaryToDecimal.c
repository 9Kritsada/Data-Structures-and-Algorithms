// รับข้อมูลเลขฐานสอง แปลงข้อมูลเป็นเลขฐานสิบ
#include <stdio.h>

void binaryToDecimal(long long binary) {
  int decimal = 0;
  int base = 1;
    
  while (binary > 0) {
    int digit = binary % 10;
    decimal += digit * base;
    base *= 2;
    binary /= 10;
  }

  printf("Decimal is : %lld", decimal);
}

int main() {
  long long binary;

  printf("Input binary : ");
  scanf("%lld", &binary);
  binaryToDecimal(binary);

  return 0;
}