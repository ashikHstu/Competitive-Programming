#include <bits/stdc++.h>
using namespace std;

char altBit(char c)
{
    if(c=='0')return '1';
    return '0';
}
vector<pair<int,int>> findMovesToMakeZero(string st)
{
    vector<pair<int,int>>moves;
    int eqPos=-1;
    char curChar='2';
    for(int i=1;i<st.size();i++)
    {
        if(st[i]==st[i-1])
        {
            eqPos=i-1;
            curChar=st[i];
            break;
        }
    }

    if(eqPos==-1)
    {
        moves.push_back({0,2});
        st[0]=altBit(st[0]);
        st[1]=altBit(st[1]);
        st[2]=altBit(st[2]);
        curChar=st[3];
        eqPos=2;
    }
    int L=eqPos;
    int R=eqPos+1;
    while(L>0 && st[L-1]==st[L])
    {
        L--;
    }
    while(R<st.size()-1 && st[R+1]==st[R])
    {
        R++;
    }

    while(L>0)
    {
        if(st[L-1]!=curChar)
        {
            moves.push_back({L,R});
            //st[L-1]=altBit(st[L-1]);
            curChar=st[L-1];
        }
        L=L-1;
    }
    while(R<st.size()-1)
    {
        if(st[R+1]!=curChar)
        {
            moves.push_back({L,R});
            //st[R+1]=altBit(st[R+1]);
            curChar=st[R+1];
        }
        R=R+1;
    }
    if(curChar!='0')
    {
        moves.push_back({L,R});
    }
    return moves;
}

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<pair<int,int>>findMoves=findMovesToMakeZero(s);
    vector<pair<int,int>>findReverseMoves=findMovesToMakeZero(t);
    reverse(findReverseMoves.begin(),findReverseMoves.end());
    cout<<findMoves.size()+findReverseMoves.size()<<endl;
    for(auto move:findMoves)
    {
        cout<<move.first+1<<" "<<move.second+1<<endl;
    }

    //cout<<endl<<endl;
    for(auto move:findReverseMoves)
    {
        cout<<move.first+1<<" "<<move.second+1<<endl;
    }
}

int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }
}