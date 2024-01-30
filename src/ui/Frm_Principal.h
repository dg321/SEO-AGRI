/****************************************************************************
** Form interface generated from reading ui file 'ui\Frm_Principal.ui'
**
** Created: sáb 31. mar 18:07:59 2012
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.0   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRM_PRINCIPAL_H
#define FRM_PRINCIPAL_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qmainwindow.h>
#include <TerraViewBase.h>
#include <PluginParameters.h>
#include <Persistente.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class ResultVisual;
class QTabWidget;
class QWidget;
class QFrame;
class QGroupBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QTable;
class QTextEdit;
class QComboBox;
class QDateEdit;

class Frm_Principal : public QMainWindow
{
    Q_OBJECT

public:
    Frm_Principal( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~Frm_Principal();

    QTabWidget* tab_Principal;
    QWidget* tab_Perdas;
    QFrame* frm_Perdas;
    QFrame* ln_PerdaSeparacao;
    QGroupBox* gb_PerdaCadastro;
    QLineEdit* edt_PerdaUmidade;
    QLineEdit* edt_PerdaPerda;
    QLabel* lb_PerdaPerda;
    QLabel* lb_PerdaUmidade;
    QPushButton* bt_PerdaSalvar;
    QLabel* lb_PerdaGrafico;
    ResultVisual* gf_PerdaGrafico;
    QGroupBox* gb_PerdaLista;
    QPushButton* bt_PerdaDeletar;
    QTable* tb_PerdaLista;
    QWidget* tab_Colheitadeiras;
    QFrame* frm_Colheitadeiras;
    QGroupBox* gb_ColheitadeiraCadastro;
    QLabel* lb_ColheitadeiraNome;
    QLineEdit* edt_ColheitadeiraNome;
    QLabel* lb_ColheitadeiraHaHora;
    QLineEdit* edt_ColheitadeiraHaHora;
    QLabel* lb_ColheitadeiraHoraColhida;
    QLineEdit* edt_ColheitadeiraHoraColhida;
    QLabel* lb_ColheitadeiraDescricao;
    QTextEdit* edt_ColheitadeiraDescricao;
    QPushButton* bt_ColheitadeiraSalvar;
    QFrame* ln_ColheitadeiraSeparador;
    QLabel* lb_ColheitadeiraLista;
    QTable* tb_ColheitadeiraLista;
    QPushButton* bt_ColheitadeiraDeletar;
    QWidget* tab_Areas;
    QFrame* frm_areas;
    QFrame* line7;
    QLabel* lb_AreaListaArea;
    QPushButton* bt_AreaSalvar;
    QGroupBox* gb_AreasCadastro;
    QLabel* lb_AreaNome;
    QPushButton* bt_AreaMaisCoordenadas;
    QLineEdit* edt_AreaNome;
    QTable* tb_AreaCoordenada;
    QPushButton* bt_AreaDeletar;
    QTable* tb_AreaLista;
    QWidget* tab_Umidade;
    QFrame* frm_Umidade;
    QGroupBox* gb_UmidadeCadastro;
    QLabel* lb_UmidadeNome;
    QComboBox* cb_UmidadeArea;
    QLabel* lb_UmidadeData;
    QDateEdit* de_UmidadeData;
    QLabel* lb_UmidadeUmidade;
    QLineEdit* edt_UmidadeUmidade;
    QFrame* ln_UmidadeSeparador;
    QLabel* lb_UmidadeLista;
    QTable* tb_UmidadeLista;
    QPushButton* bt_UmidadeSalvar;
    QPushButton* bt_UmidadeDelete;
    QGroupBox* gb_UmidadeFiltro;
    QLabel* lb_UmidadeFiltroArea;
    QLabel* lb_UmidadeFiltroData;
    QComboBox* cb_UmidadeFiltroArea;
    QComboBox* cb_UmidadeFiltroData;
    QPushButton* bt_UmidadeFiltrar;
    QWidget* tab_Distancias;
    QFrame* frm_Distancias;
    QLabel* lb_Distancia;
    QTable* tb_DistanciaMatriz;
    QPushButton* bt_DistanciaSalvar;
    QWidget* tab_Ordem;
    QFrame* frm_Ordenar;
    QLabel* lb_Ordenar;
    QPushButton* bt_OrdenarAdicionar;
    QPushButton* bt_OrdenarAdicionarTodas;
    QPushButton* bt_OrdenarRemoverTodos;
    QPushButton* bt_OrdenarRemover;
    QPushButton* bt_OrdenarOrdenar;
    QTable* tb_OrdenarLista;
    QTable* tb_OrdenarHaOrdenar;
    QWidget* tab_Sobre;
    QFrame* frm_Sobre;

    void iniciar( TerraViewBase * tview, PluginParameters * params );
    void atualizaTodasTabelas();
    void atualizarTabela( QTable * qtTabela, Persistente * objeto, TeDatabase * database, string nomeTabela, string filtro );
    void carregaTodosCombo();
    void carregaMatrizDistancia();
    void atualizaTabelaOrdem();

public slots:
    virtual void bt_PerdaDeletar_clicked();
    virtual void bt_PerdaSalvar_clicked();
    virtual void bt_ColheitadeiraSalvar_clicked();
    virtual void bt_ColheitadeiraDeletar_clicked();
    virtual void bt_AreaSalvar_clicked();
    virtual void bt_AreaMaisCoordenadas_clicked();
    virtual void bt_UmidadeSalvar_clicked();
    virtual void bt_UmidadeDelete_clicked();
    virtual void bt_UmidadeFiltrar_clicked();
    virtual void carregaCombo( QComboBox * cbCombo, Persistente * objeto, TeDatabase * database, string nomeTabela, string item, string filtro, bool itemTodos );
    virtual void bt_AreaDeletar_clicked();
    virtual void bt_DistanciaSalvar_released();
    virtual void bt_OrdenarAdicionar_clicked();
    virtual void bt_OrdenarAdicionarTodas_clicked();
    virtual void bt_OrdenarRemoverTodos_clicked();
    virtual void bt_OrdenarRemover_clicked();
    virtual void bt_OrdenarOrdenar_clicked();

protected:

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    QPixmap image1;

};

#endif // FRM_PRINCIPAL_H
