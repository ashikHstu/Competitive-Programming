#include <bits/stdc++.h>
using namespace std;

struct data
{
    int l,r,ind;
    data(int _l,int _r,int _ind)
    {
        l=_l;r=_r;ind=_ind;
    }
    bool operator <(const data &d)const
    {
        if(l==d.l)
        {
            return r>d.r;
        }
        return l<d.l;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<data>vec;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin>>l>>r;
        vec.push_back(data(l,r,i));
    }

    sort(vec.begin(),vec.end());

    int cur=vec[0].r;
    for(int i=1;i<n;i++)
    {
        if(vec[i].l<=cur && vec[i].r<=cur)
        {
            cout<<vec[i].ind<<endl;
            return 0;
        }
        else if(i+1<n && vec[i+1].l <=cur+1 && vec[i+1].r>vec[i].r)
        {
            cout<<vec[i].ind<<endl;
            return 0;
        }
       cur=vec[i].r;
    }

    cout<<"-1\n";

}
