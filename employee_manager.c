#include "manage.h"

int cnt=0;
int emp_id[1005];
char f_nam[1005][30],l_name[1005][30],m_name[1005][30];
char emai[1005][30],do_b[1005][30],do_j[1005][30];
char mobi[1005][30],salar[1005][30],designtio[1005][30];

int main() {
	retrive_data();
	while (1) {
		printf("Menu Driven Employee Managment SyStem With Data Validation\n");
		printf("1. Press 1 to register user\n");
		printf("2. Press 2 to search user by employee if\n");
		int sel;
		scanf("%d",&sel);
		if(sel==1) {
			int id=get_id();
			register_new_employee(id);
			printf("New Employee Registered Successfully with employee id %d\n",emp_id[cnt-1]);
		}
		else {
			int e_id;
			printf("Please input Employee id you want to search: ");
			scand("%d",&eid)
			int id=search_idx(e_id);
			if(id!=-1) {
				printf("Employee ID:\t%d\n",e_id);
				printf("First Name:\t%s\n",f_nam[id]);
				printf("Middle Name:\t%s\n",m_nam[id]);
				printf("Last Name:\t%s\n",l_nam[id]);
				printf("Email-ID:\t%s\n",emai[id]);
				printf("D.O.B:\t%s\n",do_b[id]);
				printf("D.O.J:\t%s\n",do_j[id]);
				printf("Mobile:\t%s\n",mobi[id]);
				printf("Designation:\t%s\n",designatio[id]);
				printf("Salary:\t%s\n",salar[id]);
			}
			else {
				printf("No such employee found\n");
			}
		}

		int in;
		printf("To continue press 1\nTo exit press anything other than 1\n");
		scanf("%d",&in);
		if(in==1) continue;
		break;
	}
}
