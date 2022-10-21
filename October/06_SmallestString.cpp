class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // code here
        int n = S.size();
        if (n & (n - 1) || n == 1) {
            k *= 2;
        } else {
            k /= 2;
        }
        if (k > n) {
            return "-1";
        }
        stack<char> st;
        for(int i = 0; i < n; i++) {
            while (!st.empty() && S[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(S[i]);
        }
        while(!st.empty() && k) {
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};