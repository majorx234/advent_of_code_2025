#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

int *read_input() {
  size_t i = 0;
  int* data = NULL;
  do {
    char buf[1024] = {0};
    i = scanf("%s" , buf);
    if (i != EOF) {
      if (buf[0] == 'L') {
        buf[0] = '-';
        arrput(data, atoi(buf));
      } else if (buf[0] == 'R') {
        buf[0] = '+';
        arrput(data, atoi(&buf[1]));
      }
    }
    // Einfügen! abbruch wenn speicher voll
  } while (i != EOF);
  return data;
}

int main(int argc, char *argv[]) {
  int start_value = 50;
  int current_value = start_value;
  int count_zero = 0;
  int *data = read_input();
  for( size_t i = 0; i<arrlen(data); i++) {
    printf("%d\n", data[i]);
    current_value = (current_value + data[i]);
    if( current_value < 0) current_value = 100 + current_value;
    current_value %= 100;
    if( current_value == 0) count_zero++;
    printf("%d, zeros=%d\n", current_value, count_zero);
  }
}
