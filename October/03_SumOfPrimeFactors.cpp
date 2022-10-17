class Solution {
  public:
    int sumOfAll(int l, int r){
        // code here
        int res = 0;
        for(int i = l; i <= r; i++) {
            int n = i;
            if (n % 2 == 0) {
                res += 2;
                while(n % 2 == 0) {
                    n /= 2;
                }
            }
            for(int j = 3; j <= sqrt(n); j += 2) {
                if (n % j == 0) {
                    res += j;
                    while(n % j == 0) {
                        n /= j;
                    }
                }
            }
            if (n > 2) {
                res += n;
            }
        }
        return res;
    }
};