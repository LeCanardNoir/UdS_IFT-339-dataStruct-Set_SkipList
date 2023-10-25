// Set_SkipList.cpp : définit le point d'entrée de l'application.
//

#include "set.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	set<int> s;
	s.insert(3);
	s.insert(4);
	s.insert(7);
	s.insert(1);
	s.insert(25);
	s.insert(10);
	s.insert(9);
	s.insert(50);
	afficher(cout, s);

	set<int> s2;
	afficher(cout, s2);

	s2 = set(s);
	afficher(cout, s2);


	return 0;
}