typedef struct books
{
	int Bookid;
	char Bookname[20];
	char author[20];
	char publication[20];
	int generation;
	int page;
	int price;
	char language[20];
	int edition;
}books;
void storeBook(books*,int);
void displayBook(books*,int);
void search(books*,int);
void update(books*,int);
void deleteB(books*,int*);
