void count_sort(vector<int>&p,vector<int>&c)
{
    int n=c.size();
    vector<int>cnt(n);
    for(int i=0;i<n;i++)
        cnt[c[i]]++;
    vector<int>pos(n),p_new(n);
    pos[0]=0;
    for(int i=1;i<n;i++)
        pos[i]=pos[i-1]+cnt[i-1];

    for(auto x:p)
    {
        int i=c[x];
        p_new[pos[i]]=x;
        pos[i]++;
    }
    p=p_new;
}

vector<int> suffix_array(string st)
{
    st+="$";
    int n=st.size();
    vector<int>p(n),c(n);
    {
        vector<pair<char,int>>a(n);
        for(int i=0;i<n;i++)
        a[i]={st[i],i};

        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
            p[i]=a[i].second;

       c[p[0]]=0;
       for(int i=1;i<n;i++)
       {
           if(a[i].first==a[i-1].first)
            c[p[i]]=c[p[i-1]];
           else
            c[p[i]]=c[p[i-1]]+1;
       }

    }

    int k=0;
    while((1<<k)<n)
    {
        for(int i=0;i<n;i++)
        {
            p[i]=(p[i]-(1<<k)+n)%n;
        }

        count_sort(p,c);

        vector<int>c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            pair<int,int>prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int>now={c[p[i]],c[(p[i]+(1<<k))%n]};
            if(now==prev)
                c_new[p[i]]=c_new[p[i-1]];
            else
                c_new[p[i]]=c_new[p[i-1]]+1;
        }
        c=c_new;
        k++;
    }


    vector<int>lcp(n);
    k=0;

    for(int i=0;i<n-1;i++)
    {
        int pi=c[i];
        int j=p[pi-1];

        while(st[i+k]==st[j+k])k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }

    return p;
}

