/*두 개의 단어 begin, target과 단어의 집합 words가 있습니다.아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 hit, target가 cog, words가[hot, dot, dog, lot, log, cog]라면 hit->hot->dot->dog->cog와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.
입출력 예
begin	target	words	return
hit	cog[hot, dot, dog, lot, log, cog]	4
hit	cog[hot, dot, dog, lot, log]	0
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
target인 cog는 words 안에 없기 때문에 변환할 수 없습니다*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace change_word
{
	void solutionImpl(string begin, string& target, vector<string>& words, int changeCount, vector<int>& res)
	{
		if (begin == target)
		{
			res.push_back(changeCount);
			return;
		}

		if (words.size() == 0)
		{
			return;
		}

		for (auto i = 0; i < begin.size(); ++i)
		{
			string src = begin;
			src.erase(i, 1);

			for (auto j = 0; j < words.size(); ++j)
			{
				string dst = words[j];
				dst.erase(i, 1);

				if (src == dst)
				{
					string next = words[j];
					vector<string> next_words = words;
					next_words.erase(next_words.begin() + j);
					solutionImpl(words[j], target, next_words, changeCount + 1, res);
				}
			}
		}
	}
	int solution(string begin, string target, vector<string> words)
	{
		vector<int> changeCounts;
		solutionImpl(begin, target, words, 0, changeCounts);

		if (changeCounts.size() == 0)
		{
			return 0;
		}
		else
		{
			return *std::min_element(changeCounts.begin(), changeCounts.end());
		}
	}
}
