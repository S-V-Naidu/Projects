#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N strlen(g)
char t[128], cs[128], g[]="10110";
int a,e,c;
void xorr() {
	for(c=1; c<N; c++)
		cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc() {
	for(e=0; e<N; e++)
	{
	
		cs[e]=t[e];
}
	do {
		if(cs[0]=='1')
		{
		
			xorr();
		}
		for(c=0; c<N-1; c++)
		{
		
			cs[c]=cs[c+1];
		}
		cs[c]=t[e++];

	} while(e<=a+N-1);

}
int main() {
	printf("\nEnter poly: ");
	scanf("%s",t);
	printf("\nGenerating polynominal is: %s\n",g);
	a=strlen(t);
	for(e=a; e<a+N-1;e++)
	{
		t[e]='0';
	}
	printf("\nModified polynomial: %s\n",t);
	crc();
	printf("\nCheckSum: %s\n",cs);
	for(e=a; e<a+N-1; e++)
		t[e]=cs[e-a];
	printf("\nFinal codeword is:%s\n",t);
	int pos,check;
	int count=0;
up:	printf("\nError detection 1(yes) 0(no): ");
	scanf("%d",&check);
	if(check==1){
		printf("\nEnter postion to insert error: ");
		scanf("%d",&pos);
		t[pos]=(t[pos]==1)?'0':'1';
		printf("\nError detected!!");
	} 
	else if(check==0){
		printf("\nNo error detected:(");
	}
	else{
		if(count==5){
			printf("\nJust go to hell you piece of shit!");
			exit(0);
		}
		printf("\nEnter any of the two given choices!\n");
		if(count==4){
			printf("\nThis is the last warning!!");
		}
		count++;
		goto up;
	}
	return 0;
}
