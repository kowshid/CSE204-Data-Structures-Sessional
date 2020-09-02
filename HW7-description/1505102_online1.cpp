#include<stdio.h>
#include<iostream>

#define MAX_HEAP_SIZE 100000

#define MAXREAL 999999.0

using namespace std;

class HeapItem
{
public:
	char data;
	int frequency;
	HeapItem *left;
	HeapItem *right;
};

class MinHeap
{
public:
	HeapItem ** A;
	int heapLength;
	char way[6];

	MinHeap()
	{
		A = new HeapItem*[MAX_HEAP_SIZE];
		heapLength=0;
	}

	~MinHeap()
	{
		if(A) delete [] A;
		A = 0;
	}

    void insertItem(char data, int frequency)
    {
        HeapItem *temp;
        temp = new HeapItem;
        temp->data = data;
        temp->frequency = frequency;
        temp->left = 0;
        temp->right = 0;

        A[++heapLength] = temp;

        buHeapify(heapLength);
    }

	HeapItem* removeMin()
	{
		HeapItem *temp;
		temp = new HeapItem;
		temp = A[1];
		A[1] = A[heapLength];
		heapLength--;
		heapify(1);

		return temp;
	}


	void heapify(int i)
	{
		int l,r,smallest;
		while(1)
		{
			l=2*i;
			r=2*i+1;
			smallest=i;

			if(l>heapLength && r>heapLength)
				break;
			else if(r>heapLength)
				smallest = l;
			else if(l>heapLength)
				smallest = r;
			else if( A[l]->frequency < A[r]->frequency )
				smallest = l;
			else
				smallest = r;

			if(A[i]->frequency <= A[smallest]->frequency)
				break;
            else
			{
				HeapItem *t;
				t=A[i];
				A[i]=A[smallest];
				A[smallest]=t;
				i=smallest;
			}

		}
	}

	void buHeapify(int i)
	{
		while(i > 1)
		{
			HeapItem *temp;
			int p;
			p = i/2;
			if(A[p]->frequency > A[i]->frequency)
			{
				temp = A[p];
				A[p] = A[i];
				A[i] = temp;
			}

			i = p;
		}
	}

    void printHeap()
    {
        printf("Heap length: %d\n", heapLength);
        for(int i=1;i<=heapLength;i++)
        {
            printf("(%c,%d) ", A[i]->data, A[i]->frequency);
        }
        printf("\n");
    }

	bool Empty()
	{
		if(heapLength==0)return true;
		else return false;
	}

	void traverse(HeapItem *h, int level)
	{
		if(h->left == 0 && h->right == 0)
		{
			way[level] = '\0';
			cout << h->data << " " << way << endl;
			return;
		}

		way[level] = '0';
		traverse(h->left, level+1);
		way[level] = '1';
		traverse(h->right, level+1);

	}

	void huffman()
	{
		while(heapLength > 1)
		{
			HeapItem *t = new HeapItem;
			t->left = removeMin();
			t->right = removeMin();
			t->frequency = t->left->frequency + t->right->frequency;
			A[++heapLength] = t;

			buHeapify(heapLength);
		}

		cout << endl;
		traverse(removeMin(), 0);
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	MinHeap heap;
	char ch;
	int id;

	for(int i = 0; i < n; i++)
	{
		cin >> ch >> id;
		heap.insertItem(ch, id);
	}

	//heap.printHeap();
	heap.huffman();
	//heap.printHeap();

    return 0;
}
