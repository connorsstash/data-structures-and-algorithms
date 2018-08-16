#include "assignment4.h"
#include <iostream>
#include <iomanip>

using namespace std;

using std::cin;
using std::cout;

int main() {
	Queue q;
	string op;
	int val = 0;

	cout << "operation -- size front end" << endl;

	/*ifstream inFile;
	inFile.open("input.txt");
	if (!inFile)						//  I added this cause I wana use an input file seeeee
	{
		cout << "no input file."
	}                                   */

	cin >> op;

	while (!cin.eof()) {
		if (op == "push") {
			cin >> val;
			q.push(val);
			cout << op << " " << val << "    -- ";
		}
		else if (op == "pop") {
			q.pop();
			cout << op << "       -- ";
		}
		else {
			cerr << "Error input: " << op << endl;
			return 1;
		}
		cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
		cin >> op;
	}

	//inFile.close; // I wana close the input file seeeeeeee

	while (!q.empty())
		q.pop();

	return 0;
}

