#include "main.h"
#include "user.h"
#include "menu.h"
//�����Լ�
int main() {
	User user[MAX_NUM]; //����� ������ ������ ����ü �迭
	int person = 0; //����� user��
	openFile(user, &person);//����� �����͸� �ҷ����� �Լ�
	init(); //ȭ�� ũ�� �ʱ�ȭ
	while (1) {
		titleDraw("<���� �뿩 ���α׷�>");
		switch (mainMenu())
		{
		case 0: //�α���
			system("cls");
			gotoxy(0, 0);
			int result = login(user, &person);
			if (result != -1) {
				system("cls");
				User *nowUser = user + result;
				showBookMenu(nowUser);
			}
			else Sleep(500);
			break;
		case 1: //ȸ������
			gotoxy(0, 0);
			system("cls");
			insert(user, &person);
			saveFile(user, &person);
			break;
		default:
			return 0;
		}
		system("cls");
	}
}