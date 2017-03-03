#include <qapplication.h>
#include <qmessagebox.h>
#include "frmcommissioner.h"
#include <QPlastiqueStyle>
#include <iostream>
#include <QPixmap>
#include <QSplashScreen>
#include "Debug.h"
#include <unistd.h>
void printAsciiStart() {
    std::cout   << "\n"
                << "   \e[1;30m********************************************************************\e[0m\n"
                << "   \e[1;30m*\e[0m     \e[1;30m _   _    ___                 _       _                      \e[0m\e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m     \e[1;34m| |_| |__/ __|___ _ __  _ __ (_)_____(_)___ _ _  ___ _ _     \e[0m\e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m     \e[1;34m|  _| / / (__/ _ \\ '  \\| '  \\| (_-<_-< / _ \\ ' \\/ -_) '_|    \e[0m\e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m     \e[1;34m \\__|_\\_\\\\___\\___/_|_|_|_|_|_|_/__/__/_\\___/_||_\\___|_|      \e[0m\e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m                                                                  \e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m                        (tkCommissioner)                          \e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m                                                                  \e[1;30m*\e[0m\n"
                << "   \e[1;30m*\e[0m                                                                  \e[1;30m*\e[0m\n"
                << "   \e[1;30m********************************************************************\e[0m\n";
}

int main(int argc, char ** argv) {
    QApplication::setStyle(new QPlastiqueStyle);
    QApplication a(argc, argv);

    QStringList arguments = a.arguments();

    if (arguments.size() < 3 || arguments.size() > 5) {
        std::cout << "Invalid set of arguments" << std::endl;
        return 0;
    }

    printAsciiStart();

    //Debug::Inst()->setEnabled(true);
    
    Commissioner* w = new Commissioner;

    std::vector<QPair<QString, QString> > treePaths;

    if      (arguments.size() == 3) {
        treePaths.push_back(QPair<QString, QString>(arguments[1], arguments[2]));
        treePaths.push_back(QPair<QString, QString>("", ""));
    }
    else if (arguments.size() == 4) {
        treePaths.push_back(QPair<QString, QString>(arguments[1], arguments[3]));
        treePaths.push_back(QPair<QString, QString>(arguments[2], arguments[3]));
    }
    else {
        treePaths.push_back(QPair<QString, QString>(arguments[1], arguments[2]));
        treePaths.push_back(QPair<QString, QString>(arguments[3], arguments[4]));
    }

    w->setInput("/data/users/cctrack/avartak/QtProjects/data/tmp/tmp.root", treePaths);
    w->show();
    a.connect(w, SIGNAL(destroyed()), &a, SLOT(quit()));

    return a.exec();
}

