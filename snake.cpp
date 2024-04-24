#include<iostream>
#include<graphics.h>
//#include<string.h>
#include<windows.h>

using namespace std;

void menu();
void setting();
void set_avatar();
void level_1();
void show_score(int);
void set_speed();
void game_over();
void loading_animation();

int count;
char avatar[10]="stripe";
char speed[10]="low";
char text[25];

int main(){
	initwindow(450+8,800+11);
	loading_animation();
	menu();
	closegraph();	
	return 0;
}

void loading_animation(){
	setfillstyle(1,GREEN);
	for(int x=1;x<160;x++)
	{
		strcpy(text,"Snake");
		settextstyle(10,HORIZ_DIR,7);
		outtextxy(130,200,text);
		
		strcpy(text,"Loading...");
		settextstyle(8,HORIZ_DIR,2);
		outtextxy(166+5,655,text);
		
		rectangle(139-2,685-2,319+1,705+1);
		bar(139+x,685,139+20+x,685+20);
		delay(5);
	}
}

void menu(){
	count=1;
	int x=0,y=0;
	for(;;)
	{
		setfillstyle(1,BLACK);
		floodfill(1,1,YELLOW);
		
		strcpy(text,"Snake");
		settextstyle(10,HORIZ_DIR,7);
		outtextxy(130,200,text);
		
		settextstyle(8,HORIZ_DIR,3);

		strcpy(text,"Quick play");
		outtextxy(141,365,text);
		
		strcpy(text,"Choose level");
		outtextxy(141,415,text);
		
		strcpy(text,"Setting");
		outtextxy(141,465,text);
		
		strcpy(text,"Exit");
		outtextxy(141,515,text);
		
		setcolor(WHITE);
		
		if(GetAsyncKeyState(VK_DOWN))	
			if(count<4)
				count++;
		
		if(GetAsyncKeyState(VK_UP))	
			if(count>1)
				count--;
				
		setlinestyle(1,0,2);
		if(count==1)	rectangle(130,355,318,400);
		if(count==2)	rectangle(130,405,318,450);
		if(count==3)	rectangle(130,456,318,501);
		if(count==4)	rectangle(130,506,318,501+50);
		
		if(GetAsyncKeyState(VK_RETURN))	
		{
			if(count==1)	level_1();
//			if(count==2)	choose_level();
			if(count==3)	setting();
			if(count==4)	exit(1);
		}		
		delay(50);
	}
}

void setting(){
	count=1;
	for(;;)
	{
		setfillstyle(1,BLACK);
		floodfill(1,1,YELLOW);
		
		strcpy(text,"Snake");
		settextstyle(10,HORIZ_DIR,7);
		outtextxy(130,200,text);
		
		strcpy(text,"Avatar");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(182,365,text);
		
		strcpy(text,"Speed");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(183,415,text);
		
		strcpy(text,"Go back");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(171,465,text);
		
		setcolor(WHITE);
		
		if(GetAsyncKeyState(VK_DOWN))	
			if(count<3)
				count++;
		
		if(GetAsyncKeyState(VK_UP))	
			if(count>1)
				count--;
				
		setlinestyle(1,0,2);
		if(count==1)	rectangle(130,355,318,400);
		if(count==2)	rectangle(130,405,318,450);
		if(count==3)	rectangle(130,456,318,501);
		
		if(GetAsyncKeyState(VK_RETURN))	
		{
			if(count==1)	set_avatar();
			if(count==2)	set_speed();
			if(count==3)	menu();
		}		
		delay(50);
	}
}

void set_avatar(){
	count=1;
	for(;;)
	{
		setfillstyle(1,BLACK);
		floodfill(1,1,YELLOW);
		
		strcpy(text,"Snake");
		settextstyle(10,HORIZ_DIR,7);
		outtextxy(130,200,text);
		
		strcpy(text,"Choose avatar");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(138,365,text);
		
		//simple
		setfillstyle(1,GREEN);
		bar(163,415,283,435);
		
		//stripe
		bar(163,465,181,485);
		bar(183,465,201,485);
		bar(203,465,221,485);
		bar(223,465,241,485);
		bar(243,465,261,485);
		bar(263,465,281,485);
		
		strcpy(text,"Go back");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(171,465+55,text);
		
		setcolor(WHITE);
		
		if(GetAsyncKeyState(VK_DOWN))	
			if(count<3)
				count++;
		
		if(GetAsyncKeyState(VK_UP))	
			if(count>1)
				count--;
				
		setlinestyle(1,0,2);
		if(count==1)	rectangle(130,405,318,450);
		if(count==2)	rectangle(130,456,318,501);
		if(count==3)	rectangle(130,456+50,318,501+50);
		
		if(GetAsyncKeyState(VK_RETURN))	
		{
			if(count==1)	strcpy(avatar,"simple");
			if(count==2)	strcpy(avatar,"stripe");
			if(count==3)	menu();
		}		
		delay(50);
	}
}

void set_speed(){
	count=1;
	for(;;)
	{
		setfillstyle(1,BLACK);
		floodfill(1,1,YELLOW);
		
		strcpy(text,"Snake");
		settextstyle(10,HORIZ_DIR,7);
		outtextxy(130,200,text);
		
		settextstyle(8,HORIZ_DIR,3);
		strcpy(text,"Slow");
		outtextxy(153,365,text);
		
		strcpy(text,"Moderate");
		outtextxy(153,415,text);
		
		strcpy(text,"Fast");
		outtextxy(153,465,text);
		
		strcpy(text,"Go back");
		outtextxy(153,515,text);
		
		setcolor(WHITE);
		
		if(GetAsyncKeyState(VK_DOWN))	
			if(count<4)
				count++;
		
		if(GetAsyncKeyState(VK_UP))	
			if(count>1)
				count--;
				
		setlinestyle(1,0,2);
		if(count==1)	rectangle(130,355,318,400);
		if(count==2)	rectangle(130,405,318,450);
		if(count==3)	rectangle(130,456,318,501);
		if(count==4)	rectangle(130,506,318,501+50);
		
		if(GetAsyncKeyState(VK_RETURN))	
		{
			if(count==1)	strcpy(speed,"low");
			if(count==2)	strcpy(speed,"moderate");
			if(count==3)	strcpy(speed,"fast");
			if(count==4)	menu();
		}		
		delay(50);
	}
}

void level_1(){
	int poison_x=-20,poison_y=-20;
	int i;
	int direction=1;
	int length=1;
	int head_x[50],head_y[50];
	int food_x=220,food_y=400;
	
	loading_animation();
	for(i=0;i<50;i++)
	{
		head_x[i]=-20;
		head_y[i]=-20;
	}
	
	head_x[0]=60;
	head_y[0]=60;
	
	while(1)
	{
		setfillstyle(1,BLACK);
		floodfill(1,1,YELLOW);
		
		setfillstyle(1,GREEN);
		
		bar(0,0,440,18);		//top bar
		bar(0,0,18,800);		//left bar
		bar(422,0,450,800);		//right bar
		bar(0,782,450,800);		//bottom bar
		
		//showing score
		show_score(length);
		
		//generating food
		if(head_x[0]==food_x && head_y[0]==food_y)
		{
			//generation poison food
			if(length%7==0)
			{
				do
				{
					poison_x=rand()%420	;
				}while(poison_x%20!=0 || poison_x<20 || poison_x>760 );
				
				do
				{
					poison_y=rand()%760;	
				}while(poison_y%20!=0 || poison_y<20 || poison_y>760 );

				setfillstyle(1,RED);
			}
			
			length++;

			X:
			food_x=rand()%420;
			if(food_x%20!=0 || food_x<20)
				goto X;
			
			//making sure that food is not generated on the snake body area
			for(i=0;i<length;i++)
				if(food_x==head_x[i])
					goto X;
				
			Y:
			food_y=rand()%760;
			if(food_y%20!=0 || food_y<20)
				goto Y;
			
			//making sure that food is not generated on the snake body area
			for(i=0;i<length;i++)
				if(food_y==head_y[i])
					goto Y;
		}
		
		setfillstyle(1,RED);
		if(strcmp(avatar,"stripe")==0)
			bar(poison_x,poison_y,poison_x+18,poison_y+18);		
		else
			bar(poison_x,poison_y,poison_x+20,poison_y+20);		
		
		setfillstyle(1,WHITE);
		if(strcmp(avatar,"stripe")==0)
			bar(food_x,food_y,food_x+18,food_y+18);
		else
			bar(food_x,food_y,food_x+20,food_y+20);
		

		if(poison_x==head_x[0] && poison_y==head_y[0])
		{
			poison_x=-20;
			poison_y=-20;
			
			head_x[length]=-20;
			head_y[length]=-20;			
			
			length--;
		}

		//snake body
		setfillstyle(1,GREEN);
		if(strcmp(avatar,"stripe")==0)
		{
			for(i=0;i<length;i++)
				bar(head_x[i],head_y[i],head_x[i]+18,head_y[i]+18);
		}
		else
		{
			for(i=0;i<length;i++)
				bar(head_x[i],head_y[i],head_x[i]+20,head_y[i]+20);
		}
		
		for(i=length-1;i>0;i--)
		{
			head_x[i] = head_x[i-1];
			head_y[i] = head_y[i-1];
		}
		
		if(GetAsyncKeyState(VK_RIGHT))	
			if(direction!=2)
				direction=1;
				
		if(GetAsyncKeyState(VK_LEFT))	
			if(direction!=1)
				direction=2;
				
		if(GetAsyncKeyState(VK_UP))		
			if(direction!=4)
				direction=3;
				
		if(GetAsyncKeyState(VK_DOWN))	
			if(direction!=3)
				direction=4;				
		
		//snake movement
		switch(direction)
		{
			case 1:	
				head_x[0]+=20;
				break;
			
			case 2:
				head_x[0]-=20;
				break;
			
			case 3:
				head_y[0]-=20;
				break;
			
			case 4:
				head_y[0]+=20;
				break;
				
			default:
				direction=direction;		
		}
		
		//boundry hit case
		if(head_x[0]<20 || head_x[0]>400 || head_y[0]<20 || head_y[0]>760)	
			game_over();	
		
		if(GetAsyncKeyState(VK_ESCAPE))										
			menu();
		
		//checking if snake head touches it own body
		for(i=1;i<length-1;i++)
			if(head_x[0]==head_x[i] && head_y[0]==head_y[i])
				game_over();
		
		if(strcmp(speed,"low")==0)
			delay(80);
		else if(strcmp(speed,"moderate")==0)
			delay(50);
		else
			delay(25);
	}
}

void game_over(){
	strcpy(text,"Game over");
	
	setcolor(WHITE);
	circle(229-10,700,5);
	circle(229+10,700,5);
	arc(229,762,70,110,45);

	for(;;)
	{
		setcolor(WHITE);
		strcpy(text,"Game over");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(229-60,732,text);
		
		delay(500);
		
		setcolor(BLACK);
		strcpy(text,"Game over");
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(229-60,732,text);
		
		delay(500);
		
		if(GetAsyncKeyState(VK_ESCAPE))
			menu();
	}
}

void show_score(int score){
	strcpy(text,"Score ");
	outtextxy(225+70,30,text);
	if     (score==1)	strcpy(text,"1");
	else if(score==2)	strcpy(text,"2");
	else if(score==3)	strcpy(text,"3");
	else if(score==4)	strcpy(text,"4");
	else if(score==5)	strcpy(text,"5");
	else if(score==6)	strcpy(text,"6");
	else if(score==7)	strcpy(text,"7");
	else if(score==8)	strcpy(text,"8");
	else if(score==9)	strcpy(text,"9");
	else if(score==10)	strcpy(text,"10");
	else if(score==11)	strcpy(text,"11");
	else if(score==12)	strcpy(text,"12");
	else if(score==13)	strcpy(text,"13");
	else if(score==14)	strcpy(text,"14");
	else if(score==15)	strcpy(text,"15");
	else if(score==16)	strcpy(text,"16");
	else if(score==17)	strcpy(text,"17");
	else if(score==18)	strcpy(text,"18");
	else if(score==19)	strcpy(text,"19");
	else if(score==20)	strcpy(text,"20");
	else if(score==21)	strcpy(text,"21");
	else if(score==22)	strcpy(text,"22");
	else if(score==23)	strcpy(text,"23");
	else if(score==24)	strcpy(text,"24");
	else if(score==25)	strcpy(text,"25");
	else if(score==26)	strcpy(text,"26");
	else if(score==27)	strcpy(text,"27");
	else if(score==28)	strcpy(text,"28");
	else if(score==29)	strcpy(text,"29");
	else if(score==30)	strcpy(text,"30");
	else if(score==31)	strcpy(text,"31");
	else if(score==32)	strcpy(text,"32");
	else if(score==33)	strcpy(text,"33");
	else if(score==34)	strcpy(text,"34");
	else if(score==35)	strcpy(text,"35");
	else if(score==36)	strcpy(text,"36");
	else if(score==37)	strcpy(text,"37");
	else if(score==38)	strcpy(text,"38");
	else if(score==39)	strcpy(text,"39");
	else if(score==40)	strcpy(text,"40");
	else if(score==41)	strcpy(text,"41");
	else if(score==42)	strcpy(text,"42");
	else if(score==43)	strcpy(text,"43");
	else if(score==44)	strcpy(text,"44");
	else if(score==45)	strcpy(text,"45");
	else if(score==46)	strcpy(text,"46");
	else if(score==47)	strcpy(text,"47");
	else if(score==48)	strcpy(text,"48");
	else if(score==49)	strcpy(text,"49");
	else
	{
		strcpy(text,"50");
		for(;;)
		{
			setcolor(WHITE);
			strcpy(text,"Congratulations!");
			settextstyle(8,HORIZ_DIR,2);
			outtextxy(130,700,text);	
			
			strcpy(text,"You completed the task :) ");
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(86,720,text);		
			
			delay(500);
			
			setcolor(BLACK);
			strcpy(text,"Congratulations!");
			settextstyle(8,HORIZ_DIR,2);
			outtextxy(130,700,text);	
			
			strcpy(text,"You completed the task :) ");
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(86,720,text);	
			delay(500);
			
			if(GetAsyncKeyState(VK_RETURN))
				menu();
		}
	}
	outtextxy(225+70+20+40+20+3+5,30,text);
}
