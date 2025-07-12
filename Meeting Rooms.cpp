/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    static bool comparator(const Interval& a,const Interval& b){
        return a.start<b.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort(intervals.begin(),intervals.end(),comparator);
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    return a.start < b.start;
});

        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i].start<intervals[i-1].end){
                return false;
            }
        }
        return true;
    }
};
