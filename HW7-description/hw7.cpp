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
	int * map;
	char way[6];

	MinHeap() //constructor
	{
		A = new HeapItem*[MAX_HEAP_SIZE];
		map = new int[MAX_HEAP_SIZE];
		heapLength=0;
	}

	~MinHeap() //destructor
	{
		if(map) delete [] map;
		if(A) delete [] A;
		map = 0; //set to NULL after deletion
		A = 0; //set to NULL after deletion
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
        map[data] = heapLength;

        buHeapify(heapLength);
    }

    //this function removes (and returns) the node which contains the minimum frequency value
	HeapItem* removeMin()
	{
	    //write your codes here
		HeapItem *temp;
		temp = new HeapItem;
		temp = A[1];
		A[1] = A[heapLength];
		heapLength--;
		heapify(1);

		return temp;
	}


    //The function updates the frequency value of an existing data
    //stored in the heap
	//Note that updates can result in an increase or decrease of frequency value
	//Call to heapify or buheapify is required
	void updateFrequency(char data, int frequency)
	{
		//Write your codes here.
		int i = map[data];
		int temp = A[i]->frequency;
		A[i]->frequency = frequency;

		if(temp < frequency) heapify(i);
		else buHeapify(i);
	}

    //This function returns the frequency value of a data stored in heap
	float getfrequency(char data)
	{
		int i = map[data];
		return A[i]->frequency;
	}

    //This function heapifies the heap
    //When a frequency value of ith node is increased (because of update), then calling
    //this function will restore heap property
	void heapify(int i)
	{
		int l,r,smallest;
		while(1)
		{
			l=2*i;      //left child index
			r=2*i+1;    //right child index
			smallest=i;

			if(l>heapLength && r>heapLength)
				break; //nothing to do, we are at bottom
			else if(r>heapLength)
				smallest = l;
			else if(l>heapLength)
				smallest = r;
			else if( A[l]->frequency < A[r]->frequency )
				smallest = l;
			else
				smallest = r;

			if(A[i]->frequency <= A[smallest]->frequency)
				break;	//we are done heapifying
            else
			{
                //swap nodes with smallest child, adjust map array accordingly
				HeapItem *t;
				t=A[i];
				A[i]=A[smallest];
				map[A[i]->data]=i;
				A[smallest]=t;
				map[A[smallest]->data]=smallest;
				i=smallest;
			}

		}
	}

    //This function heapifies the heap form bottom to up
    //When a frequency value of ith node is decreased (because of update), then calling
    //this function will restore heap property
    //In addition, when a new item is inserted at the end of the heap, then
    //calling this function restores heap property
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
				map[A[p]->data] = p;
				A[i] = temp;
				map[A[i]->data] = i;
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
