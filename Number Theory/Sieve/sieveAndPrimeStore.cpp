/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://www.spoj.com/problems/TDKPRIME/
   verdict : Accepted
*/
#include <bits/stdc++.h>
using namespace std;
#define limit 100000001
int prime_chek[limit + 1], primes[50000000], total_primes;
void sieve_and_store_primes()
{
    int sqn = sqrt(limit) + 1;
    prime_chek[0] = prime_chek[1] = 1;
    primes[total_primes] = 2;
    total_primes++;
    for (int i = 3; i <= sqn; i += 2)
    {
        if (prime_chek[i] == 0)
        {
            primes[total_primes] = i;
            total_primes++;
            for (int j = i * i; j <= limit; j += i + i)
            {
                prime_chek[j] = 1;
            }
        }
    }
    if (sqn % 2 == 0)
    {
        sqn++;
    }
    for (int i = sqn; i < limit; i += 2)
    {
        if (prime_chek[i] == 0)
        {
            primes[total_primes] = i;
            total_primes++;
        }
    }
}
int main()
{
    sieve_and_store_primes();
    cout << total_primes << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {

        int ask;
        cin >> ask;
        ask--;
        cout << primes[ask] << endl;
    }
}
