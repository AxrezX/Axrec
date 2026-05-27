// 836.合并集合
// 题目提交记录■讨论题解
// 一共有n个数，编号是1~n，最开始每个数各自在一个集合中。
// 现在要进行m个操作，操作共有两种：
// 1."M a b”，将编号为a和b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
// 2."Q a b”，询问编号为a和b的两个数是否在同一个集合中；
// 输入格式
// 第一行输入整数n和m。
// 接下来m行，每行包含一个操作指令，指令为"M a b"或"Q a b"中的一种。
// 输出格式
// 对于每个询问指令"Q a b”，都要输出一个结果，如果a和b在同一集合内，则输出"Yes"，否则输出"No"。
// 每个结果占一行

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find (int x) //返回x的祖宗节点+路径压缩
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}