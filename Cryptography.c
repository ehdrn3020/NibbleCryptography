/*�˰��� �� ����
Step 1 : FILE �����͸� ���� number.txt���� 16������ ���� fscanf�� �޾� input������ �����Ѵ�.
Step 2 : N��°�� ��Ʈ�� � �� ���� ��ȯ�ϴ� getNbit()�Լ��� N��° ��Ʈ�� ���� �ٲپ��ִ� �Լ� setNbit()�Լ��� �����Ѵ�.
Step 3 : Step2�� �Լ����� �̿��Ͽ� input������ ����4bit ����4bit�� ������, �ߺ� ������ 8bit�� ������ִ� �Լ� Alter()�� ȣ�� �ȴ�. ���� c1, c2�� ����ȴ�.
Step 4 : c1�Ǵ� c2�� 8��° ��Ʈ�� 1(����)�̸� setNbit()�� ���� 0���� �ٲپ� �ش�.
Step 5 : ��� ���� �����ϴ� �ؽ�Ʈ������ ����Ѵ�.
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
