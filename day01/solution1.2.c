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

int mod(int a, int b){
  int c = a % b;
  return c >= 0 ? c : b + c;
}

int main(int argc, char *argv[]) {
  int start_value = 50;
  bool was_zero = false;
  int current_value = start_value;
  int count_zero = 0;
  int count_all_zeros = 0;
  int *data = read_input();
  for( size_t i = 0; i<arrlen(data); i++) {
    printf("%d\n", data[i]);
    current_value = (current_value + data[i]);
    int rounds = 0;
    if( current_value < 0) {
      if (!was_zero) {
        rounds++;
      }
      int absolut = abs(current_value);
      rounds += (int)absolut/100;
    } else if (current_value == 0 && data[i] < 0) {
      rounds++;
    } else {
      rounds += (int)current_value/100;
    }
    current_value = mod(current_value, 100);

    if( current_value == 0) {
      was_zero = true;
      count_zero++;
    } else {
      was_zero = false;
    }
    count_all_zeros += rounds;
    printf("%d, zeros=%d, all_zeros: %d\n", current_value, count_zero, count_all_zeros);
  }
}
