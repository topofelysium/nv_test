
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace target_number { extern int solution(vector<int> numbers, int target); }
namespace change_word { extern int solution(string begin, string target, vector<string> words); }
namespace travel_route { extern vector<string> solution(vector<vector<string>> tickets);}

int main()
{
	travel_route::solution(
		{
			{"ICN", "SFO"},
			{"ICN", "ATL"},
			{"SFO", "ATL"},
			{ "ATL", "ICN" },
			{ "ATL", "SFO" } 
		});
	
}