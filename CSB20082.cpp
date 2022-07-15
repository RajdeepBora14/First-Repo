#include <stdio.h>
#include <math.h>
void bin_byte(char,int[]); /* function to convert a byte value to 
binary string */
void ieee754(float *,int[]); 
/* function to print the byte values of a float using IEEE754 
format S-E-M */


/* Function to convert byte value to binary */
void bin_byte(char num,int bin[8])
{
int i;
for (i=7;i>=0;i--)
{
if (((int)pow(2,i) & num)!=0)
    bin[i]=1;
else
    bin[i]=0;
}

}
/* Function to print byte values of a given float number */
void ieee754(float *f,int BIN[32])
{
char b0,b1,b2,b3, *ptrb;
/* Breaking the number n into 4 bytes, b0, b1, b2, b4 */
ptrb=(char*)f;
b0=*ptrb;
b1=*(ptrb+1);
b2=*(ptrb+2);
b3=*(ptrb+3);

int B3[8],B2[8],B1[8],B0[8];
bin_byte(b3,B3);
bin_byte(b2,B2);
bin_byte(b1,B1);
bin_byte(b0,B0);

int i,j;

for( i= 31,j=7;i>=24&&j>=0 ;i--,j--){
	BIN[i]=B3[j];
}
for( i= 23,j=7;i>=16&&j>=0 ;i--,j--){
	BIN[i]=B2[j];
}
for( i= 15,j=7;i>=8&&j>=0 ;i--,j--){
	BIN[i]=B1[j];
}
for( i= 7;i>=0;i--){
	BIN[i]=B0[i];
}


}


int datarep(float f){
	int Data[32];
	ieee754(&f,Data);
	int i,j;
	int k=1;
	int num=0;
	for( i = 31;i>=0;i--){
		if(i%4==0){
			printf("%d	",Data[i]);
		}else{
			printf("%d",Data[i]);
		}
	}
	
	for(j=0;j<32;j++){
		if(k&Data[j]==1)
		   num+=pow(2,j);
	}
	return num;
}




int main() {
float f;
printf("Give a floating point number:");
scanf("%f",&f);
 datarep(f);
return 0;
}