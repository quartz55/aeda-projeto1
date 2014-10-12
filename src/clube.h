#include <vector>

#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

using std::vector;

class Clube{

    vector <Jogador *> jogadores;
    vector <Socio *> socios;
    vector <Pessoa *> externos;
    vector <Modalidade *> modalidades;

    public:
    Clube();

};
