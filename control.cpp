#include"header/pacman.h"

int A[BRS][KLM];
int i=1,j,e,temp,k,temp2, ghostmat, countPowerUp, scorepac, elementArray;
int rowLocation, colLocation;
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
		readimagefile("assets//img//inGame//maps//background.gif", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);

}

void tempMapsGhost(int temp, int baris, int kolom){
		readimagefile("assets//img//inGame//maps//telor_maps.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);

}

void tempMapsGhift(int temp, int baris, int kolom){
		readimagefile("assets//img//inGame//maps//lb_bonus.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
}
void limit(){
	bool kiri, kanan, atas, bawah;

	if(A[i-1][j]==0 || A[i-1][j]==7 || A[i-1][j]==5 || A[i-1][j]==9 || A[i-1][j]==2){
		atas = true;
		k=0;
	}else if(A[i][j]==0 && ( A[i][j-1]==1 || A[i][j+1]==1)){
		atas = false;
		k=0;
	}else if((i<=0)||(A[i+1][j]==1)){
		atas = false;
	}else if(A[i][j]==0 && A[i-1][j]==1 && ( A[i][j-1]==0 || A[i][j+1]==0)){
		atas = false;
		k=0;

   }else if(A[i][j]==0 && ( A[i][j-1]==3 || A[i][j+1]==3)){
		atas = false;
		k=0;
	}else if((i<=0)||(A[i+1][j]==3)){
		atas = false;
	}else if(A[i][j]==0 && A[i-1][j]==3 && ( A[i][j-1]==0 || A[i][j+1]==0)){
		atas = false;
		k=0;
   }else {
   	    atas = false;
   }


	if((j<=0) || (A[i+1][j]==1) || (A[i+1][j]==1)){
		bawah = false;
	}else if((j<=0) || (A[i+1][j]==3) || (A[i+1][j]==3)){
		bawah = false;
	}else{
		bawah = true;
	}

	if((j<=0) || (A[i][j-1]==1) || (A[i][j-1]==1)){
		kiri = false;
	}else if((j<=0) || (A[i][j-1]==3) || (A[i][j-1]==3)){
		kiri = false;
	}else{
		kiri = true;
	}

	if((j>=31)||(A[i][j+1]==1) || (A[i][j+1]==1)){
		kanan = false;
	}else if((j>=31)||(A[i][j+1]==3) || (A[i][j+1]==3)){
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
		}else if(temp == 0 && temp2 == 0 && (A[i+1][j]!=0 || A[i-1][j]!=0)){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,2);
		}else if(temp == 0 && temp2 ==0){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)-20,40*i,(40+40*j)-20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)-20,40*i,(40+40*j)+20,40+40*i);
		}else if(temp == 0 && temp2 == 0 && A[i+1][j]!=1){
			readimagefile("assets//img//inGame//player//char//karakter1.gif", 40*j,(40*i)+20,40+40*j,(40+40*i)+20);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)-20,40+40*i);
			run(baris,kolom,2);
		}
       else if(temp == 0 && temp2 == 0 &&  A[i-1][j]!=0){
		 	readimagefile("assets//img//inGame//player//char//karakter1.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
			delay(150);
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
		}
		else if(temp == 0 && (A[i+1][j]==0 || A[i-1][j]==0)){
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
			readimagefile("assets//img//inGame//maps//background.gif", (40*j)+20,40*i,(40+40*j)+20,40+40*i);
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
				readimagefile("assets//img//inGame//maps//background.gif", 40*j,(40*i)+20,40+40*j,(40+40*i)+20);
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

void pacmanLocation(){
	rowLocation = i;
	colLocation = j;
}

void returnPacman(){
	i = rowLocation;
	j = colLocation;
}

void movement(int l){
		ceksprite(k, i, j);
		A[i][j]=temp;
	tempMaps(temp, i, j);

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
			egg(A[i][j],i,j);
		}
	}
	i=15;
	j=1;
}

void next_level(){
	A[1][2]=7;
	if(i==1 && (j==1 || j==3)){
	}
	A[31][1]=7;
	if(i==31 && (j==1 || j==3)){
	}
	A[15][15]=7;
	if(i==15 && (j==1 || j==3)){
	}
	A[20][8]=7;
	if(i==20 && (j==1 || j==3)){
	}
}



int num_level(int l){
	if(A[i][j]==7){
		l++;
		if(l > 1){
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


void limitghost(int location){
	adress p;
	bool kiri, kanan, atas, bawah;
	if(p->up->info == 0 || p->up->info == 3 || p->up->info == 5 || p->up->info == 7 || p->up->info == 2 )
		atas = true;
	else
		atas = false;
	if(A[i+1][j]==0 || A[i+1][j]==3 || A[i+1][j]==5 || A[i+1][j]==7 || A[i+1][j]==2)
		bawah = true;
	else
		bawah = false;
	if(A[i][j-1]==0 || A[i][j-1]==3 || A[i][j-1]==5 || A[i][j-1]==7 || A[i][j-1]==2){
		kiri = true;
	} else{
		kiri = false;
	}
	if(A[i][j+1]==0 || A[i][j+1]==3 || A[i][j+1]==5 || A[i][j+1]==7 || A[i][j+1]==2){
		kanan = true;
	} else{
		kanan = false;
	}
	moveGhost(atas, bawah, kiri, kanan, location);
}

void ghostTrail(int dir){
	if(dir==dUp){
		if(A[i-1][j]==2){
			ghostmat = 2;
		}
		if(A[i-1][j]==0){
			ghostmat = 0;
		}
		if(A[i-1][j]==5){
			ghostmat = 5;
		}
	}
	if(dir==dDown){
		if(A[i+1][j]==2){
			ghostmat = 2;
		}
		if(A[i+1][j]==0){
			ghostmat = 0;
		}
		if(A[i+1][j]==5){
			ghostmat = 5;
		}
	}
	if(dir==dLeft){
		if(A[i][j-1]==2){
			ghostmat = 2;
		}
		if(A[i][j-1]==0){
			ghostmat = 0;
		}
		if(A[i][j-1]==5){
			ghostmat = 5;
		}
	}
	if(dir==dRight){
		if(A[i][j+1]==2){
			ghostmat = 2;
		}
		if(A[i][j+1]==0){
			ghostmat = 0;
		}
		if(A[i][j+1]==5){
			ghostmat = 5;
		}
	}
}

void moveGhost(bool up, bool down, bool left, bool right, int location){
	if(location == aboveLeft){
		if(up && !left){
			ghostTrail(dUp);
			A[i-1][j]=9;
			i--;
		}else
		if(up && left){
			ghostTrail(dUp);
			A[i-1][j]=9;
			i--;
		}else
		if(!up && left){
			ghostTrail(dLeft);
			A[i][j-1]=9;
			j--;
		}else
		// Agar tidak stuck di satu tempat jika tidak ada jalan, ghost digerakkan ke arah yang berlawanan
		if(!up && !left){
			if(down){
				ghostTrail(dDown);
				A[i+1][j]=9;
				i++;
			}else if(right){
				ghostTrail(dRight);
				A[i][j+1]=9;
				j++;
			}
		}
	}
	if(location == above){
		if(up){
			ghostTrail(dUp);
			A[i-1][j]=9;
			i--;
		}else
		// Agar tidak stuck
		if(!up){
			if(right){
				ghostTrail(dRight);
				A[i][j+1]=9;
				j++;
			}else if(down){
				ghostTrail(dDown);
				A[i+1][j]=9;
				i++;
			}else if(left){
				ghostTrail(dLeft);
				A[i][j-1]=9;
				j--;
			}
		}
	}
	if(location == aboveRight){
		if(up && !right){
			ghostTrail(dUp);
			A[i-1][j]=9;

			i--;
		}else
		if(up && right){
			ghostTrail(dRight);
			A[i][j+1]=9;

			j++;
		}else
		if(!up && right){
			ghostTrail(dRight);
			A[i][j+1]=9;

			j++;
		}else
		// Agar tidak stuck
		if(!up && !right){
			if(left){
				ghostTrail(dRight);
				A[i][j-1]=9;

				j--;
			}else if(down){
				ghostTrail(dDown);
				A[i+1][j]=9;

				i++;
			}
		}
	}
	if(location == Left){
		if(left){
			ghostTrail(dLeft);
			A[i][j-1]=9;

			j--;
		}else
		// Agar tidak stuck
		if(!left){
			if(right){
				ghostTrail(dRight);
				A[i][j+1]=9;

				j++;
			}else if(down){
				ghostTrail(dDown);
				A[i+1][j]=9;

				i++;
			}else if(up){
				ghostTrail(dUp);
				A[i-1][j]=9;

				i--;
			}
		}
	}
	if(location == Right){
		if(right){
			ghostTrail(dRight);
			A[i][j+1]=9;

			j++;
		}else
		// Agar tidak stuck
		if(!right){
			if(left){
				ghostTrail(dLeft);
				A[i][j-1]=9;

				j--;
			}else if(down){
				ghostTrail(dDown);
				A[i+1][j]=9;

				i++;
			}else if(up){
				ghostTrail(dUp);
				A[i-1][j]=9;

				i--;
			}
		}
	}
	if(location == belowLeft){
		if(down && left){
			ghostTrail(dDown);
			A[i+1][j]=9;

			i++;
		}else
		if(down && !left){
			ghostTrail(dDown);
			A[i+1][j]=9;

			i++;
		}else
		if(!down && left){
			ghostTrail(dLeft);
			A[i][j-1]=9;

			j--;
		}else
		// Agar tidak stuck
		if(!down && !left){
			if(right){
				ghostTrail(dRight);
				A[i][j+1]=9;

				j++;
			}else if(up){
				ghostTrail(dUp);
				A[i-1][j]=9;

				i--;
			}
		}
	}
	if(location == below){
		if(down){
			ghostTrail(dDown);
			A[i+1][j]=9;

			i++;
		}else
		// Agar tidak stuck
		if(!down){
			if(left){
				ghostTrail(dLeft);
				A[i][j-1]=9;

				j--;
			}else if(right){
				ghostTrail(dRight);
				A[i][j+1]=9;

				j++;
			}else if(up){
				ghostTrail(dUp);
				A[i-1][j]=9;

				i--;
			}
		}
	}
	if(location == belowRight){
		if(down && right){
			ghostTrail(dDown);
			A[i+1][j]=9;

			i++;
		}else
		if(down && !right){
			ghostTrail(dDown);
			A[i+1][j]=9;

			i++;
		}else
		if(!down && right){
			ghostTrail(dRight);
			A[i][j+1]=9;

			j++;
		}else
		// Agar tidak stuck
		if(!down && !right){
			if(left){
				ghostTrail(dLeft);
				A[i][j-1]=9;

				j--;
			}else if(up){
				ghostTrail(dDown);
				A[i-1][j]=9;

				i--;
			}
		}
	}
}


void checkPacmanLocation(){
	if((i>rowLocation) && (j>colLocation)){
		limitghost(aboveLeft);
	}
	else if((i>rowLocation) && (j == colLocation)){
		limitghost(above);
	}
	else if((i > rowLocation) && (j < colLocation)){
		limitghost(aboveRight);
	}
	else if((i == rowLocation) && (j > colLocation)){
		limitghost(Left);
	}
	else if((i == rowLocation) && (j < colLocation)){
		limitghost(Right);
	}
	else if((i < rowLocation) && (j > colLocation)){
		limitghost(belowLeft);
	}
	else if((i < rowLocation) && (j == colLocation)){
		limitghost(below);
	}
	else if((i < rowLocation) && (j < colLocation)){
		limitghost(belowRight);
	}
}
//
//void ghostt(){
//	for(i=0;i<BRS;i++){
//		for(j=0;j<KLM;j++){
//			if(A[i][j]==9){
//					ghost(i, j);
//						if(ghostmat == 5){	// Mengecek nilai matriks yang diinjak ghost
//							A[i][j]=5;
//							tempMapsGhost(temp, i, j);
//						}
//						if(ghostmat == 0){
//							A[i][j]=temp;
//							tempMaps(temp, i, j);
//						}
//						if(ghostmat ==2){
//							A[i][j]=2;
//						tempMapsGhift(temp, i, j);
//						}
//						checkPacmanLocation();
//						ghost(i, j);
//					}
//		}
//	}
//}


bool die(){
	if((A[i][j] == 9) || (A[i-1][j] == 9) || (A[i+1][j] == 9) || (A[i][j+1] == 9) || (A[i][j-1] == 9)){
		gameover_screen(scoree.point, scoree.duration.hours, scoree.duration.minute, scoree.duration.second);
		return 1;
	}
	return 0;
}


void menu_utama(){
	   
    sprite *gambar = sprite_create(50) ;
	   int x,y,lv;
    List maze;
	bool kiri, kanan, atas, bawah;
	int ltemp;
	int p=1; CreateList(&maze);
    soundmenu();
	menu:
	cleardevice();
	menu_awal();
	while(1){
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if((x>200 && x<200+351)&&(y>210 && y<210+230)){
			cleardevice();
			pilihan();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>150 && x<150+450)&&(y>50 && y<50+300)){
				int lv = 1;
				while(lv<=1){
					cleardevice();
					soundgame();
//					level(lv);
//					ltemp = lv;
                    cleardevice();
                    Makelist(&maze,lv);
                    map_view(gambar,maze);
                    getch();  lv = 1 ;
//					pacmanLocation();
//					if(lv==1){
//					timer_start();
//					}
//					while(lv>=1){
//					returnPacman();
//						pointt();
//						die();
//						movement(lv);
//						limit();
//						lv=num_level(lv);
//						pacmanLocation();
//						ghostt();
//						timer_end();
				}	}
				}
		    }else if ((x>700 && x<700+450)&&(y>50 && y<50+300)){
				while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>700 && x<700+450)&&(y>50 && y<50+300)){
				int lv = 2;
				while(lv<=2){
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					pacmanLocation();
					if(lv==2){
					timer_start();
					}
					while(lv>=2){
						returnPacman();
						pointt();
						die();
						movement(lv);
						limit();
						lv=num_level(lv);
						pacmanLocation();
						ghostt();
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
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					pacmanLocation();
					if(lv==3){
					timer_start();
					}
					while(lv>=3){
						returnPacman();
						pointt();
						die();
						movement(lv);
						limit();
						lv=num_level(lv);
						pacmanLocation();
						ghostt();
						timer_end();
					}
			}
				}
			}	goto menu;
			}else if ((x>700 && x<700+450)&&(y>380 && y<380+300)){
				while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>700 && x<700+450)&&(y>380 && y<380+300)){
				int lv = 4;
				while(lv<=4){
					cleardevice();
					soundgame();
					level(lv);
					ltemp = lv;
					maping();
					pacmanLocation();
					if(lv==4){
					timer_start();
					}
					while(lv==4){
						returnPacman();
						pointt();
						die();
						movement(lv);
						limit();
						lv=num_level(lv);
						pacmanLocation();
						ghostt();
						timer_end();
					}
			}
				}
			}	goto menu;
			
		
			}else if((x>200 && x<200+350)&&(y>460 && y<460+230)){
			view_leaderboard();
			leaderboard();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
					if((x>30 && x<30+150)&&(y>640 && y<700)){
					goto menu;
				}
			}
		}else if((x>650 && x<650+350)&&(y>460 && y<460+230)){
			while(1){
				how();
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>35 && x<35+80)&&(y>640 && y<652+80)){
					goto menu;
				}
			}
		}else if((x>650 && x<650+350)&&(y>210 && y<210+230)){
			about();
			while(1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if((x>30 && x<30+150)&&(y>640 && y<700)){
					goto menu;
				}
			}
		}else if((x>1150 && x<1150+80)&&(y>620 && y<620+80)){
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

 void timer(clock_t dur_h, clock_t dur_m, clock_t dur_s){
 scoree.duration.hours=dur_h;
 scoree.duration.minute=dur_m;
 scoree.duration.second=dur_s;
}
