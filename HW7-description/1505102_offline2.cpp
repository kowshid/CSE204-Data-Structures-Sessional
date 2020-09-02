#include <iostream>

using namespace std;

class Schedule
{
public:
	int start;
	int end;
};

void Merge(Schedule arr[], int l, int m, int h)
{
	int length1, length2, i, j, k;

	length1 = m - l + 1;
	length2 = h - m;

	Schedule x[length1], y[length2];

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
		if(x[i].end < y[j].end)
		{
			arr[k] = x[i];
			i++;
		}

		else
		{
			arr[k] = y[j];
			j++;
		}

		k++;
	}

	//one array is empty

	while(i < length1)
	{
		arr[k] = x[i];
		i++;
		k++;
	}

	while(j < length2)
	{
		arr[k] = y[j];
		j++;
		k++;
	}
}

void MergeSort(Schedule arr[], int l, int h)
{
	if (l >= h) return;
	else
	{
		int m = (l+h)/2;

		MergeSort(arr, l, m);
		MergeSort(arr, m+1, h);

		Merge(arr, l, m, h);
	}
}

int main()
{
	int len, t, count = 0;

	cin >> len;

	Schedule temp, a[len], b[len];

	for(int i = 0; i < len; i++)
	{
		cin >> a[i].start >> a[i].end;
	}

	MergeSort(a, 0, len-1);

    cout << endl;

//	for(int i = 0; i < len; i++)
//	{
//		cout << a[i].start << " " << a[i].end << endl;
//	}

	temp = a[0];
	b[count++] = temp;
	t = temp.end;

	for(int i = 1; i < len; i++)
	{
		if(a[i].start >= t)
		{
			temp = a[i];
			t = temp.end;
			b[count++] = temp;
		}
	}

	cout << endl << count << endl;

	for(int i = 0; i < count; i++)
	{
		cout << b[i].start << " " << b[i].end << endl;
	}

	return 0;
}
