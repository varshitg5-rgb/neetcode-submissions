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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starta;
        vector<int> enda;
        for(auto x : intervals){
            starta.push_back(x.start);
            enda.push_back(x.end);
        }
        sort(starta.begin(),starta.end());
        sort(enda.begin(),enda.end());
        int ans = 0;
        int res = 0;
        int s = 0;
        int e = 0;
        while(s<intervals.size()){
            if(starta[s]<enda[e]){
                ans++;
                s++;
            }else{
                ans--;
                e++;
            }

             res = max(ans,res);
        }
        return res;
    }
};
