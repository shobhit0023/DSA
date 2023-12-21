#include <bits/stdc++.h>
#include <string>
using namespace std;
bool isPalind(string s,int i,int j){
    if(j<i){
        return true;
    }


    if(s[i]!=s[j]){
        return false;
    }
    isPalind(s,i+1,j-1);
    // return(true);

}
int main(){
    string s;
    cin>>s;
    
    int i=0;
    int j=s.length()-1;
    isPalind(s,i,j);

    if(isPalind(s,i,j)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
}