#include <QtWidgets>

#include "notepad.h"

Notepad::Notepad(QWidget *wgt) : QMainWindow(wgt) {

    setWindowTitle(tr("Unnamed"));
    doc = new Document;
    fileMenu = new QMenu(tr("&File"));
    editMenu = new QMenu(tr("&Edit"));
    formatMenu = new QMenu(tr("&Format"));
    aboutMenu = new QMenu(tr("&About"));
    fileMenu->addAction(tr("&New"),doc, SLOT(createFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), doc,  SLOT(openFile()), QKeySequence::Open);
    fileMenu->addAction(tr("Save"), doc, SLOT(saveFile()), QKeySequence::Save);
    fileMenu->addAction(tr("Save as"), doc, SLOT(saveFileAs()));
    fileMenu->addAction(tr("Quit"), qApp, SLOT(quit()), QKeySequence::Quit);


    editMenu->addAction(tr("&Cancel"), doc, SLOT(undo()), QKeySequence(Qt::CTRL + Qt::Key_Z));
    editMenu->addSeparator();

    editMenu->addAction(tr("&Cut"), doc, SLOT(cut()), QKeySequence::Cut);
    editMenu->addAction(tr("&Copy"), doc, SLOT(copy()), QKeySequence::Copy);
    editMenu->addAction(tr("&Paste"), doc, SLOT(paste()), QKeySequence::Paste);
    editMenu->addAction(tr("Delete"), doc, SLOT(deleteSlot()), QKeySequence::Delete);

    editMenu->addSeparator();

    editMenu->addAction(tr("Find"), doc, SLOT(searchSlot()), QKeySequence::Find);
    editMenu->addAction(tr("Find next"), doc, SLOT(searchNextSlot()), QKeySequence::FindNext);
    editMenu->addAction(tr("Replace"), doc, SLOT(replaceSlot()), QKeySequence::Replace);
    editMenu->addAction(tr("Forward to"), doc, SLOT(forwardToSlot()), QKeySequence::Forward);

    editMenu->addSeparator();
    editMenu->addAction(tr("Select All"), doc, SLOT(selectAll()), QKeySequence::SelectAll);
    editMenu->addAction(tr("Date and time"), doc, SLOT(dateAndTimeSlot()), Qt::Key_F5);

    formatMenu->addAction(tr("Font"), doc, SLOT(selectFontSlot()));

    aboutMenu->addAction(tr("About"), qApp, SLOT(Qt::about()));

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(editMenu);
    menuBar()->addMenu(formatMenu);
    menuBar()->addMenu(aboutMenu);
    menuBar()->show();
    setCentralWidget(doc);

}
void Notepad::closeEvent(QCloseEvent *ev){
    //doc->setSettingsToDefault();
}








