#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c && b==d)
    {
        cout<<"0\n";
    }
    else if(a+b==c+d || a-b==c-d  || (abs(a-c)+abs(b-d)<=3)){
        cout<<"1\n";
    }
    else if((a+b)%2==(c+d)%2)
    {
        cout<<"2\n";
    }
    else {
        long long int ext=d-b;
        long long int newx=a+ext;

        long long int newy=b+ext;
       // cout<<"New point : "<<newx<<", "<<newy<<endl;
        if(abs(newx-c)+abs(newy-d)<=3){
            cout<<"2\n";
            return 0;
        }

           ext=c-a;
        newx=a+ext;

         newy=b+ext;
       // cout<<"New point : "<<newx<<", "<<newy<<endl;
        if(abs(newx-c)+abs(newy-d)<=3){
            cout<<"2\n";
            return 0;
        }

        cout<<"3\n";
    }
    return 0;


}
