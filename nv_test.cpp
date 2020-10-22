
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace target_number
{
	extern int solution(vector<int> numbers, int target);
};
int main()
{
	cout << target_number::solution({ 1,1,1,1,1 }, 3);

	cin;
}