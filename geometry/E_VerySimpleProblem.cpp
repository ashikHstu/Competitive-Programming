#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define dt long long int

struct Point{
   dt x,y;
   Point(dt _x=0,dt _y=0)
   {
       x=_x;
       y=_y;
   }

   Point operator -(const Point &other)const{
             return {x-other.x,y-other.y};
   }


};


dt Cross(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}


int main()
{
   FasterIO;

    long long int n;cin>>n;
    vector<Point>vec(n);

    for(int i=0;i<n;i++)
    {
        cin>>vec[i].x>>vec[i].y;
    }

    int q;cin>>q;
    while(q--)
    {
    long long int res=0;
        Point ask;
        cin>>ask.x>>ask.y;
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            long long int cur=Cross(vec[(i+1)%n]-vec[i],ask-vec[i]);
            if(cur>0)ok=false;
        }
        if(!ok)
        {
            cout<<"0\n";
            continue;
        }


        long long int kotoPorjonto=0;
        for(int i=0;i<n;i++)
        {
              int left=1,right=n-1;
              while(left<=right)
              {
                  int mid=((left+right)/2);
                  int wPoint=(i+mid)%n;
                  long long int currentCross=Cross(vec[wPoint]-vec[i],ask-vec[i]);
                  if(currentCross>0)
                  {
                      right=mid-1;
                  }
                  else {
                    kotoPorjonto=mid;
                    left=mid+1;
                  }
              }
                 long long int x=kotoPorjonto-1;
              res+=(x*(x+1))/2;

        }

        res=((n*(n-1)*(n-2))/6)-res;
        cout<<res<<endl;
    }


}
