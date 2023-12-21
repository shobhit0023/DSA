#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){
    vector<int>prices={7,1,5,3,6,4};
    int mini=prices[0];
    int profit=0;

    for(int i=1;i<prices.size();i++){
        int cost=prices[i]-mini;
        profit=max(cost,profit);

        mini=min(mini,prices[i]);

    }
    cout<<profit;
}