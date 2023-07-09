class Solution {
public:
    string parseTernary(string e) {
        int i = 0;
        return parse(e, i);
    }
private:
    string parse(string& e, int& i) {
        int i0 = i;
        if (i + 1 < e.size() && e[i + 1] == '?') { // recursion case - only if e[i + 1] == '?'
            i += 2;
            string a = parse(e, i); // parse both to advance the iterator
            string b = parse(e, ++i);
            return e[i0] == 'T' ? a : b;
        }
        return e.substr(i++, 1); // parse digit or boolean result - just eat a bite
    }
};