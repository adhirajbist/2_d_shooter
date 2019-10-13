#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>

//function for menu
menu()
{
 int i,ch;
 char ch1,ch2;
 gotoxy(30,5);
 cprintf("Ship Ultimatum");
 while(ch1!='\r')
 {
  gotoxy(25,10);
  cout<<"PRESS ENTER TO CONTINUE";
  for(i=30;i<44;i++)
  {
   gotoxy(i,6);
   cout<<"*";
   delay(55);
   cout<<"  ";
  }
  if(kbhit())
  ch1=getch();
 }
 clrscr();
 gotoxy(30,5);
 cprintf("Ship Ultimatum");
 cout<<"\n\n\n\t1> PLAY GAME\n\n\t2> HELP\n\n\t3> exit";
 cout<<"\n\n\tEnter choice:  ";
 cin>>ch;

 switch(ch)
 {
  case 1: break;
  case 2: clrscr();
	  cout<<"CONTROLS:";
	  cout<<"\n\nPress 'A' to move left and 'D' to move right.";
	  cout<<"\n\nPress 'S' to stop your ship.";
	  cout<<"\n\nPress 'W' to shoot.";
	  cout<<"\n\nPress 'Q' to exit whenever you want to.";
	  cout<<"\n\n\n\nDisplay:";
	  cout<<"\nOn the upper right side of the screen enemy's health will be shown";
	  cout<<"\nand on the lower right side of the screen your health.";
	  cout<<"\n\n\n\n\n\tEnter 'P' to play or any other key to exit the game";
	  cout<<"\n\nEnter choice: ";
	  cin>>ch2;

	  switch(ch2)
	  {
	   case 'p': clrscr();
		     break;
	   case 'P': clrscr();
		     break;
	   default: cout<<"Exiting....";
		    delay(2000);
		    exit(0);
		    break;
	  }
	  break;
  case 3: cout<<"\n\nExiting....";
	  delay(2000);
	  exit(0);
	  break;
  default: cout<<"\n\nERROR: INVALID CHOICE";
	   cout<<"\nExiting....";
	   delay(2000);
	   exit(0);
	   break;
 }
}

main()
{
 clrscr();
 int ch2,p=74,e=73,i,enemy=36,ship=36,bullet=22,temp,temp2,dir=1,count=0,bullet2=3;
 char ch;

 menu();                              //calling menu funtion to display menu
 clrscr();
 //BORDER
 for (i=1;i<=80;i++)
 {
  gotoxy(i,1);
  cout<<"#";
  gotoxy(i,24);
  cout<<"#";
 }

 for (i=1;i<=24;i++)
 {
  gotoxy(1,i);
  cout<<"#";
  gotoxy(80,i);
  cout<<"#";
 }
 //BORDER MADE

 //Enemy health
 gotoxy (52,1);
 cout<<"                         ";
 gotoxy (53,1);
 cout<<"Enemy Health: ";
 gotoxy (68,1);
 cout<<"------";

 //Player health
 gotoxy (52,24);
 cout<<"                         ";
 gotoxy (53,24);
 cout<<"Player Health: ";
 gotoxy (69,24);
 cout<<"------";

 //Starting display
 gotoxy(enemy,2);
 cout<<"<========>";
 gotoxy(ship,23);
 cout<<"<___||___>";
 ch=getch();
 if((ch=='a')||(ch=='A'))
  dir=2;
   else if((ch=='d')||(ch=='D'))
    dir=1;


 //Main coding begins!!

//when no one is shooting
a: while((ch!='q')&&(ch!='Q'))
 {

  //make ships
  gotoxy(enemy,2);
  cout<<"<========>";
  gotoxy(ship,23);
  cout<<"<___||___>";

  delay(55);

  //erase ships
  gotoxy(enemy,2);
  cout<<"          ";
  gotoxy(ship,23);
  cout<<"          ";

  //movement of enemy ship
  if(dir==1)
  {
   enemy--;
  }
  if (dir==2)
  {
   enemy++;
  }

  if(enemy==1)
  {
   enemy=2;
   dir=2;
  }
  if(enemy==71)
  {
   dir=1;
   enemy=70;
  }

  count++;
  if (count%10==0)
  {
   temp2=enemy+4;
   goto b;
  }

  if(kbhit())
  ch=getch();

   if((ch=='a')||(ch=='A'))
   {
    if(ship>2)
     ship-=2;
   }
   if((ch=='d')||(ch=='D'))
   {
    if(ship<70)
     ship+=2;
   }

   if((ch=='w')||(ch=='W'))
   {
     temp=ship+4;
     if(count%10==0)
     {
      temp2=enemy+4;
      goto b;
     }
      else
       break;
   }
 }

//when player shoots bullet
c: while((ch!='q')&&(ch!='Q'))
 {

  //make ships
  gotoxy(enemy,2);
  cout<<"<========>";
  gotoxy(ship,23);
  cout<<"<___||___>";

  //make bullet
  gotoxy(temp,bullet);
  cout<<"||";

  delay(55);

  //erase ships
  gotoxy(enemy,2);
  cout<<"          ";
  gotoxy(ship,23);
  cout<<"          ";

  //erase bullet
  gotoxy(temp,bullet);
  cout<<"  ";

  //If player's bullet hits enemy
  if ((bullet==2)&&(temp>=enemy)&&(temp<=enemy+9))
  {
   if (e==67)
   {
    gotoxy(33,10);
    cout<<"YOU WON!!!";
    gotoxy(27,12);
    cout<<"Press any key to exit";
    getch();
    exit(0);
   }
    else
    {
     gotoxy(e,1);
     cout<<" ";
     e=e-1;
    }
  }

  //movement of bullet
  bullet--;
   if (bullet==1)
   {
    bullet=22;
    goto a;
   }

  //count
  count++;
  if (count%10==0)
  {
   temp2=enemy+4;
   goto d;
  }

  //movement of enemy ship
  if(dir==1)
  {
   enemy--;
  }
  if (dir==2)
  {
   enemy++;
  }

  if(enemy==1)
  {
   enemy=2;
   dir=2;
  }
  if(enemy==71)
  {
   dir=1;
   enemy=70;
  }


  if(kbhit())
  ch=getch();

   if((ch=='a')||(ch=='A'))
   {
    if(ship>2)
     ship-=2;
   }
   if((ch=='d')||(ch=='D'))
   {
    if(ship<70)
     ship+=2;
   }

 }

//when enemy shoots bullet
b: while((ch!='q')&&(ch!='Q'))
 {

  //make ships
  gotoxy(enemy,2);
  cout<<"<========>";
  gotoxy(ship,23);
  cout<<"<___||___>";

  //make bullet2
  gotoxy(temp2,bullet2);
  cout<<"[]";

  delay(55);

  //erase ships
  gotoxy(enemy,2);
  cout<<"          ";
  gotoxy(ship,23);
  cout<<"          ";

  //erase bullet2
  gotoxy(temp2,bullet2);
  cout<<"  ";

  //If enemy's bullet hits player
  if ((bullet2==23)&&(temp2>=ship)&&(temp2<=ship+9))
  {
   if (p==68)
   {
    gotoxy(33,10);
    cout<<"YOU LOST";
    gotoxy(27,12);
    cout<<"Press any key to exit";
    getch();
    exit(0);
   }
    else
    {
     gotoxy(p,24);
     cout<<" ";
     p=p-1;
    }
  }

  //movement of bullet2
   bullet2++;
   if (bullet2==24)
   {
    bullet2=3;
    goto a;
   }

  //movement of enemy ship
  if(dir==1)
  {
   enemy--;
  }
  if (dir==2)
  {
   enemy++;
  }

  if(enemy==1)
  {
   enemy=2;
   dir=2;
  }
  if(enemy==71)
  {
   dir=1;
   enemy=70;
  }

  if(kbhit())
  ch=getch();

   if((ch=='a')||(ch=='A'))
   {
    if(ship>2)
     ship-=2;
   }
   if((ch=='d')||(ch=='D'))
   {
    if(ship<70)
     ship+=2;
   }

   if((ch=='w')||(ch=='W'))
   {
     temp=ship+4;
     break;
   }
 }

//when enemy's and player's bullet are on the screen
d: while((ch!='q')&&(ch!='Q'))
 {

  //make ships
  gotoxy(enemy,2);
  cout<<"<========>";
  gotoxy(ship,23);
  cout<<"<___||___>";

  //make bullet
  gotoxy(temp,bullet);
  cout<<"||";

  //make bullet2
  gotoxy(temp2,bullet2);
  cout<<"[]";

  delay(55);

  //erase ships
  gotoxy(enemy,2);
  cout<<"          ";
  gotoxy(ship,23);
  cout<<"          ";

  //erase bullet
  gotoxy(temp,bullet);
  cout<<"  ";

  //erase bullet2
  gotoxy(temp2,bullet2);
  cout<<"  ";


  //If player's bullet hits enemy
  if ((bullet==2)&&(temp>=enemy)&&(temp<=enemy+9))
  {
   if (e==67)
   {
    gotoxy(33,10);
    cout<<"YOU WON";
    gotoxy(27,12);
    cout<<"Press any key to exit";
    getch();
    exit(0);
   }
    else
    {
     gotoxy(e,1);
     cout<<" ";
     e=e-1;
    }
  }

  //If enemy's bullet hits player
  if ((bullet2==23)&&(temp2>=ship)&&(temp2<=ship+9))
  {
   if (p==68)
   {
    gotoxy(33,10);
    cout<<"YOU LOST";
    gotoxy(27,12);
    cout<<"Press any key to exit";
    getch();
    exit(0);
   }
    else
    {
     gotoxy(p,24);
     cout<<" ";
     p=p-1;
    }
  }

  //movement of bullet
   bullet--;
   if (bullet==1)
   {
    bullet=22;
    if(bullet2==24)
    {
     bullet2=3;
     goto a;
    }
     else
      goto b;
   }

  //movement of bullet2
   bullet2++;
   if (bullet2==24)
   {
    bullet2=3;
    if(bullet==1)
    {
     bullet=22;
     goto a;
    }
     else
      goto c;
   }

  //movement of enemy ship
  if(dir==1)
  {
   enemy--;
  }
  if (dir==2)
  {
   enemy++;
  }

  if(enemy==1)
  {
   enemy=2;
   dir=2;
  }
  if(enemy==71)
  {
   dir=1;
   enemy=70;
  }

  if(kbhit())
  ch=getch();

   if((ch=='a')||(ch=='A'))
   {
    if(ship>2)
     ship-=2;
   }
   if((ch=='d')||(ch=='D'))
   {
    if(ship<70)
     ship+=2;
   }
 }

 return(0);
}