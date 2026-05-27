#include <iostream>
#include <algorithm>
using namespace std;

const int N= 1000010;
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i<= n; i ++)
    {
        if(!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}


// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e8 + 10;
// int primes[N], cnt;
// bool st[N];
// int n, q, k;

// // void get_prime(int n)
// // {
// //     for (int i = 2; i <= n; i++)
// //     {
// //         if (!st[i])
// //         {
// //             primes[cnt++] = i;
// //             for (int j = i + i; j <= n; j += i) st[j] = true;
// //         }
// //     }
// // }

// void get_prime(int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         if (!st[i]) primes[cnt++] = i;
//         for (int j = 0; primes[j] <= n / i; j++)
//         {
//             st[primes[j] * i] = true;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> q;
//     get_prime(n);
//     while (q--)
//     {
//         cin >> k;
//         cout << primes[k - 1] << endl;
//     }
//     return 0;
// }