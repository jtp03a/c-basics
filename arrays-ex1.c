// Find all the prime numbers from 3 - 100
// A number is considered prime if it is not evenly divisible by any other previous prime numbers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int primes[50] = {0};
  int primeIndex = 2;

  bool isPrime;

  // specify first 2 prime numbers
  primes[0] = 2;
  primes[1] = 3;

  // Loop to find the prime numbers
  for (int i = 5; i <= 100; i++) {
    if (i % 2 == 0) {
      continue;
    }
    isPrime = true;
    for (int j = 1; isPrime && i / primes[j] >= primes[j]; j++) {
      if (i % primes[j] == 0) {
        isPrime = false;
      }
    }
    if (isPrime == true) {
      primes[primeIndex] = i;
      primeIndex++;
    }
  }

  // Loop to print out the primes array
  for (int i = 0; i <= primeIndex -1; i++) {
    printf("%d\t", primes[i]);
  }

  return 0;
}