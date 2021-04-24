#include"header/pacman.h"
void menu_awal(){
	int x, y;
   	readimagefile("assets//img//opening//background.jpeg",fullscreen);
   	x= 320;
   	y= -190;
   	readimagefile("assets//img//inGame//logo.gif", x,y,700+x,700+y);
	x= 580;
   	y= 310;
	readimagefile("assets//img//inGame//a.gif",x,y,151+x,70+y);
	x=557;
	y=400;
	readimagefile("assets//img//inGame//highscore.gif",x,y,185+x,90+y);
	x=40;
	y=600;
	readimagefile("assets//img//inGame//cara.jpg",x,y,80+x,80+y);
	x=560;
	y=500;
	readimagefile("assets//img//inGame//about us.gif",x,y,185+x,90+y);
	x=580;
	y=600;
	readimagefile("assets//img//inGame//exit.gif",x,y,151+x,70+y);
}

void splashscreen(){
	int x, y, a, b, i=400, j=50, k, l;

	a=300;
	b=300;

	soundloading();
	x=((getmaxx()/2)-(a/2));
	y=((getmaxy()/2)-(b/2));
	k=((getmaxx()/2)-(i/2));
	l=((getmaxy()/2)-(j/2));

		readimagefile("assets//img//opening//background1.jpeg",fullscreen);
		delay(999);
	    readimagefile("assets//img//opening//1.jpg",fullscreen);
		readimagefile("assets//img//opening//2.jpg",fullscreen);
		readimagefile("assets//img//opening//3.jpg",fullscreen);
		readimagefile("assets//img//opening//4.jpg",fullscreen);
		readimagefile("assets//img//opening//5.jpg",fullscreen);
		readimagefile("assets//img//opening//6.jpg",fullscreen);
		readimagefile("assets//img//opening//7.jpg",fullscreen);
		readimagefile("assets//img//opening//8.jpg",fullscreen);
		readimagefile("assets//img//opening//9.jpg",fullscreen);
		readimagefile("assets//img//opening//10.jpg",fullscreen);
		readimagefile("assets//img//opening//11.jpg",fullscreen);
		readimagefile("assets//img//opening//12.jpg",fullscreen);
		readimagefile("assets//img//opening//13.jpg",fullscreen);
		readimagefile("assets//img//opening//14.jpg",fullscreen);
		readimagefile("assets//img//opening//15.jpg",fullscreen);
		readimagefile("assets//img//opening//16.jpg",fullscreen);
		readimagefile("assets//img//opening//17.jpg",fullscreen);
		readimagefile("assets//img//opening//18.jpg",fullscreen);
        readimagefile("assets//img//opening//19.jpg",fullscreen);
		readimagefile("assets//img//opening//20.jpg",fullscreen);
		readimagefile("assets//img//opening//21.jpg",fullscreen);
		readimagefile("assets//img//opening//22.jpg",fullscreen);
		readimagefile("assets//img//opening//23.jpg",fullscreen);
		readimagefile("assets//img//opening//24.jpg",fullscreen);
		readimagefile("assets//img//opening//25.jpg",fullscreen);
		readimagefile("assets//img//opening//26.jpg",fullscreen);
		readimagefile("assets//img//opening//27.jpg",fullscreen);
		readimagefile("assets//img//opening//28.jpg",fullscreen);
		readimagefile("assets//img//opening//29.jpg",fullscreen);
		readimagefile("assets//img//opening//30.jpg",fullscreen);
        readimagefile("assets//img//opening//31.jpg",fullscreen);
        readimagefile("assets//img//opening//32.jpg",fullscreen);
		readimagefile("assets//img//opening//33.jpg",fullscreen);
		readimagefile("assets//img//opening//34.jpg",fullscreen);
		readimagefile("assets//img//opening//35.jpg",fullscreen);
		readimagefile("assets//img//opening//36.jpg",fullscreen);
		readimagefile("assets//img//opening//37.jpg",fullscreen);
		readimagefile("assets//img//opening//38.jpg",fullscreen);
		readimagefile("assets//img//opening//39.jpg",fullscreen);
		delay(100);


}

void about(){
	int x, y;
   	readimagefile("assets//img//inGame//aboutUs//aboutus.jpg",fullscreen);
	x=35;
	y=652;
    readimagefile("assets//img//inGame//aboutUs//back.gif",x,y,80+x,80+y);
}

void keluar(){
	readimagefile("assets//img//opening//yakin.gif",420,240,420+420,240+240);
	readimagefile("assets//img//opening//tidak.jpg",470,390,520,440);
	readimagefile("assets//img//opening//ya.jpg",740,390,790,440);
}

void how(){
    int x,y;
    x=35;
    y=652;
		readimagefile("assets//img//inGame//cara main.jpg",fullscreen);
        readimagefile("assets//img//inGame//aboutUs//back.gif",x,y,80+x,80+y);
}


