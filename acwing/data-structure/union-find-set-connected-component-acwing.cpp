// 给定一个包含 n个点（编号为 1~n）的无向图，初始时图中没有边。
// 现在要进行 m个操作，操作共有三种：
// C a b：在点 a和点 b之间连一条边，a和 b可能相等；
// Q1 a b：询问点 a和点 b是否在同一个连通块中，a和 b可能相等；
// Q2 a：询问点 a所在连通块中点的数量；
// 输入格式：
// 第一行输入整数 n和 m。
// 接下来 m行，每行包含一个操作指令，指令为 C a b、Q1 a b或 Q2 a中的一种。
// 输出格式：
// 对于每个询问指令 Q1 a b，如果 a和 b在同一个连通块中，则输出 Yes，否则输出 No。
// 对于每个询问指令 Q2 a，输出一个整数表示点 a所在连通块中点的数量。
// 每个结果占一行。

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int p[N], sz[N];

int find (int x) //返回x的祖宗节点+路径压缩
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        sz[i] = 1;
    }
    while (m -- )
    {
        char op[5];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            sz[find(a)] += sz[find(b)];
            p[find(b)] = find(a);
        }
        else if (op[0] == 'I')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", sz[find(a)]);
        }
    }
    return 0;
}