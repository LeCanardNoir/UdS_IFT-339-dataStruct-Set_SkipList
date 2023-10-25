//
//  setImpl.h
//  SkipList
//
//  Jean Goulet 2017
//
//  Devoir fait par
//     Coéquipier 1 : Gabriel Dumont-Hétu
//     Coéquipier 2 : Bruno Pouliot
//

#ifndef SkipList_set2_h
#define SkipList_set2_h

/////////////////////////////////////////////////////////////////
// copieur et destructeur de liste

template <typename TYPE>
set<TYPE>::set(const set<TYPE>& src)
    : set()
{

	iterator it = src.begin();
	cellule* cellFin = m_avant->m_prec[0];
	while (it != src.end()) {
		//DONE : Optimisation d'insertion en O(n)
		this->insert(cellFin, *it);
		++it;
	}
}

template <typename TYPE>
set<TYPE>::~set()
{
	clear();
	cellule* apres = m_avant->m_prec[0];
	delete apres;
	delete m_avant;
}

/////////////////////////////////////////////////////////////////
// find
// localise un élément, retourne la fin si absent

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::find(const TYPE& x)
{
	// DONE: 04 find(const TYPE& x)
	// return it or m_avant->m_prec[0]

	iterator it = lower_bound(x);
	if (it != m_avant->m_prec[0] && !(*it < x))
		return it;

	return m_avant->m_prec[0];
}

// lower_bound
// localise la premiere position ou l'element n'est
// pas plus petit que celui recu en parametre

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::lower_bound(const TYPE& t)
{
	cellule* c = m_avant;
	size_t k = m_avant->m_suiv.size();
	for (int i = k - 1; i >= 0; i--) {
		//cellule* c->m_suiv[i]
		int tailleSuivant = c->m_suiv.size();
		bool pasNull = (c->m_suiv[i])->m_contenu;
		bool valeurPlusPetite = false;
		if(pasNull)
			valeurPlusPetite = *(c->m_suiv[i]->m_contenu) < t;

		while (pasNull && valeurPlusPetite) {
			c = c->m_suiv[i];
			pasNull = (c->m_suiv[i])->m_contenu;
			if(c->m_suiv[i]->m_contenu)
				valeurPlusPetite = *(c->m_suiv[i]->m_contenu) < t;
		}
	}
	iterator it = iterator(c->m_suiv[0]);
	return it;
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::upper_bound(const TYPE& x)
{
	// DONE: 03 À TESTER upper_bound(const TYPE& x)
	cellule* c = m_avant;
	size_t k = m_avant->m_suiv.size();
	for (int i = k - 1; i >= 0; i--) {
		while (!(x < *(c->m_suiv[i]->m_contenu))) {
			c = c->m_suiv[i];
		}
	}
	iterator it = iterator(c);
	return it;
}

/////////////////////////////////////////////////////////////////
// erase(VAL)
// elimine VAL de l'ensemble, si present

template <typename TYPE>
size_t set<TYPE>::erase(const TYPE& VAL)
{
	// DONE: 05 erase(const TYPE& VAL)
	// find it
	// erase(it);
	iterator it = find(VAL);
	if (it != m_avant->m_prec[0]) {
		erase(it);
		return 0;
	}
	return 1;
}

// erase(it)
// elimine de l'ensemble l'element en position it

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::erase(iterator it)
{
	// DONE: 06 erase(iterator it) 
	cellule* cell = it.m_pointeur;
	if (it != m_avant->m_prec[0]) {
		size_t k = cell->m_prec.size();
		std::vector<cellule*> vPrec = cell->m_prec;
		std::vector<cellule*> vSuiv = cell->m_suiv;

		for (size_t i = 0; i < k; i++) {
			vPrec[i]->m_suiv[i] = vSuiv[i];
			vSuiv[i]->m_prec[i] = vPrec[i];
		}

		delete it.m_pointeur;
		it.m_pointeur = nullptr;
		m_size--;
	}

	//it.m_pointeur = cell->m_suiv[0];
	/*delete cell;
	cell = nullptr;*/

	return it;
}

#endif
