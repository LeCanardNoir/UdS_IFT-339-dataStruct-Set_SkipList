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
	while (it != src.end()) {
		// Complexité de O(n log n)
		// TODO: 999 Améliorer l'insertion des éléments initiaux
		// Peut être amélioré en devenant O(n) en admettant que
		// les éléments de la skip_list initiale sont déjà dans l'ordre,
		// donc en ajoutant des éléments directement à la fin.
		this->insert(*it);
		++it;
	}
}

template <typename TYPE>
set<TYPE>::~set()
{
	// TODO: 02 ~set() faire le destructeur
}

/////////////////////////////////////////////////////////////////
// find
// localise un élément, retourne la fin si absent

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
    cellule *c = m_avant;
    cellule *apres = m_avant->m_prec[0];
	while(c->m_suiv[0] != apres)
		if(*c->m_suiv[0]->m_contenu < t)
			c = c->m_suiv[0];
		else
			break;
	return iterator(c->m_suiv[0]);
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::upper_bound(const TYPE& x)
{
	// TODO: 03 upper_bound(const TYPE& x)
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
