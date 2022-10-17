class Solution {
public:
    int findMinChar(string &str) {
        vector<int> lps(str.size());
        int i = 1, len = 0;
        int M = str.size();
        lps[0] = 0;
        while(i < M) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return ((M / 2) - lps[M - 1]);
    }
    int minChar(string str){
        //Write your code here
        string rev = str;
        reverse(rev.begin(), rev.end());
        string concat = str + "$" + rev;
        return findMinChar(concat);
    }
};