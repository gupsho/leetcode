/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0)
            return 0;
        if(points.size() <= 2)
            return points.size();
        map<double, int> slopes;
        int maxP, duplicates, out = 0;
        for(int i = 0; i < points.size(); i++)
        {
            maxP = 0;
            duplicates = 0;
            for(int j = i+1; j < points.size(); j++)
            {
                if(points[j].x == points[i].x && points[j].y == points[i].y)
                {
                    duplicates ++;
                    continue;
                }
                double slope = INT_MAX;
                if(points[j].x != points[i].x)
                    slope = (double)(points[j].y - points[i].y)/ (points[j].x - points[i].x);
                    
                if(slopes.find(slope) != slopes.end())
                    slopes[slope]++;
                else
                    slopes[slope] = 1;
            }
            for(map<double,int>::iterator it = slopes.begin(); it != slopes.end(); ++it) {
                if(it->second > maxP)
                    maxP = it->second;
            }
            maxP = maxP + duplicates + 1; // +1 for the current point
            if(out < maxP)
                out = maxP;
            
            slopes.clear();
        }
        
        return out;
    }
};
