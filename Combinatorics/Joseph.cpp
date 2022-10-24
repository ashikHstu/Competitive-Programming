#include <iostream>
using namespace std;

int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n;

	cout<<"Enter the number of people : ";
	cin>>n;
	n--;
	int k;

	cout<<"Enter the number of people to skip to kill someone : ";
	cin>>k;
    k++;
	cout << "The Safe place is " << josephus(n, k)+1<<endl;
	return 0;
}


