/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int bfs(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return sum;
    }

    int temp = root->val;

    root->val += bfs(root->right, sum);
    sum = bfs(root->left, root->val);

    return sum;
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    bfs(root, 0);
    return root;
}