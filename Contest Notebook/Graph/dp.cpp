
for(i=1; i<=n; i++)
{
    cin>>a;
    dp[a]++;
}
for(i=0; i<22; i++)
{
    for(j=0; j<(1<<22); j++)
    {
        if(j&(1<<i))
        {
            dp[j]+=dp[j^(1<<i)];
            //number of element for a value of her all subset
        }
    }
}

