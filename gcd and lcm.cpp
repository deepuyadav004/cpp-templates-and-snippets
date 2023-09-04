// for gcd
long long gcd(long long a, long long b) {
    return b ? gcd (b, a % b) : a;
}

// for lcm
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
