class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        // Step 2: Traverse and count overlaps
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                // Overlap, remove this interval
                count++;
            } else {
                // No overlap, update prevEnd
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
