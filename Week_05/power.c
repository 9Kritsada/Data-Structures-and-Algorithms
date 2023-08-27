#include <stdio.h>
#include <conio.h>
  
double power( double m, int n ) {
  double x, y;
  if( n > 0 ) {
    x = n - 1;
    printf("%.0lf^%d = %.0lf * %.0lf^%.0lf\n", m, n, m, m, x); 
    y = power( m, x );
    printf("%.0lf^%d = %.0lf * %.0lf = %.0lf\n", m, n, m, y, (m * y)); 
    return (m * y);
  }
  else if( n < 0 ) {
    x = n + 1;
    printf("%.0lf^%d = (1/%.0lf) * %.0lf^%.lf\n", m, n, m, m, x); 
    y = power( m, x );
    printf("%.0lf^%d = (1/%.0lf) * %lf = %lf\n", m, n, m, y, (( 1 / m ) * y)); 
    return (( 1 / m ) * y);
  }
  else {
    printf("...............Roll Back Point\n");
    return 1; 
  }
}

int main() {
  int M, N;
  int status = 1;
  printf("POWER ( M^N ) PROGRAM\n");
  printf("=============================\n");
  while (status != 2) {
    printf("['1'=Start : '2'=Exit] : "); 
    scanf("%d", &status);                
    if(status != 2) {
      // Input
      printf("Enter Number M : ");
      scanf("%d", &M);
      printf("Enter Number N : ");
      scanf("%d", &N);
      // Display
      double ans = power(M, N);
      printf("\nAnswer M^N = %lf\n", ans);
      printf("----------------Finished\n");
      getch();
    }
  }
  return 0;
}