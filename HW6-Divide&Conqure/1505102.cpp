//1505102
//Merge Sort and Count Inversion

#include <iostream>

using namespace std;

int Merge(int arr[], int l, int m, int h)
{
	int length1, length2, i, j, k, count = 0;

	length1 = m - l + 1;
	length2 = h - m;

	int x[length1], y[length2]; //two arrays to divide

	for(i = l, j = 0; j < length1; i++, j++)
	{
		x[j] = arr[i];
	}

	for (j = 0; j < length2; i++, j++)
	{
		y[j] = arr[i];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < length1 && j < length2)
	{
		if(x[i] < y[j])
		{
			arr[k] = x[i];
			i++;
			count = count + j;
		}

		else
		{
			arr[k] = y[j];
			j++;
		}

		k++;
	}

	//one array is empty
	//code will enter anyone of the following while loops
	while(i < length1)
	{
		arr[k] = x[i];
		i++;
		k++;
		count += j;
	}

	while(j < length2)
	{
		arr[k] = y[j];
		j++;
		k++;
	}

	return count;
}

int MergeSort(int arr[], int l, int h)
{
	if (l >= h) return 0;

	else
	{
		int m = (l+h)/2, count = 0;

		//divide
		count = MergeSort(arr, l, m);
		count += MergeSort(arr, m+1, h);
		//conquer
		count += Merge(arr, l, m, h);

		return count;
	}
}

int main()
{
	int len;

	cin >> len;

	int a[len], result;

	for(int i = 0; i < len; i++)
	{
		cin >> a[i];
	}

	result = MergeSort(a, 0, len-1);

	for(int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl << result << endl;

	return 0;
}
//5 2 10 8 1 9 4 3 6 7
