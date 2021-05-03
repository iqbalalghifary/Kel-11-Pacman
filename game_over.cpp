#include"header/pacman.h"



void gameover(int i, int j){
	_beginthread(gameover_sound,0,NULL);
}

void gameover_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
	readimagefile("assets//img//inGame//lose//LOSE.jpg", 0,0,1280,720);
	delay(200);
	savescore_screen(p,dur_h,dur_m,dur_s);
}

void savescore_screen(int p,clock_t dur_h, clock_t dur_m,clock_t dur_s){
	int x,y,j,k;
	readimagefile("assets//img//inGame//nothing", 0,0,1280,720);
	view_save_score();
	char nama[11]= {'K','e','l','o','m','p','o','k',' ','1','1'};
	settextstyle(2, 0, 8); outtextxy(600, 280 ,nama);
	int ax, z=0;
	while(1){
		if(kbhit()){
			ax = getch();
			if(ax == 51){
				readimagefile("assets//img//inGame//maps//score.jgp", 600, 300, 720, 600);
			}
			if(ax == 80){
				nama[z]--;
				if(nama[z] < 65){
					nama[z] = 90;
				}
				outtextxy(600, 150 ,nama);
			}else if(ax == 72){
				nama[z]++;
				if(nama[z] > 90){
					nama[z] = 65;
				}
				outtextxy(600, 150 ,nama);
			}else if(ax == 77){
				if(z < 3) z++;
			}else if(ax == 75){
				if(z > 0) z--;
			}
		}
		view2_score(p);
		view2_time(dur_h,dur_m,dur_s);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>510 && x<580+300)&&(y>520 && y<550+300)){
			save(nama,p);
			cleardevice();
			menu_utama();
		}
	}
}

void view2_score(int p){
	char msg[13];
	settextstyle(2, 0, 8);
	sprintf(msg, "score \n %d", p);
	outtextxy(600,320,msg);
}

void view2_time(clock_t dur_h, clock_t dur_m,clock_t dur_s){
	char msg[20];
	settextstyle(2, 0, 8);
	sprintf(msg, "Time %d:%d:%d", dur_h,dur_m,dur_s);
	outtextxy(600,360,msg);
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

}
