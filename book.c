#include<stdio.h>
#include"book.h"
void storeBook(books *arr,int x)
{
    int i,j;
    for(i=0;i<x;i++)
    {
    	printf("\n****************************************\n");
        printf("\n%d BOOK DETAILS: ",(i+1));
        printf("\nEnter the Bookid             :");
        scanf("%d",&arr[i].Bookid);
        for(j=0;j<i;j++)
        {
        	if(arr[i].Bookid==arr[j].Bookid)
        	{
        		printf("\nBook id already exist.\nEnter new book id: ");
        		scanf("%d",&arr[j].Bookid);
        		j=-1;
			}
		}
        fflush(stdin);
        printf("Enter Book Name              :");
        scanf("%[^\n]s",&arr[i].Bookname);
        fflush(stdin);
        printf("Enter Author Name            :");
        scanf("%[^\n]s",&arr[i].author);
        fflush(stdin);
        printf("Enter publication name       :");
        scanf("%[^\n]s",&arr[i].publication);
        printf("Enter Generation of book     :");
        scanf("%d",&arr[i].generation);
        printf("Enter the price of book      :");
        scanf("%d",&arr[i].price);
        fflush(stdin);
        printf("Enter the Language of book   :");
        scanf("%[^\n]s",&arr[i].language);
        printf("Enter the Edition of book    :");
        scanf("%d",&arr[i].edition);
        printf("Enter Pages of book          :");
        scanf("%d",&arr[i].page);
    }
    printf("\n****************************************\n");
}
void displayBook(books *arr, int y) 
{
    int i;
    printf("\n\n***************INFORMATION OF STORED BOOK***************\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("BOOK ID\t | BOOK NAME \t\t| AUTHOR NAME\t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0;i<y;i++)
	{
        printf("%-9d| %-21s| %-22s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookid, arr[i].Bookname, arr[i].author, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void search(books *arr, int z)
{
    int ch, i, id;
    char name[20],authorb[20],sa;
    int found;
    do
    {
        found=0;
        printf("\nDo you want to search for a book? Y/N: ");
        scanf(" %c",&sa);
        if(sa=='y'||sa=='Y')
        {
            printf("\nEnter 1 to search by book id.");
            printf("\nEnter 2 to search by book name.");
            printf("\nEnter 3 to search by author name.");
            scanf("%d", &ch);
            if(ch==1)
            {
                printf("\nEnter the book id you want to search: ");
                scanf("%d",&id);
                for(i=0;i<z;i++)
                {
                    if(arr[i].Bookid == id)
                    {
                    	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("BOOK NAME \t\t| AUTHOR NAME\t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
                        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("%-24s| %-22s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookname, arr[i].author, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
                        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        found = 1;
                        break;
                    }
                }
            }
            if(ch==2)
            {
            	fflush(stdin);
                printf("\nEnter the book name you want to search: ");
                scanf("%[^\n]s",&name);
                for(i=0;i<z;i++)
                {
                    if(strcasecmp(arr[i].Bookname, name)==0)
                    {
                    	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("BOOK ID\t | AUTHOR NAME\t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
                        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("%-9d| %-21s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookid, arr[i].author, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
                        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        found = 1;
                        break;
                    }
                }
            }
            else if(ch==3)
            {
            	fflush(stdin);
                printf("\nEnter the author name you want to search: ");
                scanf(" %[^\n]s",&authorb);
                for(i=0;i<z;i++)
                {
                    if(strcasecmp(arr[i].author, authorb)==0)
                    {
                    	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("BOOK ID\t | BOOK NAME \t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
                        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        printf("%-9d| %-21s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookid, arr[i].Bookname, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
                        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        found = 1;
                        break;
                    }
                }
            }
            if(found==0)
            {
                printf("\nBook not found Try again!!!\n");
            }
        }
        if(sa=='n'||sa=='N')
        {
            printf("\nExit from searching menu.");
            break; 
        }
    }while(sa=='y');
}
void update(books *arr, int w)
{
    int i,j,ch,id,flag=0;
    char sa;
    char name[20];
    for(i=0;i<w;i++)
    {
        printf("*******************************************\n");
        printf("Do you want to update the book? Y/N: ");
        scanf(" %c",&sa);
        if(sa=='Y'||sa=='y')
        {
            printf("Enter the book id that you want to update the book: ");
            scanf("%d",&id); 
                if(arr[i].Bookid==id)
                {
            	    flag=1;
                    printf("\nEnter 1 to update the book name.\n");
                    printf("Enter 2 to update the author name.\n");
                    printf("Enter 3 to update the publication.\n");
                    printf("Enter 4 to update the generation.\n");
                    printf("Enter 5 to update the pages.\n");
                    printf("Enter 6 to update the price.\n");
                    printf("Enter 7 to update the language.\n");
                    printf("Enter 8 to update the edition.\n");
                    scanf("%d",&ch);
                    if(ch==1)
                    {
                	    fflush(stdin);
                        printf("Enter the new book name: ");
                        scanf("%[^\n]s",&arr[i].Bookname);
                    }
                    else if(ch==2)
                    {
                	    fflush(stdin);
                        printf("Enter the new author name: ");
                        scanf("%[^\n]s",&arr[i].author);
                    }
                    else if(ch==3)
                    {
                	    fflush(stdin);
                        printf("Enter the new publication name: ");
                        scanf("%[^\n]s",&arr[i].publication);
                    }
                    else if(ch==4)
                    {
                        printf("Enter the new generation of book: ");
                        scanf("%d",&arr[i].generation);
                    }
                    else if(ch==5)
                    {
                        printf("Enter the new pages of book: ");
                        scanf("%d",&arr[i].page);
                    }
                    else if(ch==6)
                    {
                        printf("Enter the new price of book: ");
                        scanf("%d",&arr[i].price);
                    }
                    else if(ch==7)
                    {
                	    fflush(stdin);
                        printf("Enter the new language of book: ");
                        scanf("%[^\n]s",&arr[i].language);
                    }
                    else if(ch==8)
                    {
                        printf("Enter the new edition of book: ");
                        scanf("%d",&arr[i].edition);
                    }
                    else 
                    {
                        printf("\nInvalid choice.\n");
                        break;
                    }
                }
            }
        if(sa=='N'||sa=='n')
        {
            printf("\nExit\n");
            break;
        }
        if((sa!='Y'||sa!='y')&&(sa!='n'||sa!='N'))
        {
            printf("\nInvalid choice.\n");
            continue;
        }
    }
        for(i=0;i<w;i++)
        {
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("BOOK ID\t | BOOK NAME \t\t| AUTHOR NAME\t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for(i=0;i<w;i++)
     	    {
                printf("%-9d| %-21s| %-22s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookid, arr[i].Bookname, arr[i].author, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
            }
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
}
void deleteB(books *arr,int *l)
{
    int id;
    int i,j;
    char sa;
    int found=0; 
    printf("\nEnter the book id to delete it detail: ");
    scanf("%d",&id);
    for(i=0;i<*l;i++)
    {
    	if(arr[i].Bookid==id)
    	{
    		found=1;
    		for(j=i;j<*l;j++)
    		{
    			arr[j]=arr[j+1];
			}
		}
	}
	if(found==1)
	{
		*l=*l-1;
	}
	else
	{
		printf("\nRecord not found.");
	}
	for(i=0;i<*l;i++)
	{
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("BOOK ID\t | BOOK NAME \t\t| AUTHOR NAME\t\t| PUBLICATION NAME\t| BOOK GENERATION\t| BOOK PRICE\t| BOOK LANGUAGE\t\t| BOOK EDITION\t| BOOK PAGES\t|\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for(i=0;i<*l;i++)
	    {
            printf("%-9d| %-21s| %-22s| %-22s| %-22d| %-14d| %-22s| %-14d| %-14d|\n",arr[i].Bookid, arr[i].Bookname, arr[i].author, arr[i].publication,arr[i].generation, arr[i].price, arr[i].language, arr[i].edition, arr[i].page);
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	printf("\nRecord deleted successfully");
}

