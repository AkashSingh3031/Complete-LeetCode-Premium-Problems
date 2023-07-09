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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string result = to_string(root->val);
        if (root->children.empty()) return result + " null";
        for (Node* child : root->children) {
            result += " " + serialize(child);
        }
        return result + " null";
    }
  
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream iss(data);
        queue<string> q;
        string token;
        while (iss >> token) {
            q.push(token);
        }
        return deserializeHelper(q);
    }
private:
    Node* deserializeHelper(queue<string>& q) {
        string valStr = q.front();
        q.pop();
        if (valStr == "null") return nullptr;
        Node* root = new Node(stoi(valStr), {});
        while (q.front() != "null") {
            root->children.push_back(deserializeHelper(q));
        }
        q.pop();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));