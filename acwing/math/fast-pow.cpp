#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b, p;

ll fastPow(int a, int b, int p)
{
    ll ans = 1, base = a;
    while (b > 0)
    {
        if (b & 1) ans = ans * base % p;
        base = base * base % p;
        b >>= 1;
    }
    return ans;
}


// for (; n; n / 2)
// {
//     if (n % 2) res = res * x % MOD;
//     x = x * x % MOD;
// }

//计算x^y的值
// long long quickMul(long long x, long long y, long long m) {
//     long long res = 1;
//     while (y) {
//         if (y & 1)
//         {
//             res = (res * x) % m;
//         }
//         y >>= 1;
//         x = (x * x) % m;
//     }
//     return res;
// }

int main()
{
    cin >> a >> b >> p;
    cout << a << '^' << b << " " << "mod" << " " << p << '=' << fastPow(a, b, p) << endl;
    return 0;
}