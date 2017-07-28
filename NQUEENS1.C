#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include "c:\turboc3\include\stack.h"

int myIsEmpty(struct myStack *s)
{
if(s->top==-1)
{
return 1;
}
else
{
return 0;
}
}

int myIsFull(struct myStack *s)
{
if(s->top==SIZE-1)
{
return 1;
}
else
{
return 0;
}
}

int myPush(struct myStack *s,int data)
{
if(s->top==SIZE-1)
{
return 0;
}
else
{
s->top=s->top+1;
s->arr[s->top]=data;
return 1;
}
}



int myPop(struct myStack *s,int *data)
{
if(s->top==-1)
{
return 0;
}
else
{
*data=s->arr[s->top];
s->top=s->top-1;
return 1;
}
}

int myPeek(struct myStack *s,int *data)
{
if(s->top==-1)
{
return 0;
}
else
{
*data=s->arr[s->top];
return 1;
}
}
int x,y;
int a[100][100];

int temp(int i,int j,int n){
int b;
int c;
for(b=0;b<n;b++)
{
if(b!=i)
{
a[b][j]=1;
}
}
for(b=0;b<n;b++)
{
if(b!=j)
a[i][b]=1;
}

c=j;
b=i;

while(c<n && b<n)
{
if(b!=i && c!=j)
a[b][c]=1;
b++;
c++;
}

b=i;
c=j;
while(c>=0 && b<n)
{
if(b!=i && c!=j)
a[b][c]=1;
b++;
c--;
}


b=i;
c=j;
while(c<n && b>=0)
{
if(b!=i && c!=j)
a[b][c]=1;
b--;
c++;
}

b=i;
c=j;
while( c>=0 && b>=0)
{
if(b!=i && c!=j)
a[b][c]=1;
b--;
c--;
}

return 1;
}

int temp1(int i,int j,int n){
int b;
int c;
a[i][j]=0;
for(b=0;b<n;b++)
{
if(b!=i)
{
a[b][j]=0;
}
}
for(b=0;b<n;b++)
{
if(b!=j)
a[i][b]=0;
}

c=j;
b=i;

while(c<n && b<n)
{
if(b!=i && c!=j)
a[b][c]=0;
b++;
c++;
}

b=i;
c=j;
while(c>=0 && b<n)
{
if(b!=i && c!=j)
a[b][c]=0;
b++;
c--;
}


b=i;
c=j;
while(c<n && b>=0)
{
if(b!=i && c!=j)
a[b][c]=0;
b--;
c++;
}

b=i;
c=j;
while( c>=0 && b>=0)
{
if(b!=i && c!=j)
a[b][c]=0;
b--;
c--;
}

return 1;
}

int temp2(struct myStack *s,int n){
int cnt=0;
int b[100];
while(!myIsEmpty(s))
{
myPop(s,&y);
myPop(s,&x);
a[x][y]=5;
temp(x,y,n);
b[cnt]=y;
b[cnt+1]=x;
cnt=cnt+2;
}
cnt--;
while(cnt>=0){
myPush(s,b[cnt]);
cnt--;
}
return 1;
}
void far *bitmap1;
int drawqueen(){
   int gdriver=DETECT, gmode, errorcode;
   void far *ptr[4];
   int x,y;
   void far *bitmap=malloc(20);
   /* auto-detect the graphics driver and mode */
   //initgraph(&gdriver, &gmode, "");
   //errorcode = graphresult(); /* check for any errors */
   //if (errorcode != grOk)
   //{
      //printf("Graphics error: %s\n", grapherrormsg(errorcode));
      //printf("Press any key to halt:");
      //getch();
      //exit(1);
   //}

   bitmap1=bitmap;
   for(x=50;x<82;x++)
   putpixel(x,50,15);
   for(x=50;x<82;x++)
   putpixel(x,53,15);
   /*putpixel(50,51,15);
   putpixel(50,52,15);
   putpixel(108,51,15);
   putpixel(108,52,15);*/
   for(y=53;y>=50;y--){
   putpixel(50,y,15);
   putpixel(82,y,15);
   }

   line(50,50,54,30);
   line(54,30,58,50);
   line(58,50,62,30);
   line(62,30,66,50);
   line(66,50,70,30);
   line(70,30,74,50);
   line(74,50,78,30);
   line(78,30,82,50);
   //line(96,50,103,20);
   //line(103,20,108,50);
   circle(54,28,2);
   circle(62,28,2);
   circle(70,28,2);
   circle(78,28,2);
   //circle(103,18,2);
   floodfill(55,49,15);
   floodfill(63,49,15);
   floodfill(70,49,15);
   floodfill(78,49,15);
   floodfill(54,28,15);
   floodfill(62,28,15);
   floodfill(70,28,15);
   floodfill(78,28,15);
   floodfill(52,51,15);
   //floodfill(91,18,15);
   //floodfill(103,18,15);
   getimage(50,26,82,53,bitmap);
   cleardevice();
   //putimage(80,80,bitmap,XOR_PUT);
   //getch();
   return 1;
}
int queen(int x,int y){
x=x-16;
y=y-16;
putimage(x,y,bitmap1,XOR_PUT);
return 1;
}


int display(int x,int y,int num)
{
int max=400/num;
max=max*num;
x=(x*(max/num) + max/(num*2));
y=(y*(max/num) + max/(num*2));
settextstyle(0,0,0);
setcolor(12);
//outtextxy(y,x,"q");
queen(y,x);
return 1;
}
int removequeen(int x,int y,int num)
{
int b;
int max=400/num;
max=max*num;
x=(x*(max/num) + max/(num*2));
y=(y*(max/num) + max/(num*2));
settextstyle(0,0,0);
b=getpixel(x,y);
if(b==WHITE)
{
setcolor(15);
}else{
setcolor(0);

}
//outtextxy(y,x,"q");
queen(y,x);
return 1;
}

int draw(int num)
{
int temp,temp3,cnt;
int max;
int x,y;
int b;
int c,i,j;
//int gdriver=DETECT,gmode,errorcode;

//initgraph(&gdriver,&gmode,"");
//errorcode=graphresult();
//if(errorcode!=grOk)
//{
//printf("%d",errorcode);
//}
//scanf("%d",&num);
max=400/num;
max=max*num;
cleardevice();

rectangle(max,max,1,1);
b=1;
for(c=1;c<=num;c++)
{
for(i=1;i<=max;i++)
{
putpixel(b,i,15);
putpixel(i,b,15);
}
b=b+max/num;
setcolor(15);
settextstyle(8,0,3);
outtextxy(450,25,"moves:");
}


i=j=1;
temp=1;
temp3=1;
cnt=1;

while(temp3<=max)
{
if(cnt%2!=0)
{
temp=1;
}else{
temp=max/num+1;
}
while(temp<=max)
{

for(i=temp;i<=temp+((max/num)-1);i++)
{
for(j=temp3;j<=temp3+((max/num)-1);j++)
{
putpixel(i,j,15);
}
}
temp=temp+(2*(max/num));
}
cnt++;
temp3=temp3+max/num;
}

setcolor(12);
cnt=1;
i=1;

x=y=400/(num*2);
settextstyle(1,0,3);
/*while(y<=400)
{
x=400/(num*2);
while(x<=400)
{
outtextxy(x,y,"q");
x=x+400/num;
}
y=y+400/num;
}*/
//display(1,0,num);
//removequeen(1,0,num);
getch();
//closegraph();
return 1;
}
void main()
{
int d,e;
int n;
int i,j;
int flag;

int b1=1;


while(b1){
int flag1=0;
int x1=450,y1=75;
char string[100];
struct myStack s;



int gdriver=DETECT,gmode,errorcode;
clrscr();
printf("enter the value for n:\t");
scanf("%d",&n);
s.top=-1;
initgraph(&gdriver,&gmode,"");
errorcode=graphresult();
if(errorcode!=grOk)
{
printf("%d",errorcode);
}

drawqueen();
draw(n);
//putimage(5,5,bitmap1,XOR_PUT);
/*a[i][j]=5;
temp(i,j,n);
myPush(&s,i);
myPush(&s,j);


i=1;
j=1;
a[i][j]=5;
temp(i,j,n);
myPush(&s,i);
myPush(&s,j);
temp1(i,j,n);
a[i][j]=0;
temp2(&s,n);*/

for(i=0;i<n && flag1==0;i++){
int j=0;
flag=1;
while(flag){
if(j<n && a[i][j]!=1)
{
//printf("%d\n",i);
//printf("%d\n",j);
myPush(&s,i);
myPush(&s,j);
sprintf(string,"(%d,%d)",i,j);
settextstyle(0,0,0);
setcolor(7);
outtextxy(x1,y1,string);
if(y1!=375)
{
y1+=25;
}else{
x1=x1+50;
y1=75;
}
a[i][j]=5;
display(i,j,n);
getch();
temp(i,j,n);
/*for(d=0;d<n;d++)
{
for(e=0;e<n;e++)
{
printf("%d\t",a[d][e]);
}
printf("\n\n");
}
getch();
clrscr();*/
flag=0;
}
if(j==n)
{
//a[i][j-1]=0;
if(!myIsEmpty(&s))
{
myPop(&s,&j);
//printf("%d\n",j);
myPop(&s,&i);

//printf("%d\n",i);
temp1(i,j,n);
//myPeek(&s,&b1);
//printf("%d\n",b1);
temp2(&s,n);
//myPeek(&s,&b1);
//printf("%d\n",b1);
a[i][j]=0;
removequeen(i,j,n);

setcolor(0);

sprintf(string,"(%d,%d)",i,j);
if(x1!=450 && y1==75){
x1=x1-50;
y1=375;
}else{
y1=y1-25;
}
outtextxy(x1,y1,string);
getch();
/*for(d=0;d<n;d++)
{
for(e=0;e<n;e++)
{
printf("%d\t",a[d][e]);
}
printf("\n\n");
}
getch();
clrscr();*/
}

}

if(myIsEmpty(&s) && j==n){
flag=0;
flag1=1;
}
if(j<n)
j++;
}
}

/*for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n\n");
}*/
if(flag1==0)
{
setcolor(2);
settextstyle(8,0,4);
outtextxy(100,400,"success");

}else{
setcolor(4);
settextstyle(8,0,4);
outtextxy(125,400,"failure");
}
getch();
closegraph();
clrscr();
printf("enter 1 to continue\n");
printf("enter 0 to exit\t");
scanf("%d",&b1);
}
}













