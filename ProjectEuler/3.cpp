/*
  Largest prime factor
  Problem 3
  The prime factors of 13195 are 5, 7, 13 and 29.

  What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>

using namespace std;

bool isPrime(long number) {
  for (long i = 1; i < number; i++) {
    if (number % i != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  long num = 600851475143;
  long max = 1;
  for (long i = 1; i < num; i++) {
    if (num % i == 0 && isPrime(i)) {
      max = i;
    }
  }
  cout << max << endl;
  return 0;
}
