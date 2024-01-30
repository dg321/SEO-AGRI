#include <seo_agriplugin.h>
#include <Frm_Principal.h>
#include <qmessagebox.h>

Frm_Principal* mainForm;

seo_agriPlugin::seo_agriPlugin(PluginParameters* params):
QObject(),
TViewAbstractPlugin(params)
{
	loadTranslationFiles("seo_agri_");
}

seo_agriPlugin::~seo_agriPlugin()
{
	end();
}

void seo_agriPlugin::init()
{
	//Here you must put the enterings for the plug-in. Use qt signal/slots to do it!
	TerraViewBase* tview = getMainWindow();
	
	if (tview)
	{
		QPopupMenu* mnu = getPluginsMenu();
		
		if (mnu !=0)
		{

			mnu -> insertItem(tr("SEO-AGRI"), this, SLOT(execPlugin()));
		}

	}
}

void seo_agriPlugin::end()
{
	delete mainForm;
}

void seo_agriPlugin::execPlugin()
{	
	mainForm = new Frm_Principal(this->params_->qtmain_widget_ptr_,"Sistema Especialista Para Otimização de Colheita de Agricola", Qt::WType_TopLevel | Qt::WShowModal );

	TerraViewBase* tview = getMainWindow();

	if(tview->currentDatabase())
	{		
		if (tview)
		{
			mainForm->iniciar(tview, this->params_);
		}

	} else 
	{
		QMessageBox::information(tview, tr("Aviso de conexão"), tr("Primeiro conecte o TerraView a uma Base de Dados"));
	}

}