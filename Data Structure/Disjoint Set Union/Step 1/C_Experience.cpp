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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setSize, setMin, setMax, experience_points;

    void init(int n)
    {
        parent = setSize = setMin = setMax = experience_points = vector<int>(n + 1, 0);
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
        return findParent(parent[u]);
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
        experience_points[parent1] -= experience_points[parent2]; /// reducing the current parents ExperiencePoint as it will add later

        parent[parent1] = parent[parent2];
    }

    void addPoint(int u, int value)
    {
        experience_points[findParent(u)] += value;
    }
    int getPoints(int u)
    {
        if (parent[u] == u)
            return experience_points[u];
        return experience_points[u] + getPoints(parent[u]);
    }

    bool isSameSet(int i, int j)
    {
        return findParent(i) == findParent(j);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int a, v;
            cin >> a >> v;
            dsu.addPoint(a, v); // Adding v to all the elements who has the current parent a
        }
        else if (op == "join")
        {
            int u, v;
            cin >> u >> v;
            dsu.Union(u, v); // Make union of two set
        }
        else
        {
            int u;
            cin >> u;
            cout << dsu.getPoints(u) << endl; // finding the point of that node
        }
    }
    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
