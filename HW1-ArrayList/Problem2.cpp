#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class List {
	int tos;
	int maxSize;
	int *numbers;

public:
	List()
	{
		tos = 0;
		maxSize = 10;
		numbers = new int[maxSize];
	}

	void insertItem (int a)
	{
		if (tos == maxSize) increaseSize();

		numbers[tos++] = a;
//		show();
	}

	int deleteItem()
	{
		int temp = numbers [tos - 1];
		tos--;

		return temp;
	}

	int getTOS ()
	{
		return tos;
	}

	void increaseSize()
	{
        int *temp = numbers;
        maxSize = maxSize*2;
        numbers = new int [maxSize];
        memcpy(numbers, temp, maxSize/2);
        delete[] temp;
	}
};

int main() {
	List arrayList;
	string par;
	int len, i, dif;
	char ch;

	cin >> par;
	len = par.length();

	for(i = 0; i <len; i++)
	{
		if (par[i] == '(' || par[i] == '{' || par[i] == '[')
			{
				arrayList.insertItem(par[i]);
			}
		else if (par[i] == ')' || par[i] == '}' || par[i] == ']')
		{
			ch = arrayList.deleteItem();
			dif = par[i] - ch;
			if(dif > 2 || dif < 1) break;
		}
	}

	if (arrayList.getTOS() == 0)
	{
		cout<<"Balanced"<<endl;
	}
	else
	{
		cout<<"Not Balanced"<<endl;
	}

	return 0;
}
