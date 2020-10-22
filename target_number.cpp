/*n���� ���� �ƴ� ������ �ֽ��ϴ�.�� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�.���� ���[1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

- 1 + 1 + 1 + 1 + 1 = 3
+ 1 - 1 + 1 + 1 + 1 = 3
+ 1 + 1 - 1 + 1 + 1 = 3
+ 1 + 1 + 1 - 1 + 1 = 3
+ 1 + 1 + 1 + 1 - 1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
�� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.
����� ��
numbers	target	return
[1, 1, 1, 1, 1]	3	5
����� �� ����
������ ���� ���� �����ϴ�.*/

#include <string>
#include <vector>

using namespace std;

namespace target_number {

	// �Ƹ��� ���� Ž��?
	void calc(int src, vector<int>& numbers, int index, int target, int& answer)
	{
		if (index == numbers.size())
		{
			if (src == target)		answer++;
			return;
		}

		int plus = src + numbers[index];
		int minus = src - numbers[index];

		calc(plus, numbers, index + 1, target, answer);
		calc(minus, numbers, index + 1, target, answer);
	};

	int solution(vector<int> numbers, int target) 	
	{
		int answer = 0;
		int res = 0;

		calc(0, numbers, 0, target, answer);

		return answer;
	}
}