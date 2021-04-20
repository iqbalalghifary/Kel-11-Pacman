#include"header/pacman.h"

clock_t ts, te, dur_s,dur_m,dur_h;

void soundloading(){
	PlaySound("assets//Sounds//loading1.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void soundgame(){
	PlaySound("assets//Sounds//ingame.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void soundmenu(){
	PlaySound("assets//Sounds//opening.wav",NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

void score_sound(void *arg){
	mciSendString("open assets//Sounds//Poin.wav type mpegvideo alias score",NULL,0,NULL);
	mciSendString("play score from 0",NULL,0,NULL);
	_endthread();
}

void bomb_sound(void *arg){
	mciSendString("open assets//Sounds//bomb.wav type mpegvideo alias bomb",NULL,0,NULL);
	mciSendString("play bomb from 0",NULL,0,NULL);
	_endthread();
}

void next_sound(void *arg){
	mciSendString("open assets//Sounds//Finish.wav type mpegvideo alias next",NULL,0,NULL);
	mciSendString("play next from 0",NULL,0,NULL);
	_endthread();
}

void gameover_sound(void *arg){
	mciSendString("open assets//Sounds//die.wav type mpegvideo alias die",NULL,0,NULL);
	mciSendString("play die from 0",NULL,0,NULL);
	_endthread();
}

void fall_sound(void *arg){
	mciSendString("open assets//Sounds//fall.wav type mpegvideo alias fall",NULL,0,NULL);
	mciSendString("play fall from 0",NULL,0,NULL);
	_endthread();
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
