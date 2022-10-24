#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;

    int ar[n+2];
    vector<int>vec;
    for(int i=0; i<n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int sum=x+y+z;
        ar[i]=sum;
        vec.push_back(sum);
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++){

    int position=vec.end()-upper_bound(vec.begin(),vec.end(),ar[i]+300);
    position++;
    if(position<=k)cout<<"Yes\n";
    else cout<<"No\n";

    }


    return 0;

}
