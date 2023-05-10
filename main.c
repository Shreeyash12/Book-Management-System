#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.c"
void main()
{
    int n=0, ch;
    books *ptr;
    printf("\t\t\t********** BOOK MANAGEMENT SYSTEM **********\t\t\n");
    do{
        printf("\n Menu: \n1.)Store\n2.)Display\n3.)Search\n4.)Update\n5.)Delete\n6.)Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\nPlease enter number of books you want: ");
            scanf("%d",&n);
            ptr=(books*)malloc(sizeof(books)*n);
            storeBook(ptr,n);
            break;
        case 2:
            if(n==0) 
			{
                printf("\nNo books are currently stored.\n");
            }
            else
			{
                displayBook(ptr,n);
            }
            break;
        case 3:
            if(n==0) 
			{
                printf("\nNo books are currently stored.\n");
            }
            else 
			{
                search(ptr,n);
            }
            break;
        case 4:
            if(n==0) 
			{
                printf("\nNo books are currently stored.\n");
            }
            else
			{
                update(ptr,n);
            }
            break;
        case 5:
            if(n==0)
			{
                printf("\nNo books are currently stored.\n");
            }
            else
			{
                deleteB(ptr,&n);
                free(ptr);
            }
            break;
        case 6:
            printf("\nExit.");
            break;
        default:
            printf("\nInvalid choice.");
        }
    }while(ch!=6);
}
