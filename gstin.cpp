#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#define strset_length 36
#define gstin_length 15
using namespace std;

fstream fp,output;
int check_gstin(char ch_gstin[])
{
	string strset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char charset[strset_length];
	strcpy(charset,strset.c_str());
	char gstin_without_check_digit[gstin_length],check_digit;
	
	//ch_gstin = gstin_without_check_digit + check_digit
	strncpy(gstin_without_check_digit,ch_gstin,14);
	gstin_without_check_digit[14]='\0';
	check_digit=ch_gstin[14];
	
	int len=strset_length,factor=2,sum=0,check_code_point=0;
	for(int i=strlen(gstin_without_check_digit)-1;i>=0;i--)
	{
		int codepoint=-1;
		for(int j=0;j<strset_length;j++)
		{
			if(charset[j]==ch_gstin[i])
				codepoint=j;
		}
		int digit=factor*codepoint;
		factor=(factor==2)?1:2;
		digit=(digit/len)+(digit%len);
		sum+=digit;
	}
	check_code_point=(len-(sum%len))%len;
	if(check_digit==charset[check_code_point])
		return 1;
	else
		return 0;
}
int main(int argc,char *argv[])
{
	int count=0,processed=0;
	char gstin[15],*p,*party_name;
	string line;
	ifstream file(argv[1]);
	while(getline(file,line))
		count++;
	char buffer[50];
	output.open("result.txt",ios::out);
	fp.open(argv[1],ios::in);
	for(int i=1;i<=count;i++)
	{
		fp.getline(buffer,100);
		p=strtok(buffer,"|");
		strcpy(gstin,p);
		party_name=strtok(NULL,"\n");
		if(!check_gstin(gstin))
			output<<gstin<<"--"<<party_name<<"--INVALID\n";
		processed++;
	}
	fp.close();
	output<<"Records Checked = "<<processed<<"\n";
	output.close();
	return 0;
}
