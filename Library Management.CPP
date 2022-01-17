//LIBRARY MANAGEMENT

/***************************************************************************/
//                           HEADER FILES USED
/***************************************************************************/
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
#include<DOS.h>

int count=0;

/***************************************************************************/
//                             CLASSES USED
/***************************************************************************/

class book
{
 protected:
  int bookno;
   char booknm[40];
   char author[30];
   char publication[30];
   int price;
 public:
   void getdata();
   void add();
   void del();
   void modify();
   void search();
   void display();
   void report_1();

   int records();
   int getbno()
{
   return bookno;
}
}
   obj;

class STUDENT
{
 int cls;
 char section;
 char name[30];
 int books_issued;
 int rollno;
  public:
   void input();
   void showdata();
   void adding();
   void deleting();
   void searching();
   void modification();
   void report_2();
   int records1();
   int getrno()
{
   return rollno;
}
}
   obj1;

/**************************************************************************/
//             TO FIND NUMBER OF RECORDS IN A FILE
/**************************************************************************/

int book::records()
{
 int n;
  ifstream fin;
  fin.open("BOOK.txt");
  fin.seekg(0,ios::end);
  n=fin.tellg()/sizeof(obj);
 return n;
}

int STUDENT::records1()
{
 int n;
  ifstream fin;
  fin.open("STUDENT.txt");
  fin.seekg(0,ios::end);
  n=fin.tellg()/sizeof(obj1);
 return n;
}

/**************************************************************************/
//                         FUNCTIONS TO GET DATA
/**************************************************************************/

void book::getdata()
{
 int i,n;
 clrscr();
  cout<<"Enter the Book's number : ";
  cin>>bookno;
  cout<<"Enter the Book's Name : ";
  gets(booknm);
  cout<<"Enter the Author's Name : ";
  gets(author);
  cout<<"Enter the name of the Publication : ";
  gets(publication);
  cout<<"Enter the price of the book : ";
  cin>>price;
}

void STUDENT::input()
{
 int i,n;
 clrscr();
  cout<<"Enter the Class : ";
  cin>>cls;
  cout<<"Enter the Section: ";
  cin>>section;
  cout<<"Enter the Student's Roll Number : ";
  cin>>rollno;
  cout<<"Enter the Student's Name : ";
  gets(name);
  cout<<"Enter the number of books issued to the student : ";
  cin>>books_issued;
}

/**************************************************************************/
//                     FUNCTIONS TO DISPLAY DATA
/**************************************************************************/

void book::display()
{
  cout<<"\n\nBook's number   : ";
  cout<<bookno;
  cout<<"\nBook's Name     : ";
  cout<<booknm;
  cout<<"\nAuthor's Name   : ";
  cout<<author;
  cout<<"\nPublication     : ";
  cout<<publication;
  cout<<"\nPrice           : ";
  cout<<price;
}

void STUDENT::showdata()
{
  cout<<"\n\nClass                 : ";
  cout<<cls;
  cout<<"\nSection               : ";
  cout<<section;
  cout<<"\nStudent's Roll Number : ";
  cout<<rollno;
  cout<<"\nStudent's Name        : ";
  cout<<name;
  cout<<"\nNumber of books issued to the student : ";
  cout<<books_issued;
}

/**************************************************************************/
//                    FUNCTIONS FOR ADDING RECORDS
/**************************************************************************/

void book::add()
{
 fstream fio;
 char ch='y';
   while(ch=='y')
{
	fio.open("BOOK.txt",ios::app);
	getdata();
	fio.write((char*)&obj,sizeof(obj));
	fio.flush();
	fio.close();
	clrscr();
	cout<<"Any more records<<y/n>>-------> : ";
	cin>>ch;
}
}

void STUDENT::adding()
{
 fstream fto;
 char c='y';
   while(c=='y')
{
	fto.open("STUDENT.txt",ios::app);
	input();
	fto.write((char*)&obj1,sizeof(obj1));
	fto.flush();
	fto.close();
	clrscr();
	cout<<"Any more records<<y/n>>-------> : ";
	cin>>c;
}
}

/**************************************************************************/
//                     FUNCTIONS FOR DELETING RECORDS
/**************************************************************************/

void book::del()
{
 fstream fin,fout;
 unsigned long bno;
 clrscr();
 cout<<"Enter the Book No to be deleted : ";
 cin>>bno;
 fin.open("BOOK.txt",ios::in);
 fin.seekg(0);
 fout.open("temp.txt",ios::app);
 fin.read((char*)&obj,sizeof(obj));

  while(!fin.eof())
{
	if(obj.getbno()!=bno)
	fout.write((char*)&obj,sizeof(book));
	fin.read((char*)&obj,sizeof(book));
}
 fin.close();
 fout.close();
 remove("BOOK.txt");
 rename("temp.txt","BOOK.txt");
}

void STUDENT::deleting()
{
 fstream fin,fout;
 unsigned long rno;
 clrscr();
 cout<<"Enter the Roll No of the Student to be deleted :";
 cin>>rno;
 fin.open("STUDENT.txt",ios::in);
 fin.seekg(0);
 fout.open("temp1.txt",ios::app);
 fin.read((char*)&obj1,sizeof(obj1));

  while(!fin.eof())
{
	if(obj1.getrno()!=rno)
	fout.write((char*)&obj1,sizeof(rollno));
	fin.read((char*)&obj1,sizeof(rollno));
}
 fin.close();
 fout.close();
 remove("STUDENT.txt");
 rename("temp1.txt","STUDENT.txt");
}

/**************************************************************************/
//                    FUNCTIONS FOR SEARCHING RECORDS
/**************************************************************************/

void book::search()
{
 clrscr();
 ifstream f;
 book b1;
 char name[50];
 f.open("BOOK.TXT",ios::in|ios::binary);
 cout<<"Enter Book's Name whose record to be seen  : ";
 gets(name);
 do
{
    f.read((char *)&b1,sizeof(b1));
      if(f.eof()==1)
{
      break;
}
    if(strcmp(b1.booknm,name)==0)
{
	 cout<<"\n        Number   : "<<b1.bookno;
	 cout<<"\n        Name     : "<<b1.booknm;
	 cout<<"\n        Author   : "<<b1.author;
	 cout<<"\n        Price    : "<<b1.price;
	 cout<<"\n Publication     : "<<b1.publication;
	 getchar();
}
}
  while(f);
  f.close();
}

void STUDENT::searching()
{
  clrscr();
   ifstream f;
   STUDENT s1;
  char nm[50];
  f.open("STUDENT.txt",ios::in|ios::binary);
  cout<<"Enter Student's Name whose record to be seen  : ";
  gets(nm);
  do
{
     f.read((char *)&s1,sizeof(s1));
       if(f.eof()==1)
{
	  break;
}
       if(strcmp(s1.name,nm)==0)
{
	  cout<<"\n        Class            : "<<cls;
	  cout<<"\n        Section          : "<<section;
	  cout<<"\n        Name             : "<<name;
	  cout<<"\n        Roll No.         : "<<rollno;
	  cout<<"\n        Books Issued     : "<<books_issued;
	  getchar();
}
}
  while(f);
   f.close();
}

/***************************************************************************/
//                           FUNCTIONS TO MODIFY
/***************************************************************************/

void book::modify()
{
 fstream fin,temp;
 int f=0,n1;
 char nm[40],a[30], pb[30];
 int ch1;
 int bno,pri;
 fin.open("BOOK.txt",ios::in|ios::out);
 cout<<"Enter the Book No. for which the updation is to be done : ";
 cin>>bno;

  while(!fin.eof())
{
	n1=fin.tellg();
	fin.read((char *)&obj,sizeof(obj));
	obj.display();
	if(obj.bookno==bno)
{
	   cout<<"\n\nEnter New Book Name : ";
	   gets(nm);
	   cout<<"Enter Author's Name : ";
	   gets(a);
	   cout<<"Enter the Publisher's name : ";
	   gets(pb);
	   cout<<"Enter the price : ";
	   cin>>pri;
	   strcpy(booknm,nm);
	   strcpy(author,a);
	   strcpy(publication,pb);
	   price=pri;
	   fin.seekg(n1);
	   fin.write((char*)&obj,sizeof(obj));
	   fin.flush();
	   f=1;
	   break;
}
}
   if(f==0)
   cout<<"\nNo record with same code exists in the file!!!!";
   fin.seekg(0);
   getch();
   fin.close();
}

void STUDENT::modification()
{
  fstream fin,temp;
  int f=0,n1;
  char naam[40];
  char sec;
  int clss;
  int rno,nbi;
  fin.open("STUDENT.txt",ios::in|ios::out);
  cout<<"Enter the Roll No. for which the updation is to be done : ";
  cin>>rno;

  while(!fin.eof())
{
	n1=fin.tellg();
	fin.read((char *)&obj1,sizeof(obj1));
	obj1.showdata();
	if(obj1.rollno==rno)
{
	   cout<<"\n\nEnter the New Student's Name : ";
	   gets(naam);
	   cout<<"Enter the Student's Class : ";
	   cin>>clss;
	   cout<<"Enter the Section : ";
	   cin>>sec;
	   cout<<"Enter the numbers of books issued to the student : ";
	   cin>>nbi;
	   strcpy(name,naam);
	   cls=clss;
	   section=sec;
	   books_issued=nbi;
	   fin.seekg(n1);
	   fin.write((char*)&obj1,sizeof(obj1));
	   fin.flush();
	   f=1;
	   break;
}
}
   if(f==0)
   cout<<"\nNo record with same code exists in the file!!!!";
   fin.seekg(0);
   getch();
   fin.close();
}

/***************************************************************************/
//                                  REPORTS
/***************************************************************************/

void book::report_1()
{
  clrscr();
  int no,i;
  cout<<"\n\n";
  no=records();
  fstream f;
  f.open("BOOK.txt",ios::in|ios::binary);
  f.seekg(0);
  f.read((char *)&obj,sizeof(obj));
  for(i=1;i<=no;i++)
{
    obj.display();
    f.read((char *)&obj,sizeof(obj)) ;
}
  f.close();
  getch();
}

void STUDENT::report_2()
{
  clrscr();
  int num, i;
  cout<<"\n\n";
  fstream f;
  num=records1();
  f.open("STUDENT.txt",ios::in|ios::binary);
  f.seekg(0);
  f.read((char *)&obj1,sizeof(obj1));
  for(i=1;i<=num;i++)
{
    obj1.showdata();
    f.read((char *)&obj1,sizeof(obj1)) ;
}
  f.close();
  getch();
}

void welcome()
{
 int i;
 int midx, midy;
  setcolor(12);
  rectangle(0,0,getmaxx(),getmaxy()-10);
  rectangle(5,5,getmaxx()-5,getmaxy()-15);
  rectangle(10,10,getmaxx()-10,getmaxy()-20);
  rectangle(15,15,getmaxx()-15,getmaxy()-25);
  rectangle(20,20,getmaxx()-20,getmaxy()-30);
  rectangle(25,25,getmaxx()-25,getmaxy()-35);
  setcolor(9);
  midx = getmaxx() / 2;
  midy = getmaxy() / 2;
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  settextstyle(4,0,6);
  outtextxy(midx, midy-130, "BOOK MANAGEMENT");

  for (i=EMPTY_FILL; i<USER_FILL; i++)
{
     setfillstyle(5, getmaxcolor());
     bar3d(midx-50, midy-50, midx+50,midy+70, 15, 2);
}
     line(midx-35, midy-55, midx+50, midy-55);
     line(midx+60, midy-52, midx+60, midy+55);
     line(midx+55, midy-50, midx+55, midy+62);
  getch();
}

void main()
{
  int choice;
  char ch;
  clrscr();
  int gdriver = DETECT, gmode, errorcode;
  int style, midx, midy;
  initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   errorcode = graphresult();
   if(errorcode != grOk)
{
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
}
   welcome();
   clrscr();
   cleardevice();
      settextstyle(3, HORIZ_DIR, 6);
      outtextxy(310, 100, "MAIN MENU");
      settextstyle(1, HORIZ_DIR, 4);
      outtextxy(310, 200, "A. Book's Records");
      settextstyle(1, HORIZ_DIR, 4);
      outtextxy(310, 250, "B. Student's Records");
      settextstyle(1, HORIZ_DIR, 4);
      outtextxy(310, 350, "Your choice : ");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"                                                    ";
  cin>>ch;
  closegraph();
  if(ch=='a'||ch=='A')
{
  do
{
   clrscr();
   cout<<"\n\n\n                                 Book Menu\n";
   cout<<"\n\n                              1. Add Records\n";
   cout<<"\n                              2. Delete Records\n";
   cout<<"\n                              3. Modify Records\n";
   cout<<"\n                              4. Search Record\n";
   cout<<"\n                              5. Report \n";
   cout<<"\n                              6. Exit and Save\n";
   cout<<"\n\n                              Enter your choice : ";
   cin>>choice;

   switch(choice)
{
    case 1: //adding record
      obj.add();
      break;
    case 2://delete record
      obj.del();
      break;
    case 3://modify record
      obj.modify();
      break;
    case 4://search record
      obj.search();
      break;
    case 5://report
      obj.report_1();
      break;
    case 6:
      cout<<"\n                                Session Ended"<<"\n";
      cout<<"                                  Thank you!";
      break;
}
}
    while
    (choice!=6);
}
  else
  if(ch=='b'||ch=='B')
{
  clrscr();
  do
{
  clrscr();
  cout<<"\n\n\n                                Student Menu\n";
  cout<<"\n\n                              1. Add Records\n";
  cout<<"\n                              2. Delete Records\n";
  cout<<"\n                              3. Modify Records\n";
  cout<<"\n                              4. Search Record\n";
  cout<<"\n                              5. Report \n";
  cout<<"\n                              6. Exit and Save\n";
  cout<<"\n\n                              Enter your choice : ";
  cin>>choice;

  switch(choice)
{
    case 1: //adding record
       obj1.adding();
       break;
    case 2://delete record
       obj1.deleting();
       break;
    case 3://modify record
       obj1.modification();
       break;
    case 4://search record
       obj1.searching();
       break;
    case 5://report
       obj1.report_2();
       break;
    case 6:
       cout<<"\n                                Session Ended"<<"\n";
       cout<<"                                  Thank you!";
       break;
}
}
    while
    (choice!=6);
}
    getch();
}