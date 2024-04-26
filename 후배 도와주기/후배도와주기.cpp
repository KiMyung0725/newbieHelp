#include <stdio.h>

// ���α׷� ����
int main() {
	//2���� �迭 ���� output�� �÷��̾ �Է��ϴ� ī�� ��ȣ, color�� �������� ������ �ִ� �迭 ( ���ڷ� ǥ�� )
	int output[4][4] = { { 11, 12, 13, 14 },
						 { 21, 22, 23, 24 },
						 { 31, 32, 33, 34 },
						 { 41, 42, 43, 44 } };
	int color[4][4] = {
						 { 0, 1, 2, 7 },
						 { 3, 5, 6, 0 },
						 { 2, 4, 6, 3 },
						 { 4, 5, 1, 7 } };
	//int �� ���� �ʱ�ȭ, row�� �� column�� ��
	int card1 = 0, card2 = 0, row = 0, column = 0;

	do {
		// ���� ī�� ���� ��Ȳ ���
		// card1/10-1�� �ǹ�
		// ó������ ����ڰ� �Է� ���ؼ� card1 card2�� 0�ΰ� �����ϰ� ���ǹ� �״�� ���󰡸� ��µǴ� ��� ����
		// ����ڰ� ���� �Է��� �Ѵٸ� output ���߿� �Է� -> 11�̶� �����ϸ� 11/10-1 = 0 2���� �迭���� output[0][0]�����Ѱ��� ����

		for (row = 0; row < 4; row++) {
			for (column = 0; column < 4; column++) {
				if ((output[row][column] <= 7)
					|| ((row == (card1 / 10 - 1)) && (column == (card1 % 10 - 1)))
					|| ((row == (card2 / 10 - 1)) && (column == (card2 % 10 - 1)))) {
					printf("\033[4%dm", color[row][column]);
					printf("\033[%d;%df    ", row * 3 + 1, column * 4 + 1);
					printf("\033[%d;%df    ", row * 3 + 2, column * 4 + 1);
					printf("\033[%d;%df    ", row * 3 + 3, column * 4 + 1);
					printf("\033[0m");
				}
				else {
					printf("\033[%d;%df    ", row * 3 + 1, column * 4 + 1);
					printf("\033[%d;%df %d%d ", row * 3 + 2, column * 4 + 1, row + 1, column + 1);
					printf("\033[%d;%df    ", row * 3 + 3, column * 4 + 1);
				}
			}
		}

		// ���� �� ī�带 �����ϸ� ī�� ��ȣ ��� ī�� ���� ���
		//card1 != card2 �ΰ� ���� �ٸ����ΰ� Ȯ�� �Ϸ��� �ϴ� �Ű� ���⼭ card1 %10 �� �� ����ڰ� 12��� �Է��ϸ� 2�� ��� ( ���� �ڸ� )
		if ((card1 != card2) && (color[card1 / 10 - 1][card1 % 10 - 1] == color[card2 / 10 - 1][card2 % 10 - 1])) {
			//������ output�迭�� color�� ����� �� ���� ����
			output[card1 / 10 - 1][card1 % 10 - 1] = color[card1 / 10 - 1][card1 % 10 - 1];
			output[card2 / 10 - 1][card2 % 10 - 1] = color[card2 / 10 - 1][card2 % 10 - 1];

			// �̶� �� �̻� ���� ī�� ��ȣ�� ������ ����
			for (row = 0; row < 4; row++) {
				for (column = 0; column < 4; column++) {
					if (output[row][column] > 7) {
						column = 10;
						row = 10;
						break;
					}
				}
			}
			if (row == 4) {
				printf("\033[1;1f                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("        Success!!       \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				printf("                        \n");
				break;
			}
		}

		// ī�� �� �� ���� �Է¹ޱ�

		printf("\033[15;1fù��° ī�带 �����ϼ���:       \033[15;27f");
		scanf_s("%d", &card1);
		printf("\033[16;1f�ι�° ī�带 �����ϼ���:       \033[16;27f");
		scanf_s("%d", &card2);
		//while�� �� ������ ���� �ݺ��ϴ°�
	} while ((1 <= card1 / 10) && (card1 / 10 <= 4) && (1 <= card1 % 10) && (card1 % 10 <= 4)
		&& (1 <= card2 / 10) && (card2 / 10 <= 4) && (1 <= card2 % 10) && (card2 % 10 <= 4));

	// ���α׷� ����
	return 0;
}