#include<iostream>
#include<climits>
using namespace std;
#define mx 1000004
#define ll long long int
ll a[mx];
ll n;

ll maxSubArraySum()
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int t;
    cin>>t;
    while(t--){

        cin>>n;

        for(int i=0;i<n;i++) cin>>a[i];
    }

    ll max_sum = maxSubArraySum();
    cout << max_sum<<endl;;
    return 0;
}
