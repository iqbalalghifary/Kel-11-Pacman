#include"header/pacman.h"

int A[BRS][KLM];
int i=1,j,e,temp,k,temp2;
void *map;
unsigned long size;
typedef struct{
	clock_t second,minute,hours;
} times;
typedef struct{
	char name[10];
	int point;
	times duration;
} sc;

sc scoree;

void level(int l){
	int a,b;
	for(a=0;a<BRS;a++){
		for(b=0;b<KLM;b++){
			A[a][b]=maps_level(l, a, b);
		}
	}
}

void tempMaps(int temp, int baris, int kolom){
	if(temp==0){
		readimagefile("assets//img//inGame//maps//background.gif", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
//	if(temp==1){
//		readimagefile("", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
//	}
}

void limit(){
	bool kiri, kanan, atas, bawah;

	if(A[i-1][j]==0 || A[i][j+1]==1 ){
		atas = true;
		k=0;
	}else if(A[i][j]==0 && ( A[i][j-1]==1 || A[i][j+1]==1 || A[i][j-1]==1)){
		atas = false;
		k=0;
	}else if((i<=0)||(A[i+1][j]==1)){
		atas = false;
	}else{
		atas = true;
	}

	if(A[i+1][j]==0|| (A[i][j]==0 && A[i+1][j]==0)){
		bawah = true;
	}else if((i>=17)||(A[i+1][j]==6)){
		bawah = false;
	}

	if((j<=0) || (A[i][j-1]==1) || (A[i][j-1]==1)){
		kiri = false;
	}else{
		kiri = true;
	}

	if((j>=31)||(A[i][j+1]==1) || (A[i][j+1]==1)){
		kanan = false;
	}else{
		kanan = true;
	}
	move(atas,bawah,kiri,kanan);
}

void move(bool up, bool down, bool left, bool right){
	switch(getch())
	{
		case KEY_UP	:
			if(up){
				i--;
			}
			break;
		case KEY_RIGHT:
			if(right){
                k = 0;
				j++;
			}
			break;
		case KEY_DOWN	:
			if(down){
				i++;
				if(A[i+1][j]==6 || A[i-1][j]==6){
					k=5;
				}else{
					k=0;
				}

			}
			break;
		case KEY_LEFT	:
			if(left){
                k = 1;
				j--;
			}
			break;
	}
}

void ceksprite(int sprite, int baris, int kolom){
	if(sprite==0){
		if(temp == 0 && temp2 !=1){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,2);
		}else if(temp == 0 && temp2 == 0 && A[i+1][j]!=0){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,2);
		}else if(temp == 0 && temp2 ==0){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
		}else if(temp == 0 && temp2 == 0 && A[i+1][j]!=1){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", 40*j,(40*i)+20,40+40*j,(40+40*i)+20);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,2);
		}else if(temp == 0 && temp2 == 0 &&  A[i-1][j]!=0){
		 	readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);	
		}else if(temp == 0 && (A[i+1][j]==0 || A[i-1][j]==0)){
			naik(baris, kolom, 1);
		}else{
			run(baris,kolom,1);
		}
	}
	if(sprite==1){
		if(temp == 0 && temp2 !=0){
			readimagefile("assets//img//inGame//player//char//karakter2.jpg", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			delay(10);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			run(baris,kolom,4);
		}else if(temp == 0 && temp2 == 0 && A[i+1][j]!=0){
			readimagefile("assets//img//inGame//player//char//karakter2.jpg", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			delay(10);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,4);
		}else if(temp == 0 && temp2 ==0){
			readimagefile("assets//img//inGame//player//char//karakter2.jpg", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			delay(10);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
		}else if(temp == 0 && (A[i+1][j]==0 || A[i-1][j]==0)){
			naik(baris, kolom, 1);
		}else{
			run(baris,kolom,3);
		}
	}
	if(sprite==2){
		if(temp == 0 && (temp2 ==0 || A[i+1][j]==0)){
			if(temp2 == 0){
				readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
				delay(150);
				readimagefile("assets//img//inGame//maps//purple.jpg", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			}else if(temp2 != 0){
				readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
				delay(150);
				readimagefile("assets//img//inGame//maps//background.gif", 40*j,(40*i)+20,40+40*j,(40+40*i)-20);
			}
		}
		naik(baris,kolom,1);
	}
	if(sprite==3){
		if(temp == 0 && (temp2 ==0 || A[i+1][j]==0) && A[i+1][j]!=1){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", 40*j,(40*i)+20,40+40*j,(40+40*i)+20);
			delay(150);
			readimagefile("assets//img//inGame//maps//purple.jpg", 40*j,(40*i)+20,40+40*j,(40+40*i)+20);
		}else{
			readimagefile("assets//img//inGame//player//char//karakter2.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
		}
		naik(baris, kolom, 1);
	}
	if(sprite==6){
		run(baris,kolom,1);
	}
	if(sprite==7){
		run(baris,kolom,3);
	}
}

void pointt(){
	scoree.point=score(A[i][j],0,0,scoree.point);
	view_score(scoree.point);
}

void tempp(){
	temp2 = temp;
	temp = A[i][j];
	if(temp == 5){
		temp = 0;
	}
}

void movement(int l){
	A[i][j]=2;
	if(A[i][j]==2){
		ceksprite(k, i, j);
		e=getch();
		A[i][j]=temp;
	}
	tempMaps(temp, i, j);
	finish(scoree.point, l);
}

void maping(){
	for(i=0;i<BRS;i++){
		for(j=0;j<KLM;j++){
			maps(A[i][j],i,j);
		}
	}
	size = imagesize(fullscreen);
	map = malloc(size);
	getimage(fullscreen,map);
	for(i=0;i<BRS;i++){
		for(j=0;j<KLM;j++){
			diamond(A[i][j],i,j);
		}
	}
	i=15;
	j=0;
}

void pause(){
	char msg[13];
	putimage(0,0,map, COPY_PUT);
	settextstyle(2, 0, 8);
	while(e!='c'){
		sprintf(msg, "pause");
		outtextxy(600,330,msg);
		sprintf(msg, "press 'c' to continue");
		outtextxy(500,530,msg);
		e=getch();
	}
	putimage(0,0,map, COPY_PUT);
	for(int a=0;a<BRS;a++){
		for(int b=0;b<KLM;b++){
			diamond(A[a][b],a,b);
		}
	}
}

void sc_lv(int l){
	if(l==1){
		readimagefile("assets//img//inGame//startt.jpg",fullscreen);
		delay(1300);
	}else{
		readimagefile("assets//img//inGame//nextlevel.jpg",fullscreen);
		delay(1300);
	}
}

void next_level(){
	A[1][2]=7;
	if(i==1 && (j==1 || j==3)){
		_beginthread(next_sound,0,NULL);
	}
	A[31][1]=7;
	if(i==31 && (j==1 || j==3)){
		_beginthread(next_sound,0,NULL);
	}
	A[15][15]=7;
	if(i==15 && (j==1 || j==3)){
		_beginthread(next_sound,0,NULL);
	}
	A[20][8]=7;
	if(i==20 && (j==1 || j==3)){
		_beginthread(next_sound,0,NULL);
	}
}

void die(){
	if(A[i+1][j]==9){
		i= i + 1;
		gameover(i,j);
		gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
	}
}

int num_level(int l){
	if(A[i][j]==7){
		l++;
		if(l > 2){
			winner_view(scoree.point);
			savescore_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
		}
		delay(1000);
	}
	return l;
}

void save(char* name, int l){
	sc p;
	FILE *fp;

	strcpy(p.name,name);
	p.point = l;
	p.duration.hours = scoree.duration.hours;
	p.duration.minute = scoree.duration.minute;
	p.duration.second = scoree.duration.second;
	if((fp=fopen("File_highscore.dat", "ab+")) == NULL){
		printf("File tidak dapat dibuka!\n");
	}else{
		fwrite(&p, sizeof(sc), 1, fp);
	}
	fclose(fp);
}

void leaderboard(){
	sc p;
	FILE *fp;
	char view[15];
	int n=1;
	int tinggi = 300;
	Sort_file();
	if((fp=fopen("File_highscore.dat", "rb")) == NULL){
		printf("File tidak dapat dibuka!\n");
	}else{
		rewind(fp);
		while (fread(&p, sizeof(sc), 1, fp) == 1 && n <= 5){
			settextstyle(2, 0, 8);
//			sprintf(view,"%i",n);
//			outtextxy(320, tinggi, view);
		
			sprintf(view,"%s", p.name);
			outtextxy(450, tinggi, view);
	
			sprintf(view,"%d", 	p.point);
			outtextxy(770, tinggi, view);
			tinggi += 40;
			n++;
		}
	}
	fclose(fp);
}

void Sort_file(){
	sc dt,temp;

	int i,x;
	int f_struct;
	int f_file;

	FILE *fp;

	if ((fp=fopen("File_highscore.dat", "rb+"))==NULL)
      {
            printf ("File tidak dapat dibuka\n");
      }
	f_struct = sizeof(sc);
	fseek(fp, 0, SEEK_END);
	f_file = ftell(fp);

	rewind(fp);
	for(i=0;i< f_file; i += f_struct){
		for(x=0;x< f_file - f_struct; x += f_struct){
			fread(&dt, f_struct, 1, fp);
			fread(&temp, f_struct, 1, fp);
			if(dt.point<temp.point){
				fseek(fp, -(f_struct * 2), SEEK_CUR);
				fwrite(&temp, f_struct, 1, fp);
				fwrite(&dt, f_struct, 1, fp);
				fseek(fp, -f_struct , SEEK_CUR);
			}
			else{
				fseek(fp, -f_struct , SEEK_CUR);
			}
		}
		rewind(fp);
	}
	fclose(fp);
}


void timers(clock_t dur_h, clock_t dur_m,clock_t dur_s){
	scoree.duration.hours=dur_h;
	scoree.duration.minute=dur_m;
	scoree.duration.second=dur_s;
}

void pilihan(){
	pilihan:
	int x, y;
	readimagefile("assets//img//opening//background.jpeg",fullscreen);
	x= 150;
   	y= 50;
	readimagefile("assets//img//inGame//level1.jpg",x,y,450+x,300+y);
	x= 700;
	y= 50;
	readimagefile("assets//img//inGame//level1.jpg",x,y,450+x,300+y);
	x= 150;
	y= 380;
	readimagefile("assets//img//inGame//level1.jpg",x,y,450+x,300+y);
	x= 700;
	y= 380;
	readimagefile("assets//img//inGame//level1.jpg",x,y,450+x,300+y);
	x=35;
	y=652;
    readimagefile("assets//img//inGame//aboutUs//back.gif",x,y,90+x,90+y);
}

void menu_utama(){
	int x, y, ltemp;
	
	int p=1;
    soundmenu();
	menu:
	menu_awal();
	while(1){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>580 && x<580+151)&&(y>310 && y<310+70)){
			pilihan();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>150 && x<150+450)&&(y>50 && y<50+300)){
				int lv = 1;
				while(lv<=1){
					sc_lv(lv);
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					if(lv==1){
					timer_start();	
					}
					while(lv>=1){
						view_level(ltemp);
						pointt();
						tempp();
						movement(lv);
						if(e=='P' || e=='p' ){
							pause();
						}else{
							limit();
						}
						lv=num_level(lv);
						die();
						timer_end();
					}
				}
			    }else if ((x>700 && x<700+450)&&(y>50 && y<50+300)){
				while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>700 && x<700+450)&&(y>50 && y<50+300)){
				int lv = 2;
				while(lv<=2){
					sc_lv(lv);
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					if(lv==2){
					timer_start();	
					}
					while(lv>=2){
						view_level(ltemp);
						pointt();
						tempp();
						movement(lv);
						if(e=='P' || e=='p' ){
							pause();
						}else{
							limit();
						}
						lv=num_level(lv);
						die();
						timer_end();
					}
			}
				}
			}	goto menu;
			}else if ((x>35 && x<35+90)&&(y>652 && y<652+90)){
				while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>35 && x<35+90)&&(y>652 && y<652+90)){
					goto menu;
				}
			}
	}  else if ((x>150 && x<150+450)&&(y>380 && y<380+300)){
				while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>150 && x<150+450)&&(y>380 && y<380+300)){
				int lv = 3;
				while(lv<=3){
					sc_lv(lv);
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					if(lv==3){
					timer_start();	
					}
					while(lv>=3){
						view_level(ltemp);
						pointt();
						tempp();
						movement(lv);
						if(e=='P' || e=='p' ){
							pause();
						}else{
							limit();
						}
						lv=num_level(lv);
						die();
						timer_end();
					}
			}
				}
			}	goto menu;
			}
		}
			}else if((x>557 && x<557+185)&&(y>400 && y<400+90)){
			view_leaderboard();
			leaderboard();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
					if((x>30 && x<30+150)&&(y>650 && y<700)){
					goto menu;
				}
			}
		}else if((x>40 && x<40+80)&&(y>600 && y<680)){
			while(1){
				how();
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>35 && x<35+80)&&(y>652 && y<652+80)){
					goto menu;
				}
			}
		}else if((x>560 && x<560+185)&&(y>500 && y<500+90)){
			about();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>30 && x<30+150)&&(y>650 && y<700)){
					goto menu;
				}
			}
		}else if((x>580 && x<580+125)&&(y>600 && y<600+60)){
			keluar();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>420 && x<520)&&(y>390 && y<440)){
					goto menu;
				}else if((x>740 && x<790)&&(y>390 && y<440)){
					exit(1);
				}
			}
		}
}
 }


	



 
