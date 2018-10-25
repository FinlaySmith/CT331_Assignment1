#include <stdio.h>

int main(int arg, char* argc[]){
  printf("\n****************************************\n"); 
  printf("** CT311 Assignment1 - Question 1     **\n");
  printf("****************************************\n\n");

  int i = 10;
  int* i_ref = &i;
  
  double d = 2.0f;
  double* d_ref = &d;

  long int l = 4;
  
  char c = 'C';
  char* c_ref = &c;

  printf("  size of types:\n\n >> int     : %d bytes\n >> int*    : %d bytes\n >> long    : %d bytes\n >> double* : %d bytes\n >> char**  : %d bytes\n", 
          sizeof(i), sizeof(i_ref), sizeof(l), sizeof(d_ref), sizeof(c_ref) );

  return 0;
}
