/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void shift(
    TreeNode*& root, stack<TreeNode*>& parents,
    function<TreeNode*(TreeNode*)> shift_0,
    function<TreeNode*(TreeNode*)> shift_1,
    function<bool(int, int)> cmp_0
) {
    if (!root) return;

    if (shift_1(root)) {
        parents.push(root);

        for (
            auto* root_next = shift_1(root);
            root_next;
            root_next = shift_0(root_next)
        ) {
            parents.push(root_next);
            root = root_next;
        }

        return;
    }

    auto target = root->val;

    // try going up
    while (root) {
        if (cmp_0(root->val, target)) break;

        if (parents.empty()) {
            root = nullptr;
            break;
        }
        root = parents.top();
        parents.pop();
    }
}

// Decrement root to the prev node
void prev(TreeNode*& root, stack<TreeNode*>& parents) {
    return shift(
        root, parents,
        [](TreeNode* n) { return n->right; },
        [](TreeNode* n) { return n->left; },
        [](int e0, int e1) { return e0 < e1; }
    );
}

// Increment root to the post node
void post(TreeNode*& root, stack<TreeNode*>& parents) {
    return shift(
        root, parents,
        [](TreeNode* n) { return n->left; },
        [](TreeNode* n) { return n->right; },
        [](int e0, int e1) { return e0 > e1; }
    );
}

int closest(int e0, int e1, int target) {
    if (abs(e0 - target) < abs(e1 - target)) {
        return e0;
    }
    return e1;
}

int bst(
    TreeNode* root,
    int target
) {
    if (!root) return -1;

    int ret = root->val;
    if (ret == target) return target; // base case

    auto root_next = target < root->val ? root->left : root->right;
    auto _ret = bst(root_next, target);
    if (_ret >= 0) {
        ret = closest(ret, _ret, target);
    }

    return ret;
}

TreeNode* bst_exact(
    TreeNode* root,
    stack<TreeNode*>& parents,
    int target
) {
    if (!root) return nullptr;

    int ret = root->val;
    if (ret == target) return root; // base case

    parents.push(root); // push the stack

    auto root_next = target < root->val ? root->left : root->right;
    return bst_exact(root_next, parents, target);
}

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (!root) return {};

        // We can probably get the nearest node and its
        // parent stack at the same time;
        // but I'm lazy.
        // So 2 searches are performed.
        const auto exact = bst(root, target);

        stack<TreeNode*> parents_prev;
        auto* n_prev = bst_exact(root, parents_prev, exact);
        auto parents_post = parents_prev;
        auto* n_post = n_prev;

        vector<int> ret_prev;
        ret_prev.reserve(k);
        for (auto i = 0; i < k; i += 1) {
            prev(n_prev, parents_prev);
            if (!n_prev) break;
            ret_prev.push_back(n_prev->val);
        }

        vector<int> ret_post;
        ret_post.reserve(k);
        for (auto i = 0; i < k; i += 1) {
            post(n_post, parents_post);
            if (!n_post) break;
            ret_post.push_back(n_post->val);
        }

        vector<pair<double, int>> ret;
        ret.reserve(k * 2 + 1);
        ret.emplace_back(abs(target - exact), exact);
        for (auto val : ret_prev) {
            ret.emplace_back(abs(target - val), val);
        }
        for (auto val : ret_post) {
            ret.emplace_back(abs(target - val), val);
        }
        sort(ret.begin(), ret.end());

        vector<int> ret_vec;
        ret_vec.reserve(k);
        for (auto i = 0; i < k; i += 1) {
            ret_vec.push_back(ret[i].second);
        }

        return ret_vec;
    }
};