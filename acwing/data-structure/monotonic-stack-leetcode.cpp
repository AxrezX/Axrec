// 返回 left，其中 left[i] 是 nums[i] 左侧最近的严格大于 nums[i] 的数的下标，若不存在则为 -1
// 时间复杂度 O(nums.size())
vector<int> left_greater(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n);
    stack<int> st;
    st.push(-1); // 哨兵
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.top()] <= x) { // 如果求严格小于，改成 >=
            st.pop();
        }
        left[i] = st.top();
        st.push(i);
    }
    return left;
}

// 返回 right，其中 right[i] 是 nums[i] 右侧最近的严格大于 nums[i] 的数的下标，若不存在则为 nums.size()
// 时间复杂度 O(nums.size())
vector<int> right_greater(vector<int>& nums) {
    int n = nums.size();
    vector<int> right(n);
    stack<int> st;
    st.push(n); // 哨兵
    for (int i = n - 1; i >= 0; i--) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.top()] <= x) { // 如果求严格小于，改成 >=
            st.pop();
        }
        right[i] = st.top();
        st.push(i);
    }
    return right;
}

作者：灵茶山艾府
链接：https://leetcode.cn/discuss/post/9oZFK9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。