#include <iostream>
using namespace std;
#include <utility>
#include "Map.h"

int main()
{

    Map<int,int> dis;

	cout << "\nInserting elements\n";
	dis*(1,69);
	dis*(2,300);
	dis*(3,72);

    cout << "\nTesting size...\n";

	dis.size();
	cout << "Size is: " <<  dis.size() << endl;

	cout << "\nFinding...\n";
	dis.find(2);

	cout << "\nErasing..\n";
	dis.erase(2);
	
	cout << "\nFinding deleted node...\n";
	dis.find(2);

	cout << "\n Is empty?\n";
	dis.empty();

	cout << "\nClearing...\n";
	dis.clear();
	
	cout << "\n Is empty?\n";
	dis.empty();

    return 0;
}
