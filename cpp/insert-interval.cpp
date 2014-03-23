/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    struct sortInterval {
        bool operator()(const Interval &i1, const Interval &i2)
        {
            if(i1.start == i2.start)
                return i1.end < i2.end;
            return i1.start < i2.start;
        }
    };
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        stack<Interval> st;
        vector<Interval> output;
        if(intervals.size() == 0)
        {
            output.push_back(newInterval);
            return output;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), sortInterval());
        st.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            Interval temp = st.top();
            if(temp.start <= intervals[i].start && temp.end >= intervals[i].end)
                continue;
            else if(temp.start <= intervals[i].start && temp.end <= intervals[i].end && temp.end >= intervals[i].start)
            {
                Interval in(temp.start, intervals[i].end);
                st.pop();
                st.push(in);
            }
            else if(temp.start >= intervals[i].start && temp.end <= intervals[i].end)
            {
                st.pop();
                st.push(intervals[i]);
            }
            else if(temp.start >= intervals[i].start && temp.end >= intervals[i].end && temp.start <= intervals[i].end)
            {
                Interval in(intervals[i].start, temp.end);
                st.pop();
                st.push(in);
            }
            else
            {
                output.push_back(temp);
                st.pop();
                st.push(intervals[i]);
            }
            
        }
        if(!st.empty())
            output.push_back(st.top());
        st.pop();
        return output;
    }
};
