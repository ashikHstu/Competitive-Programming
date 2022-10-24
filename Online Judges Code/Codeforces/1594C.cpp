#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    char ch;

        cin >> n>> ch;
        string st;
        cin>>st;
        int m=0;
        int len=st.size();
        for(int i=0;i<len;i++)
        {
            if(st[i]!=ch)m++;
        }

        if(m==0)
        {
            cout<<"0\n";
            return;
        }
        else if(st[len-1]==ch)
        {
            cout<<1<<endl;
            cout<<n<<endl;
            return;
        }
        else if(m==1)
        {
            cout<<1<<endl;
            cout<<n-1<<endl;
            return;
        }
        else if(st[len-2]==ch)
        {
            cout<<1<<endl;
            cout<<n-1<<endl;
            return;
        }

        bool ok2=true;
        for(int i=1;i<=len;i++)
        {
            bool ok=true;



            for(int j=i;j<=len;j+=i)
            {

                if(st[j-1]!=ch)
                {
                    ok=false;
                    break;
                }

            }
            if(ok)
            {
              //  cout<<"then it is?"<<endl;
                cout<<1<<endl;
                cout<<i<<endl;
                return;
            }
        }




            cout<<2<<endl;

            cout<<n-1<<" "<<n<<endl;

}


int main()
{
    int tc;

    cin >> tc;

    while(tc--)
    {
        solve();
    }
    return 0;
}
