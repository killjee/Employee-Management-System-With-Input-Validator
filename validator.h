#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function to take input name It validates:
		- Name must have first character as uppercase alphabet
		- Characters other than first character are lower case alphabets
		- Name must only contain characters
		- As, we need to take first name and last name separatly it wouldn't contain spaces too
Parameter to this function is a character pointer which will store the input name and if wrong
name is entered it will be an empty string with 1st character containing '\0'
*/
void input_name(char *ch) {

/*	Allocate memory to character arraya and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);

/*	Find lenth of string input and assign '\0' to last character*/
	int len=strlen(ch);
	ch[len]='\0';

/*	Validating first character is uppercase alphabet*/
	if(ch[0]<'A' && ch[0]>'Z') {
		ch[0]='\0';
		return;
	}

/*	Validating other characters are lowercase english characters*/
	int i;
	for (i=0 ; i<len ; i++) {
		if(ch[i]<'a' && ch[i]>'z') {
			ch[0]='\0';
			return;
		}
	}

	return;
}

/*Function to take validated input of email It validates:
		- Email must have exactly one '@' character
		- There must be a domain name after '@' character 
		- Domain name should be of format xyz.com
		- Example of email abc@xyz.com
Parameter to this function is a character pointer which will store the input email and if wrong
name is entered it will be an empty string with 1st character containing '\0'
*/
void input_emailid(char *ch) {
/*	Allocate memory to character arraya and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);

/*	Find lenth of string input and assign '\0' to last character*/
	int len=strlen(ch);
	ch[len]='\0';

/*	Validate if input contains exactly one '@' character*/
	int cnt=0,i,id=0;
	for (i=0 ; i<len ; i++) {
		if(ch[i]=='@') {
			id=i;
			cnt++;
		}
	}
	if(cnt!=1 || !isalpha(ch[len-1])) {
		ch[0]='\0';
		return;
	}

/*	Validating if input has a correct domain name*/
	int chk=0;
	cnt=0;
	for (i=id+1 ; i<len-1 ; i++) {
		if((ch[i]<='z' && ch[i]>='a') || (ch[i]>='A' && ch[i]<='Z'))	continue;
		if(ch[i]=='.')	cnt++;
		else	chk=1;
	}
	if(chk || cnt!=1) {
		ch[0]='\0';
		return;
	}
	return;
}

/*Function to take validated input of Date It validates:
		- Date Must be in a given range
		- Date must be proper no 31st February allowed but 29/02/2016 is allowed
		- date must be in format DD/MM/YYYY or DD-MM-YYYY
Parameter to this function is a character pointer which will store the input email and if wrong
name is entered it will be an empty string with 1st character containing '\0', Range of date in years
*/
void input_date(char *ch , int hi , int lo) {
/*	Allocate memory to character array and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);

/*	Find lenth of string input and assign '\0' to last character*/
	int len=strlen(ch);
	ch[len]='\0';

/*	Validating if input is of correct length*/
	if(len!=10) {
		ch[0]='\0';
		return;
	}

/* Validating if input's 2nd and 5th position is / or -*/
	if(ch[2]!='/' && ch[2]!='-') {
		ch[0]='\0';
		return;
	}
	if(ch[5]!='/' && ch[5]!='-') {
		ch[0]='\0';
		return;
	}

/*	Validating if other characters are digits*/
	int i;
	for (i=0 ; i<len ; i++) {
		if(i==2 || i==5)	continue;
		if(!isdigit(ch[i])) {
			ch[0]='\0';
			return;
		}
	}

/* Validating if year is in the given range*/
	int yea=0;
	for (i=6 ; i<len ; i++) {
		yea=yea*10;
		yea=yea+(ch[i]-'0');
	}
	if(yea<lo || yea>hi) {
		ch[0]='\0';
		return;
	}
/* Validating if date is not ambiguous*/
	int mo=0,da=0;
	mo=(ch[3]-'0')*10+(ch[4]-'0');
	da=(ch[0]-'0')*10+(ch[1]-'0');
	if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12) {
		if(da<1 || da>31) {
			ch[0]='\0';
			return;
		}
	}
	else if(mo==2) {
		if(da<1 || da>29)	return;
		if(da==29) {
			if(yea%100!=0 && yea%4!=0) {
				ch[0]='\0';
				return;
			}
			else if(yea%400!=0) {
				ch[0]='\0';
				return;
			}
		}
	}
	else {
		if(da<1 || da>30) {
			ch[0]='\0';
			return;
		}
	}

	return;
}

/*Function to take validated input of mobile number It validates:
		- Mobile number must be of 10 digits
		- Mobile number must have digits only.
Parameter to this function is a character pointer which will store the input email and if wrong
name is entered it will be an empty string with 1st character containing '\0'.
*/
void input_mobile(char *ch) {
/*	Allocate memory to character array and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);

/*	Find lenth of string input and assign '\0' to last character*/
	int len=strlen(ch);
	ch[len]='\0';

/*	Validating if input is of correct length*/
	if(len!=10) {
		ch[0]='\0';
		return;
	}

/*	Validating if input contains digits only*/
	for (i=0 ; i<len ; i++) {
		if(!isdigit(ch[i])) {
			ch[0]='\0';
			return;
		}
	}
}

/*Function to take input salary:
		- Salary must be integer
		- Salary must be in a given range
Parameter to this function is a character pointer which will store the input salary and if wrong
salary is entered it will be an empty string with 1st character containing '\0'.
*/
void input_salary(char *ch , int mi , int ma) {
/*	Allocate memory to character array and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);

/*	Find lenth of string input and assign '\0' to last character*/
	int len=strlen(ch);
	ch[len]='\0';

	if(len>8){
		ch[0]='\0';
		return;
	}

/*	Validating if input contains digits only*/
	int amt=0
	for (i=0 ; i<len ; i++) {
		if(!isdigit(ch[i])) {
			ch[0]='\0';
			return;
		}
		amt=amt*10;
		amt=amt+(ch[i]-'0');
	}

	if(amt<mi || amt>ma) {
		ch[0]='\0';
		return;
	}
}

/*Function to take input salary:
		- Salary must be integer
		- Salary must be in a given range
Parameter to this function is a character pointer which will store the input salary and if wrong
salary is entered it will be an empty string with 1st character containing '\0'.
*/
void input_designation(char *ch ) {
/*	Allocate memory to character array and take input*/
	ch=(char *)malloc(sizeof(char)*25);
	scanf("%s",&ch);
	int len=strlen(ch);

	ch[len]='\0';
	return;
}