#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

int main()
{	
	char str[200];
	char nu[200];
	aNode *head = create_list();
	
	FILE *fp;
	printf("Please enter the name of a text file : ");
	scanf("%s",str);
	fp=fopen(str, "r");
	if (fp==NULL)
	{
		 printf("TEST\n");
	}
	else 
	{
		while(fgets(nu, 100, fp)!=NULL)
		{
			int nuint = atoi(nu);
			add(head, nuint);
		}	
		prettyPrint(head);
		
		printf("What number would you like to delete? \n");
		scanf("%s",str);
		
		
		fclose(fp);
	}
	return (0);
}    
