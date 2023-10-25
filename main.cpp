// Set_SkipList.cpp : définit le point d'entrée de l'application.
//

#include "set.h"
#include <iostream>

using namespace std;
void testFind(set<int>, int);

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
	s.insert(2);
	afficher(cout, s);

	set<int> s2;
	afficher(cout, s2);

	s2 = set(s);
	afficher(cout, s2);

	testFind(s2, 1);
	testFind(s2, 8);
	testFind(s2, 99);
	testFind(s2, 50);

	s2.erase(2);
	afficher(cout, s2);

	return 0;
}

void testFind(set<int> s, int x) {
	auto it = s.find(x);
	if (it != s.end() && *it == x)
		std::printf("\nValeur %d trouvé: %d\n", x, *it);
	else
		std::printf("\nValeur %d inexistante\n", x);
}