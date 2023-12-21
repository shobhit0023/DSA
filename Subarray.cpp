//**** Print Subarray using Recursion******//

#include<iostream>
#include<vector>
using namespace std;
void print_Subseq(vector<int>&arr,int start,int end){
    if(end == arr.size()){
        return;
    }
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    print_Subseq(arr,start,end+1);
}
void printSubseq(vector<int> &arr){
    for(int start=0;start<arr.size();start++){
        int end=start;
        print_Subseq(arr,start,end);
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int start=0;
    int end=0;
    printSubseq(arr);
   
}