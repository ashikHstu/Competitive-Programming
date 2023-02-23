#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, E;
    cin >> R >> E;

    int count = 0;
    double circumference_c2 = 2 * M_PI * R;

    for (int r = 1; r < R; r++)
    {
        double circumference_c1 = 2 * M_PI * r;
        double rotations = circumference_c2 / circumference_c1;
        int overlapping_points = (rotations * circumference_c1) / circumference_c2;

        if (overlapping_points == E)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}