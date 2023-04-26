#include <stdio.h>
#include <stdlib.h>

const char* USAGE_ERROR = "Usage %s starting_number\n";
const char* OUT_OF_BOUNDS_ERRORS ="argument %lld must be > 0 and less than or equal to 2,147,483,647\n";
const char* STOP_TIME = "n = %lld has a stopping time of %d\n";

unsigned int
compute(unsigned long long num){
  if (num ==1){
        return 0;
  }
  else if (num % 2 == 0){
        return 1 + compute(num/2);
  }
  else{
        return 1 + compute(num*3+1);
  }
}

int
main(int argc, char **argv){
  if (argc !=2) {
        fprintf(stderr, USAGE_ERROR, argv[0]);
        return EXIT_FAILURE;
  }
  long long n = atoll( argv[1] );

  if (n <= 0 || n>2147483647){
        fprintf(stderr, OUT_OF_BOUNDS_ERRORS, n);
        return EXIT_FAILURE;
  }

  printf(STOP_TIME, n, compute(n));

  return EXIT_SUCCESS;
}
