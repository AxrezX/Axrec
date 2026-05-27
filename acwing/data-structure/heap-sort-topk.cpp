// 插入一个数：heap[ ++ sz] = x; up(sz);
// 求集合当中的最小值：heap[1];
// 删除最小值：heap[1] = heap[sz]; sz -- ; down(1);
// 删除任意一个元素：heap[k] = heap[sz]; sz -- ; down(k); up(k);
// 修改任意一个元素：heap[k] = x; down(k); up(k);

// n个数求前m个最小

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], sz;

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t); // 递归可改循环
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap(h[u], h[u / 2]);
        u /= 2;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    sz = n;
    for (int i = n / 2; i; i -- ) down(i);
    while (m -- )
    {
        printf("%d ", h[1]);
        h[1] = h[sz];
        sz -- ;
        down(1);
    }
    return 0;
}
