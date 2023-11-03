// รับข้อมูลเลขฐานสิบ ASCII แปลงเป็นตัวอักษร 0-1, A-Z หรือ a-z (อ้างอิงเลขจากตาราง ASCII)

#include <stdio.h>

int main() {
  int decimal = 0;
  
  printf("Input decimal : ");
  scanf("%d", &decimal);
  printf("ASCII is %c", decimal);
  
  return 0;
}