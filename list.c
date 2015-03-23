#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" // Change back to list

aNode* create_list()
{
	aNode* head;
	head = (aNode*)malloc(sizeof(aNode));
	head->value = 0;
	head->next = NULL;
	return head;
}

void add(aNode* head, int x)
{
		aNode* free;

		free = head;
		while(free->next != NULL)
		{
			free = free->next;
		}
		
		free->next = (aNode*)malloc(sizeof(aNode));
		free->next->value = x;
		free->next->next = NULL;		
}

void prettyPrint(aNode* head)
{
	aNode *p = head;
	printf("Your linked list: "); 
	while(p->next != NULL)
	{
		p = p->next;
		printf(" %d ", p->value);
		if(p->next != NULL)
		{
			printf("->");
		}
	}
	printf("\n");
}


BOOLEAN delete(aNode* head, int x)
{
	aNode *previous = NULL;
	aNode *p = head;
	aNode* findNode(int z) 
	{
		while(p != NULL)
        	{
                	if (p->value == z)
                	{
                        	return p;
			}       
               	 	previous = p; 
                	p = p->next;
        	}       
        	return NULL;
	}
	
	aNode *del = findNode(x);

	if(del == NULL)
	{
		return FALSE;
	}
	
	//if first node to be deleted
	if(head->next == del)
	{
		head->next = del->next;
		free(del);
		return TRUE;
	}
	//if last node to be deleted
	if(del->next == NULL)
	{
		free(del);
		previous->next = NULL;
		return TRUE;	
	}
	//if a middle note is to be deleted
	else
	{
		previous->next = del->next;
		free(del);
		return TRUE;
	}
}
