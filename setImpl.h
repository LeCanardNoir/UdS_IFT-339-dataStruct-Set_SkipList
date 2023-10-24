//
//  setImpl.h
//  SkipList
//
//  Jean Goulet 2017
//
//  Devoir fait par
//     Co�quipier 1 : Gabriel Dumont-H�tu
//     Co�quipier 2 : Bruno Pouliot
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
	while (it != src.end()) {
		// Complexit� de O(n log n)
		// TODO: 999 Am�liorer l'insertion des �l�ments initiaux
		// Peut �tre am�lior� en devenant O(n) en admettant que
		// les �l�ments de la skip_list initiale sont d�j� dans l'ordre,
		// donc en ajoutant des �l�ments directement � la fin.
		this->insert(*it);
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
// localise un �l�ment, retourne la fin si absent

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::find(const TYPE& x)
{
	// TODO: 04 find(const TYPE& x)
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
			valeurPlusPetite = *((c->m_suiv[i])->m_contenu) < t;

		while (pasNull && valeurPlusPetite) {
			c = c->m_suiv[i];
		}
	}
	iterator it = iterator(c->m_suiv[0]);
	return it;
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::upper_bound(const TYPE& x)
{
	// TODO: 03 upper_bound(const TYPE& x)
	cellule* c = m_avant;
	size_t k = m_avant->m_suiv.size();
	for (int i = k - 1; i >= 0; i--) {
		while (!(x < c->m_suiv[i].val)) {
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
	// TODO: 05 erase(const TYPE& VAL)
}

// erase(it)
// elimine de l'ensemble l'element en position it

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::erase(iterator it)
{
	// TODO: 06 erase(iterator it) 
}

#endif
