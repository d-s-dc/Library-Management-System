#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count = 0;		//Total no. of unique books

void re_turn(FILE *fptr)
{
int c,tc;
char arr[20],temp[100];
char *p;
printf("Enter the book title: ");
scanf("%s",arr);
int s = strlen(arr);
fgets(temp,100,fptr);
fgets(temp,100,fptr);
while(!feof(fptr))
{
fgets(temp,100,fptr);
p = &temp[13];
if(!strcmp(p,arr))
break;
for(int t=0;t<6;t++)
fgets(temp,100,fptr);
}
for(int t=0;t<3;t++)
fgets(temp,100,fptr);
p = &temp[25];
tc = atoi(p);		//total number of books available
fgets(temp,100,fptr);
p = &temp[29];
c = atoi(p);
c++;
if(c>tc)		//checking if count > total books
{
printf("Exceeding total number of books\n");
return;
}
fseek(fptr, -strlen(arr), SEEK_CUR);
fputs("Number of copies available - ",fptr);
fprintf(fptr,"%d\n",c);
}

void issue(FILE *fptr)
{
int c;
char arr[20],temp[100];
char *p;
printf("Enter the book title: ");
scanf("%s",arr);
int s = strlen(arr);
fgets(temp,100,fptr);
fgets(temp,100,fptr);
while(!feof(fptr))
{
fgets(temp,100,fptr);
p = &temp[13];
printf("temp - %s p -%s\n",temp,p);
if(!strcmp(p,arr))
break;
for(int t=0;t<6;t++)
fgets(temp,100,fptr);
}
for(int t=0;t<4;t++)
fgets(temp,100,fptr);
p = &temp[29];
c = atoi(p);
c--;
fseek(fptr, -strlen(arr), SEEK_CUR);
fputs("Number of copies available - ",fptr);
fprintf(fptr,"%d\n",c);
}

void search(FILE *fptr)
{
char arr[20],temp[100];
char *p;
printf("Enter the characters: ");
scanf("%s",arr);
int s = strlen(arr);
fgets(temp,100,fptr);
fgets(temp,100,fptr);
while(!feof(fptr))
{
fgets(temp,100,fptr);
p = &temp[13];
int t=0;
while(arr[t]!='\0')
{
if(arr[t]!=p[t])
break;
t++;
}
if(arr[t]=='\0')
printf("%s",p);
for(int t=0;t<6;t++)
fgets(temp,100,fptr);
}
}

void Add(FILE *fptr,FILE *fr)
{
char *ar[] = {"BookID - ", "Book Title - ", "Publisher - ", "Author Name - ", "Total Number of Copies - ", "Number of copies available - "};
char bt[100],p[100],an[100],arr[100];
int c;		//to store number of copies
printf("%s",ar[1]);
scanf(" %[^\n]",bt);
printf("%s",ar[2]);
scanf(" %[^\n]",p);
printf("%s",ar[3]);
scanf(" %[^\n]",an);
printf("%s",ar[4]);
scanf(" %d",&c);

int ch;		//checker
char *ptr;
fgets(arr,100,fr);
while(!feof(fr))
{
ch = 0;
fgets(arr,100,fr);
fgets(arr,100,fr);
ptr = &arr[13];
printf("%s\n",ptr);
if(strcmp(ptr,bt) == 0)
ch++;
fgets(arr,100,fr);
ptr = &arr[12];
if(strcmp(ptr,p) == 0)
ch++;
fgets(arr,100,fr);
ptr = &arr[14];
if(strcmp(arr,an) == 0)
ch++;

if(ch == 3)
{
printf("Book already there\n");
fgets(arr,100,fr);
ptr = arr;
for(int t =0;t<25;t++)
ptr++;
c += atoi(ptr);
fseek(fr, -strlen(arr), SEEK_CUR);
fputs(ar[4],fr);
fprintf(fr,"%d\n",c);

fgets(arr,100,fr);
ptr = arr;
for(int t =0;t<29;t++)
ptr++;
fseek(fr, -strlen(arr), SEEK_CUR);
fputs(ar[5],fr);
fprintf(fr,"%d\n",c);
return ;
}

for(int t=0;t<3;t++)
fgets(arr,100,fr);
}

fputc('\n',fptr);
fputs(ar[0],fptr);		//printing "BookID" to file
count++;			//generating id
fprintf(fptr,"%d\n",count);	//printing id to file

fputs(ar[1],fptr);		//printing "Book Title" to file
fprintf(fptr,"%s\n",bt);	//printing it to file

fputs(ar[2],fptr);
fprintf(fptr,"%s\n",p);

fputs(ar[3],fptr);
fprintf(fptr,"%s\n",an);

fputs(ar[4],fptr);
fprintf(fptr,"%d\n",c);

fputs(ar[5],fptr);
fprintf(fptr,"%d\n",c);
}

void main()
{
int c;		//choice
FILE *f1,*f2;
do
{
printf("What do you want to do\n1) Add a book\n2) Search for a book\n3) Issue a book\n4) Return\n5) Exit\n");
scanf("%d",&c);
if(c==5)
continue;
switch(c)
{
case 1: f1 = fopen("Library.txt","w");
f2 = fopen("Library.txt","r+");
\\Add(f1,f2);
fclose(f1);
fclose(f2);
break;
case 2: f1 = fopen("Library.txt","r");
search(f1);
fclose(f1);
break;
case 3: f1 = fopen("Library.txt","r");
issue(f1);
fclose(f1);
break;
case 4: f1 = fopen("Library.txt","r");
re_turn(f1);
fclose(f1);
break;
}
}while(c!=5);

}
