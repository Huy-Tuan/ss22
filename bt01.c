#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
	char id[30];
	char name[50];
	int age;
};
struct Student students[100];
int numberStudent = 0;
// ham de lay du lieu tu file.
void loadFileStudent(){ // ham in ra thong tin sinh vien
	FILE *file;
	file = fopen("student.bin", "rb");
	if(file == NULL){
		printf("Loi khong mo duoc file!\n");
		return;
	}
	// thao tac voi file ( lay du lieu o trong file ra )
	numberStudent = fread(&students,sizeof(struct Student),100,file);
	
	fclose(file);
}
// ham in thong tin sinh vien.
void printStudent(){ 
	if(numberStudent == 0) {
		printf("Danh sach sinh vien rong!\n");
		return;
	}
	for(int i = 0; i < numberStudent; i++){
		printf("Thong tin sinh vien thu %d la:\n", i + 1);
		printf("ID: %s\n", students[i].id);
		printf("Ten sinh vien: %s\n", students[i].name);
		printf("Tuoi sinh vien: %d\n", students[i].age);
		
	}
}
void saveStudent(){
	FILE *file;
	// mo file
	file = fopen("student.bin", "wb");
	// thao tac file
	fwrite(students, sizeof(struct Student), numberStudent, file);
	//dong file
	fclose(file);
}
//Ham them sinh vien
void addStudent(){
	/*
	kiem tra numberstudent co vuot 100 ko
	tao struct sinhvien
	nhap thong tin sinh vien
	students[numberStudent] = student1;
	numberStudent++;
	*/
	if(numberStudent >= 100){
		printf("Danh sach da day khong the them!\n");
		return;
	}
	struct Student student1;
	/*FILE *file;
	file = fopen("student.bin", "wb");
	if(file == NULL){
		printf("Khong mo duoc file!\n");
		return;
	
	int n;
	printf("Nhap so luong sinh vien muon them: ");
	scanf("%d", &n);
	getchar();
	
	for(int i = 0; i < n; i++){
		printf("Thong tin sinh vien thu %d: \n", i + 1);
		printf("ID: ");
		fgets(students[i].id, sizeof(struct Student), stdin);
		students[i].id[strcspn(students[i].id, "\n")] = '\0';
		printf("Name: ");
		fgets(students[i].name, sizeof(struct Student), stdin);
		students[i].name[strcspn(students[i].name, "\n")] = '\0';
		printf("Age: ");
		scanf("%d", &students[i].age);
		getchar();	
	}
	for(int i = 0; i < n; i++){
		fprintf(file,"ID:%s Name:%s Age:%d\n", student1[i].id, student1[i].name, student1[i].age);
	*/
	getchar();
	printf("ID:");
	fgets(student1.id, sizeof(student1.id), stdin);
	student1.id[strcspn(student1.id, "\n")] = '\0';
	printf("Name: ");
	fgets(student1.name, sizeof(student1.name), stdin);
	student1.name[strcspn(student1.name, "\n")] = '\0';
	printf("Age: ");
	scanf("%d", &student1.age);
	getchar();
	students[numberStudent] = student1;
	numberStudent++;
	printf("Them sinh vien thanh cong!\n");
	// luu sinh vien lai
	saveStudent();
//	fclose(file);
}
// ham sua thong tin sinh vien
void editStudent(){
	char x[30];
	int found = 0;
	printf("Hay nhap ID sinh vien muon sua: ");
	scanf("%s", &x);
	getchar();
	for(int i= 0; i < numberStudent; i++){
		if(strcmp(x, students[i].id) == 0){
			found = 1;
			printf("Moi ban sua thong tin:\n");
			printf("ID:");
			fgets(students[i].id, sizeof(students[i].id), stdin);
			students[i].id[strcspn(students[i].id, "\n")] = '\0';
			printf("Name: ");
			fgets(students[i].name, sizeof(students[i].name), stdin);
			students[i].name[strcspn(students[i].name, "\n")] = '\0';
			printf("Age:");
			scanf("%d", &students[i].age);
			getchar();
			
			saveStudent();
		}		
	}
	if(!found) {
		printf("Khong tim thay ID sinh vien!\n");
		return;
	}
}
void deletStudent(){
	char x[30];
	int found = 0;
	printf("Hay nhap ID sinh vien muon xoa: ");
	scanf("%s",&x);
	getchar();
	for(int i = 0; i < numberStudent; i++){
		if(strcmp(x, students[i].id) == 0){
			found = 1;
			for(int j = i; j < numberStudent - 1; j++){
				students[j] = students[j+1];
			}
			numberStudent--;
			printf("Da xoa sinh vien voi ID: %s\n", x);
			saveStudent();
			break;
		}
	}
	 if(!found) {
	 	printf("Khong tim thay ID!\n");
	 }
}

int main () {
	loadFileStudent();
	int choice;
	do{
		printf("==========MENU==========\n");
		printf("1. In danh sach sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("Hay nhap lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printStudent();
				break;
			case 2:
				addStudent();
				break;
			case 3:
				editStudent();
				break;
			case 4:
				deletStudent();
				break;
			case 5:
				
				break;
			case 6:
				break;
			case 7:
				printf("Ban da thoat chuong trinh");
				break;
			
		}
	}while (choice != 7);
	return 0;
}

