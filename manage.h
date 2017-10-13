#include "validator.h"

int cnt;
int emp_id[1005];
char f_name[1005][30],l_name[1005][30],m_name[1005][30];
char emai[1005][30],do_b[1005][30],do_j[1005][30];
char mobi[1005][30],salar[1005][30],designatio[1005][30];

void register_new_employee(int id , int cnt) {
	FILE *fp;
	fp=fopen("Data.txt","a");

	printf("Please input your first Name: ");

	char f_nam[30];
	while (1) {
		int bkhl=input_name(f_nam);
		if(bkhl)	break;
		printf("\nFirst Name not in correct format input again\n");
	}

	printf("Please input your Middle Name: ");

	char m_nam[30];
	while (1) {
		if(input_name(m_nam))	break;
		printf("\nMiddle Name not in correct format input again \n");
	}

	printf("Please input your Last Name: ");

	char l_nam[30];
	while (1) {
		if(input_name(l_nam)) {
			break;
		}
		printf("\nLast Name not in correct format input again \n");
	}

	printf("Please input your email id: ");

	char email[30];
	while (1) {
		if(input_emailid(email))	break;
		printf("\nEmail not in correct format input again\n");
	}

	printf("Please input your D.O.B: ");

	char dob[30];
	while (1) {
		if(input_date(dob,1970,2000))	break;
		printf("\ndob not in correct format input again\n");
	}

	printf("Please input your D.O.J: ");

	char doj[30];
	while (1) {
		if(input_date(doj,1950,2016))	break;
		printf("\ndoj not in correct format input again\n");
	}

	printf("Please input your mobile number: ");

	char mobile[30];
	while (1) {
		if(input_mobile(mobile))	break;
		printf("\nmobile number not in correct format input again\n");
	}

	printf("Please input your salary: ");

	char salary[30];
	while (1) {
		if(input_salary(salary,2000,2016))	break;
		printf("\nsalary not in correct format input again\n");
	}

	printf("Please input your designation: ");

	char designation[30];
	while (1) {
		if(input_designation(designation))	break;
		printf("\ndesignation not in correct format input again\n");
	}

	fprintf(fp,"%d\n", id);
	fprintf(fp,"%s\n", f_nam);
	fprintf(fp,"%s\n", m_nam);
	fprintf(fp,"%s\n", l_nam);
	fprintf(fp,"%s\n", email);
	fprintf(fp,"%s\n", dob);
	fprintf(fp,"%s\n", doj);
	fprintf(fp,"%s\n", mobile);
	fprintf(fp,"%s\n", salary);
	fprintf(fp,"%s\n", designation);
	emp_id[cnt]=id;
	strcpy(f_name[cnt],f_nam);
	strcpy(m_name[cnt],m_nam);
	strcpy(l_name[cnt],l_nam);
	strcpy(emai[cnt],email);
	strcpy(do_b[cnt],dob);
	strcpy(do_j[cnt],doj);
	strcpy(mobi[cnt],mobile);
	strcpy(salar[cnt],salary);
	strcpy(designatio[cnt],designation);
	cnt++;

	fclose(fp);
}

void retrive_data(){
	FILE *fp;
	fp=fopen("Data.txt","r");

	while (fscanf(fp,"%d",&emp_id[cnt])!=EOF) {
		fscanf(fp,"%s",f_name[cnt]);
		fscanf(fp,"%s",m_name[cnt]);
		fscanf(fp,"%s",l_name[cnt]);
		fscanf(fp,"%s",emai[cnt]);
		fscanf(fp,"%s",do_b[cnt]);
		fscanf(fp,"%s",do_j[cnt]);
		fscanf(fp,"%s",mobi[cnt]);
		fscanf(fp,"%s",salar[cnt]);
		fscanf(fp,"%s",designatio[cnt]);
		cnt++;
	}

}

int get_id(int cnt) {
	int p=0,q=cnt;
	while (q!=0) {
		p=p*10+(q%5);
		q/=5;
	}
	return p;
}

int search_idx(int id , int cnt) {
	int i;
	for (i=0 ; i<cnt ; i++) {
		if(id==emp_id[i])	return i;
	}
	return -1;
}

int modify_idx(int id , int cnt) {
	int a=search_idx(id,cnt);
	if(a==-1)	return -1;

	FILE *fp;
	fp=fopen("Data.txt","w");

	printf("Please input your first Name: ");

	char *f_nam;
	while (1) {
		input_name(f_nam);
		if(f_name[0]!='\0')	break;
		printf("\nFirst Name not in correct format input again\n");
	}

	printf("Please input your Middle Name: ");

	char *m_nam;
	while (1) {
		input_name(m_nam);
		if(m_name[0]!='\0')	break;
		printf("\nMiddle Name not in correct format input again \n");
	}

	printf("Please input your Last Name: ");

	char *l_nam;
	while (1) {
		input_name(l_nam);
		if(l_name[0]!='\0')	break;
		printf("\nLast Name not in correct format input again\n");
	}

	printf("Please input your email id: ");

	char *email;
	while (1) {
		input_emailid(email);
		if(email[0]!='\0')	break;
		printf("\nEmail not in correct format input again\n");
	}

	printf("Please input your D.O.B: ");

	char *dob;
	while (1) {
		input_date(dob,1970,2000);
		if(dob[0]!='\0')	break;
		printf("\ndob not in correct format input again\n");
	}

	printf("Please input your D.O.J: ");

	char *doj;
	while (1) {
		input_date(doj,2000,2016);
		if(doj[0]!='\0')	break;
		printf("\ndoj not in correct format input again\n");
	}

	printf("Please input your mobile number: ");

	char *mobile;
	while (1) {
		input_mobile(mobile);
		if(mobile[0]!='\0')	break;
		printf("\nmobile number not in correct format input again\n");
	}

	printf("Please input your salary: ");

	char *salary;
	while (1) {
		input_salary(salary,1000,2000000);
		if(salary[0]!='\0')	break;
		printf("\nsalary not in correct format input again\n");
	}

	printf("Please input your designation: ");

	char *designation;
	while (1) {
		input_designation(designation);
		if(designation[0]!='\0')	break;
		printf("\ndesignation not in correct format input again\n");
	}

	emp_id[a]=id;
	strcpy(f_name[a],f_nam);
	strcpy(m_name[a],m_nam);
	strcpy(l_name[a],l_nam);
	strcpy(emai[a],email);
	strcpy(do_b[a],dob);
	strcpy(do_j[a],doj);
	strcpy(mobi[a],mobile);
	strcpy(salar[a],salary);
	strcpy(designatio[a],designation);

	for (int i=0 ; i<cnt ; i++) {
		fprintf(fp,"%d\n", id);
		fprintf(fp,"%s\n", f_name[i]);
		fprintf(fp,"%s\n", m_name[i]);
		fprintf(fp,"%s\n", l_name[i]);
		fprintf(fp,"%s\n", emai[i]);
		fprintf(fp,"%s\n", do_b[i]);
		fprintf(fp,"%s\n", do_j[i]);
		fprintf(fp,"%s\n", mobi[i]);
		fprintf(fp,"%s\n", salar[i]);
		fprintf(fp,"%s\n", designatio[i]);
	}

	fclose(fp);
	return 1;
}

int del_idx(int id , int cnt) {
	int a=search_idx(id,cnt);
	if(a==-1)	return -1;

	FILE *fp;
	fp=fopen("Data.txt","w");
	for (int i=0 ; i<cnt ; i++) {
		if(i==a)	continue;
		fprintf(fp,"%d\n", id);
		fprintf(fp,"%s\n", f_name[i]);
		fprintf(fp,"%s\n", m_name[i]);
		fprintf(fp,"%s\n", l_name[i]);
		fprintf(fp,"%s\n", emai[i]);
		fprintf(fp,"%s\n", do_b[i]);
		fprintf(fp,"%s\n", do_j[i]);
		fprintf(fp,"%s\n", mobi[i]);
		fprintf(fp,"%s\n", salar[i]);
		fprintf(fp,"%s\n", designatio[i]);
	}

	fclose(fp);
	return 1;
}
