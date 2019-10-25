#include "document.h"

Document::Document(QWidget *wgt) : QTextEdit(wgt) {
    saved = false;
    replaceDialog = new ReplaceDialog(this);
    searchDialog = new SearchDialog(this);
    connect(searchDialog, SIGNAL(search()), this, SLOT(searchNextSlot()));
    connect(replaceDialog, SIGNAL(search()), this, SLOT(searchForReplaceSlot()));
    connect(replaceDialog, SIGNAL(replace()), this, SLOT(replaceTextSlot()));
    connect(replaceDialog, SIGNAL(replaceAll()), this, SLOT(replaceAllSlot()));
}

void Document::openFile(){
    QString str = QFileDialog::getOpenFileName(nullptr, "Open File","", "*.txt" );
    if(!str.isEmpty()){
        QFile file(str);
        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            setPlainText(stream.readAll());
            file.close();
            docTitle = str;
            emit changeWindowTitle(docTitle);
        }
    }
    return;
}

void Document::saveFile(){
    if(docTitle == "Unnamed"){
        saveFileAs();
        return;
    }
    QString str = QFileDialog::getSaveFileName(nullptr, "SaveFile","", tr("Text files(*.txt);;All files (*)")  );
    if(!str.isEmpty()){
        QFile file(docTitle);
        if(file.open(QIODevice::WriteOnly)){
            QTextStream stream(&file);
            stream <<  toPlainText();
            file.close();
            emit changeWindowTitle(docTitle);
        }

    }
}

void Document::createFile(){
    if(!document()->isEmpty()){
       int n = QMessageBox::warning(nullptr, "Warning", "The text in the file has been changed"
                                    "\n Do you want to save changes?",
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
       if(n == QMessageBox::Yes){
           saveFile();
           return;
       } else if(n == QMessageBox::No){
           clear();
           docTitle = "Unnamed";
       }
    }
}


void Document::deleteSlot(){
    textCursor().removeSelectedText();
}

void Document::saveFileAs(){
    QString str = QFileDialog::getSaveFileName(nullptr, docTitle,"", tr("Text files(*.txt);;All files (*)"));
    if(!str.isEmpty()){
        docTitle = str;
        saveFile();
    }
}

void Document::searchNextSlot(){

    QString searchText = searchDialog->getSearchText();
    bool toTop = searchDialog->isToTop();
    bool registerChecked = searchDialog->caseSensitivity();

    if(!find(searchText, QTextDocument::FindFlags(toTop & 0x00001) | QTextDocument::FindFlags(registerChecked & 0x00002))){
        return;
    }
    textCursor().select(QTextCursor::WordUnderCursor);

}

void Document::searchSlot(){
    searchDialog->show();
 }

void Document::replaceSlot(){
    replaceDialog->show();

}

#include <QDebug>

void Document::replaceAlSlot(){

   QString target = replaceDialog->getSearchText();
   QString replacement = replaceDialog->getReplaceText();
   moveCursor(QTextCursor::Start);
    while(find(target)){
       textCursor().insertText(replacement);
   }
   replaceDialog = nullptr;
}

void Document::searchForReplaceSlot(){

    QString searchText = replaceDialog->getSearchText();
    bool registerChecked = replaceDialog->caseSensitivity();

    if(!find(searchText, QTextDocument::FindFlags(registerChecked & 0x00002))){
        return;
    }
    textCursor().select(QTextCursor::WordUnderCursor);

}

void Document::replaceTextSlot(){
      QString replacement = replaceDialog->getReplaceText();
      textCursor().removeSelectedText();
      textCursor().insertText(replacement);
}

void Document::forwardToSlot(){

}

void Document::selectFontSlot(){
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok) {
        QTextCharFormat format = currentCharFormat();
        format.setFont(font);
        setCurrentCharFormat(format);
    }
}

void Document::dateAndTimeSlot(){
    QString dateAndTimeString = QDateTime::currentDateTime().toString(Qt::SystemLocaleShortDate);
    textCursor().insertText(dateAndTimeString);
}




