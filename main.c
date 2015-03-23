#include <stdio.h>
#include <stdlib.h>
#include "list.h" //change back to list
#include <string.h>

int main()
{	
	char str[200];
	char nu[200];
	aNode *head = create_list();
	char ans[4] = "yes";
	
	FILE *fp;
	printf("Please enter the name of a text file : \n");
	scanf("%s",str);
	fp=fopen(str, "r");
	while (fp==NULL)
	{
		printf("Invalid filename, please enter the name of a file: \n");
		scanf("%s",str);
       	 	fp=fopen(str, "r");
	}
	while(fgets(nu, 100, fp)!=NULL)
	{
		int nuint = atoi(nu);
		add(head, nuint);
	}	
	fclose(fp);
		
	do 
	{
		prettyPrint(head);
		
		printf("What number would you like to delete? \n");
		int tdel;
		scanf("%d",&tdel);
		BOOLEAN success = delete(head, tdel);
		
		if(success==TRUE)
		{
			printf("NUMBER WAS DELETED\n");
		}
		else
		{
			printf("NUMBER WAS NOT FOUND\n");
		}
		prettyPrint(head);
		printf("Do you want to delete another number? \n");
		scanf("%s",ans);
	
	}while(strcmp(ans,"yes")==0 || strcmp(ans,"y")==0 || strcmp(ans,"YES")==0 || strcmp(ans,"Y")==0);
	return (0);
}    
