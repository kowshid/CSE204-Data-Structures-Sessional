#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;
struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
	tail = 0;
}

struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem (int item) //insert at the beginning of the linked list
{
    struct listNode * newNode ;
    struct listNode *temp;

    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ; //point to previous first node
    list = newNode ; //set list to point to newnode as this is now the first node

    temp = list;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	tail = temp;

    return SUCCESS_VALUE ;
}

//add required codes to delete item, remember to properly set the tail pointer!

int deleteItem(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }

    if (temp == 0) return NULL_VALUE ; //item not found to delete

    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }

    else if(temp  == tail)
	{
		tail = prev;
		prev->next = NULL;
		free(temp);
	}
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
}

int deleteAfter(int item)
{
	if(list == NULL)
	{
		printf("Empty List\n");
		return NULL_VALUE;
	}

	if(list->next == NULL)
	{
		return NULL_VALUE;
	}

	struct listNode * current ;
    struct listNode * temp ;

    temp = list ;
    //current = temp;

    while(temp != NULL)
    {
        current = temp;
        temp = temp->next;
        if(current->item == item) break;
    }

    if(temp == NULL) return NULL_VALUE;

    else
    {
        current->next = temp->next;
        temp->next = NULL;
        free(temp);

        return SUCCESS_VALUE;
    }
}

int insertLast(int item)
{
    //write your codes here
    if(tail == NULL)
	{
		insertItem(item);
		return SUCCESS_VALUE;
	}

    struct listNode * newNode ;

    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    newNode->item = item;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;

    return SUCCESS_VALUE ;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete Item. 3. Search item. \n");
        printf("4. Insert Last. 5. Print. 6. exit. 7.Delete After\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
		{
			int item;
            scanf("%d", &item);
            insertLast(item);
		}
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
		{
			int item;
            scanf("%d", &item);
            deleteAfter(item);
		}
    }
}
