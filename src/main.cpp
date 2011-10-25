#include <QtGui/QApplication>
#include <QtDeclarative>
#ifdef __arm__
#include <applauncherd/MDeclarativeCache>
#endif


Q_DECL_EXPORT int main(int argc, char *argv[])
{
#ifdef __arm__
    QApplication *app = MDeclarativeCache::qApplication(argc, argv);
#else
    QApplication *app = new QApplication(argc, argv);
#endif


    app->setProperty("NoMStyle", true);
    QDeclarativeView *view = new QDeclarativeView();
    view->setSource(QUrl("qrc:/qml/main.qml"));


    QStringList result;
    result = app->arguments().filter("--uri=");
    if ((result.isEmpty() == false) && (result.count()==1)) { //interested in only one hit, sry
        if (result.at(0).startsWith("--uri=")) {
            QString gotoUri = result.at(0).mid(6);
            QDeclarativeContext *context = view->rootContext();
            context->setContextProperty("gotoUri", gotoUri);
        }
    }

#ifdef __arm__
    view->showFullScreen();
#else
    view->show();
#endif

    QObject::connect(view->engine(), SIGNAL(quit()), view, SLOT(close()));

    return app->exec();
}
