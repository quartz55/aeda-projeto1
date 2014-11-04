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
#include "data.h"

using std::vector;using std::string;


class Clube{

	Data dataActual;

    vector <Pessoa *> externos;
    vector <Jogador *> jogadores;
    vector <Socio *> socios;

    vector <Modalidade *> modalidades;
    vector <SubModalidade *> sub_modalidades;

    vector <Despesa *> despesas;



    public:

    Clube();

    //DATA
    static string FILE_JOGADORES;
    static string FILE_MODALIDADES;
    static string FILE_SOCIOS;
    static string FILE_DATA;
    static string FILE_DESPESAS;
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

    bool addDespesa(Despesa *d);
    //#######################################

    //REMOVE
    bool removeExterno(Pessoa *p);
    bool removeJogador(Jogador *j);
    bool removeSocio(Socio *s);

    bool removeModalidade(Modalidade *m);
    bool removeSubModalidade(SubModalidade *sm);

    bool removeDespesa(Despesa *d);

    //#######################################

    bool changeModalidade(string name, string new_name);
    bool changeSubModalidade(string name, string new_name);

    bool changeDespesa(Despesa* d, string newInfo, Data* novaData, float novoValor);

    //LISTAGEM
    void listarPessoas();

    template<class C>
    void listar(vector <C *> pessoas, bool idade, bool sexo);

    template<class C>
    void listarPorModalidades(vector<C *> pessoas);

    void listarExternos();
    void listarJogadores();
    void listarSocios();

    void listarModalidades();

    void listarDespesas();
    //#######################################

    //CRUD
    void CRUD();
    void manutencao();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);
	bool manutencaoModalidades();
	bool manutencaoModalidade(Modalidade * m1);
	bool manutencaoSocios();
	bool manutencaoSocio(Socio * s1);
	bool manutencaoDespesas();
	bool manutencaoDespesa(Despesa* d1);
    //#######################################

    //FILE MANAGEMENT
    bool readModalidades(string filename);
    bool readJogadores(string filename);
    bool readSocios(string filename);
    bool readData(string filename);
    bool readDespesas(string filename);

    bool writeModalidades(vector<Modalidade *> modalidade, string filename);
    bool writeJogadores(vector<Jogador *> jogadores, string filename);
    bool writeSocios(vector<Socio *> socios, string filename);
    bool writeData(string filename);
    bool writeDespesas(string filename);

    bool readAll();
    bool writeAll();
    //#######################################

    bool quit();

    void clearScr();

};
