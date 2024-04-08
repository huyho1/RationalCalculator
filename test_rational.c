#include "rational.h"

int main(int argc, char *argv[]) {
    int num1, denom1, num2, denom2; //initialize numerators/denominators/operations
    char op[3];

    if (argc < 3) { //makes sure there's at least 2 files
        printf("Error");
        return 1;
    }

    FILE *outputFile = fopen(argv[argc-1], "w");

    for (int i = 1; i < argc-1; i++) {
    FILE *inputFile = fopen(argv[i], "r");

        while (read_rational(inputFile, &num1, &denom1, &num2, &denom2, op) > 0) {
            Rational rational1 = create_rational(num1, denom1);
            Rational rational2 = create_rational(num2, denom2);
            Rational result; //operations answer

            print(outputFile, &rational1);       
            fprintf(outputFile, " %s ", op); 
            print(outputFile, &rational2);       
            fprintf(outputFile, "\t: ");  

            if (strcmp(op, "+") == 0) { //addition
                result = add(&rational1, &rational2);
                print(outputFile, &result);
            } 
            else if (strcmp(op, "-") == 0) { //subtraction
                result = subtract(&rational1, &rational2);
                print(outputFile, &result);
            } 
            else if (strcmp(op, "*") == 0) { //multiplication
                result = multiply(&rational1, &rational2);
                print(outputFile, &result);
            } 
            else if (strcmp(op, "/") == 0) { //division
                result = divide(&rational1, &rational2);
                print(outputFile, &result);
            }
            else if (strcmp(op, "==") == 0) { //equality
                if (equal(&rational1, &rational2)) {
                    fprintf(outputFile, "true");      
                } 
                else fprintf(outputFile, "false");    
            }
            else if (strcmp(op, "!=") == 0) { //not equal
                if (!(equal(&rational1, &rational2))) {
                    fprintf(outputFile, "true");
                } 
                else fprintf(outputFile, "false");    
            }
            else if (strcmp(op, ">=") == 0) { //greater than or equal to
                if (compare(&rational1, &rational2) > -1) {
                    fprintf(outputFile, "true");      
                } 
                else fprintf(outputFile, "false");    
            }
            else if (strcmp(op, "<=") == 0) {  //less than or equal to
                if (compare(&rational1, &rational2) < 1) {
                    fprintf(outputFile, "true");     
                } 
                else fprintf(outputFile, "false");   
            }
            else if (strcmp(op, ">") == 0) { //greater than
                if (compare(&rational1, &rational2) == 1) {
                    fprintf(outputFile, "true");      
                } 
                else fprintf(outputFile, "false");     
            }
            else if (strcmp(op, "<") == 0) { //less than
                if (compare(&rational1, &rational2) == -1) {
                    fprintf(outputFile, "true");     
                } 
                else fprintf(outputFile, "false");    
            }
            fprintf(outputFile, "\n");
        }
    }
    return 0;
}

int read_rational(FILE * f1, int * n1, int * d1, int * n2, int * d2, char op[]) {
  char line[100];
  char * s = fgets(line, 99, f1);
  if (s == NULL) {
    return 0;
  } else {
    // 1. rational1 op rational2
    if (sscanf(line, "%d/%d %s %d/%d", n1, d1, op, n2, d2) == 5) {
      return 5;
    }
    // 2. num1 op rational2
    else if (sscanf(line, "%d %s %d/%d", n1, op, n2, d2) == 4) {
      *d1 = 1;
      return 4;
    }
    // 3. rational1 op num2
    else if (sscanf(line, "%d/%d %s %d", n1, d1, op, n2) == 4) {
      *d2 = 1;
      return 4;
    }
    // 4. num1 op num2
    else if (sscanf(line, "%d %s %d", n1, op, n2) == 3) {
      *d1 = 1;
      *d2 = 1;
      return 3;
    }
    // 5. Error!
    else {
      return -1;
    }
  }
}