void init(int maxN)
{
    int i,j;
    for(i=2; i<=maxN; i++)
    {
        phi[i] = i;
    }

    for(i=2; i<=maxN; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=maxN; j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}
void solve()
{
     cin >> n;
     cout << phi[n] << endl;
}

