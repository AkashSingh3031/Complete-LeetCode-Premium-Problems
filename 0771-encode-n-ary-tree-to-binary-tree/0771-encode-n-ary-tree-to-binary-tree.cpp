/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* node) {
        if(!node) return NULL;
        TreeNode* root= new TreeNode(node->val),*ptr;
        for(Node*p : node->children) {
            if(root->right==NULL) {
                root->right = encode(p);
                ptr=root->right;
            } else {
                ptr->left=encode(p);
                ptr=ptr->left;
            }
        }
        return root;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node* node = new Node(root->val);
        TreeNode*ptr = root->right;
        while(ptr) {
            node->children.push_back(decode(ptr));
            ptr=ptr->left;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));