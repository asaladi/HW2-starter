#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256 // maximum length of a single word

int main(int argc, char* argv[]) {

  if (argc !=3) {
          fprintf(stderr, "Error, expected two arguments\n");
          return EXIT_FAILURE;
  }

  // char word[MAX_LEN];

  FILE* fin = fopen(argv[1], "r");

  if(fin == NULL) {
    perror("Could not open input file.");
    return 1;
  }

  // TODO: Write your code here to implement the encryption.

  int num = atoi(argv[2]);

  int cin;
  int cout;
  while ((cin = fgetc(fin)) != EOF){
        if ( toupper(cin) >=65 && toupper(cin) <=90){

                int extra;
                if ( cin <= 90) {
                        extra = 65;
                }
                else{
                        extra = 97;
                }

                cout = ((cin-extra+num)%26)+extra;

        }
        else{
                cout = cin;
        }
        fputc(cout, stdout);
  }


  // clean up gracefully
  fclose(fin);

  return 0;
}
