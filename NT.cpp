// Dealing with negative m
inline long long modulo(long long a, long long m){
    if (m < 0) m = -m;
    return (a % m + m) % m;
}

// Modular Exponentiation
inline long long mod_exponent(long long n, long long power){
    long long result = 1;
    n %= m;
    while (power){
        if (power & 1) result = result * n % m;
        n = n * n % m;
        power >>= 1;
    }
    return result;
}

// Modular Inverse
long long mod_inverse(long long a){return mod_exponent(a, m - 2);}

// Integer Square Root
inline long long square_root(long long n){
    if (n <= 1) return n;

    long long result = 0;
    long long bit = 1LL << 62;

    while (bit > n) bit >>= 2;
    while (bit != 0){
        if (n >= result + bit){
            n -= result + bit;
            result = (result >> 1) + bit;
        } else {
            result >>= 1;
        }
        bit >>= 2;
    }
    return result;
}

// Exponential Function
inline long long exponent(long long n, long long power, long long m){
    if (power == 0) return 1;
    if (n == 0) return 0;
    long long result = 1;
    while (power > 0){
        if (power & 1) result = result * n % m;
        power >>= 1;
        n = n * n % m;
    }
    return result;
}

// Factorial and Choose Function
vector<long long> fact(1, 1);

inline long long factorial(int n){
    while ((int)fact.size() <= n) fact.push_back(fact.back() * fact.size() % m);
    return fact[n];
}

inline long long nCr(int n, int r){
    if (r < 0 || r > n) return 0;
    long long numerator = factorial(n);
    long long denominator = factorial(r) * factorial(n - r) % m;
    return numerator * mod_exponent(denominator, m - 2) % m; // Fermat's Little Theorem
}

// Binary Operations
string dec_to_bin(int n){
    if (n == 0) return "0";
    string result = "";
    while (n > 0){
        result += (n % 2 ? "1" : "0");
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

cout << __builtin_popcount(n) << "\n"; // Outputs the number of "1"s
cout << __builtin_clz(n) << "\n"; // Outputs the number of leading zeros
cout << __builtin_ctz(n) << "\n"; // Outputs the number of trailing zeros
