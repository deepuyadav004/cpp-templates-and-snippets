/*
________                               _____.___.           .___            
\______ \   ____   ____ ______  __ __  \__  |   |____     __| _/____ ___  __
 |    |  \_/ __ \_/ __ \\____ \|  |  \  /   |   \__  \   / __ |\__  \\  \/ /
 |    `   \  ___/\  ___/|  |_> >  |  /  \____   |/ __ \_/ /_/ | / __ \\   / 
/_______  /\___  >\___  >   __/|____/   / ______(____  /\____ |(____  /\_/  
        \/     \/     \/|__|            \/           \/      \/     \/      
*/


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// Macros definition
#define ll long long
#define lld long double
#define inf 1e18

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// x.find_by_order(1) -> return pointer to element present at index 1
// x.order_of_key(2) -> return index of element 2

// https://aryanc403.com/blog/y_combinator/
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


#ifndef ONLINE_JUDGE
#include "D:\coding\cpp files\customHeaderFiles\debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

//To make unordered_map unhackable 
// use it as unordered_map<int,int,custom_hash> mapp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


// clock
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Predefined values
const ll mod = 1e9+7;

void solve(){

}

int main(){

    auto begin = std::chrono::high_resolution_clock::now();
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //   freopen("Error.txt", "w", stderr);
    // #endif

    int testcase=1;
    cin>>testcase;
    while(testcase--){
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 

    return 0;
}
