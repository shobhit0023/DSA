LeetCode: 539

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(int i=0;i<timePoints.size();i++){
             string curr = timePoints[i];
             int hours = stoi(curr.substr(0,2));
             int min = stoi(curr.substr(3,2));
             int total= hours*60 + min;
             minutes.push_back(total);
        }
        sort(minutes.begin(),minutes.end());
        int mini = INT_MAX;
        int n=minutes.size();
        for(int i=0;i<n-1;i++){
            int diff = minutes[i+1]-minutes[i];
            mini = min(mini,diff);
        }
        
        int mindiff=(minutes[0]+1440)-minutes[n-1];
        mini=min(mini,mindiff);
        
        return mini;
        
        
    }
};