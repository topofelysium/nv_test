/*���� ����
�־��� �װ����� ��� �̿��Ͽ� �����θ� ¥���� �մϴ�.�׻� ICN ���׿��� ����մϴ�.

�װ��� ������ ��� 2���� �迭 tickets�� �Ű������� �־��� ��, �湮�ϴ� ���� ��θ� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��� ������ ���ĺ� �빮�� 3���ڷ� �̷�����ϴ�.
�־��� ���� ���� 3�� �̻� 10, 000�� �����Դϴ�.
tickets�� �� ��[a, b]�� a ���׿��� b �������� ���� �װ����� �ִٴ� �ǹ��Դϴ�.
�־��� �װ����� ��� ����ؾ� �մϴ�.
���� ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return �մϴ�.
��� ���ø� �湮�� �� ���� ���� �־����� �ʽ��ϴ�.
����� ��
tickets	return
[[ICN, JFK], [HND, IAD], [JFK, HND]][ICN, JFK, HND, IAD]
[[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL, SFO]][ICN, ATL, ICN, SFO, ATL, SFO]

[ICN, SFO]	[ICN, ATL]	[SFO, ATL]	[ATL, ICN]
[SFO, ATL]	[ATL, ICN]	[ATL, ICN]	[ICN, SFO]
[ATL, ICN]	[ICN, SFO]	[ICN, SFO]	[SFO, ATL]
[ICN, ATL]	[SFO, ATL]				[ATL, SFO]
[ATL, SFO]	[ATL, SFO]

����� �� ����
���� #1

[ICN, JFK, HND, IAD] ������ �湮�� �� �ֽ��ϴ�.

���� #2

[ICN, SFO, ATL, ICN, ATL, SFO] ������ �湮�� ���� ������[ICN, ATL, ICN, SFO, ATL, SFO] �� ���ĺ� ������ �ռ��ϴ�.*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace travel_route {
	void solutionImpl(string begin, vector<bool>& isVisit, vector<vector<string>>& tickets, vector<int>& answer)
	{
		for (auto i=0; i<tickets.size(); ++i)
		{
			if (isVisit[i] == true)
			{
				continue;
			}

			if (begin == tickets[i][0])
			{
				answer.push_back(i);
				isVisit[i] = true;

				solutionImpl(tickets[i][1], isVisit, tickets, answer);
			}
		}
	}

	vector<string> solution(vector<vector<string>> tickets) 
	{
		vector<vector<string>> answers;
		
		for (auto i=0; i<tickets.size(); ++i)
		{
			if (tickets[i][0] != "ICN")
			{
				continue;
			}

			vector<int> indies;
			vector<bool> isVisit;
			isVisit.resize(tickets.size(), false);
			isVisit[i] = true;

			indies.push_back(i);
			solutionImpl(tickets[i][1], isVisit, tickets, indies);

			vector<string> answer;

			auto it = indies.begin();
			answer.push_back(tickets[*it][0]);

			while (it != indies.end())
			{
				answer.push_back(tickets[*it][1]);
				it++;
			}

			answers.push_back(answer);
		}

		std::sort(answers.begin(), answers.end());
		return answers[0];
	}
}