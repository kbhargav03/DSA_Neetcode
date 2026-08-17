#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {

            int n = cost.size();

            int prev2 = 0; //dp[0]
            int prev1 = 0; //dp[1]

            for(int i = 2; i <=n; i++) {
                int current = min(prev1 + cost[i-1],
                prev2 + cost[i-2]);
                prev2 = prev1;
                prev1 = current;
            }
            return prev1;
        }
};

int main() {
    Solution solution;

    vector<int> cost = {10, 15, 20};

    int answer = solution.minCostClimbingStairs(cost);

    cout << "Minimum cost : " << answer << endl; //15
    
    return 0;
}
