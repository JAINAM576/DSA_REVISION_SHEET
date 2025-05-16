class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            else if(s[i]==')'){
                if(open>=1){
                    open--;
                }
                else if(open==0){
                    ans++;
                }
            }
        }
        return ans+open;
    }
};


// ((   ))

//)) 