// 定义 s 的真前缀为不等于 s 的前缀，s 的真后缀为不等于 s 的后缀。
// 定义 s 的 border 为既是 s 的真前缀又是 s 的真后缀的字符串。例如在 s=aabcaa 中，a 和 aa 都是 s 的 border。
// 对于模式串 p 的每个前缀 p[:i]，计算这个前缀的最长 border 长度，记在 π 数组中。
// 利用 π 数组，可以快速计算模式串 p 出现在文本串 t 的哪些位置上。
// 注：π 数组的定义参考《算法导论》，国内数据结构教材通常定义为 next 数组。以严蔚敏那本为例，二者的关系是 next[i+1]=π[i]+1，即 π 数组整体右移一位，元素值加一。

// 在文本串 text 中查找模式串 pattern，返回所有成功匹配的位置（pattern[0] 在 text 中的下标）
vector<int> kmp(const string& text, const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m);
    int cnt = 0;
    for (int i = 1; i < m; i++) {
        char b = pattern[i];
        while (cnt && pattern[cnt] != b) {
            cnt = pi[cnt - 1];
        }
        if (pattern[cnt] == b) {
            cnt++;
        }
        pi[i] = cnt;
    }

    vector<int> pos;
    cnt = 0;
    for (int i = 0; i < text.size(); i++) {
        char b = text[i];
        while (cnt && pattern[cnt] != b) {
            cnt = pi[cnt - 1];
        }
        if (pattern[cnt] == b) {
            cnt++;
        }
        if (cnt == m) {
            pos.push_back(i - m + 1);
            cnt = pi[cnt - 1];
        }
    }
    return pos;
}

作者：灵茶山艾府
链接：https://leetcode.cn/discuss/post/SJFwQI/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。