#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;

void initializeTree()
{
    root = 0;
}

struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}

int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}

int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;

    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
	if(node == 0) return 0;

	if(node->left == 0 && node->right == 0) return 1;

	else return getSize(node->left) + getSize(node->right) + 1;
}

int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    //write your codes here
    if(root == 0) return -1;

    int count = 0;
    struct treeNode *temp = root;

	while(temp->item != node->item)
	{
		if(temp->item < node->item)
		{
			temp = temp->right;
			count++;
		}

		if(temp->item > node->item)
		{
			temp = temp->left;
			count++;
		}
	}

	return count;
}

int calcDepth(int item)//return depth of an item in the tree
{
    //write your codes here
    if(root == 0) return -1;

    struct treeNode * node = 0;

    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeDepth(node);
}

void deleteNode(struct treeNode *temp)
{
	struct treeNode *current = root;
	struct treeNode *temp2;

    while(temp != root && current->left !=temp && current->right !=temp)
	{
		if(current->item < temp->item)
		{
			current = current->right;
		}

		else
		{
			current = current->left;
		}
	}

	if(temp->right == 0)
	{
		if(current->left == temp)
		{
			current->left = temp->left;
		}

		else
		{
			current->right = temp->left;
		}

		free(temp);
	}

	else
	{
		temp2 = temp->right;
		while(temp2->left != 0)
		{
			temp2 = temp2->left;
		}

		int value= temp2->item;
		deleteNode(temp2);
		temp->item=value;
	}
}

int deleteItem(struct treeNode * node, int item)
{
    //write your code here, return TRUE, FALSE

    struct treeNode *temp = searchItem(node, item);
    //struct treeNode *current;
	//struct treeNode *temp2;

    if(temp == 0) return FALSE_VALUE;

    if(temp == root)
	{
		if(temp->right == 0 && temp->left == 0)
		{
			root = 0;
			return TRUE_VALUE;
		}

		else if(temp->right == 0)
		{
			root = root->left;
			free(temp);
			return TRUE_VALUE;
		}

		else if(temp->left == 0)
		{
			root = root->right;
			free(temp);
			return TRUE_VALUE;
		}
	}

    deleteNode(temp);

    return TRUE_VALUE;

//    current = root;
//    while(current->left !=temp && current->right !=temp)
//	{
//		if(current->item < item)
//		{
//			current = current->right;
//		}
//
//		if(current->item > item)
//		{
//			current = current->left;
//		}
//	}
//
//	if(temp->right == 0)
//	{
//		if(current->left == temp)
//		{
//			current->left = temp->left;
//		}
//
//		else
//		{
//			current->right = temp->left;
//		}
//	}
//
//	else
//	{
//		temp2 = temp->right;
//		while(temp2->left != 0)
//		{
//			temp2 = temp2->left;
//		}
//
//		temp->item = temp2->item;
//		free(temp2);
//	}
}

int getMinItem() //returns the minimum item in the tree
{
    //write your codes here
    if(root == 0) return -1;

    struct treeNode *temp = root;

    while (temp->left != 0)
	{
		temp = temp->left;
	}

	return temp->item;
}

int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
    if(root == 0) return -1;

    struct treeNode *temp = root;

    while (temp->right != 0)
	{
		temp = temp->right;
	}

	return temp->item;
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    //write your codes here
    if(node==0) return 0;

	if(node->left == 0 && node->right == 0)
	{
		if(node->item >= leftBound && node->item <= rightBound) return 1;
		else return 0;
	}

	int total = rangeSearch(node->left, leftBound, rightBound) + rangeSearch(node->right, leftBound, rightBound);

	if(node->item >= leftBound && node->item <= rightBound) return total + 1;

	else return total;
}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. 6. PrintInOrder.\n");
        printf("7. Get Size. 8. Get MinItem. 9. Get MaxItem. 10.Range Search.\n");
        printf("11. Calculate Depth of Item. 12. Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }

        else if (ch == 7)
		{
			printf("%d\n", getSize(root));
		}

		else if (ch == 8)
		{
			printf("%d\n",getMinItem());
		}

		else if(ch == 9)
		{
			printf("%d\n", getMaxItem());
		}

		else if(ch == 10)
		{
			int low, high;
			scanf("%d%d", &low, &high);
			printf("%d\n", rangeSearch(root, low, high));
		}

        else if(ch==11)
        {
            int a;
            scanf("%d", &a);
            printf("%d\n", calcDepth(a));
        }

        else if(ch == 12) break;
    }
}
/* 1 50 1 30 1 70 1 60 1 80 1 20 1 40 1 35 1 45 1 15 1 25*/
