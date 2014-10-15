#include <vector>

#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

#include "modalidade.h"
#include "submodalidade.h"

#include "quota.h"
#include "despesa.h"

using std::vector;

class Clube{

    vector <Pessoa *> externos;
    vector <Jogador *> jogadores;
    vector <Socio *> socios;

    vector <Modalidade *> modalidades;
    vector <SubModalidade *> sub_modalidades;

    vector <Quota *> quotas;
    vector <Despesa *> despesas;

    public:

    Clube();

    //ADD
    bool addJogador(Jogador *j){jogadores.push_back(j); return true;}
    bool addSocio(Socio *s){socios.push_back(j); return true;}
    bool addExterno(Pessoa *e);

    bool addModalidade(Modalidade *m){modalidades.push_back(m); return true;}
    bool addSubModalidade(SubModalidade *sm){sub_modalidades.push_back(sm); return true;}

    bool addQuota(Quota *q);
    bool addDespesa(Despesa *d);
    //#######################################

    bool changeModalidade(string name, string new_name);
    bool changeSubModalidade(string name, string new_name);

    void CRUD();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);


};
