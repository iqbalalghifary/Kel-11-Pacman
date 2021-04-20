#include"header/pacman.h"
void menu_awal(){
	int x, y;
   	readimagefile("assets//img//opening//2.jpg",fullscreen);
	x= 580;
   	y= 300;
	readimagefile("assets//img//inGame//play.jpg",x,y,125+x,60+y);
	x=550;
	y=400;
	readimagefile("assets//img//inGame//score.jpg",x,y,185+x,60+y);
	x=40;
	y=600;
	readimagefile("assets//img//inGame//cara.jpg",x,y,80+x,80+y);
	//x=795;
	//readimagefile("assets//img//opening//aboutUs.gif",x,y,230+x,60+y);
	x=580;
	y=500;
	readimagefile("assets//img//inGame//exit.jpg",x,y,125+x,60+y);
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

		readimagefile("assets//img//opening//ezgif-frame-001.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-034.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-035.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-036.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-037.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-038.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-039.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-040.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-041.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-042.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-043.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-044.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-054.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-056.jpg",fullscreen);
		delay(50);
		readimagefile("assets//img//opening//ezgif-frame-064.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-066.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-068.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-069.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-070.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-071.jpg",fullscreen);
		delay(10);
		readimagefile("assets//img//opening//ezgif-frame-074.jpg",fullscreen);
		delay(50);


		readimagefile("assets//img//loading//load1.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load2.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load3.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load4.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load5.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load6.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load7.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load8.jpg", k, l+100, k+i, l+j+100);
		delay(250);
		readimagefile("assets//img//loading//load9.jpg", k, l+100, k+i, l+j+100);
		delay(300);


}

void about(){
	int x, y;
   	readimagefile("assets//img//inGame//aboutUs//background.jpg",fullscreen);
	x=520;
	y=30;
	readimagefile("assets//img//opening//about//kel.jpg",x,y,200+x,50+y);

   	x=70;
	y=80;
	readimagefile("assets//img//opening//about//ar.jpg",x,y,150+x,250+y);

	x=550;
	y=80;
	readimagefile("assets//img//opening//about//be.jpg",x,y,150+x,250+y);

    x=1070;
	y=80;
	readimagefile("assets//img//opening//about//li.jpg",x,y,150+x,250+y);

	x=70;
	y=370;
	readimagefile("assets//img//opening//about//far.jpg",x,y,150+x,250+y);

	x=550;
	y=370;
	readimagefile("assets//img//opening//about//ro.jpg",x,y,150+x,250+y);

	x=1070;
	y=370;
	readimagefile("assets//img//opening//about//ji.jpg",x,y,150+x,250+y);

	x=30;
	y=650;
	readimagefile("assets//img//inGame//back.jpg",x,y,150+x,50+y);
}

void keluar(){
	readimagefile("assets//img//opening//yakin.gif",420,240,420+420,240+240);
	readimagefile("assets//img//opening//tidak.gif",470,390,520,440);
	readimagefile("assets//img//opening//ya.gif",740,390,790,440);
}

void how(){
    int x,y;
    x=35;
    y=652;
		readimagefile("assets//img//inGame//cara main.jpg",fullscreen);
        readimagefile("assets//img//inGame//aboutUs//back.jpg",x,y,80+x,80+y);
}


