#include <bits/stdc++.h>
using namespace std;
#define Setprecision(a) cout << setprecision(a) << fixed
double x,y;
struct point
{
    double x,y;
    point()
    {
        x=0.0;
        y=0.0;
    }
    point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }

    void updateNorth(double v)
    {
        y+=v;
    }
    void updateSouth(double v)
    {
        y-=v;
    }
    void updateEast(double v)
    {
        x+=v;
    }
    void updateWest(double v)
    {
        x-=v;
    }

};
double dist(point p1,point p2)
{
    return hypot(p1.x-p2.x,p1.y-p2.y);
}

void solve(string st)
{
    point p;
    double d=0;
    int n=st.size();
    for(int i=0; i<n; i++)
    {
        if(st[i]>='0' && st[i]<='9')
        {
            int digit=st[i]-'0';
            d*=10;
            d+=digit;
        }
        else
        {
            if(st[i+1]>='A' && st[i+1]<='Z')
            {
                d*=d;
                double ct=d/2.0;
                ct=sqrt(ct);
                if(st[i]=='N')p.updateNorth(ct);
                else if(st[i]=='S')p.updateSouth(ct);
                else if(st[i]=='E')p.updateEast(ct);
                else if(st[i]=='W')p.updateWest(ct);

                i++;
                if(st[i]=='N')p.updateNorth(ct);
                else if(st[i]=='S')p.updateSouth(ct);
                else if(st[i]=='E')p.updateEast(ct);
                else if(st[i]=='W')p.updateWest(ct);


                i++;
            }
            else
            {
                double ct=d;
                if(st[i]=='N')p.updateNorth(ct);
                else if(st[i]=='S')p.updateSouth(ct);
                else if(st[i]=='E')p.updateEast(ct);
                else if(st[i]=='W')p.updateWest(ct);
                i++;
            }
            d=0.0;
        }
    }
    cout<<"The treasure is located at (";

    cout<<p.x<<","<<p.y;
    cout<<").\n";
    point origin;
    double res=dist(origin,p);

    cout<<"The distance to the treasure is ";
    cout<<res<<".\n";
}

int main()
{
    Setprecision(3);
    string st;
    int Map=1;
    while(cin>>st)
    {
        if(st=="END")return 0;
        if(Map!=1)cout<<"\n";
        cout<<"Map #"<<Map<<endl;
        Map++;
        solve(st);
    }
}
