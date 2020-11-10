#include"sequence.h"

using namespace std;

int main()
{
	int cap = 0;
	int choice = 0;
	double value = 0.0;
	int pos = 0;

	cout << "What size sequence would you like to test?\n";
	cin >> cap;

	sequence<double> seq(cap);

	cout << "enter your first value:\n";
	cin >> value;
	seq.push_back(value);

	bool done = false;
	while (!done)
	{
		cout << "How would you like to manipulate the data?\n";
		cout << "1: at (return an element at a given position)\n";
		cout << "2: set (overwrite an element at a given position)\n";
		cout << "3: push_back (add a given element to the end of the array)\n";
		cout << "4: insert (insert an element at a given position in the array)\n";
		cout << "5: remove (removes an element from a given position in the array)\n";
		cout << "6: check if the sequence is full\n";
		cout << "7: check if the sequence is empty\n";
		cout << "8: print the sequence's contents, capacity and number of elements\n";
		cout << "9: exit program\n";
		cin >> choice;

		switch (choice)
		{
			case 1://at
				cout << "enter the postion of the element to be returned\n";
				cout << "from 0 to " << seq.num_element() - 1 << endl;
				cin >> pos;
				cout << "the value at that position is " << seq.at(pos) << endl;
				break;
			case 2://set
				cout << "enter the value to be set: ";
				cin >> value;
				cout << "enter the position to be overwritten from 0 to ";
				cout << seq.num_element()-1 << endl;
				cin >> pos;
				seq.set(value, pos);
				break;

			case 3://push_back
				cout << "enter the value to be pushed back: ";
				cin >> value;
				seq.push_back(value);
				break;

			case 4://insert
				cout << "enter the value to be inserted\n";
				cin >> value;
				cout << "enter the position for the value to be inserted into";
				cout << " from 0 to " << seq.num_element()-1 << endl;
				cin >> pos;
				seq.insert(value, pos);
				break;

			case 5://remove
				cout << "enter the position to be removed";
				cout << " from 0 to " << seq.num_element()-1 << endl;
				cin >> pos;
				seq.remove_current(pos);
				break;

			case 6://check full
				if (seq.full())
					cout << "the sequence is full!\n";
				else
					cout << "the sqence is not full\n";
				break;

			case 7://check empty
				if (seq.empty())
					cout << "the sequence is empty!\n";
				else
					cout << "the sqence is not empty\n";
				break;

			case 8://print
				seq.print();
				break;

			case 9://exit program
				done = true;
				break;

			default:
				cout << "please make a valid selection\n";
		}
	}
	cin.get();
	return 0;
}