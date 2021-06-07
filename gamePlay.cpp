#include "siluman.h"

int A[BARIS][KOLOM];
int i=1,j,e,temp,k,temp2;
int rowLocation, colLocation;

typedef struct{
	char name[10];
	int point;
}vScore;

vScore skor;

//============================PROSEDUR MENENTUKAN LEVEL MAP========================================
void set_level(int l){
	int a,b;
	for(a=0;a<BARIS;a++){
		for(b=0;b<KOLOM;b++){
			A[a][b]=maps_level(l, a, b);
		}
	}
}
//============================PROSEDUR MEMBACA GAMBAR UNTUK TEMP PADA MAP==========================
void mapTemps(int temp, int baris, int kolom){
	if(temp==0){
		readimagefile("assets//img//inGame//maps//background.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
	if(temp==1){
		readimagefile("assets//img//inGame//maps//bata.jpg", 40*kolom-1,40*baris,40+40*kolom-1,40+40*baris);
	}
}
//============================PROSEDUR MENGATUR BATAS PERGERAKAN PLAYER============================
void move_limit(){
	bool kiri, kanan, atas, bawah;
	if(A[i-1][j]==0 || A[i-1][j]== 5 || A[i-1][j]== 6 || A[i-1][j]== 10 ){
		atas = true;
	}else{
        atas = false;
	}

	if(A[i+1][j]==0 || A[i+1][j]==5 || A[i+1][j]==6 || A[i+1][j]==10 ){
		bawah = true;
	}else{
        bawah = false;
	}
	if(A[i][j-1]==0 || A[i][j-1]==5 || A[i][j-1]==6 || A[i][j-1]==10){
		kiri = true;
	}

	if(A[i][j+1]==0 || A[i][j+1]==5 || A[i][j+1]==6 || A[i][j+1]==10){
		kanan = true;
	}
	player_movement(atas,bawah,kiri,kanan);
}
//============================PROSEDUR TOMBOL UNTUK PERGERAKAN PLAYER==============================
void player_movement(bool up, bool down, bool left, bool right){
	switch(getch())
	{
		case KEY_UP	:
			if(up){
                k=0;
				i--;
			}
			break;
		case KEY_RIGHT:
			if(right){
                k = 1;
				j++;
			}
			break;
		case KEY_DOWN	:
			if(down){
                k=3;
				i++;
			}
			break;
		case KEY_LEFT	:
			if(left){
                k = 2;
				j--;
			}
			break;
	}
}
//============================PROSEDUR CEKSPRITE DAN PERGERAKAN SELANJUTNYA========================
void ceksprite(int sprite, int baris, int kolom){
	if(sprite==0){
		if(temp == 0 || temp2 ==0){
			atas(baris,kolom,3);
		}
	}
	if(sprite==1){
		if(temp == 0 || temp2 ==0){
			samping(baris,kolom,1);
        }
	}
	if(sprite==2){
		if(temp == 0 || temp2 ==0){
            samping(baris,kolom,2);
		}
	}
	if(sprite==3){
            bawah(baris, kolom,4);
	}
}
//============================PROSEDUR INISIALISASI TEMP===========================================
void setTemp(){
	temp2 = temp;
	temp = A[i][j];
	if(temp == 5 || temp == 6  ){
		temp = 0;
	}
}

void lokasiPacman(){
    rowLocation = i;
    colLocation = j;
}

void returnPacman(){
    i = rowLocation;
    j = colLocation;
}
//============================PROSEDUR MENGATUR POSISI KARAKTER PADA MAP===========================
void player_maping(){
	for(i=0;i<BARIS;i++){
		for(j=0;j<KOLOM;j++){
			maps(A[i][j],i,j);
		}
	}
	i=9;
	j=16;
}
//============================FUNCTION UNTUK MENGHITUNG POIN PLAYER================================
int score(int matrix, int brs, int klm, int p){
	if (matrix==5){
		p++;
//		_beginthread(score_sound,0,NULL);
	}else if (matrix==6){
        p=p+10;
	}
	return p;
}
//============================PROSEDUR INISIALISASI NILAI UNTUK SKOR BAR===========================
void setPoint(){
	skor.point=score(A[i][j],0,0,skor.point);
	score_bar(skor.point);
}
//============================PROSEDUR MENENTUKAN TEMP PADA MAPS SETELAH BERGERAK==================
void movement(int l){
	A[i][j]=1;
	if(A[i][j]==1){
		ceksprite(k, i, j);
		e=getch();
		A[i][j]=temp;
	}
	mapTemps(temp, i, j);
	endPoint(skor.point, l);
}
//============================PROSEDUR MENAMPILKAN GAMBAR SEBAGAI GERBANG NEXT LEVEL===============
void mapsEnd(){
	A[1][2]=10;
	gerbang(1,2);
}
//============================PROSEDUR COLLISION KETIKA MENABRAK MUSUH=============================
void player_die(){
    if(A[i][j]==9){
        game_over(i,j);
		game_end(skor.point);
    }
}
//============================FUNCTION MENENTUKAN LEVEL SELANJUTNYA SETELAH MASUK GERBANG==========
int set_level2(int l){
	if(A[i][j]==10){
		l++;
		if(l > 3){
			screen_winner(skor.point);
			scr_highScore(skor.point);
		}
		delay(1000);
	}
	return l;
}
//============================PROSEDUR MENAMPILKAN GERBANG SETELAH LIMIT POINT SETIAP MAPS=========
void endPoint(int p, int l){
	if(l == 1){
		if(p == 398){
			mapsEnd();
		}
	}else if(l == 2){
		if(p ==706){
			mapsEnd();
		}
	}else if(l == 3){
		if(p == 1050){
			mapsEnd();
		}
	}
}
//============================PROSEDUR MENYIMPAN FILE SKOR PLAYER==================================
void save_file(char* name, int l){
	vScore p;
	FILE *fsiluman;

	strcpy(p.name,name);
	p.point = l;
	if((fsiluman=fopen("SILUMAN.dat", "ab+")) == NULL){
		printf("File tidak dapat dibuka!\n");
	}else{
		fwrite(&p, sizeof(vScore), 1, fsiluman);
	}
	fclose(fsiluman);
}
//============================PROSEDUR MENAMPILKAN HIGH SCORE======================================
void high_score(){
	vScore p;
	FILE *fsiluman;
	char view[15];
	int n=1;
	int tinggi = 250;
	sort_file();
	if((fsiluman=fopen("SILUMAN.dat", "rb")) == NULL){
		printf("File tidak dapat dibuka!\n");
	}else{
		rewind(fsiluman);
		while (fread(&p, sizeof(vScore), 1, fsiluman) == 1 && n <= 5){
			settextstyle(2, 0, 8);
			sprintf(view,"%i",n);
			outtextxy(430, tinggi, view);
			sprintf(view,"%s",p.name);
			outtextxy(460, tinggi, view);
			sprintf(view,"%d",p.point);
			outtextxy(900, tinggi, view);
			tinggi += 40;
			n++;
		}
	}
	fclose(fsiluman);
}
//============================PROSEDUR SORTING DATA DALAM FILE=====================================
void sort_file(){
    FILE *fsiluman;
	vScore data,temp;

	int i, x, vSize, vFile;

	if ((fsiluman=fopen("SILUMAN.DAT", "rb+"))==NULL)
      {
            printf ("File tidak dapat dibuka\n");
      }
	vSize = sizeof(vScore);
	fseek(fsiluman, 0, SEEK_END);
	vFile = ftell(fsiluman);

	rewind(fsiluman);
	for(i=0;i< vFile; i += vSize){
		for(x=0;x< vFile - vSize; x += vSize){
			fread(&data, vSize, 1, fsiluman);
			fread(&temp, vSize, 1, fsiluman);
			if(data.point<temp.point){
				fseek(fsiluman, -(vSize * 2), SEEK_CUR);
				fwrite(&temp, vSize, 1, fsiluman);
				fwrite(&data, vSize, 1, fsiluman);
				fseek(fsiluman, -vSize , SEEK_CUR);
			}
			else{
				fseek(fsiluman, -vSize , SEEK_CUR);
			}
		}
		rewind(fsiluman);
	}
	fclose(fsiluman);
}


void mapTempsGhost(int temp, int baris, int kolom){

    readimagefile("assets//img//inGame//pelet.jpg", 30*kolom-1, 30*baris-1,30*kolom-1,30*baris,30+30*kolom-1,30+30*baris);
}
void ghost(){
 for(i=0;i<18;i++){
    for(j=0;j<32;j++){
        if(A[i][j] == 7){
            enemy(i,j);
            A[i][j]=temp;
            mapTempsGhost(temp,i,j);

            int x = rand() % 4 + 1;
            switch(x){
            case 1:
                A[i+1][j]=7;
                i++;
                break;
            case 2:
                A[i-1][j]=7;
                i--;
                break;
            case 3:
                A[i][j+1]=7;
                j++;
                break;
            case 4:
                A[i][j-1]=7;
                j--;
                break;
                }
            enemy(i,j);
            }
        }
    }
}
void limit_enemy(){
	bool kiri, kanan, atas, bawah;
	if(A[i-1][j]==0 || A[i-1][j]== 5 || A[i-1][j]== 6 || A[i-1][j]== 10 ){
		atas = true;
	}else{
        atas = false;
	}

	if(A[i+1][j]==0 || A[i+1][j]==5 || A[i+1][j]==6 || A[i+1][j]==10 ){
		bawah = true;
	}else{
        bawah = false;
	}
	if(A[i][j-1]==0 || A[i][j-1]==5 || A[i][j-1]==6 || A[i][j-1]==10){
		kiri = true;
	}

	if(A[i][j+1]==0 || A[i][j+1]==5 || A[i][j+1]==6 || A[i][j+1]==10){
		kanan = true;
	}
	enemy_movement(bool up, bool down, bool left, bool right);
}

void enemy_movement(bool up, bool down, bool left, bool right){
 			if(up){
                k=0;
                while(temp==0){

				i--;
				delay(1000);
                }

			}
			if(right){
                k = 0;
                while(temp==0){

				j++;
				delay(1000);
                }
			}

			if(down){
                    k=0;
                    while(temp==0){

				i++;
				delay(1000);
                    }
			}
			if(left){
			    k = 0;
                while(temp==0){

				j--;
				delay(1000);
                }
			}
}

