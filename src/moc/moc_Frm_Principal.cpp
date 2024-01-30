/****************************************************************************
** Frm_Principal meta object code from reading C++ file 'Frm_Principal.h'
**
** Created: sáb 31. mar 18:08:01 2012
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../ui/Frm_Principal.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Frm_Principal::className() const
{
    return "Frm_Principal";
}

QMetaObject *Frm_Principal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Frm_Principal( "Frm_Principal", &Frm_Principal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Frm_Principal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Frm_Principal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Frm_Principal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Frm_Principal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Frm_Principal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"bt_PerdaDeletar_clicked", 0, 0 };
    static const QUMethod slot_1 = {"bt_PerdaSalvar_clicked", 0, 0 };
    static const QUMethod slot_2 = {"bt_ColheitadeiraSalvar_clicked", 0, 0 };
    static const QUMethod slot_3 = {"bt_ColheitadeiraDeletar_clicked", 0, 0 };
    static const QUMethod slot_4 = {"bt_AreaSalvar_clicked", 0, 0 };
    static const QUMethod slot_5 = {"bt_AreaMaisCoordenadas_clicked", 0, 0 };
    static const QUMethod slot_6 = {"bt_UmidadeSalvar_clicked", 0, 0 };
    static const QUMethod slot_7 = {"bt_UmidadeDelete_clicked", 0, 0 };
    static const QUMethod slot_8 = {"bt_UmidadeFiltrar_clicked", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "cbCombo", &static_QUType_ptr, "QComboBox", QUParameter::In },
	{ "objeto", &static_QUType_ptr, "Persistente", QUParameter::In },
	{ "database", &static_QUType_ptr, "TeDatabase", QUParameter::In },
	{ "nomeTabela", &static_QUType_ptr, "string", QUParameter::In },
	{ "item", &static_QUType_ptr, "string", QUParameter::In },
	{ "filtro", &static_QUType_ptr, "string", QUParameter::In },
	{ "itemTodos", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"carregaCombo", 7, param_slot_9 };
    static const QUMethod slot_10 = {"bt_AreaDeletar_clicked", 0, 0 };
    static const QUMethod slot_11 = {"bt_DistanciaSalvar_released", 0, 0 };
    static const QUMethod slot_12 = {"bt_OrdenarAdicionar_clicked", 0, 0 };
    static const QUMethod slot_13 = {"bt_OrdenarAdicionarTodas_clicked", 0, 0 };
    static const QUMethod slot_14 = {"bt_OrdenarRemoverTodos_clicked", 0, 0 };
    static const QUMethod slot_15 = {"bt_OrdenarRemover_clicked", 0, 0 };
    static const QUMethod slot_16 = {"bt_OrdenarOrdenar_clicked", 0, 0 };
    static const QUMethod slot_17 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "bt_PerdaDeletar_clicked()", &slot_0, QMetaData::Public },
	{ "bt_PerdaSalvar_clicked()", &slot_1, QMetaData::Public },
	{ "bt_ColheitadeiraSalvar_clicked()", &slot_2, QMetaData::Public },
	{ "bt_ColheitadeiraDeletar_clicked()", &slot_3, QMetaData::Public },
	{ "bt_AreaSalvar_clicked()", &slot_4, QMetaData::Public },
	{ "bt_AreaMaisCoordenadas_clicked()", &slot_5, QMetaData::Public },
	{ "bt_UmidadeSalvar_clicked()", &slot_6, QMetaData::Public },
	{ "bt_UmidadeDelete_clicked()", &slot_7, QMetaData::Public },
	{ "bt_UmidadeFiltrar_clicked()", &slot_8, QMetaData::Public },
	{ "carregaCombo(QComboBox*,Persistente*,TeDatabase*,string,string,string,bool)", &slot_9, QMetaData::Public },
	{ "bt_AreaDeletar_clicked()", &slot_10, QMetaData::Public },
	{ "bt_DistanciaSalvar_released()", &slot_11, QMetaData::Public },
	{ "bt_OrdenarAdicionar_clicked()", &slot_12, QMetaData::Public },
	{ "bt_OrdenarAdicionarTodas_clicked()", &slot_13, QMetaData::Public },
	{ "bt_OrdenarRemoverTodos_clicked()", &slot_14, QMetaData::Public },
	{ "bt_OrdenarRemover_clicked()", &slot_15, QMetaData::Public },
	{ "bt_OrdenarOrdenar_clicked()", &slot_16, QMetaData::Public },
	{ "languageChange()", &slot_17, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Frm_Principal", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Frm_Principal.setMetaObject( metaObj );
    return metaObj;
}

void* Frm_Principal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Frm_Principal" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool Frm_Principal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: bt_PerdaDeletar_clicked(); break;
    case 1: bt_PerdaSalvar_clicked(); break;
    case 2: bt_ColheitadeiraSalvar_clicked(); break;
    case 3: bt_ColheitadeiraDeletar_clicked(); break;
    case 4: bt_AreaSalvar_clicked(); break;
    case 5: bt_AreaMaisCoordenadas_clicked(); break;
    case 6: bt_UmidadeSalvar_clicked(); break;
    case 7: bt_UmidadeDelete_clicked(); break;
    case 8: bt_UmidadeFiltrar_clicked(); break;
    case 9: carregaCombo((QComboBox*)static_QUType_ptr.get(_o+1),(Persistente*)static_QUType_ptr.get(_o+2),(TeDatabase*)static_QUType_ptr.get(_o+3),(string)(*((string*)static_QUType_ptr.get(_o+4))),(string)(*((string*)static_QUType_ptr.get(_o+5))),(string)(*((string*)static_QUType_ptr.get(_o+6))),(bool)static_QUType_bool.get(_o+7)); break;
    case 10: bt_AreaDeletar_clicked(); break;
    case 11: bt_DistanciaSalvar_released(); break;
    case 12: bt_OrdenarAdicionar_clicked(); break;
    case 13: bt_OrdenarAdicionarTodas_clicked(); break;
    case 14: bt_OrdenarRemoverTodos_clicked(); break;
    case 15: bt_OrdenarRemover_clicked(); break;
    case 16: bt_OrdenarOrdenar_clicked(); break;
    case 17: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Frm_Principal::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Frm_Principal::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool Frm_Principal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
