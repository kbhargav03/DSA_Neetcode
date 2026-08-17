#include <iostream>
using namespace std;

class Solution {
    public:
        int climbStairs(int n){
            if(n <= 1) return 1;

            int prev2 = 1;
            int prev1 = 1;

            for(int i = 2; i <= n; i++){
                int current = prev1 + prev2;
                prev2 = prev1;
                prev1 = current;
            }
            return prev1;
        }
};

int main() {
    Solution s;

    cout << s.climbStairs(5) << endl; // Output: 8
    cout << s.climbStairs(3) << endl; // Output: 3
}