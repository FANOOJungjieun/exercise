#include<iostream>
#include<ctime>

using namespace std;

bool correct;
int set[4];
int number[4];
int digits[4];
int stk, ball;


void init(int ran[]) {
	srand((unsigned int)time(0));


	int sb1 = 0;
	int sb2 = 0;
	int sb3 = 0;
	int sb4 = 0;

	while (sb1 == sb2 || sb1 == sb3 || sb1 == sb4 || sb2 == sb3 || sb2 == sb4 || sb3 == sb4)
	{
		sb1 = rand() % 10;
		sb2 = rand() % 10;
		sb3 = rand() % 10;
		sb4 = rand() % 10;
	}

	ran[0] = sb1;
	ran[1] = sb2;
	ran[2] = sb3;
	ran[3] = sb4;

	return;
}

void baseball() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (set[i] == number[j]) {
				if (i == j) {
					stk++;
				}
				else {
					ball++;
				}
			}
		}
	}

	if (stk == 4) {
		correct = true;
	}

	return;
}


int main() {

	init(set);

	correct = false;
	int input2;

	cout << "�̰��� ���ڰ� �ߺ����� �ʴ� 4�ڸ����� ���� �߱� �����Դϴ�." << endl;

	while (!correct) {
		int input;
		stk = 0;
		ball = 0;

		cout << "���̶�� �����Ǵ� 4�ڸ����� ���ڸ� �Է��ϼ���. : ";

		cin >> input;

		input2 = input;

		number[3] = input % 10;
		digits[3] = number[3];
		input /= 10;

		number[2] = input % 10;
		digits[2] = number[2];
		input /= 10;

		number[1] = input % 10;
		digits[1] = number[1];
		input /= 10;

		number[0] = input % 10;
		digits[0] = number[0];
		input /= 10;

		baseball();

		cout << "��Ʈ����ũ = " << stk << endl;
		cout << "�� = " << ball << endl;

	}

	cout << "�����մϴ�. ������ = " << input2 << endl;


	return 0;
}