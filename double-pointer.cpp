// 最长连续不重复子序列：给定一长度为 n的整数序列，请找出最长的不包含重复数字的连续子序列，输出它的长度

#include <iostream>
using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[a[i]] ++ ;
        while (s[a[i]] > 1)
        {
            s[a[j]] -- ;
            j ++ ;
        }
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}