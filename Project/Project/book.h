#include "main.h"
#pragma once

//���� ����ü 
typedef struct book {
	char title[MAX_NUM]; //������
	char publisher[MAX_NUM]; //���ǻ��
	char author[MAX_NUM]; //���ڸ�
	int state; //��������
}BOOK;

/* ���� ���� �Լ� */

 //���� ������ ���¸� ��Ÿ���� ���ڿ� 
extern char state[2][10];
extern char bar[216];

//������ �˻��Ͽ� �˻������ �����ϴ� �Լ� 
void findBooks(BOOK *books, int type, char *keyword, int *returnList, int *length);
//���������͸� �ҷ����� �Լ�
void ReadBooks(BOOK *books);
//���� �뿩 
void rentBook(BOOK *books, int idx);
//���� ����
void eliminateWord(char *words, char *data);
//ȭ�鿡 ��������� ����ϴ� �Լ�
void drawBooks(BOOK *books, int *list);
//���� �ݳ�
void returnBook(BOOK *books);