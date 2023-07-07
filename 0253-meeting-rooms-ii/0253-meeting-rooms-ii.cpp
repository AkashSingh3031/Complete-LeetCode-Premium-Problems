class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t[0]]++, m[t[1]]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }
};