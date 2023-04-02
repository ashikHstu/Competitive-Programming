/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
   verdict : Accepted
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setSize, setMin, setMax;

    void init(int n)
    {
        parent = setSize = setMin = setMax = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = setMin[i] = setMax[i] = i, setSize[i] = 1;
        }
        totalConnectedComponent = n;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    /*
    int findParent(int u)
      {
          while (u != parent[u])
          {
              parent[u] = parent[parent[u]];
              u = parent[u];
          }
          return u;
      }
    */

    int getSetSize(int u)
    {
        return setSize[findParent(u)];
    }
    int getSetMin(int u)
    {
        return setMin[findParent(u)];
    }
    int getSetMax(int u)
    {
        return setMax[findParent(u)];
    }

    void Union(int u, int v)
    {
        int parent1 = findParent(u), parent2 = findParent(v);

        if (parent1 == parent2)
            return;

        totalConnectedComponent--;

        if (setSize[parent1] > setSize[parent2])
            swap(parent1, parent2);

        setSize[parent2] += setSize[parent1];
        setMin[parent2] = min(setMin[parent1], setMin[parent2]);
        setMax[parent2] = max(setMax[parent1], setMax[parent2]);
        setSize[parent1] = 0;
        parent[parent1] = parent[parent2];
    }

    bool isSameSet(int i, int j) { return findParent(i) == findParent(j); }
};

int main()
{
    FasterIO;
    int n, op;
    cin >> n >> op;
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < op; i++)
    {
        string type;
        cin >> type;
        if (type == "union")
        {
            int a, b;
            cin >> a >> b;
            dsu.Union(a, b); // to make the union of two set,which contain element a and element b
        }
        else
        {
            int ind;
            cin >> ind;
            cout << dsu.getSetMin(ind) << " " << dsu.getSetMax(ind) << " " << dsu.getSetSize(ind) << endl;
            /*
               getSetMin(ind)-> to get the minimum among the set which contain the element ind
               getSetMax(ind)-> to get the maximum among the set which contain the element ind
               getSetSize(ind)-> to get the size of a set which contain the element ind
            */
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
