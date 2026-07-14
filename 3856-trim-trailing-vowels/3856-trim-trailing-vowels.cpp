class Solution {
public:
    string trimTrailingVowels(string s) {

        int n=s.size();
        int idx=n-1;

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            idx=i-1;
            else
            break;
        }

       return s.substr(0, idx + 1);
        
    }
};