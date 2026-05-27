// 维护一个集合，初始时集合为空，支持如下几种操作：
// "I x"，插入一个数x；
// "PM"，输出当前集合中的最小值；
// "DM"，删除当前集合中的最小值（当最小值不唯一时，删除最早插入的最小值）；
// "D K"，删除第k个插入的数；
// "C k x"，修改第k个插入的数，将其变为x；
// 现在要进行N次操作，对于所有第2个操作，输出当前集合的最小值。
// 输入格式
// 第一行包含整数N。
// 接下来N行，每行包含一个操作指令，操作指令为"I x"、"PM"、"DM"、"D K"或"C k x"中的一种。
// 输出格式
// 对于每个输出指令"PM"，输出一个结果，表示当前集合中的最小值。
// 每个结果占一行。

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], sz;
// ph[j] = k, hp[k] = j;
// p->h: 下标映射到堆, h->p: 堆映射到下标

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t); // 递归可改循环
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n -- )
    {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            sz ++ ;
            m ++ ;
            ph[m] = sz, hp[sz] = m;
            h[sz] = x;
            up(sz);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, sz);
            sz -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, sz);
            sz -- ;
            down(k), up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}