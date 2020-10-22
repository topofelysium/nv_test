/*�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�.�Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
���� ��� begin�� hit, target�� cog, words��[hot, dot, dog, lot, log, cog]��� hit->hot->dot->dog->cog�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
begin�� target�� ���� �ʽ��ϴ�.
��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
����� ��
begin	target	words	return
hit	cog[hot, dot, dog, lot, log, cog]	4
hit	cog[hot, dot, dog, lot, log]	0
����� �� ����
���� #1
������ ���� ���� �����ϴ�.

���� #2
target�� cog�� words �ȿ� ���� ������ ��ȯ�� �� �����ϴ�*/

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
