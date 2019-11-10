#include <stdio.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

void printList(struct ListNode *head)
{
	while(head != NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}

	printf("\n");
	return;
}

void reversePrintList(struct ListNode **head)
{
    struct ListNode *prev, *curr,*next;

    if (head == NULL || (*head == NULL))
        return;
    
    prev = *head;
    curr = (*head)->next;
    if (curr == NULL)
    {
		printf("%d", (*head)->data);
		return;
    }
	else
	{
		next = curr->next;
	}

	//反转
	while(next != NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
	}

	curr->next = prev;
	
	(*head)->next = NULL;
	*head = curr;

	while(curr != NULL)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

/* 新建链表，倒序存储原有链表，然后打印 */
void reversePrintList2(struct ListNode *head)
{

}

/* 上述方法不是最好的方法，使用递归最好 */
void recursivelyPrintList(struct ListNode *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		recursivelyPrintList (head->next);

	printf("%d ", head->data);

	return;
}

void main()
{
	struct ListNode *a,b,c,d,e;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;
	a = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	printList (a);
    //reversePrintList (&a);
    recursivelyPrintList (a);
    return;
}
