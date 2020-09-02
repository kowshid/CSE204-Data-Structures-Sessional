#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class SortedList
{
    int tos;
    int maxSize;
    int *numbers;

public:
    SortedList()
    {
        tos = 0;
        maxSize = 10;
        numbers = new int[maxSize];
    }

//    void sortList()
//    {
//        int i, j, temp;
//
//        for(i = 0; i < (tos - 1); i++)
//        {
//            for(j = (i + 1); j < tos; j++)
//            {
//                if(numbers[i] > numbers[j])
//                {
//                    temp = numbers[i];
//                    numbers[i] = numbers[j];
//                    numbers[j] = temp;
//                }
//            }
//        }
//    }

//    void insertItem (int a)
//    {
//        if (tos == maxSize) increaseSize();
//
//        numbers[tos++] = a;
//        sortList();
//        show();
//    }

    void insertItem (int a)
    {
        int i, j;

		if(tos == 0)
		{
			numbers[tos++] = a;
			show();
		}
        else if (tos == maxSize) increaseSize();

		else if(a >= numbers[tos - 1])
        {
            numbers[tos++] = a;

            show();
        }
        else
        {
            for(i = (tos - 1); i >= 0; i--)
            {
                if(a < numbers[i])
                {
                    //pos = i;
                    for (j = tos; j > i; j--)
                    {
                        numbers[j] = numbers[j-1];
                    }

                    numbers[i] = a;
                    tos++;

                    show();
                    break;
                }
            }
        }
    }

    int deleteItem(int a)
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

        for (; i < (tos - 1); i++)
        {
            numbers[i] = numbers[i+1];
        }

        tos--;

        if(tos == 0)
		{
			cout << "List has become Empty" << endl;
		}

        else show();

        return a;
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

int main()
{
    SortedList arrayList;
    char in;
    int a;

    while (true)
    {
        cin >> in;

        if (in == 'I')
        {
            cin >> a;
            arrayList.insertItem(a);
        }

        if (in == 'D')
        {
            cin >> a;
            arrayList.deleteItem(a);
        }

        if (in == 'F')
        {
            cin >> a;
            arrayList.searchList(a);
        }

        if (in == 'T') return 0;
    }
}
