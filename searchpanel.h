#ifndef SEARCHPANEL_H
#define SEARCHPANEL_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QCheckBox>

class SearchPanel : QWidget
{
   Q_OBJECT
private:

    QLabel *searchLabel;
    QLabel *replaceLabel;

    QLineEdit *searchForLine;
    QLineEdit *replaceLine;

    QPushButton *searchPrevious;
    QPushButton *continueSearching;
    QPushButton *replace;
    QPushButton *replaceAndContinueSearching;
    QPushButton *replaceAll;

    QCheckBox *caseSensitive;
    QCheckBox *words;
    QCheckBox *useRegExp;

    QGroupBox *checkBoxGroup;

    QHBoxLayout *checkGroupLayout;
    QGridLayout *searchLayout;

public:
    SearchPanel(QWidget *wgt = nullptr);
    void showPanel();
private slots:
    void setButtonsEnabled(const QString&);
};

#endif // SEARCHPANEL_H
