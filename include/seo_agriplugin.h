#ifndef __SEO_AGRI_PLUGIN_H_
#define __SEO_AGRI_PLUGIN_H_

#include <TViewAbstractPlugin.h>

//Qt include files
#include <qobject.h>

class seo_agriPlugin: public QObject, public TViewAbstractPlugin
{
	Q_OBJECT

public:
	/**	\brief Constructor.
	 *	\param params Plugin parameters.
	 */
	seo_agriPlugin(PluginParameters* params);

	/**	\brief Destructor.
	 */
	~seo_agriPlugin();

	/**	\brief Initializer method.
	 */
	void init();

	/**	\brief Finalizer method.
	 */
	void end();

protected slots:
	void execPlugin();
};

#endif //__SEO_AGRI_PLUGIN_H_