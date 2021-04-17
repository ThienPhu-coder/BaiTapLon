#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
//NOTE: struct employee
struct Employee{
    char name[30];
    char province[30];
    int year;
};
void enter(Employee *employee);// NOTE: hàm nhập 1 nhân viên
void print(Employee *employee); // NOTE: hàm xuất 1 nhân viên
void enter(Employee *&employee, int &amount);// NOTE: nhập danh sách nhân viên
void print(Employee *employee, int amount);// NOTE:xuất danh sách nhân viên
// NOTE: main
int main()
{
    Employee *employee;
    int amount = 0;
    employee = (Employee*)malloc(sizeof(Employee));
    enter(employee, amount);
    arrange(employee, amount);
    print(employee, amount);
    count(employee, amount);
    return 0;
}
void enter(Employee *employee)
{
    printf("Name of employee: \n");
    fflush(stdin);
    gets(employee->name);
    printf("province of employee: \n");
    gets(employee->province);
    printf("year of birth of employee: \n");
    scanf("%d", &employee->year);
}
void print(Employee *employee)
{
    printf("Name of employee: %s\n", employee->name);
    printf("province of employee: %s\n", employee->province);
    printf("year of bỉth of employee: %d\n", employee->year);
}
void enter(Employee *&employee, int &amount)
{
    // NOTE: nhập số lượng
    printf("Nhap vao so luong nhan vien: \n");
    scanf("%d", &amount);
    /// NOTE: cấp phát bộ nhớ
    employee = (Employee*)realloc(employee, (amount)*sizeof(Employee));
    // NOTE: nhập vào lần lượt các nhân viên
    for(int index = 0; index < amount; index++){
        printf("Nhap thong tin nhan vien thu %d \n", index);
        enter(&*(employee+index));
    }
}
void arrange(Employee *employee, int amount)
{
    Employee temp;
    for(int i = 0; i < amount-1; i++){
        for(int j = i+1; j < amount; j++){
            if(strcmp((employee+i)->province, (employee+j)->province) < 0){
                temp = *(employee+i);
                *(employee+i) = *(employee+j);
                *(employee+j) = temp;
            }
        }
    }
}
void count(Employee *employee, int amount)
{
    int count = 0;
    for(int i = 0; i < amount-1; i++){
        for(int j = i+1; j < amount; j++){
            if(strcmp((employee+i)->province, (employee+j)->province) == 0){
                count ++;
            }
            else{
                printf("Tinh %s có %d nhan vien\n", (employee+i)->province, count);
                count = 0;
            }
        }
    }
}
void findByProvince(Enployee *employee, int amount, char search[30]){
    fflush(stdin);
    printf("\nNhap Tỉnh: ");
    gets(search);
    for(int index = 0; index < amount; index++){
        if(strcmp((employee+index)->province, search) == 0){
            printf("\t%s\n\t%s\n\t%d", (employee+index)->Name, (employee+index)->Province, (employee+index)->Year)
        }
    }
}
void printf(Employee *employee, int amount){
    for(int index = 0; index < amount; index++){
        printf("Nhan vien thu %d \n", index);
        printf(employee+index);
    }
}
