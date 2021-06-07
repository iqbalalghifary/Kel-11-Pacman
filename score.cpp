#include"header/pacman.h"

int score(int mat, int brs, int klm, int p){
	if (mat==5){
		p++;
	}
	if (mat==2){
        p=p+5;
	}
	return p;
}

void view_score(int p){
	char msg[3];
	settextstyle(1, 0, 1);
	sprintf(msg, "score: %d", p);
	outtextxy(100,0,msg);
}

void winner_view(int l){
	cleardevice();
	readimagefile("assets//img//inGame//win//WIN.jpg", fullscreen);
	delay(2000);
}



void view_leaderboard()
{
	int x,y;

	readimagefile("assets//img//inGame//highscore//BCKGRND SCORE.gif",fullscreen);

	x=100;
	y=120;
	readimagefile("assets//img//inGame//highscore//nama_skor.gif",x,y,800+x,600+y);

	x=410;
	y=120;
	readimagefile("assets//img//inGame//highscore//score.gif",x,y,800+x,600+y);

    x=35;
	y=652;
    readimagefile("assets//img//inGame//aboutUs//back.gif",x,y,80+x,80+y);

}


