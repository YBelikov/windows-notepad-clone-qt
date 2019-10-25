#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QMainWindow>
#include "document.h"

class QMenuBar;
class QMenu;
class QToolBar;

class Notepad : public QMainWindow {
    Q_OBJECT
private:

    Document *doc;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *aboutMenu;

    QToolBar* topToolBar;


public:

    Notepad(QWidget *wgt = nullptr);
    virtual void closeEvent(QCloseEvent*) override;
};

#endif // NOTEPAD_H
