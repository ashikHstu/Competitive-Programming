/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


#define maxN 5005
#define K 25
int Log[maxN+1];
int sparse_table[maxN][K+1];
int ar[maxN];
int N;

/// precomputing all logarithm
void calLog()
{
    Log[1]=0;
    for(int i=2; i<=maxN; i++)
        Log[i]=Log[i/2]+1;

}

void makeSparseMin()
{
    for(int i=0; i<N; i++)
    {
        sparse_table[i][0]=ar[i];
    }
    for(int j=1; j<=K; j++)
    {
        for(int i=0; i+(1<<j)<=N; i++)
        {
            sparse_table[i][j]=min(sparse_table[i][j-1],sparse_table[i+(1<<(j-1))][j-1]);
        }
    }
}

int findMin(int L,int R)
{
    int j=Log[R-L+1];
    int minimum=min(sparse_table[L][j],sparse_table[R-(1<<j)+1][j]);
    return minimum;
}

int rangeRes(int L,int R,int cur)
{
   // cout<<"total call "<<L<<", "<<R<<endl;
    if(L==R)return 1;
    if(R<L)return 0;
    int min_in_range=findMin(L,R);
    min_in_range-=cur;

   // cout<<"min in range "<<L<<", "<<R<<" : "<<min_in_range<<endl;
    int res=R-L+1;
    int r2=min_in_range;
    int Lz=-1;
    for(int i=L;i<=R;i++)
    {
        if(ar[i]-min_in_range-cur==0)
        {
          //  cout<<"how many : "<<i<<endl;
          //  if(i>=3)
          //  cout<<"went at 3-4 "<<"there: "<<i<<"\n";
           // cout<<"lz : "<<Lz<<" "<<i-1<<endl;
            r2+=(rangeRes(Lz+1,i-1,cur+min_in_range));
            Lz=i;
        }
        if(i==4)
        {

           // cout<<"lz : "<<Lz<<endl;
        }
    }
 //   cout<<"lz : "<<Lz<<endl;
    r2+=(rangeRes(Lz+1,R,cur+min_in_range));

//cout<<"range "<<L<<" to "<<R<<" : "<<min(res,r2)<<endl;
    return min(res,r2);
}



int main()
{
    calLog();

    cin>>N;
    for(int i=0;i<N;i++)cin>>ar[i];

    makeSparseMin();



   cout<<rangeRes(0,N-1,0)<<endl;

    return 0;
}


 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
