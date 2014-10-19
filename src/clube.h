#include <vector>
#include <fstream>
#include <sstream>

#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

#include "modalidade.h"
#include "submodalidade.h"

#include "quota.h"
#include "despesa.h"

using std::vector;

const string FILE_JOGADORES = "txt/jogadores.txt";
const string FILE_MODALIDADES = "txt/modalidades.txt";

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

    //GET
    vector<Modalidade *> getMods(){return modalidades;}
    vector<Jogador *> getJogadores(){return jogadores;}

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

    void listarModalidades();

    void CRUD();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);

    //FILE MANAGEMENT
    bool readModalidades();
    bool readJogadores();
    bool writeModalidades(vector<Modalidade *> modalidade);
    bool writeJogadores(vector<Jogador *> jogadores);

};
