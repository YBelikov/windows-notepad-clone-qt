#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QSettings>

class QLineEdit;
class QGroupBox;
class QRadioButton;
class QLabel;
class QCheckBox;

class SearchDialog : public QDialog
{
    Q_OBJECT
private:

    QLabel *label;
    QLineEdit *searchLine;
    QPushButton *searchNextButton;
    QPushButton *cancelButton;
    QGroupBox *searchDirection;
    QRadioButton *topDirectionButton;
    QRadioButton *bottomDirectionButton;
    QCheckBox *withRegisterRecognition;
    QGridLayout *searchDialogLayout;

public:

    SearchDialog(QWidget *wgt = nullptr);

    QString getSearchText();
    bool caseSensitivity();
    bool isToTop();


private slots:

    void enableSearchButtonSlot(const QString&);
signals:
    void search();

};

#endif // SEARCHDIALOG_H
