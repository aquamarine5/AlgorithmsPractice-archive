/*
 * @Author: aquamarine5 && aquamarine5_@outlook.com
 * Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
 * lovely lonely, but be a quokka.
 */
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
const ll mod = 100000009;
ll factorial(ll n)
{
    ll result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= (i % mod);
    }
    return result;
}
ll factorial2(ll last, ll count)
{
    ll result = last;
    // 3!=6
    // factorial(3!,3)
    // result=6
    for (ll i = count + 1; i <= last; ++i)
    {
        result *= (i % mod);
    }
    return result;
}
// 7!!=7!/(6!/5!!)=7!*5!!/6!
ll doubleFactorial(ll n)
{
    ll result = n % 2 == 0 ? 2 : 1;
    for (ll i = result; i <= n; i += 2)
    {
        result *= (i % mod);
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    ll sr = (factorial2(factorial(n) % mod, n)) % mod;
    ll dr = doubleFactorial(n) % mod;
    cout << (sr + dr) % mod;
}