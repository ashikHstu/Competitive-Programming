#include <bits/stdc++.h>
using namespace std;
#define int long long
struct matrix
{
    int v[5][5];
    int row, col; // number of row and column
};
int mod = 1000000007;

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (int i = 0; i < r.row; i++)
    {
        for (int j = 0; j < r.col; j++)
        {
            int sum = 0;
            for (int k = 0; k < a.col; k++)
            {
                sum += (a.v[i][k] * b.v[k][j]) % mod;
                sum %= mod;
            }
            r.v[i][j] = sum % mod;
        }
    }
    return r;
}

// returns mat^p
matrix power(matrix mat, int p)
{
    assert(p >= 1);
    if (p == 1)
        return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int32_t main()
{
    int tcase;
    int a, b, n;

    cin >> tcase;
    while (tcase--)
    {
        // input routine
        cin >> n >> a;
        b = a;
        // preparing the matrix
        matrix mat;
        mat.row = mat.col = 2;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;

        if (n < 3)
        {
            if (n == 0)
                cout << a << endl;
            if (n == 1)
                cout << b << endl;
            if (n == 2)
                cout << (a + b) % mod << endl;
        }
        else
        {
            mat = power(mat, n);
            cout << mat.v[0][0] << " " << mat.v[0][1] << endl;
            cout << "a : " << a << endl;
            int ans = (a * mat.v[0][0]) % mod + (a * mat.v[0][1]) % mod;
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}