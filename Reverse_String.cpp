#include<iostream>
#include<string>
using namespace std;
void rev_string(string &s,int i,int j){
  
    
 
    
    if(i>=j){
        
        return;
    }
    swap(s[i],s[j]);

    rev_string(s,i+1,j-1);
}
int main(){
    string s;
    cin>>s;
    cout<<s<<endl;
    int i=0;
    int j=s.length()-1;
    
    rev_string(s,i,j);

    cout<<s;
    

}