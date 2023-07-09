/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    /*
        depths.size() == ints.size(), where depths[i] corresponds to the depth of the ith integer.
        As long as these lists can be properly populated, finding the weight and returning the 
        required sum is trivial.
    */
    vector<int> depths;
    vector<int> ints;

    /*
        Note that this variable is needed as depths for empty lists aren't recorded in the depths list. 
        Empty lists still contribute to depth, so this variable will take those into account as well.
    */
    int maxDepth = -1;

    int depthSumInverse(vector<NestedInteger>& nestedList) {

        for (auto a : nestedList) {
            //initial depth is 1
            search(a, 1);
        }

        int sum = 0;
        for (int i = 0; i < ints.size(); i++) {
            int weight = maxDepth - depths[i] + 1;
            sum += ints[i] * weight;
        }
        return sum;
    }

    void search(NestedInteger& n, int depth) {
        //if current element is an integer, append value to ints list and depth to depths list.
        if (n.isInteger()) {
            depths.push_back(depth);
            ints.push_back(n.getInteger());
            maxDepth = max(depth, maxDepth);
            return;
        }
        
        //empty lists are still counted in depth. Don't append to any list, but update max depth accordingly.
        if (n.getList().size() == 0) {
            maxDepth = max(depth, maxDepth);
        }

        //penetrate deeper into current list. 
        for (auto& e : n.getList()) {
            search(e, depth + 1);
        }

    }
};