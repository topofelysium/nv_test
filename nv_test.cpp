
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace target_number { extern int solution(vector<int> numbers, int target); }
namespace change_word { extern int solution(string begin, string target, vector<string> words); }

int main()
{
	cout << target_number::solution({ 1,1,1,1,1 }, 3);
	cout << change_word::solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

	cin;
}