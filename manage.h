#include "validator.h"

void register_new_employee(int id) {
	FILE *fp;
	fp=fopen("Data.txt","a");

	printf("Please input your first Name: ");

	char *f_name;
	while (1) {
		input_name(f_name);
		if(f_name[0]!='\0')	break;
		printf("\nFirst Name not in correct format input again\n");
	}

	printf("Please input your Middle Name: ");

	char *m_name;
	while (1) {
		input_name(m_name);
		if(m_name[0]!='\0')	break;
		printf("\nMiddle Name not in correct format input again \n");
	}

	printf("Please input your Last Name: ");

	char *l_name;
	while (1) {
		input_name(l_name);
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
		input_mobile(mobile,2000,2016);
		if(mobile[0]!='\0')	break;
		printf("\nmobile number not in correct format input again\n");
	}

	printf("Please input your salary: ");

	char *salary;
	while (1) {
		input_salary(salary,2000,2016);
		if(salary[0]!='\0')	break;
		printf("\nsalary not in correct format input again\n");
	}

	printf("Please input your designation: ");

	char *designation;
	while (1) {
		input_designation(designation,2000,2016);
		if(designation[0]!='\0')	break;
		printf("\ndesignation not in correct format input again\n");
	}

	fprintf(fp,"%d\n", id);
	fprintf(fp,"%s\n", f_name);
	fprintf(fp,"%s\n", m_name);
	fprintf(fp,"%s\n", l_name);
	fprintf(fp,"%s\n", email);
	fprintf(fp,"%s\n", dob);
	fprintf(fp,"%s\n", doj);
	fprintf(fp,"%s\n", mobile);
	fprintf(fp,"%s\n", salary);
	fprintf(fp,"%s\n", designation);
	fclose(fp);
}

void retrive_data(){
	FIILE *fp;
	fopen("Data.txt","r");

	while (fscanf(fp,"%d",emp_id[cnt])) {
		fscanf(fp,"%s",f_nam[cnt]);
		fscanf(fp,"%s",m_nam[cnt]);
		fscanf(fp,"%s",l_nam[cnt]);
		fscanf(fp,"%s",email[cnt]);
		fscanf(fp,"%s",do_b[cnt]);
		fscanf(fp,"%s",do_j[cnt]);
		fscanf(fp,"%s",mobi[cnt]);
		fscanf(fp,"%s",doj[cnt]);
		fscanf(fp,"%s",salary[cnt]);
		fscanf(fp,"%s",designation[cnt]);
		cnt++;
	}

}

int get_id() {
	int p=0,q=cnt;
	while (q!=0) {
		p=p*10+(q%5);
		q/=5;
	}
	return p;
}

int search_idx(int id) {
	int i;
	for (i=0 ; i<cnt ; i++) {
		if(id==emp_id[i])	return i;
	}
	return -1;
}
