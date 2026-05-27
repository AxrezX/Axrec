
// int cnt = 0;
// for (int i = 1; i <= n; ++i)
// {
//     if (n % i == 0) cnt++; 
// }

// if (cnt > 2) cout <<  "不是质数" << endl;
// else cout <<  "是质数" << endl;
    




// bool isPrime_Naive(int n) {
//     if (n <= 1) return false;
//     for (int i = 2; i < n; ++i)
//         if (n % i == 0) return false;
//     return true;
// }





// bool isPrime_Sqrt(int n) {
//     if (n <= 1) return false;
//     if (n == 2) return true;
//     if (n % 2 == 0) return false;
//     for (int i = 3; i * i <= n; i += 2)
//         if (n % i == 0) return false;
//     return true;
// }






// bool isPrime_6k(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;

//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }

// i = 5          # i = 6*1 - 1 = 5
// while i * i <= n:
//     if n % i == 0 or n % (i + 2) == 0:   # 检查 i(=6k-1) 和 i+2(=6k+1)
//         return False
//     i += 6   # 跳到下一个 6k-1：5, 11, 17, 23...





// 埃拉托色尼筛法
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// vector<bool> sieve(int n) {
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= n; ++i) {
//         if (is_prime[i]) {
//             for (int j = i * i; j <= n; j += i)
//                 is_prime[j] = false;
//         }
//     }
//     return is_prime;
// }

// int main() {
//     int N = 1000000;   // 预处理上限
//     auto is_prime = sieve(N);

//     int n;
//     cout << "输入整数 (≤ " << N << "): ";
//     cin >> n;
//     if (n <= N)
//         cout << (is_prime[n] ? "是质数" : "不是质数") << endl;
//     else
//         cout << "超出预先生成范围，请用其他方法判断" << endl;
//     return 0;
// }





// 欧拉筛法
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> eulerSieve(int n) {
//     vector<bool> isPrime(n + 1, true);
//     vector<int> primes;
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i <= n; ++i) {
//         if (isPrime[i]) {
//             primes.push_back(i);
//         }
//         // 用当前已找到的质数去筛 i 的倍数
//         for (int p : primes) {
//             if (i * p > n) break;
//             isPrime[i * p] = false;
//             if (i % p == 0) break; // 核心：保证每个合数只被最小质因子筛一次
//         }
//     }
//     // 返回质数列表（如果需要）或者可以直接用 isPrime 数组查询
//     return primes; // 或者保留 isPrime 的引用
// }

// int main() {
//     const int MAXN = 1000000;
//     vector<bool> isPrime(MAXN + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     vector<int> primes;

//     // 欧拉筛
//     for (int i = 2; i <= MAXN; ++i) {
//         if (isPrime[i]) primes.push_back(i);
//         for (int p : primes) {
//             if (i * p > MAXN) break;
//             isPrime[i * p] = false;
//             if (i % p == 0) break;
//         }
//     }

//     // 查询示例
//     int n;
//     cout << "输入一个整数 (≤ " << MAXN << "): ";
//     cin >> n;
//     if (n <= MAXN)
//         cout << (isPrime[n] ? "是质数" : "不是质数") << endl;
//     else
//         cout << "超出预处理范围，请使用其他方法" << endl;

//     return 0;
// }





// 朴素试除
// sqrt 优化
// 6k±1 优化
// Miller-Rabin 素性测试
// 埃氏筛预处理表
// 欧拉筛预处理