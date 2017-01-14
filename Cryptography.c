/*알고리즘 및 설명
Step 1 : FILE 포인터를 통해 number.txt에서 16진수의 수를 fscanf로 받아 input변수에 저장한다.
Step 2 : N번째의 비트가 어떤 수 인지 반환하는 getNbit()함수와 N번째 비트의 값을 바꾸어주는 함수 setNbit()함수를 정의한다.
Step 3 : Step2의 함수들을 이용하여 input변수는 상위4bit 하위4bit로 나누어, 중복 값으로 8bit를 만들어주는 함수 Alter()로 호출 된다. 각각 c1, c2에 저장된다.
Step 4 : c1또는 c2의 8번째 비트가 1(음수)이면 setNbit()를 통해 0으로 바꾸어 준다.
Step 5 : 결과 값을 저장하는 텍스트파일을 출력한다.
*/

//Program that receives hexadecimal integer and sends lower nibble and upper nibble to 8bit each
//If the eighth bit is 1 (negative), change it to 0
//basic Cryptography

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char getNbit(int c,char input) 
{ 
	char i;
    i=1<<(c-1);
	if((i&input)!=0) return 1;
	else return 0;
}
char setNbit(int c, char input, int r) 
{
	char i=1;
	if(r==getNbit(c,input)) return input;
	else
	{
	i=1<<(c-1);
	return i^input;
	}
}
char Alter(int l1,int l2, char c) 
{
	int num=1,i,j;
	char k;
	for(i=0;i<2;i++)
		for(j=l1;j<l2;j++)
		{
			k=getNbit(j+1,c);
			c=setNbit(num++,c,k);
		}
	return c;
}
int main()
{ 
       char c1=0,c2=0;
	char input=0;
	FILE *fp1=fopen("originalDOC","rt");
	FILE *fp2=fopen("CryptographyDOC","wt");
	
	while(1)
      {
	input=fgetc(fp1);
	if(input==EOF) break;
	
       c2=Alter(0,4,input);
	c1=Alter(4,8,input);
	
       if(getNbit(8,c1)) c1=setNbit(8,c1,0);
	if(getNbit(8,c2)) c2=setNbit(8,c2,0);	
	fprintf(fp2,"%x%x ",c1,c2);
       }
       fclose(fp1);
	fclose(fp2);
	return 0;
}
