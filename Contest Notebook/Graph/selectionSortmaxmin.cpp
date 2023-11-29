#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,w,i,j,max_value,first_half,second_half;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int min_index=0;
    int max_index=n-1;
    if(n%2==0)
        first_half=n/2;
    else
        first_half=n/2+1;
    second_half=n/2;
    for(i=0,w=n-1; i<first_half,w>second_half; i++,w--)
    {
        for(j=i+1,k=w-1; j<n,k>=0; j++,k--)
        {
            if(a[min_index]>a[j])
            {
                min_index=j;
            }
            if(a[max_index]<a[k])
            {
                max_index=k;
                max_value=a[k];
            }

        }
        swap(a[i],a[min_index]);
        min_index=i+1;

        if(a[w]!=max_value)
        {
          swap(a[w],a[max_index]);
        }
        max_index=w-1;
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;

}
/**
6
1 6 2 5 3 4

*/
