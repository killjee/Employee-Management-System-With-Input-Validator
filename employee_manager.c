#include "manage.h"

int main() {
	retrive_data();
	while (1) {
		printf("Menu Driven Employee Managment SyStem With Data Validation\n");
		printf("1. Press 1 to register user\n");
		printf("2. Press 2 to search user by employee if\n");
		int sel;
		scanf("%d",&sel);
		if(sel==1) {
			int id=get_id(cnt);
			register_new_employee(id,cnt);
			printf("New Employee Registered Successfully with employee id %d\n",emp_id[cnt-1]);
		}
		else {
			int eid;
			printf("Please input Employee id you want to search: ");
			scanf("%d",&eid);
			int id=search_idx(eid,cnt);
			if(id!=-1) {
				printf("Employee ID:\t%d\n",eid);
				printf("First Name:\t%s\n",f_name[id]);
				printf("Middle Name:\t%s\n",m_name[id]);
				printf("Last Name:\t%s\n",l_name[id]);
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
