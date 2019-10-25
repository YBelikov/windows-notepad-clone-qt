#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QDateTime>
#include "searchdialog.h"
#include "replacedialog.h"

class Document : public QTextEdit
{
Q_OBJECT
private:
    QString docTitle;
    SearchDialog *searchDialog;
    ReplaceDialog *replaceDialog;
    bool saved;

public:
    Document(QWidget *wgt = nullptr);

public slots:
    void createFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void deleteSlot();
    void searchSlot();
    void searchNextSlot();
    void replaceSlot();
    void forwardToSlot();
    void dateAndTimeSlot();
    void selectFontSlot();

private slots:
    void searchForReplaceSlot();
    void replaceTextSlot();
    void replaceAlSlot();

signals:
    void changeWindowTitle(const QString&);
};


#endif // DOCUMENT_H
