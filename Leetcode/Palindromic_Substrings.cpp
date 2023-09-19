LeetCode: 647

class Solution {
public:
    int substrings(string s,int i,int j){
        int c=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
                i--;
                j++;
                c=c+1;
        }
        return c;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        
        for(int i=0;i<n;i++){
            int odd=substrings(s,i,i);
            count=count+odd;
            
            int even=substrings(s,i,i+1);
            count = count+even;
            
        }
        return count;
        
        
    }
};