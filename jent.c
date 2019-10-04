#include <stdio.h>
#include <jitterentropy.h>

#define NBYTES 1000
#define NTIMES 1000*8

void advance_cursor() {
  static int pos=0;
  char cursor[4]={'/','-','\\','|'};
  printf("%c\b", cursor[pos]);
  fflush(stdout);
  pos = (pos+1) % 4;
}

int main(int argc, char *argv[]) {
  unsigned int jv = 0;
  int jvh;
  void* mrd;
  int br;
  int i;
  char randbuf[NBYTES];

  jv = jent_version();
  jvh = jent_entropy_init();
  mrd = jent_entropy_collector_alloc(1, 0);

  FILE *file = fopen("jent_out", "w");
  for (i=0; i < NTIMES ; i++) {
    br = jent_read_entropy(mrd, randbuf, sizeof(randbuf));
    fwrite(randbuf, sizeof(randbuf), 1, file);
    advance_cursor();
  }
  fclose(file);
  printf("\n");
}

