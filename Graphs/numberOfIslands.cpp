#include <vector>
#include <iostream>

using namespace std;


class Solution {
    private:
        void dfs(vector<vector<char>>& grid, int row, int col) {
            int rows = grid.size();
            int cols = grid[0].size();

            if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
                return;
            }

            grid[row][col] = '0';

            dfs(grid, row - 1, col);
            dfs(grid, row + 1, col);
            dfs(grid, row, col - 1);
            dfs(grid, row, col + 1);
        }
    public:
        int numIsIslands(vector<vector<char>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();

            int isLandCount = 0;

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(grid[i][j] == '1') {
                        isLandCount++;
                        dfs(grid, i, j);
                    }
                }
            }
            return isLandCount;
        }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;

    cout << "Number of islands: " << solution.numIsIslands(grid) << endl;

    return 0;

}