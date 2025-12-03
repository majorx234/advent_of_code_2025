#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

typedef struct Range{
  int64_t start;
  int64_t end;
} Range;

Range *read_input() {
  Range *data = NULL;
  char c;
  size_t count = 0;
  char buffer_start[1024] = {0};
  char buffer_end[1024] = {0};
  char* buf = buffer_start;
  while ((c = getchar()) != EOF) {
    if (c == ',') {
      int64_t start = atoll(buffer_start);
      int64_t end = atoll(buffer_end);
      Range range = {
        .start = start,
        .end = end
        };
      arrput(data, range);
      memset(buffer_start, 0 , 1024*sizeof(char));
      memset(buffer_end, 0 , 1024*sizeof(char));
      count = 0;
      buf = buffer_start;
      continue;
    }
    if (c == '-') {
      buf = buffer_end;
      count = 0;
      continue;
    }
    buf[count] = c;
    count++;
  }
  // last one
  int64_t start = atoll(buffer_start);
  int64_t end = atoll(buffer_end);
  Range range = {.start = start, .end = end};
  arrput(data, range);
  return data;
}

int64_t nextid(int64_t start, int64_t end, int64_t idx) {
  int64_t digits = (int64_t)log10(start) + 1;
  int64_t dec_middle_divider = (int64_t)pow(10, (int64_t)(digits/2));
  int64_t start_pair_right = start / dec_middle_divider;
  if(digits % 2==1) {
    start_pair_right = dec_middle_divider;
  }
  int64_t start_pair_right_digits = ((int64_t)log10(start_pair_right + idx)) + 1;
  int64_t nextpair =
      (start_pair_right + idx) * (int64_t)pow(10, start_pair_right_digits) + (start_pair_right + idx);
  //printf("start: %d digits: %d dec_div: %d, start_pair_r: %d\n", start , digits, dec_middle_divider, start_pair_right);
  if(nextpair > end) return -1;
  return nextpair;
}

int main(int argc, char *argv[]) {
  Range* data = read_input();
  for (size_t i = 0;i < arrlen(data);i++) {
    printf("range %lld - %lld\n",data[i].start, data[i].end);
  }
  printf("search pairpairs\n");
  int64_t sum = 0;
  for(size_t j = 0;  j < arrlen(data); j++){
    for(size_t i = 0;  i < data[j].end - data[j].start; i++){
      int64_t next = nextid(data[j].start, data[j].end, i);
      if (next == -1) break;
      if (next < data[j].start) continue;
      sum += next;
      printf("data[%ld]: %ld-%ld next: %ld, sum: %lld\n", j, data[j].start, data[j].end, next, sum);
    }
  }
}
