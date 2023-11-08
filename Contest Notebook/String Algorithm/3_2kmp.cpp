vector <int> Z_algo(string s)
{
    int n = s.size(), i,l=0,r=0,j;
    vector <int> z(n);
    for(i=1; i<n; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && s[r] == s[r-l])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else
        {
            int j = i - l;
            if(z[j] < r - i + 1)
            {
                z[i] = z[j];
            }
            else
            {
                l = i;
                while(r < n && s[r] == s[r-l])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    return z;
}

