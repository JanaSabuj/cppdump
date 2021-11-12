class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                // find inorder predeccsor
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                // if not visited before, so rhs is null
                if (!pre -> right) {
                    pre -> right = root;// link to curr node before
                    root = root -> left;// going left
                } else {
                    // visited before, so now destroy the link
                    pre -> right = NULL;
                    nodes.push_back(root -> val);// push it
                    root = root -> right;// left done, self done , now go right
                }
            } else {
                // left completed
                nodes.push_back(root -> val);// push it
                root = root -> right;// go right
            }
        }
        return nodes;
    }
};
