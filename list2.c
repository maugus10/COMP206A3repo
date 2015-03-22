#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

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


int delete(aNode* head, int x)
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
                	//break;
			}       
               	 	previous = p; 
                	p = p->next;
        	}       
        	return NULL;
		//p = NULL;
	}
	
	aNode *del = findNode(x);

//	aNode *del = p;
	if(del == NULL)
	{
		printf("NUMBER WAS NOT FOUND\n");
		return 0;
	}
	
	//if first to be deleted
	if(head->next == del)
	{
		head->value = del->next->value;
		head->next = del->next;
		free(del);
		printf("first item ");
		return 1;
	}
	//if last to be deleted
	if(del->next == NULL)
	{
		free(del);
		previous->next = NULL;
		printf("last item ");
		return 1;	
	}
	//if in the middle
	else
	{
		previous->next = del->next;
		free(del);
		printf("NUMBER WAS DELETED\n");
		return 1;
	}
}
