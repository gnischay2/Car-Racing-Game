#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

union REGS in,out;
void welcme();                  //for welcome screen of the project
void fr1(int,int,int,int);     //for making a box
void menu();
void gframe();	       //for the fr2 of gameplay
void code();          //main coding for game
int object(int,int);   //calling object
void gover();       //game over

int choice;
void mouseposi(int *xpos,int *ypos,int *click )
	 {

	      in.x.ax=3;
	      int86(51,&in,&out);
	      *click=out.x.bx;
	      *xpos=out.x.cx;
	      *ypos=out.x.dx;
	}


void main()
     {

	 clrscr();
//	 welcme();
	 menu();
	 do{
	 switch(choice)
	    {
	       case 1 :clrscr();
		       code();
		       break;
	       case 2 :clrscr();
		       break;
	       case 3 :clrscr();
		       break;
	       case 4 :clrscr();
		       break;
	       case 5 :
		       exit(1);

	       default: printf("\n\t WRONG OPTION");
	    }
	    }while(1);

      }


void fr1(int R1, int C1, int R2, int C2)
	{

	int row, col;
	for (col=C1; col<=C2; col++)
		{
		gotoxy (col,R1);
		putch(205);
		gotoxy (col,R2);
		putch(205);
		}
	for (row=R1; row<=R2; row++)
		{
		gotoxy (C1,row);
		putch(186);
		gotoxy(C2,row);
		putch(186);
		}
	if (R1!=R2 && C1!=C2)
		{
		gotoxy(C1,R1);putch(201);
		gotoxy(C2,R1);putch(187);
		gotoxy(C1,R2);putch(200);
		gotoxy(C2,R2);putch(188);
		}
	}






void menu()
	{
		       int h;
		       clrscr();
		       textcolor(5);
		       fr1(1,2,24,79);
		       textcolor(5);
		       fr1(3,4,22,77);
		       gotoxy(31,2);
		       textcolor(5);
		       printf("CAR RACE GAME");
		       gotoxy(36,9);
		       textcolor(0);
		       cprintf("MAIN MENU");
		       textcolor(5);
		       fr1(10,30,18,55);
		       gotoxy(35,12);
		       textcolor(1);
		       cprintf("1.");
		       textcolor(8);
		       cprintf("Play Game");
		       gotoxy(35,13);
		       textcolor(1);
		       cprintf("2.");
		       textcolor(8);
		       cprintf("Instruction");
		       gotoxy(35,14);
		       textcolor(1);
		       cprintf("3.");
		       textcolor(8);
		       cprintf("Developer");
		       gotoxy(35,15);
		       textcolor(1);
		       cprintf("4.");
		       textcolor(8);
		       cprintf("Highest Record");
		       gotoxy(35,16);
		       textcolor(1);
		       cprintf("5.");
		       textcolor(8);
		       cprintf("Exit");
		       gotoxy(14,25);
		       textcolor(RED);
		       cprintf ("Press Any Highlighted Key Word To Select Your Choice.... =");
		       scanf("%d",&h);
		       choice=h;

     }



void welcme()
      {
	   int r,c,col;
	   int i, j;
	   clrscr();
	   for (i=0; i<25; i++)
	       {
		   for (j=0; j<80; j++)
		       cprintf(" ");
		   cprintf("\r\n");
		   textcolor(i+1);
		   textbackground(i);
	       }
	   sleep(2);
	   clrscr();
  }

void gframe()
     {
	   int i,a=25,b=3,c=49;
	   clrscr();
	   textbackground(0);
	   textcolor(RED);
	   cprintf("===================||||||||-----> ROAD HUNTER GAME <-----||||||||==============");
	   printf("\n");
	   cprintf("_______________________________________________________________________________");
	   printf("\n");
	   for(i=0;i<22;i++)
		 {
		   gotoxy(a,b);
		   cprintf("]*|");
		   gotoxy(c,b);
		   cprintf("|*[");

		   b++;
		 }
	   printf("\n");
	   cprintf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");


      }


void code()
      {
	    int x1,y1,cl;

	   int x=28,y=4;
	   int p=28,q=4;
	   int r=28,s=4;
	   int i=28;
	   int j=0;
	   char c;
	   textcolor(0);
	   do
	      {

		  if(y+5>17&&x==i)
		     { gover();
			getch();
			exit(1);

		     }
		  if(q+5>17&&p==i)
		     { gover();
		      getch();
		      exit(1);
		     }
		  if(s+5>17&&r==i)
		     { gover();
		       getch();
		       exit(1);
		     }

	       clrscr();
	       gframe();
	       if (j>7)
	       {
		    if(q==17)
		       {  q=4;
			  p=28+(7*(j%3));
		       }
		    textcolor(15);
		    object(p,q);
		    q++;
		}
	   if (j>15)
	      {
		    if(s==17)
		       {  s=4;
			  r=28+(7*((j+1)%3));
		       }
		    textcolor(15);
		    object(r,s);
		    s++;
		}
	   if(y==17)
	     {  y=4;
		x=28+(7*((j+2)%3));
	     }
	   textcolor(15);
//	   object(x,y);
	   y++;



	   textcolor(1);
	   gotoxy(i,18);
	   cprintf("  ^ ^  ");
	   gotoxy(i,19);
	   cprintf("||@*@||");
	   gotoxy(i,20);
	   cprintf("||***||");
	   gotoxy(i,21);
	   cprintf("  ***  ");
	   gotoxy(i,22);
	   cprintf("  ***  ");
	   gotoxy(i,23);
	   cprintf("||***||");
	   gotoxy(i,24);
	   cprintf("||***||");


	  mouseposi(&x,&y,&cl);

	   if(cl==1&&i>34)
	       i=i-7;
	   if(cl==2&&i<36)
	       i=i+7;
	    j++;
	   delay(300) ;

	   }while(!kbhit());


      }



int object(int a,int b)
      {
	 gotoxy(a,b);
	 cprintf("++++++");
	 gotoxy(a,b+1);
	 cprintf("++++++");
	 gotoxy(a,b+2);
	 cprintf("++++++");
	 gotoxy(a,b+3);
	 cprintf("++++++");
	 gotoxy(a,b+4);
	 cprintf("++++++");
	 gotoxy(a,b+4);
	 cprintf("++++++");
	 return 0;
      }

void gover()
     {
	  textcolor(5);
	  fr1(10,30,18,55);
	  gotoxy(40,14);
	  cprintf("GAME OVER");
     }
