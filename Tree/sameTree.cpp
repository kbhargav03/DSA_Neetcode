#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */


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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both nodes are null, they match at the position.
        if(p == nullptr && q == nullptr) {
            return true;
        }

        //if only one node is null, the structure differ.
        if(p == nullptr || q == nullptr) {
            return false;
        }

        /**
         * Both nodes exist. Their values and corresponding
         * left and right subtrees must match
         */
        return p->val == q->val && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
    }
};

int main() {
    /*
      Tree p :

            1 
        2       3
    */
   TreeNode* p = new TreeNode(1);
   p->left = new TreeNode(2);
   p->right = new TreeNode(3);

   /*
        Tree q :
            1
        2       3
   */

   TreeNode* q = new TreeNode(1);
   q->left = new TreeNode(2);
   q->right = new TreeNode(3);

   Solution solution;

   if(solution.isSameTree(p,q)) {
        cout << "Same Tree" << endl;
   } else {
        cout << "Different Tree" << endl;
   }

   // Free the dynamically allocated memory.
    delete p->left;
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}