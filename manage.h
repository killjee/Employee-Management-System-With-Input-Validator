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
}