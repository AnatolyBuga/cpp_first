
// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
#include <getopt.h>
using namespace std;
#include <stdio.h>
#include <string.h>
  
std::vector<int> SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    std::vector<int> res;
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]) {res.push_back(p);}
    return res;
}
  
// Driver Code
int main(int argc, char *argv[])
{
    // static struct option long_options[] = {{"number", 1, 0, 'n'},
    //                                         {"help", 0, 0, '?'},
    //                                      {0, 0, 0, 0}};
    // int opt;
    // while ((opt = getopt_long(argc, argv, "n:?", long_options, NULL)) !=
    //      EOF) { 
    //         switch(opt)
    //         break;};

    
    uint32_t n = atoi(argv[1]);
    cout    << "n: " << n << endl;
    // uint32_t n = * (int*) argv;
    // cout << "Following are the prime numbers smaller "
    //      << " than or equal to " << n << endl;
    std::vector<int> a;
    a = SieveOfEratosthenes(n);
    for (auto i: a)
        std::cout << i << ' ';
    return 0;
}