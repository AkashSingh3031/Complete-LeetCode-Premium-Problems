class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        return true;
    }
};