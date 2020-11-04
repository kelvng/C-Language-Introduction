//============================================================================
// Name        : maiantiem.c
// Author      : Nguyen Quoc Thuan
// Version     : 1.0
//============================================================================

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

/**********************************************************************
 * Ham: doc_File
**********************************************************************/
bool doc_File(int *hp, int *d, int *s)
{
	FILE *read;
	read = fopen("input.txt", "r");
	fscanf(read,"%d",&(*hp));
	fscanf(read,"%d",&(*d));
	fscanf(read,"%d",&(*s));
	fclose(read);

	if (*hp < 1 || *hp > 999) return false;
	if (*d < 1 || *d > 1000) return false;
	if (*s < 1 || *s > 100) return false;

	return true;
}

/**********************************************************************
 * Ham: ghi_File
 * Sinh vien can hoan chinh ham ghi_file de thuc hien viec ghi ket qua pR
vao file output.out tai thu muc lam viec
**********************************************************************/
void ghi_File(float pR)
{
	//sinh vien viet code de thuc hien viec ghi ket qua pR vao file output.out tai thu muc lam viec
	FILE *fptr;
	fptr = fopen("output.out", "w");
	fprintf(fptr,"%.3f",pR);
	fclose(fptr);
}

/**********************************************************************
 * Name: main
 * Target: Implements your application
 **********************************************************************/

int kiemtra(int hp){
    int i;
    int count = 0;
    if(hp < 2){
        return 0;
    }
    
    for(i = 2; i <= sqrt(hp); i++){
        if(hp % i == 0){
            count++;
        }
    }
    if(count == 0){
        return 1;
    }
	else{
        return 0;
    }
}

int tinhgs(s){
	float gs;
	if(s%6 == 0){
		gs =s/2;
	}
	else if(s%6 == 1){
		gs =2*s;
	}
	else if(s%6 == 2){
		gs = pow(-(s%9),3)/5;
	}
	else if(s%6 == 3){
		gs = -(pow((s%30),2)+3*s);
	}
	else if(s%6 == 4){
		gs = -s;
	}
	else if(s%6 ==5){
		int i;
		int temp;
		temp = (s%5)+5;
		for (i = 1; i <= temp; i++){
			gs = gs + i;
		}
		gs = gs * -1;
	}
	return gs;
}

int main() {
	
	int hp = 0;
	int d = 0;
	int s = 0;
	float P1 = 0;
	float P2 = 0;
	float pR = -1;
	int nguyento = 0;
	

	if(doc_File(&hp, &d, &s)){
		
		int i;
		float fds;
		float gs;
		//sinh vien viet code thuc hien tinh theo yeu cau de baï
		if(kiemtra(hp) == 1){
			P1 = 1000;
			P2 = (hp + s) % 1000;
		}
		else{
			P1 = hp;
			P2 = (hp + d) % 100;
		}
		
		if(d < 200){
			fds = 0;
		}
		
		if(200 <= d &&  d<= 800){
			tinhgs(s);
			fds = 40-(fabs(d -500)/20)+gs;
		}
		
		if(200 <= d && d<= 800){
			fds = 40-(fabs(d -500)/20)+gs;
		}
		
		if(200 < d && d< 300){
			fds =(d +P1+P2)/1000;
			if (fds > 0.8){
				fds = -999;
			}
		}
		
		if(d>800){
			fds=-d*s/1000;
		}
		
		if(fds == -999){
			pR =0;
		}
		else{
			pR = (P1+P2*fds)/(1000+fabs(P2*fds));
		}
		
		if(pR < 0){
			pR = 0;
		}
		
		
	}
	
	
	
	ghi_File(pR);
	float test;
	FILE *t;
	t = fopen("output.out", "r");
	if(t!=NULL){	
		fscanf(t,"%f",&test);
		printf("%f",test);
		fclose(t);
	}
	else{
		printf("DOC FILE KHONG THANH CONG");
		printf("-1");
	}
	return 2020;
}


