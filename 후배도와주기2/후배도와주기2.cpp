#include<stdio.h>
#include<string.h>

int main() {
	char a[10] = "";
	char b[10] = "\0";

	printf("이름?\n");
	scanf_s("%s", a, sizeof(a));
	fflush(stdin);
	printf("넌\n");
	scanf_s("%s", b, sizeof(b));

	printf("내 이름은 %s, 너이름은 %s", a, b);
	return 0;
}