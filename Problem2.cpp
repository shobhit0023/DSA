#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void subseq(vector<int>arr,int i,vector<int>&ans){
    if(i==arr.size()){
        for(int j=0;j<ans.size();j++){
            cout<<ans[j];
            
        }
        cout<<endl;
        // cout<<ans[i];
        return;

    }
    subseq(arr,i+1,ans);
    ans.push_back(arr[i]);
    subseq(arr,i+1,ans);
    ans.pop_back();


}
int main(){
    vector<int>arr{1,2,3};
    int i=0;
    vector<int>ans;
    subseq(arr,i,ans);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<endl;
    // }


}