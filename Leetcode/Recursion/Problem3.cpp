#include<iostream>
#include<vector>
using namespace std;
void subseq_sum(int ind,int n,int sum,int target,int arr[],vector<int> &ds){
    if(ind>=n){
        if(sum == target){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    subseq_sum(ind+1,n,sum,target,arr,ds);

    sum-=arr[ind];
    ds.pop_back();

    subseq_sum(ind+1,n,sum,target,arr,ds);

     
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int target=2;
    vector<int>ds;

    subseq_sum(0,n,0,target,arr,ds);


}