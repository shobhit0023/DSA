#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int summ(vector<int>arr,int target){
     int res=0;
    int mini=INT_MAX;
    if(target==0){
        return 0;
    }
    if(target<0){
        return(INT_MAX);
    }

    for(int i=0;i<arr.size();i++){
        res+=arr[i];
        int ans=(arr,target-res);
        if(ans!=INT_MAX){
        mini=min(mini,ans+1);
        }
        
    }
    return mini;
    
    
}
int main(){
    vector<int> arr{1,2,3};
    int target=5;
    
    int ans=summ(arr,target);
    cout<<"Answer is:"<<ans<<endl;
}