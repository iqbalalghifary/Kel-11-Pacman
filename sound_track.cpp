#include"header/pacman.h"

clock_t ts, te, dur_s,dur_m,dur_h;

void soundloading(){
	PlaySound("assets//Sounds//1.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void soundgame(){
	PlaySound("assets//Sounds//musik nu kedua.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void soundmenu(){
	PlaySound("assets//Sounds//musik nu pertama.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}
void view_time(clock_t p, clock_t l)
{
	char msg[5];
	settextstyle(1, 0, 1);
	sprintf(msg, "time: %.2d:%.2d", l, p);
	outtextxy(500,0,msg);
}

void timer_start()
{
	ts=clock();
}

void timer_end()
{
		te=clock();

		dur_s=(double)(te-ts)/CLOCKS_PER_SEC;

		if(dur_s>=60){
			ts=clock();
			dur_m+=1;
			if(dur_m>=60){
				dur_h+=1;
			}
		}

		timers(dur_h,dur_m,dur_s);
		view_time(dur_s, dur_m);
}
