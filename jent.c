#include <stdio.h>
#include <jitterentropy.h>

/*
int jent_entropy_init(void);

struct rand_data *jent_entropy_collector_alloc(unsigned int osr, unsigned int flags);
void jent_entropy_collector_free(struct rand_data *entropy_collector);

ssize_t jent_read_entropy(struct rand_data *entropy_collector, char *data, size_t len);
unsigned int jent_version(void);
*/

#define NBYTES 32

int main(int argc, char *argv[]) {
  unsigned int jv = 0;
  int jvh;
  void* mrd;
  int br;
  int i;
  char randbuf[NBYTES];

  jv = jent_version();
  /*
  printf("jv: %d\n", jv);
  */
  jvh = jent_entropy_init();
  /*
  if (jvh == 0) {
    printf("jent_entropy_init successful\n");
  } else {
    printf("jent_entropy_init failed\n");
  }
  */
  mrd = jent_entropy_collector_alloc(1, 0);
  /*
  if (mrd != NULL) {
    printf("jent_entropy_collector_alloc successful\n");
  } else {
    printf("jent_entropy_collector_alloc failed\n");
  }
  */
  br = jent_read_entropy(mrd, randbuf, sizeof(randbuf));

  for (i = 0; i < NBYTES; i++)
  {
    if (i > 0) printf(":");
    printf("%02x", randbuf[i]+128);
  }
  printf("\n");
}

