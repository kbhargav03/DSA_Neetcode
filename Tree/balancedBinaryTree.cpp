#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
    
};

class Solution {
private:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(root->left);

        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = checkHeight(root->right);

        if(rightHeight == -1) {
            return -1;
        }

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root){
        return checkHeight(root) != -1;
    }
};

int main() {
    /*
     * Constructing this tree:
     *
     *         3
     *        / \
     *       9   20
     *          /  \
     *         15   7
     *
     * This tree is balanced.
     */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    if (solution.isBalanced(root)) {
        cout << "The binary tree is balanced." << '\n';
    } else {
        cout << "The binary tree is not balanced." << '\n';
    }

    // Free the dynamically allocated memory.
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

