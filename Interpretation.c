//Code to interpret

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
char* Check(char* num)
{
	switch(*num){
         case 'a': *num=10; return num;
	  case 'b': *num=11; return num;
	  case 'c': *num=12; return num;
	  case 'd': *num=13; return num;
	  case 'e': *num=14; return num;
	  case 'f': *num=15; return num;
	}
}
char ReAlter(char c2,char c4) 
{
	int j;
	char k,num=1;
	
	if('a'<=c2&&c2<='z')
		Check(&c2);
	if('a'<=c4&&c4<='z')
		Check(&c4);

		for(j=4;j<8;j++)
		{
			k=getNbit(num++,c2);
			c2=setNbit(j+1,c2,k);
		}
		printf("%x ",c2);
		num=1;
		for(j=0;j<4;j++)
		{
		    k=getNbit(num++,c4);
		    c2=setNbit(j+1,c2,k);
		}
		printf("%x\n",c2);
	       return c2;
}
void main()
{
 FILE* fp1=fopen("originalDOC","rt");
 FILE* fp2=fopen("CryptographyDOC","wt");
 char c1,c2,c3,c4,c5,input;
	
      while(1){
		c1=fgetc(fp1);
		if(c1==EOF) break;
		c2=fgetc(fp1);
		c3=fgetc(fp1);
		c4=fgetc(fp1);
		
              if(c4==' ')
		{
		if(c1=='0')
			input=ReAlter(c1,c3);
		else if(c3=='0')
		       input=ReAlter(c2,c3);
		}
		else
		{
		c5=fgetc(fp1); 
		input=ReAlter(c2,c4);
		}

		printf("%c %c %c %c %c\n",c1,c2,c3,c4,c5);
		printf("%x\n",input);
		fprintf(fp2,"%c",input);

	       fclose(fp1);
	       fclose(fp2);
	}
}