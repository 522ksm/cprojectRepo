#include "main.h"
#pragma once
//������� ������ �����ϴ� ����ü
typedef struct {
	char name[30];
	char number[30];
	char id[20];
	char pw[10];
}User;

/*�α��� ���� �Լ�*/

//���������͸� ���Ͽ� �����ϴ� �Լ�
int saveFile(User* ptr, int* num); 
//���Ϸκ��� �����͸� �ҷ����� �Լ�
int openFile(User* ptr, int* num); 

//������� ������ �����ϴ� �Լ� = ȸ������
void insert(User* ptr, int* num); 
//�α��� �ϴ� �Լ�
int login(User* ptr, int* num);