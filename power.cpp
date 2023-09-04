long long power(long long x, long long y){
    long long res = 1;
    while(y > 0){
        if(y&1) res = (res*x)%mod;
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
}
