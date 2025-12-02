#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

typedef struct Range{
  int start;
  int end;
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
      int start = atoi(buffer_start);
      int end = atoi(buffer_end);
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
  int start = atoi(buffer_start);
  int end = atoi(buffer_end);
  Range range = {.start = start, .end = end};
  arrput(data, range);
  return data;
}

int main(int argc, char *argv[]) {
  Range* data = read_input();
  for (size_t i = 0;i < arrlen(data);i++) {
    printf("range %d - %d\n",data[i].start, data[i].end);
  }
}
