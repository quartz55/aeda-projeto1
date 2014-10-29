#include <vector>
#include <fstream>
#include <sstream>

#include "interface.h"

#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

#include "modalidade.h"
#include "submodalidade.h"

#include "quota.h"
#include "despesa.h"

using std::vector;using std::string;


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

    //DATA
    static string FILE_JOGADORES;
    static string FILE_MODALIDADES;
    static string FILE_SOCIOS;
    static Interface *iface;

    //GET
    vector<Modalidade *> getMods(){return modalidades;}
    vector<Jogador *> getJogadores(){return jogadores;}
    vector<Socio *> getSocios(){return socios;}
    //#######################################

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
    bool removeExterno(Pessoa *p);
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
    //#######################################

    //CRUD
    void CRUD();
    void manutencao();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);
    //#######################################

    //FILE MANAGEMENT
    bool readModalidades(string filename);
    bool readJogadores(string filename);
    bool readSocios(string filename);

    bool writeModalidades(vector<Modalidade *> modalidade, string filename);
    bool writeJogadores(vector<Jogador *> jogadores, string filename);
    bool writeSocios(vector<Socio *> socios, string filename);

    bool readAll();
    bool writeAll();
    //#######################################

    bool quit();

    void clearScr();

};
