int ext_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int g=ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}
bool findAnySolution(int a,int b,int c,int &x,int &y,int &g)
{
    g=ext_gcd(abs(a),abs(b),x,y);
    if(c%g)return false;
    x=x*(c/g);
    y=y*(c/g);
    if(a<0)x=-x;
    if(b<0)y=-y;
    return true;
}

