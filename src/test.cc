// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <random>         // std::thread
#include "cpkmeans.hh"

/// Test for cpkmeans

 
/// Random number with uniform distribution between 0 and 1
float random_float() {
  return (float) rand() / (float) RAND_MAX;
}

void foo(float *x, unsigned long obs, unsigned long col, unsigned long start, unsigned long stop) 
{
  // do stuff...
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0,1.0);

  std::cout << start << std::endl;

  for(unsigned long i=start; i<stop; i++) {
    float *y = x + i * col;
    for (unsigned long j=0; j<col; j++) {
      y[j] = 3.5 * j;
    }
    random_float();
  }
}


void bar(int x)
{
  // do stuff...
}

int main() 
{
  srand(20181101);

  float *x;
  unsigned long N = 1024L * 1024 * 4;
  unsigned long C = 512L;
  unsigned long bytes = N * C * sizeof(float);
  x = (float*) malloc(bytes);

  std::cout << "N=" << N << std::endl;

  int t;
  std::cin >> t;

  for(unsigned long i=0; i<(C*N); i++) {
    x[i] = 3.5;
  }

  std::thread threads[t];

  for (int i=0; i<t; i++) {
    threads[i] = std::thread(foo, x, N, C, i*N/t, (i+1)*N/t);     // spawn new thread that calls foo()
  }

  std::cout << "main, foo and bar now execute concurrently...\n";

  for (int i=0; i<t; i++) {
    threads[i].join();
  }

  // synchronize threads:

  std::cout << "foo and bar completed.\n";
  std::cin >> t;

  return 0;
}
