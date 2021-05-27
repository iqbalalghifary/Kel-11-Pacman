#include"header/pacman.h"

void ghost_path(){
	bool kiri, kanan, atas, bawah;
	
	if (arah == 1)
	
	if(A[i-1][j]==0 || A[i-1][j]==7 || A[i-1][j]==5 ){
		atas = true;
	}else if(A[i][j]==0 && ( A[i][j-1]==1 || A[i][j+1]==1)){
		atas = false;
	}else if((i<=0)||(A[i+1][j]==1)){
		atas = false;
	}else if(A[i][j]==0 && A[i-1][j]==1 && ( A[i][j-1]==0 || A[i][j+1]==0)){
		atas = false;
	}else if(A[i][j]==0 && ( A[i][j-1]==3 || A[i][j+1]==3)){
		atas = false;
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

//void check_direction(){
//	if 
//}
//
//void check_path(){
//	if ()
//}
//
//if(A[i+1][j] != 0){
//							check = true;
//						} else{
//							check = false;
//						}
//						
//						
