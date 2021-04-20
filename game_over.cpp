#include"header/pacman.h"



void gameover(int i, int j){
	_beginthread(gameover_sound,0,NULL);
	readimagefile("assets//img//inGame//player//die//apaini1.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini2.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini3.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini4.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini5.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini6.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini7.jpg", img_mtrx);
	delay(200);
	readimagefile("assets//img//inGame//player//die//apaini8.jpg", img_mtrx);
}

void gameover_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
	readimagefile("assets//img//inGame//inGameoverr.jpg", 0,0,1280,720);
	delay(2000);
	savescore_screen(p,dur_h,dur_m,dur_s);
}

void savescore_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
	int x,y,j,k;
	readimagefile("assets//img//inGame//egyp.jpg", 0,0,1280,720);
	view_save_score();
	char nama[4]={'A','A','A','A'}; settextstyle(2, 0, 8); outtextxy(600, 150 ,nama);
	int ax, z=0;
	while(1){
		if(kbhit()){
			ax = getch();
			if(ax == 51){
				readimagefile("assets//imag//inGame//maps//sore.jgp", 600, 300, 720, 600);
			}
//			if(ax == 80){
//				nama[z]--;
//				if(nama[z] < 65){
//					nama[z] = 90;
//				}
//				outtextxy(600, 150 ,nama);
//			}else if(ax == 72){
//				nama[z]++;
//				if(nama[z] > 90){
//					nama[z] = 65;
//				}
//				outtextxy(600, 150 ,nama);
//			}else if(ax == 77){
//				if(z < 3) z++;
//			}else if(ax == 75){
//				if(z > 0) z--;
//			}
		}
		view2_score(p);
		view2_time(dur_h,dur_m,dur_s);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>580 && x<580+150)&&(y>550 && y<550+50)){
			save(nama,p);
			menu_utama();
		}
	}
}

void view2_score(int p){
	char msg[13];
	settextstyle(2, 0, 8);
	sprintf(msg, "score \n %d", p);
	outtextxy(600,280,msg);
}

void view2_time(clock_t dur_h, clock_t dur_m,clock_t dur_s){
	char msg[20];
	settextstyle(2, 0, 8);
	sprintf(msg, "Time %d:%d:%d", dur_h,dur_m,dur_s);
	outtextxy(600,310,msg);
}

int move_htp(int p){
	int ax;
	if(kbhit()){
		ax = getch();
		if(ax == 77){
			p++;
			if(p==4){
				p = 1;
			}
		}else if(ax == 75){
			p--;
			if(p==0){
				p = 3;
			}
		}
	}
	return p;
}

void view_save_score(){
	int x,y;

	x=450;
	y=100;
	readimagefile("assets//img//inGame//untuk.jpg",x,y,400+x,100+y);

	x=450;
	y=280;
	readimagefile("assets//img//inGame//untuk.jpg",x,y,400+x,100+y);

	x=580;
	y=550;
	readimagefile("assets//img//inGame//save.jpg",x,y,150+x,50+y);

}
