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
	
	enum
	{
		eStart = 0,
		eEnd = 1
	};
	bool solutionImpl(string start, vector<vector<string>>& tickets, vector<bool>& isVisit, vector<string>& answer)
	{
		for( auto  i=0; i< tickets.size(); ++i)
		{
			if (true == isVisit[i] || 
				tickets[i][0] == tickets[i][1])
			{
				continue;
			}
				
			if (start == tickets[i][eStart])
			{
				isVisit[i] = true;
				answer.push_back(tickets[i][eEnd]);
				bool retVal = solutionImpl(tickets[i][eEnd], tickets, isVisit, answer);
				if (false == retVal)
				{
					answer.erase(answer.end() - 1);
					isVisit[i] = false;
					continue;
				}
				return true;
			}
		}
		if (answer.size() - 1 == tickets.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	vector<string> solution(vector<vector<string>> tickets) 
	{
		vector<string> answer;

		std::sort(tickets.begin(), tickets.end());

		vector<bool> isVisit;
		isVisit.resize(tickets.size(), false);
		answer.push_back("ICN");
		solutionImpl("ICN", tickets, isVisit, answer);
		return answer;
	}
}