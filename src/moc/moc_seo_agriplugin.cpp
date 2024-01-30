/****************************************************************************
** seo_agriPlugin meta object code from reading C++ file 'seo_agriplugin.h'
**
** Created: qua 28. mar 17:01:14 2012
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../include/seo_agriplugin.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *seo_agriPlugin::className() const
{
    return "seo_agriPlugin";
}

QMetaObject *seo_agriPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_seo_agriPlugin( "seo_agriPlugin", &seo_agriPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString seo_agriPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "seo_agriPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString seo_agriPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "seo_agriPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* seo_agriPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"execPlugin", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "execPlugin()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"seo_agriPlugin", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_seo_agriPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* seo_agriPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "seo_agriPlugin" ) )
	return this;
    if ( !qstrcmp( clname, "TViewAbstractPlugin" ) )
	return (TViewAbstractPlugin*)this;
    return QObject::qt_cast( clname );
}

bool seo_agriPlugin::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: execPlugin(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool seo_agriPlugin::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool seo_agriPlugin::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool seo_agriPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
