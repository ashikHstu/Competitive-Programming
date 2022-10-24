
#include <bits/stdc++.h>
using namespace std;
int numberOfMove=0;
void towerOfHanoi(int n, char from_rod,
					char to_rod, char aux_rod)
{
	if (n == 0)
	{
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod <<
								" to rod " << to_rod << endl;
    numberOfMove++;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}


int main()
{


	int n;

	cout<<"Enter the number of disk : ";
	cin>>n;


	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

	cout<<"\nTotal Number of Move : "<<numberOfMove<<endl<<endl;


	return 0;
}

