#include<stdio.h>
#include<string.h>

int main() {
	char a[10] = "";
	char b[10] = "\0";

	printf("�̸�?\n");
	scanf_s("%s", a, sizeof(a));
	fflush(stdin);
	printf("��\n");
	scanf_s("%s", b, sizeof(b));

	printf("�� �̸��� %s, ���̸��� %s", a, b);
	return 0;
}