#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Beginning of Implementation
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Parses the string in the linkedList
// If the linked list is head -> |a|->|b|->|c|,
// then toCString function will return "abc"
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    int i = len - 1;
    str[len] = '\0';
    node* current = head;
    while (current != NULL)
    {
        str[i--] = current->letter;
        current = current->next;
    }
    return str;
}

// Inserts character to the linkedlist
// If the linked list is head -> |a|->|b|->|c|,
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = *pHead;
    *pHead = newNode;
}

// Deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    while (*pHead != NULL)
    {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}
// End of Implementation
int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}