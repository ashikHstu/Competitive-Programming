/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link :
   verdict :
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/** STL Functions     */
// pbds
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

/**      Extra storing              */
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())

/**        End of Ex Storing                */

/**------- Char Chk----------*/
inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpper(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
/// int ar[], int left, int mid, int right


int Comparison(int L,int R)
{
    cout<<"? "<<L<<" "<<R<<endl;
    fflush(stdout);
    char ch;cin>>ch;
    if(ch=='<')return 1;
    else if(ch=='>')return 2;
    return 3;
}


vector<int> marge(vector<int>L,vector<int>R)
{
    vector<int>mainV;


    int size_left=L.size();
    int size_right=R.size();

    //L.push_back(INT_MAX);
   // R.push_back(INT_MAX);

    int index_l, index_r;

    index_l = index_r = 0;
    for (int i =0; i <size_left+size_right && index_l<size_left && index_r<size_right; i++)
    {
        int status=Comparison(L[index_l],R[index_r]);

        if (status==1)
        {
            //ar[i] = L[index_l];
            mainV.push_back(L[index_l]);
            index_l++;
        }
        else if(status==2)
        {
           // ar[i] = R[index_r];
            mainV.push_back(R[index_r]);
            index_r++;
        }
        else {
            mainV.push_back(L[index_l]);
            index_l++;
            index_r++;
            i++;
        }
    }
     while(index_l<size_left){
        mainV.push_back(L[index_l]);
        index_l++;
     }
     while(index_r<size_right)
     {
         mainV.push_back(R[index_r]);
         index_r++;
     }

    if(mainV.back()==INT_MAX)mainV.pop_back();
    return mainV;
}

vector<int> marge_sort(vector<int>ar)
{
  //  cout<<ar.size()<<endl;
    if (ar.size()<=1)
        return ar;

    int mid=(ar.size())/2;
    vector<int>ar1,ar2;
    for(int i=0;i<mid;i++)ar1.push_back(ar[i]);
    for(int i=mid;i<ar.size();i++)ar2.push_back(ar[i]);

   vector<int>m1= marge_sort(ar1);
    vector<int>m2=marge_sort(ar2);

    vector<int>vec=marge(m1,m2);

    return vec;
}

int main()
{

    int n ;

    cin>>n;
    vector<int>vec;
    for(int i=1;i<=n;i++){
            vec.push_back(i);
    }


    vector<int>vec1=marge_sort(vec);


    cout<<"! "<<vec1.size()<<endl;
    return 0;
}
