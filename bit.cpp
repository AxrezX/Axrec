// 每个数字的二进制表示1的个数

#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n = 10;
    unsigned int x = -n;
    for (int i = 31; i >= 0; i -- ) cout << (x >> i & 1);
    cout << endl;

    return 0;
}