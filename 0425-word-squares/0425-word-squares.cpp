class Solution {
public:
	vector<vector<string>> wordSquares(vector<string>& words) {
		unordered_map<string, unordered_set<string>> prefixMap;  // prefix -> set of words that has it as prefix
		for (auto w : words) {
			add(prefixMap, w);
		}
		vector<vector<string>> ans;
		int len = words[0].length();
		vector<string> curr(len, string(len, ' '));
		// prefix map + DFS
		// state: current placed strings
		search(words, prefixMap, ans, curr, 0);
		return ans;
	}
private:
	void add(unordered_map<string, unordered_set<string>>& prefix, string& w) {
		int n = w.length();
		string currW(n, ' ');
		prefix[currW].insert(w);
		for (int i = 0; i < n; i++) {
			currW[i] = w[i];
			prefix[currW].insert(w);
		}
	}
	void search(vector<string>& words, unordered_map<string, unordered_set<string>>& prefixMap, vector<vector<string>>& ans, vector<string>& curr, int i) {
		if (i == curr.size()) {
			ans.push_back(curr);
			return;
		}
		for (auto& w : prefixMap[curr[i]]) {    // only need to check the words prefixed by curr[i] 
			string ori = curr[i];
			curr[i] = w;
			bool ok = true;
			for (int j = i+1; j < curr.size() && ok; j++) { // check transpose
				curr[j][i] = w[j];
				if (!prefixMap.count(curr[j])) {    // non-existing prefix -> can't place w here
					ok = false;
				}
			}
			if (ok) {   // keep searching
				search(words, prefixMap, ans, curr, i+1);
			}
			for (int j = i+1; j < curr.size(); j++) {   // recover the state
				curr[j][i] = ' ';
			}
			curr[i] = ori;
		}
	}
};