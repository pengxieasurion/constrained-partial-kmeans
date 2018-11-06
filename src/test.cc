// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <random>         // std::thread

/// Test for cpkmeans

 
/// Random number with uniform distribution between 0 and 1
float random_float() {
  return (float) rand() / (float) RAND_MAX;
}

void foo() 
{
  // do stuff...
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0,1.0);

  for(int i=0; i<1e6; i++) {
    std::cout << "Generating random number" << std::endl;
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
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
