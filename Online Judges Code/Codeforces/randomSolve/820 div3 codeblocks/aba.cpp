#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int i,j,n,x=0;
    char w[1000];
    scanf("%[^\n]s",w);
    char cc;cin>>cc;
    printf("The inputed string is : %s \n",w);

    n = strlen(w);
    cout<<"the len is : "<<n<<endl;
      for(int i=n-2; i>0; i=i-2)
    {
        for(j=1; j<i; j=j+2)
        {
            if(j>n-1)
            j=i;

            if(w[i]==w[j])
        {
        x++;
        break;
        }
        }

    }
    printf("%d",n/2 - x);
    return 0;
}
