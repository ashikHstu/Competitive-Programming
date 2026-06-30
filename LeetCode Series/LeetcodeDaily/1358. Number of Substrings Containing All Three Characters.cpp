class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0,right=0;
        int freq[3]={0};

        int res=0;

        while(right<n)
        {
            freq[s[right]-'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0)
            {
                res+=(n-right);
                freq[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};