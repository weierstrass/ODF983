#include <sys/types.h>
#include <sys/time.h>

double timing(){
  struct timeval  t;
  gettimeofday(&t, 0);
  return t.tv_sec + t.tv_usec * 1.0e-6;
}
