#ifndef VALIDATOR_H
#define VALIDATOR_H
#include<string>
#include<array>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


class Validator
{
public:
	Validator();
	vector<char> Normalize(string input );
	int exactMatch(vector<char> pattern, vector<char>);
	int looseMatch(vector<char> pattern, vector<char>);

private:

};

Validator::Validator()
{
}

vector<char> Validator::Normalize(string input)
{
	vector<char> res;

	for (int j = 0;j < input.size();j++) {

		
		res.push_back(toupper(input[j]));

	} 

	return res;


}

int Validator::exactMatch(vector<char> pattern, vector<char> target) {

	int count{0};

	for (int i = 0;i < pattern.size();i++) {

		if (pattern[i] == target[i]) {
			count++;

		}


	 }

	return count;


}

int Validator::looseMatch(vector<char> pattern, vector<char> target) {

	int counter{ 0 };

	set<char> mySet;

	for (int i = 0;i < target.size();i++) {

		mySet.insert(pattern[i]);

	}


	auto it = mySet.begin();

	for (auto i = it;i != mySet.end();i++) {

		
	
		counter += count(begin(target), end(target),*i );
		
	

	}


	return counter;

}


#endif
