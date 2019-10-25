#include "replacedialog.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

ReplaceDialog::ReplaceDialog(QWidget *wgt) : QDialog(wgt)
{
        whatLabel = new QLabel(tr("What:"));
        replacementLabel = new QLabel(tr("For:"));
        whatLine = new QLineEdit;
        replacementLine = new QLineEdit;
        searchNextButton = new QPushButton(tr("Search Next"));
        replaceAllButton = new QPushButton(tr("Replace All"));
        replaceButton = new QPushButton(tr("Replace"));
        cancelButton = new QPushButton(tr("Cancel"));
        withRegisterRecognition = new QCheckBox(tr("Case sensitivity"));

        replaceDialogLayout = new QGridLayout;

        searchNextButton->setEnabled(false);
        replaceAllButton->setEnabled(false);
        replaceButton->setEnabled(false);

        replaceDialogLayout->addWidget(whatLabel, 0, 0);
        replaceDialogLayout->addWidget(whatLine, 0, 1);
        replaceDialogLayout->addWidget(searchNextButton, 0, 2);
        replaceDialogLayout->addWidget(replacementLabel, 1, 0);
        replaceDialogLayout->addWidget(replacementLine, 1, 1);
        replaceDialogLayout->addWidget(replaceButton, 1, 2);
        replaceDialogLayout->addWidget(replaceAllButton, 2, 2);

        replaceDialogLayout->addWidget(withRegisterRecognition, 3, 0);
        replaceDialogLayout->addWidget(cancelButton, 3, 2);
        setLayout(replaceDialogLayout);
        connect(whatLine, SIGNAL(textChanged(const QString&)), this, SLOT(enableSearchButton(const QString&)));
        connect(replacementLine, SIGNAL(textChanged(const QString&)), this, SLOT(enableReplaceButtons(const QString&)));
        connect(searchNextButton, SIGNAL(clicked()), SIGNAL(search()));
        connect(replaceButton, SIGNAL(clicked()), SIGNAL(replace()));
        connect(replaceAllButton, SIGNAL(clicked()), SIGNAL(replaceAll()));
}

void ReplaceDialog::enableSearchButton(const QString& text){
    if(!text.isEmpty()){
        searchNextButton->setEnabled(true);
    }
}

void ReplaceDialog::enableReplaceButtons(const QString& text){
    if(!text.isEmpty()){
        replaceButton->setEnabled(true);
        replaceAllButton->setEnabled(true);
    }
}

QString ReplaceDialog::getSearchText() const{
    return whatLine->text();
}

QString ReplaceDialog::getReplaceText() const{
    return replacementLine->text();
} 

bool ReplaceDialog::caseSensitivity() const{
    return withRegisterRecognition->isChecked();
}
