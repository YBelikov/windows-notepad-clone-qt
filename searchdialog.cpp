#include "searchdialog.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>

SearchDialog::SearchDialog(QWidget *wgt) : QDialog(wgt)
{

    label = new QLabel(tr("&What:"));
    searchLine = new QLineEdit;
    searchDirection = new QGroupBox(tr("&Choose direction"));
    searchNextButton = new QPushButton(tr("&Search next"));
    cancelButton = new QPushButton(tr("&Cancel"));
    topDirectionButton = new QRadioButton(tr("&Up"));
    bottomDirectionButton = new QRadioButton(tr("Down"));
    withRegisterRecognition = new QCheckBox(tr("Check register"));
    searchDialogLayout = new QGridLayout;

    searchNextButton->setEnabled(false);
    bottomDirectionButton->setChecked(true);
    withRegisterRecognition->setChecked(false);

    QHBoxLayout *searchDirectionLayout = new QHBoxLayout;
    searchDirectionLayout->addWidget(topDirectionButton);
    searchDirectionLayout->addWidget(bottomDirectionButton);

    searchDirection->setLayout(searchDirectionLayout);

    label->setBuddy(searchLine);
    searchDialogLayout->addWidget(label, 0, 0, 1, 1);
    searchDialogLayout->addWidget(searchLine, 0, 1, 1, 2);
    searchDialogLayout->addWidget(searchNextButton, 0, 3);
    searchDialogLayout->addWidget(cancelButton, 1, 3, 1, 1);
    searchDialogLayout->addWidget(withRegisterRecognition, 1, 0, 1, 2);
    searchDialogLayout->addWidget(searchDirection, 1 , 2);
    //loadSettings();
    setLayout(searchDialogLayout);
    connect(searchLine, SIGNAL(textChanged(const QString&)), this, SLOT(enableSearchButtonSlot(const QString&)));
    connect(searchNextButton, SIGNAL(clicked()), SIGNAL(search()));

}

void SearchDialog::enableSearchButtonSlot(const QString& text){
    searchNextButton->setEnabled(!text.isEmpty());
}

QString SearchDialog::getSearchText(){
   return searchLine->text();
}

bool SearchDialog::caseSensitivity(){
    return withRegisterRecognition->isChecked();
}

bool SearchDialog::isToTop(){
    return topDirectionButton->isChecked();
}



