#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"

const char* alphabet[3] = {
    " _     _  _     _  _  _  _  _ ",
    "| |  | _| _||_||_ |_   ||_||_|",
    "|_|  ||_  _|  | _||_|  ||_| _|"
};

/**
 * Display the given string in ASCII LCD format
*/
void displayLcd(char *s) {
  // Display the lines one by one
  for (int line = 0; line < 3; line++) {
    for (int c = 0; c < strlen(s); c++) {
      for (int col = 0; col < 3; col++) {
        // substract 48 to convert ASCII to numerical
        printf("%c", (char) alphabet[line][(s[c] - 48) * 3 + col]);
      }
    }
    printf("\n");
  }
}

/**
 * Display program usage
*/
void showUsage(char *name) {
  printf("Usage: %s [integer]\n", name);
}

/**
 * Check user arguments and call displayLcd with first argument
*/
int main(int argc, char **argv) {
  // Verify argument count
  if (argc != 2) {
    showUsage(argv[0]);
    return EXIT_FAILURE;
  }

  // Verify that first argument is a number
  for (int i = 0; i < strlen(argv[1]); i++) {
    if (!isdigit(argv[1][i])) {
      showUsage(argv[0]);
      return EXIT_FAILURE;
    }
  }

  displayLcd(argv[1]);
  return EXIT_SUCCESS;
}