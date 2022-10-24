#include<bits/stdc++.h>
using namespace std;


void firstFitAlgo(int allBlockSizes[], int m,
			int allProcessSizes[], int n)
{

	int allocation[n];

	memset(allocation, -1, sizeof(allocation));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (allBlockSizes[j] >= allProcessSizes[i])
			{
				allocation[i] = j;

				allBlockSizes[j] -= allProcessSizes[i];
				break;
			}
		}



	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t"
			<< allProcessSizes[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{

    cout<<"enter the number of block size : ";
    int n,m;
    cin>>n;
    cout<<"Enter the number of process : ";
    cin>>m;
    int allBlockSizes[n+2];
    int allProcessSizes[m+2];
    cout<<"Enter the blocks : "<<endl;

    for(int i=0;i<n;i++)
    {

        cout<<"Enter the "<<i+1<<" no block size : ";
        cin>>allBlockSizes[i];
    }

       cout<<"Enter the processes : "<<endl;

    for(int i=0;i<m;i++)
    {

        cout<<"Enter the "<<i+1<<" no Process size : ";
        cin>>allProcessSizes[i];
    }




	firstFitAlgo(allBlockSizes, n, allProcessSizes, m);

	return 0 ;
}


