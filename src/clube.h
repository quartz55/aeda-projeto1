#include <vector>
#include <fstream>
#include <sstream>
#include <string>

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
	void main();
	void TopMenu(string name);
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
    void listarPessoal();

    template<class C>
    std::string listarPessoas(vector <C *> pessoas, bool idade, bool sexo);

    template<class C>
    std::string listarPorModalidades(vector<C *> pessoas);

    bool listarExternos(string &lista);
    bool listarJogadores(string &lista);
    bool listarSocios(string &lista);

    std::string listarMods(vector <Modalidade *> modalidades);
    bool listarModalidades(string &lista);

    bool listarDespesas(string &lista);
    //#######################################

    //CRUD
    bool infoExternos();
    bool infoJogadores();
    bool infoSocios();
    void manutencao();
    bool manutencaoJogadores();
    bool manutencaoJogador(Jogador * j1);
	bool manutencaoSocios();
	bool manutencaoSocio(Socio * s1);
	bool manutencaoExternos();
	bool manutencaoExterno(Pessoa * p1);
	bool manutencaoModalidades();
	bool manutencaoModalidade(Modalidade * m1);
	bool manutencaoSubModalidade(Modalidade * m1);
	bool manutencaoSubModalidade(SubModalidade * sm1);
	bool manutencaoDespesas();
	bool manutencaoDespesa(Despesa* d1);
	void alterarData();
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

    void update();

    void pressToContinue();
    bool quit();

    void clearScr();

};
