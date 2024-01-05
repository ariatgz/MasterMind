#include<iostream>
#include<algorithm>
#include<string>
#include<random>
#include<array>
#include"Validator.h"


using namespace std;

using code_array= vector<char>;

array<char, 3>  colors{ 'R','G','B' };

vector<char> generator() {

	random_device rd;


	mt19937 mt(rd());
	uniform_int_distribution<int> ud(0, 2);


	vector<char> code;

	
	code.push_back(colors[ud(mt)]);
	code.push_back(colors[ud(mt)]);
	code.push_back(colors[ud(mt)]);
	code.push_back(colors[ud(mt)]);
	



	return code;


}




int main() {


	code_array code = generator();
	for (auto c : code) {
		cout << c << endl;
	}

	Validator valid;

	bool winner{ false };


	for (int i = 0;i < 13;i++) {


		string user_input;
		cout << "Please enter 4 characters: (BBRG,RRGB):\n";
		getline(cin, user_input);
		if (user_input.size() > 4) {
			cout << "Bad input" << endl;
			continue;
		}
		vector<char> userArray = valid.Normalize(user_input);


		int exact = valid.exactMatch(userArray, code);
		int loose = valid.looseMatch(userArray, code) - exact;

		if (exact == 4) {

			cout << "Congrats!! You got the code." << endl;
			winner = true;
			break;
		

		}

		cout << "Exact matches = " << exact << endl;
		cout << "Loose matches = " << loose << endl;





	}
	

	if (!winner) {

		cout << "Sorry you suck!!" << endl;
	}

	return 0;

}