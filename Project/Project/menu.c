#include "menu.h"
int keyControl() {
	int temp = _getch();
	if (temp == 224) {
		temp = _getch();
		if (temp == 72) {
			return UP;
		}
		else if (temp == 80) {
			return DOWN;
		}
	}
	else if (temp == 32) {
		return SUBMIT;
	}
}

void init() {
	system("mode con cols=100 lines=40 | title ���� �뿩"); // �ܼ�â ũ�� �� ���� ����
}

void titleDraw(char *str) {
	int minwidth = strlen(str) + (WIDTH - strlen(str)) / 2;
	printf("\n\n\n%*s", minwidth, str);
}

int mainMenu() {
	int x = 45;
	int y = 15;
	gotoxy(x - 2, y);
	printf(">  �α���");
	gotoxy(x, y + 1);
	printf("ȸ������");
	gotoxy(x, y + 2);
	printf("  ����");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}

int secondMenu() {
	int x = 42;
	int y = 15;
	gotoxy(x - 2, y);
	printf("> ���� �뿩 ����");
	gotoxy(x, y + 1);
	printf("   �����뿩");
	gotoxy(x, y + 2);
	printf("   �α׾ƿ�");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


void showBookMenu(User *nowUser) {
	//���� ��� ��ȸ
	BOOK books[MAX_NUM] = { 0 };
	ReadBooks(books);
	while (1) {

		printf("�ȳ��ϼ��� %s��\n", nowUser->name);
		init();
		titleDraw("< ���� �뿩 ���� ���� >");
		switch (secondMenu(nowUser))
		{
		case 0: //���� �뿩����
			break;
		case 1: //���� �뿩
			system("mode con cols=1000 lines=400 | title ���� �뿩"); // �ܼ�â ũ�� �� ���� ����
			drawBooks(books, NULL);
			Sleep(5000);
			break;
		case 2: //�α׾ƿ�
			return;
			break;
		default:
			break;
		}
		system("cls");
	}
}

