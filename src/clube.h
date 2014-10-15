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
    bool addExterno(Pessoa *p);
    bool addJogador(Jogador *j);
    bool addSocio(Socio *s);

    bool addModalidade(Modalidade *m){modalidades.push_back(m); return true;}
    bool addSubModalidade(SubModalidade *sm){sub_modalidades.push_back(sm); return true;}

    bool addQuota(Quota *q);
    bool addDespesa(Despesa *d);
    //#######################################

    //REMOVE
    bool removeJogador(Jogador *j);
    bool removeSocio(Socio *s);
    //#######################################

    bool changeModalidade(string name, string new_name);
    bool changeSubModalidade(string name, string new_name);

    //LISTAGEM
    void listarPessoas();
    void listarExternos();
    void listarJogadores();
    void listarSocios();

    void CRUD();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);

};
