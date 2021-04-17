#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//NOTE: struct employee
struct Employee{
    char name[30];
    char province[30];
    int year;
};
void enter(Employee &input);// NOTE: hàm nhập 1 nhân viên
void print(Employee *input); // NOTE: hàm xuất 1 nhân viên
void enterEmployee(Employee *&input, int &amount);// NOTE: nhập danh sách nhân viên
void printEmployee(Employee *input, int amount);// NOTE:xuất danh sách nhân viên
// NOTE: main
int main()
{
    Employee *employee;
    int amount = 0;
    enterEmployee(employee, amount);
    arrange(employee, amount);
    printEmployee(employee, amount);
    return 0;
}
void enter(Employee *input)
{
    printf("nhap ten nhan vien: ");
    fflush(stdin);
    gets(input->name);
    fflush(stdin);
    printf("province of employee: ");
    gets(input->province);
    printf("year of birth of employee: ");
    scanf("%d", &input->year);
}
/*void print(Employee *input)
{
    printf("ten nhan vien: %s", input->name);
    printf("province of employee: %s", input->province);
    printf("year of bỉth of employee: %d", input->year);
}*/
void enterEmployee(Employee *&input, int &amount)
{
    // NOTE: nhập số lượng
    printf("Nhap vao so luong nhan vien: ");
    scanf("%d", &amount);
    /// NOTE: cấp phát bộ nhớ
    input = (Employee*)malloc(amount * sizeof(Employee));
    // NOTE: nhập vào lần lượt các nhân viên
    for(int index = 0; index < amount; index++){
        printf("Nhap thong tin nhan vien thu %d \n", index);
        enter(&*(input+index));
    }
}
void arrange(Employee *input, int amount)
{
    Employee temp;
    for(int i = 0; i < amount-1; i++){
        for(int j = i+1; j < amount; j++){
            if(strcmp((input+i)->province, (input+j)->province) < 0){
                temp = *(input+i);
                *(input+i) = *(input+j);
                *(input+j) = temp;
            }
        }
    }
}
void count(Employee *input, int amount)
{
    int count = 0;
    for(int i = 0; i < amount-1; i++){
        for(int j = i+1; j < amount; j++){
            if(strcmp((input+i)->province, (input+j)->province) == 0){
                count ++;
            }
            else{
                printf("\nTinh %s có %d nhan vien", (input+i)->province, count);
                count = 0;
            }
        }
    }
}
void printfEmployee(Employee *output, int amount){
    for(int index = 0; index < amount; index++){
        printf("\t%s\n\t%s\n\t%d", (output+index)->name, (output+index)->province, (output+index)->year);
    }
}
