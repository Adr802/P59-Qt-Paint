#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traduccion;
    QStringList idiomas;
    idiomas << "Español" << "Ingles";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma",
                                                       "Seleccione un idioma",
                                                       idiomas);
    if(idiomaSeleccionado == "Ingles"){
        traduccion.load(":/MiPaint_en.qm");
    }

    if(idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }


    Principal w;
    w.show();
    return a.exec();
}
