class WordDistance 
{
public:
    WordDistance(vector<string>& wordsDict) 
    {
        int n = wordsDict.size();
        for (int i=0; i<n; ++i)
        {
            _map[wordsDict[i]].push_back(i);
        }

    }
    
    int shortest(string word1, string word2) 
    {
        auto v1 = _map[word1];
        auto v2 = _map[word2];
        if (v1.size() > v2.size())
        {
            v1.swap(v2);
        }
        int n = v1.size();
        int result = std::numeric_limits<int>::max();
        for (int i=0; i<n; ++i)
        {
            auto high_iter = upper_bound(v2.cbegin(), v2.cend(), v1[i]);
            if (high_iter != v2.cend())
            {
                result = std::min(result, *high_iter-v1[i]);
            }
            auto low_iter = lower_bound(v2.cbegin(), v2.cend(), v1[i]);
            if (low_iter != v2.cbegin())
            {
                --low_iter;
                result = std::min(result, v1[i]-*low_iter);
            }
        }
        return result;
    }
private:
    unordered_map<string, vector<int>> _map {};
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */