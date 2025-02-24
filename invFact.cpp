#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7; // Big modulus value
const int MAX = 1e6;     // Maximum value of n

vector<long long> factorial(MAX + 1); // To store factorials
vector<long long> invFactorial(MAX + 1); // To store inverse factorials

// Function to compute power under modulo MOD
long long power(long long x, long long y, long long mod) {
    long long result = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) // If y is odd
            result = (result * x) % mod;
        x = (x * x) % mod;
        y = y >> 1; // y = y / 2
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    // Fermat's Little Theorem for inverse factorials
    invFactorial[MAX] = power(factorial[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--) {
        invFactorial[i] = (invFactorial[i + 1] * (i + 1)) % MOD;
    }
}

// Function to compute nCr modulo MOD
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0; // Invalid case
    return (factorial[n] * invFactorial[r] % MOD * invFactorial[n - r] % MOD) % MOD;
}

int main() {
    precompute(); // Precompute factorials and inverse factorials

    int n, r;
    cout << "Enter values of n and r: ";
    cin >> n >> r;

    long long result = nCr(n, r);
    cout << "nCr modulo " << MOD << " = " << result << endl;

    return 0;
}
