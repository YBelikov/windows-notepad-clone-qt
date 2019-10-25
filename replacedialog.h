#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QObject>
#include <QDialog>


class QLabel;
class QLineEdit;
class QCheckBox;
class QGridLayout;

class ReplaceDialog : public QDialog
{
    Q_OBJECT
private:

    QLabel *whatLabel;
    QLabel *replacementLabel;
    QLineEdit *whatLine;
    QLineEdit *replacementLine;
    QPushButton *searchNextButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QPushButton *cancelButton;
    QCheckBox *withRegisterRecognition;
    QGridLayout *replaceDialogLayout;

public:

    ReplaceDialog(QWidget *wgt = nullptr);
    QString getSearchText() const;
    QString getReplaceText() const;
    bool caseSensitivity() const;
    
signals:
    void search();
    void replace();
    void replaceAll();

private slots:
    void enableSearchButton(const QString&);
    void enableReplaceButtons(const QString&);
};

#endif // REPLACEDIALOG_H
