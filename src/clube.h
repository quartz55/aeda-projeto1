#ifndef CLUBE_H
#define CLUBE_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <set>
#include <tr1/unordered_set>

#include "interface.h"

#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

#include "modalidade.h"
#include "submodalidade.h"

#include "quota.h"
#include "despesa.h"
#include "data.h"
#include "lugar.h"

#include "empresa.h"

using std::vector;using std::string;using std::priority_queue; using std::set;

struct Hash{
	int operator()(const Socio* s1) const{
		string nome = s1->getNome();
		int key = 0;
		for(unsigned int i = 0; i < nome.size(); i++){
			key = key*37 + nome[i];
		}
		return key;
	}
	bool operator()(const Socio* s1, const Socio* s2)const{
		if(s1->getNome() == s2->getNome() || s1->getNIF() == s2->getNIF()){
			return true;
		}
		return false;
	}
};

struct setCompair
{
  bool operator()(Lugar* l1, Lugar*l2) const
  {
    return *l1 < *l2;
  }
};

/**
 * Classe responsavel por criar um clube.
 */
class Clube{

	Data dataActual;

  vector <Pessoa *> externos;
  vector <Jogador *> jogadores;
  vector <Socio *> socios;

  vector <Modalidade *> modalidades;
  vector <SubModalidade *> sub_modalidades;

  vector <Despesa *> despesas;

  typedef std::tr1::unordered_set<Socio*,Hash,Hash> SociosHash;
  typedef priority_queue<Empresa*, vector<Empresa *>, CompareEmpresas> EMP_QUEUE;

  SociosHash socios_em_atraso;
  EMP_QUEUE empresas;           /**< Empresas existentes guardadas numa fila de prioridade */
  set<Lugar *,setCompair> lugares;


public:
  /**Construtor da classe. Inicializa o clube (chama o menu princiapal e a leitura de ficheiros.
   *
   */
  Clube();
  /**Menu Incial. Imprime na consola.
   *
   */
	void main();
	/** Parte superior de todos os menus. Imprime na consola.
	 *@param name especificacao do menu.
	 */
	void TopMenu(string name);
  //DATA
  static string FILE_JOGADORES; //!< Directorio do ficheiro txt com informacoes dos jogadores
  static string FILE_MODALIDADES;//!< Directorio do ficheiro txt com informacoes das modalidades
  static string FILE_SOCIOS;//!< Directorio do ficheiro txt com informacoes dos socios
  static string FILE_DATA;//!< Directorio do ficheiro txt com informacoes da data
  static string FILE_DESPESAS;//!< Directorio do ficheiro txt com informacoes das despesas
	static string FILE_EXTERNOS;//!< Directorio do ficheiro txt com informacoes dos externos
	static string FILE_EMPRESAS;//!< Directorio do ficheiro txt com informacoes das empresas 
	static string FILE_LUGARES;//!< Directorio do ficheiro txt com informacoes dos lugares
  static Interface *iface;//!< Interface "grafica"

  //GET
  /**Retorna um vector de apontadores das modalidades do clube.
   *
   */
  vector<Modalidade *> getMods(){return modalidades;}
  /**Retorna um vector de apontadores dos jogadores do clube.
   *
   */
  vector<Jogador *> getJogadores(){return jogadores;}
  /**Retorna um vector de apontadores dos socios do clube.
   *
   */
  vector<Socio *> getSocios(){return socios;}
  //#######################################

  //ADD
  /**Adiciona um novo externo ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param p apontador para o novo externo.
   */
  bool addExterno(Pessoa *p);
  /**Adiciona um novo jogador ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param j apontador para o novo jogador.
   */
  bool addJogador(Jogador *j);
  /**Adiciona um novo socio ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param s apontador para o novo socio.
   */
  bool addSocio(Socio *s);

  /**Adiciona uma nova modalidade ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param m apontador para a nova modalidade.
   */
  bool addModalidade(Modalidade *m){
    for(size_t i = 0; i < modalidades.size(); i++){
      if(modalidades[i]->getNome() == m->getNome()){
        throw modalidades[i]->getNome();
        return false;
      }
    }
    modalidades.push_back(m);
    return true;
  }
  /**Adiciona uma nova sub-modalidade ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param sm apontador para a nova sub-modalidade.
   */
  bool addSubModalidade(SubModalidade *sm){sub_modalidades.push_back(sm); return true;}
  /**Adiciona uma nova despesa ao clube. Retorna true em caso de sucesso e false caso contrario.
   *@param d apontador para a nova despesa.
   */
  bool addDespesa(Despesa *d);
  /** 
   * Adiciona uma Empresa a fila de prioridade de empresas existente
   * @note A funcao lanca uma excepcao do tipo 'string' se a empresa ja existir
   *
   * @param e Empresa a dicionar
   * @return TRUE se adicionar com sucesso
   */
  bool addEmpresa(Empresa *e);

	bool addLugar(Lugar *l){ lugares.insert(l); return true; }
  //#######################################

  //REMOVE
  /**Remove um externo do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param p apontador do externo a remover.
   */
  bool removeExterno(Pessoa *p);
  /**Remove um jogador do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param j apontador do jogador a remover.
   */
  bool removeJogador(Jogador *j);
  /**Remove um socio do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param s apontador do socio a remover.
   */
  bool removeSocio(Socio *s);

  /**Remove uma modalidade do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param m apontador da modalidade a remover.
   */
  bool removeModalidade(Modalidade *m);
  /**Remove uma sub-modalidade do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param sm apontador da sub-modalidade a remover.
   */
  bool removeSubModalidade(SubModalidade *sm);

  /**Remove uma despesa do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param d apontador da despesa a remover.
   */
  bool removeDespesa(Despesa *d);

  //#######################################
  /**Altera o nome de uma modalidade. Retorna true em caso de sucesso e false caso contrario.
   *@param name nome da modalidade a alterar.
   *@param new_name novo nome da modalidade
   */
  bool changeModalidade(string name, string new_name);
  /**Altera o nome de uma sub-modalidade. Retorna true em caso de sucesso e false caso contrario.
   *@param name nome da sub-modalidade a alterar.
   *@param new_name novo nome da sub-modalidade
   */
  bool changeSubModalidade(string name, string new_name);
  /**Altera uma despesa do clube. Retorna true em caso de sucesso e false caso contrario.
   *@param d apontador para a despesa a alterar.
   *@param newInfo string com a nova descricao da despesa.
   *@param novaData apontador para a nova data da despesa.
   *@param novoValor float com o novo custo da despesa.
   */
  bool changeDespesa(Despesa* d, string newInfo, Data* novaData, float novoValor);

  //LISTAGEM
  /**Imprime todas as pessoas associadas ao clube.
   *
   */
  void listarPessoal();

  /**Retorna uma string com pessoas(ou jogadores, ou socios, ou externos) com infomacao de idade ou genero)
   *@param pessoas vector de apontadores das pessoas a listar.
   *@param idade true se a listagem for com idade.
   *@param sexo true se a llistagem for com sexo.
   */
  template<class C>
  std::string listarPessoas(vector <C *> pessoas, bool idade, bool sexo);
  /**Retorna uma string com pessoas(ou jogadores, ou socios, ou externos) ordenadas por modalidades)
   *@param pessoas vector de apontadores das pessoas a listar.
   */
  template<class C>
  std::string listarPorModalidades(vector<C *> pessoas);

  /**Altera o parametro lista de acordo com a listagem escolhida na funcao(nome,idade,sexo).
   *@param lista No final da funcao lista contem a listagem de externos de acordo com a ordenacao escolhida.
   */
  bool listarExternos(string &lista);
  /**Altera o parametro lista de acordo com a listagem escolhida na funcao(nome,idade,sexo).
   *@param lista No final da funcao lista contem a listagem de jogadores de acordo com a ordenacao escolhida.
   */
  bool listarJogadores(string &lista);
  /**Altera o parametro lista de acordo com a listagem escolhida na funcao(nome,idade,sexo).
   *@param lista No final da funcao lista contem a listagem de socios de acordo com a ordenacao escolhida.
   */
  bool listarSocios(string &lista);
  /**Retorna uma string com os socios e as respectivas quotas em atraso.
   *@param socios Vector de apontadores para socios que vao ser listados.
   */
  std::string listarComQuotas(vector<Socio*> socios);

  /**Retorna uma string com as modalidades e as respectivas sub-modalidades.
   *@param modalidades Vector de apontadores para modalidades que vao ser listadas.
   */
  std::string listarMods(vector <Modalidade *> modalidades);
  /**Altera o parametro lista de acordo com a listagem escolhida na funcao(por nome, por numero de sub-modalidades, com jogadores, com socios).
   *@param lista No final da funcao lista contem a listagem de modalidades de acordo com a ordenacao escolhida.
   */
  bool listarModalidades(string &lista);

  /**Altera o parametro lista de acordo com a listagem escolhida na funcao(por data ou por valor).
   *@param lista No final da funcao lista contem a listagem de despesas de acordo com a ordenacao escolhida.
   */
  bool listarDespesas(string &lista);
  /** 
   * Permite listar as empresas existentes de várias maneiras possíveis
   * à escolha do utilizador
   * @note A lista é guardada na string enviada por referencia
   * 
   * @param lista String a modificar com a listagem escohida
   * @return TRUE se listagem bem sucedida, FALSE se o utilizador escolheu a opcao sair
   */
  bool listarEmpresas(string &lista);
  /** 
   * Permite listar as empresas existentes que possuem o servico escolhido pelo
   * utilizador
   * 
   * @param lista String a modificar com a listagem escolhida 
   * @return TRUE se listagem bem sucedida, FALSE se o utilizador escolheu a opcao sair
   */
  bool listarEmpresasPorServicos(string &lista);
  /** 
   * Guarda todos os servicos disponiveis numa string para mostrar no ecra
   * 
   * @param vector_ref Vetor de strings com os titulos de todos os servicos
   * 
   * @return String com os todos os servicos
   */
  string listarServicos(vector<std::string> &vector_ref);

	bool listarLugares(string &lista);
  //#######################################

  //CRUD

  /** Escolha de externo para ver a sua ficha pessoal.
   *
   */
  bool infoExternos();
  /** Escolha de jogador para ver a sua ficha pessoal.
   *
   */
  bool infoJogadores();
  /** Escolha de socio para ver a sua ficha pessoal.
   *
   */
  bool infoSocios();

  /**
   * Escolha de empresa para ver a sua informaçao.
   */
  bool infoEmpresas();
  /** Menu de manutencao.
   *
   */
  void manutencao();
  /** Menu de manutencao de jogadores.
   *
   */
  bool manutencaoJogadores();
  /** Menu de manutencao de um jogador.
   *@param j1	apontador para jogador a sofrer alteracoes.
   */
  bool manutencaoJogador(Jogador * j1);
  /** Menu de manutencao de socios.
   *
   */
	bool manutencaoSocios();
  /** Menu de manutencao de um socio.
   *@param s1	apontador para socio a sofrer alteracoes.
   */
	bool manutencaoSocio(Socio * s1);
  /** Menu de manutencao de externos.
   *
   */
	bool manutencaoExternos();
  /** Menu de manutencao de um externo.
   *@param p1	apontador para externo a sofrer alteracoes.
   */
	bool manutencaoExterno(Pessoa * p1);
  /** Menu de manutencao de modalidades.
   *
   */
	bool manutencaoModalidades();
  /** Menu de manutencao de uma modalidade.
   *@param m1	apontador para modalidade a sofrer alteracoes.
   */
	bool manutencaoModalidade(Modalidade * m1);
	/** Menu de manutencao de sub-modalidades.
	 *@param m1 apontador para a modalidade que vai sofre alteracoes nas suas sub-modalidades.
	 */
	bool manutencaoSubModalidade(Modalidade * m1);
  /** Menu de manutencao de uma sub-modalidade.
   *@param sm1 apontador para sub-modalidade a sofrer alteracoes.
   */
	bool manutencaoSubModalidade(SubModalidade * sm1);
  /** Menu de manutencao de despesas.
   *
   */
	bool manutencaoDespesas();
  /** Menu de manutencao de uma despesa.
   *@param d1	apontador para despesa a sofrer alteracoes.
   */
	bool manutencaoDespesa(Despesa* d1);

  /** 
   * Menu de manutencao de empresas
   * @return TRUE se sair com sucesso, FALSE se ocorreu algum erro
   */ 
  bool manutencaoEmpresas();
  /** 
   * Menu te manutencao de uma empresa
   * @param e1 Empresa a gerir
   * @return TRUE se houve alguma alteração à empresa, FALSE se não
   */
  bool manutencaoEmpresa(Empresa *e1);
  /** Menu de alteracao da data actual.
   *
   */
	bool manutencaoLugares();
	bool manutencaoLugares(Lugar* l1);
    /** Menu de alteracao da data actual.
     *
     */
	void alterarData();
  //#######################################

  //FILE MANAGEMENT
	/**Le as modalidades e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
  bool readModalidades(string filename);
	/**Le os jogadores e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
  bool readJogadores(string filename);
	/**Le os socios e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
  bool readSocios(string filename);
	/**Le a data e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
  bool readData(string filename);
	/**Le as despesas e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
  bool readDespesas(string filename);
	/**Le os externos e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
	bool readExternos(string filename);

	/**
   * Le as empresas e as suas informacoes do ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro com as informacoes.
	 */
	bool readEmpresas(string filename);

	bool readLugares(string filename);

	/**Guarda as modalidades e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 *@param modalidade vector de apontadores com as modalidades a guardar.
	 */
  bool writeModalidades(vector<Modalidade *> modalidade, string filename);
	/**Guarda os jogadores e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 *@param jogadores vector de apontadores com os jogadores a guardar.
	 */
  bool writeJogadores(vector<Jogador *> jogadores, string filename);
	/**Guarda os socios e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 *@param socios vector de apontadores com os socios a guardar.
	 */
  bool writeSocios(vector<Socio *> socios, string filename);
	/**Guarda a data actual no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 */
  bool writeData(string filename);
	/**Guarda as despesas e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 */
  bool writeDespesas(string filename);
	/**Guarda os externos e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 *@param externos vector de apontadores com os externos a guardar.
	 */
	bool writeExternos(vector<Pessoa *> externos, string filename);

	/**
   * Guarda as empresas e as suas informacoes no ficheio txt. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *@param empresas Fila de prioridade com as empresas a guardar
	 *@param filename Directorio do ficheiro onde sao gravadas as informacoes.
	 */
  bool writeEmpresas(EMP_QUEUE empresas, string filename);
  
	bool writeLugares(string filename);

	/**Le todos os ficheiros com as informacoes do clube. Retorna true em caso de sucesso e falso em caso de insucesso.
	 *
	 */
  bool readAll();
  /**Guarda todas as informacoes do clube nos ficheiros. Retorna true em caso de sucesso e falso em caso de insucesso.
   *
   */
  bool writeAll();
  //#######################################

  /**Actualiza o numero de sub-modalidades de uma modalidade.
   *
   */
  void update();

  /** Funcao que faz o ecra esperar ate que seja primida uma nova tecla.
   *
   */
  void pressToContinue();
  /**Desliga o programa.
   *
   */
  bool quit();
  /**Limpa a linha de comandos.
   *
   */
  void clearScr();

  /**Atualiza a tabela de dispersao socios_em_atraso.
   *
   */
  void updateHashTable();
};

#endif
