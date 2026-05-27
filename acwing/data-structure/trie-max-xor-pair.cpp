// 要解决“最大异或对”问题，我们需要找到数组中两个数的异或结果的最大值。异或运算的核心性质是：相同位为0，不同位为1。因此，我们希望高位尽可能多的为1。这里我们使用前缀树（Trie）来高效地解决这个问题。
#include <iostream>
#include <vector>
using namespace std;

const int MAX_BITS = 30; // 因为A_i < 2^31，所以最多30位（从30到0）
const int N = 100010;

int son[N * MAX_BITS][2]; // Trie树节点，每个节点有两个子节点（0和1）
int cnt[N * MAX_BITS];    // 记录每个节点的访问次数（可选，这里主要用于构建）
int idx;                  // 节点编号

// 将数字x插入到Trie树中，从最高位（30）到最低位（0）
void insert(int x) {
    int p = 0; // 从根节点开始
    for (int i = MAX_BITS; i >= 0; i--) {
        int bit = (x >> i) & 1; // 取出第i位（0或1）
        if (!son[p][bit]) {    // 如果该位对应的子节点不存在，创建新节点
            son[p][bit] = ++idx;
        }
        p = son[p][bit];       // 移动到子节点
    }
}

// 查询x与Trie树中已有数字的最大异或值
int query(int x) {
    int p = 0; // 从根节点开始
    int res = 0; // 存储最大异或结果
    for (int i = MAX_BITS; i >= 0; i--) {
        int bit = (x >> i) & 1; // 取出第i位
        int want = 1 - bit;     // 希望找到的位（与当前位不同，异或结果为1）
        if (son[p][want]) {     // 如果存在希望的位，走这条路
            res |= (1 << i);    // 该位异或结果为1，累加到结果
            p = son[p][want];
        } else {                // 不存在希望的位，只能走相同的位
            p = son[p][bit];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]); // 插入到Trie树
    }
    
    int max_xor = 0;
    for (int num : a) {
        int current = query(num); // 查询当前数的最大异或值
        if (current > max_xor) {
            max_xor = current;
        }
    }
    cout << max_xor << endl;
    return 0;
}