#include<stdio.h>
#include<sys/time.h>

double gettimeofday_sec(){
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main() {
  double start, end;
  start = gettimeofday_sec();
  double i;
  for (i = 1; i <= 100; i++)
    printf("hello world.\n");
  end = gettimeofday_sec();
  printf("%10.20f\n", end - start);
  return 0;
}
