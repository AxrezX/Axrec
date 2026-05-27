#include <iostream>
#include <vector>
#include <cmath>

/**
 * 使用埃拉托色尼筛法找出所有不超过 n 的素数。
 * @param n 上界（包含）
 * @return 存储素数的 vector
 */
std::vector<int> sieveOfEratosthenes(int n) {
    if (n < 2) return {}; // 没有小于2的素数

    // isPrime[i] 表示数字 i 是否为素数，初始时全部设为 true
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    int limit = static_cast<int>(std::sqrt(n));
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            // 从 i*i 开始标记，因为更小的倍数已经被之前的素数标记过了
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 收集所有素数
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    std::cout << "请输入上限 n: ";
    std::cin >> n;

    std::vector<int> primes = sieveOfEratosthenes(n);

    std::cout << "不超过 " << n << " 的素数有 " << primes.size() << " 个:\n";
    for (int p : primes) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}