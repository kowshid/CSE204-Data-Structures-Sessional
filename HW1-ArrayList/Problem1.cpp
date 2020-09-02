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
		show();
	}

	void insertItemAtPos (int a, int pos)
	{
		int i;

		if (tos == maxSize) increaseSize();

		for (i = (tos + 1); i > pos; i--)
		{
			numbers[i] = numbers[i-1];
		}

		numbers[pos] = a;
		tos++;

		show();
	}

	int deleteItem()
	{
		int temp = numbers [tos - 1];
		tos--;

		if (tos == 0)
		{
			cout << "Empty List" << endl;
		}

		else
		{
			show();
		}

		return temp;
	}

	int deleteFirstItem(int a)
	{
		int i;

		for(i = 0; i < tos; i++)
		{
			if (numbers[i] == a) break;
		}

		if (i == tos)
		{
			cout << "Element not Found" << endl;
			return -1;
		}

		for (;i < (tos - 1); i++)
		{
			numbers[i] = numbers[i+1];
		}

		tos--;

		show();

		return a;
	}

	int deleteLastItem(int a)
	{
		int i;

		for(i = (tos - 1); i >= 0; i--)
		{
			if (numbers[i] == a) break;
		}

		if (i < 0)
		{
			cout << "Element not Found" << endl;
			return -1;
		}

		for (;i < (tos - 1); i++)
		{
			numbers[i] = numbers[i+1];
		}

		tos--;

		show();

		return a;
	}

	void clearList()
	{
		delete[] numbers;
		tos = 0;
		maxSize = 10;
		numbers = new int[maxSize];
		cout << "Clear Completed" << endl;
	}

	int searchList(int a)
	{
		int i;

		for (i = 0; i < tos; i++)
		{
			if(numbers[i] == a)
			{
				cout << "Found at position " << i << endl;
				return i;
			}
		}

		if(i == tos)
		{
			cout << "Not Found" << endl;
			return -1;
		}
	}

	void show()
	{
		int i;

		for(i = 0; i < tos; i++)
		{
			cout << numbers[i] << " ";
		}

		cout << endl;
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
	char in, peek, pos;
	int a, position;

	while (true)
	{
		cin >> in;
		if (in == 'I')
		{
			cin >> a;

			peek = cin.peek();

			while (peek == ' ')
			{
				cin.get();
				peek = cin.peek();
			}

			if (peek == '\n')
			{
				arrayList.insertItem(a);
			}

			else
			{
				cin >> position;
				arrayList.insertItemAtPos(a, position);
			}
		}

		if(in == 'D')
		{
			peek = cin.peek();

			while (peek == ' ')
			{
				cin.get();
				peek = cin.peek();
			}

			if (peek == '\n')
			{
				arrayList.deleteItem();
			}

			else
			{
				cin >> pos >> a;

				if (pos == 'F')
				{
					arrayList.deleteFirstItem(a);
				}

				if (pos == 'L')
				{
					arrayList.deleteLastItem(a);
				}
			}
		}

		if (in == 'C')
		{
			arrayList.clearList();
		}

		if(in == 'S')
		{
			cin >> a;

			arrayList.searchList(a);
		}

		if(in == 'T') return 0;
	}
}
