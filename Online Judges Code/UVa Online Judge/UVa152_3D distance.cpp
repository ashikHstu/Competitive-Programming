#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define EPS 1e-9
struct point
{
    int x,y,z;
    point(int _x,int _y,int _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
    point()
    {

        x=y=z=0;
    }

    bool operator <(point onno)const{
       if(fabs(x-onno.x)>EPS)return x<onno.x;
       if(fabs(y-onno.y)>EPS)return y<onno.y;
       return z<onno.z;
    }

};

 double dis(point a,point b)
 {
     double ra=(a.x-b.x);
     ra*=ra;
     double rb=(a.y-b.y);
     rb*=rb;
     double rc=(a.z-b.z);
     rc*=rc;

     double total=ra+rb+rc;
     return sqrt(total);
 }


int main()
{
   // cout<<"hypot: "<<hypot(2,3)<<endl;
point p1(1000,0,0),p2(0,1000,0);
cout<<dis(p1,p2)<<endl;
  //  cout<<DBL_MAX<<endl;
    vector<point>vec;
    int res[12]={0};
    int a,b,c;while(cin>>a>>b>>c)
    {

        if(a==0 && b==0 && c==0)break;

        vec.push_back(point(a,b,c));
    }
    sort(vec.begin(),vec.end());
    vector<double>ct;
    for(int i=0;i<vec.size();i++)
    {
        double mx=DBL_MAX;
        for(int j=0;j<vec.size();j++)
        {
            if(i==j)continue;
            double d=dis(vec[i],vec[j]);
            mx=min(mx,d);
        }
        if(mx<10)
        {
            int ind=mx;
            res[ind]++;
        }
    }

    for(int i=0;i<10;i++)cout<<right<<setw(4)<<res[i];
    cout<<endl;
}
