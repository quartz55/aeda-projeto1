template <class C>
bool sortByName(const C *lhs, const C *rhs) { return lhs->getNome() < rhs->getNome();}
bool sortByIdade(const Pessoa *lhs, const Pessoa *rhs) { return lhs->getIdade() < rhs->getIdade();}
