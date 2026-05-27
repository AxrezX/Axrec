// 代码不完全正确

#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] = n;
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}

// #include <iostream>
// using namespace std;

// const int N = 1000010;

// int primes[N], cnt;
// bool st[N];

// void get_primes(int n) {
//     for (int i = 2; i <= n; i++) {
//         if (!st[i]) {
//             primes[cnt++] = i;        // 正确存储素数 i
//             // 只对素数 i 标记其倍数，从 i*i 开始
//             for (int j = i * i; j <= n; j += i) {
//                 st[j] = true;
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     get_primes(n);
//     cout << cnt << endl;   // 输出素数个数
//     return 0;
// }