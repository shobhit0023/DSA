class Solution {
public:
    int bs(vector<int>&nums,int start,int x){
        int end=nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid] == x){
                return mid;
            }
            else if(nums[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> count;
//         int i=0,j=1;
        
//             while(j<nums.size()){
//               int diff= nums[j] - nums[i];
//               if(diff == k){
//                   count.insert({nums[i], nums[j]});
//                   ++i,++j;
                  
//               }
//               else if(diff>k){
//                  i++;       
//               }
//               else{
//                   j++;
//               }
//               if(i==j) j++;
//             }
        for(int i=0;i<nums.size();i++){
            if(bs(nums,i+1,nums[i]+k) != -1){
                count.insert({nums[i],nums[i]+k});
            }
            
        }
        return count.size();
    }
};