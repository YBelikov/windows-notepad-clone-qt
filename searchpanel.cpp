#include "searchpanel.h"

SearchPanel::SearchPanel(QWidget *wgt) : QWidget(wgt)
{
    searchLabel = new QLabel(tr("Search"));
    replaceLabel = new QLabel(tr("Replace"));
    searchForLine = new QLineEdit;
    replaceLine = new QLineEdit;

    searchPrevious = new QPushButton(tr("&Search previous"));
    continueSearching = new QPushButton(tr("&Continue searching"));
    replace = new QPushButton(tr("&Replace"));
    replaceAndContinueSearching = new QPushButton(tr("&Replace and continue searching"));
    replaceAll = new QPushButton("Replace all");

    caseSensitive = new QCheckBox(tr("Case sensitive"));
    words = new QCheckBox(tr("Whole words"));
    useRegExp = new QCheckBox(tr("Use regular expresion"));

    checkBoxGroup = new QGroupBox;
    searchLayout = new QGridLayout;
    checkGroupLayout = new QHBoxLayout;

    searchPrevious->setEnabled(false);
    continueSearching->setEnabled(false);
    replace->setEnabled(false);
    replaceAndContinueSearching->setEnabled(false);
    replaceAll->setEnabled(false);

    checkGroupLayout->addWidget(caseSensitive);
    checkGroupLayout->addWidget(words);
    checkGroupLayout->addWidget(useRegExp);
    searchForLine->setMinimumWidth(550);
    replaceLine->setMinimumWidth(550);

    searchLayout->addWidget(searchLabel, 0, 0);
    searchLayout->addWidget(searchForLine, 0 , 1);
    searchLayout->addWidget(searchPrevious, 0, 2);
    searchLayout->addWidget(continueSearching, 0, 3);

    searchLayout->addWidget(replaceLabel, 1, 0);
    searchLayout->addWidget(replaceLine, 1, 1);
    searchLayout->addWidget(replace, 1, 2);
    searchLayout->addWidget(replaceAndContinueSearching, 1, 3);
    searchLayout->addWidget(replaceAll, 1, 4);
    searchLayout->addLayout(checkGroupLayout, 2, 0, 1, 3);

    connect(searchForLine, SIGNAL(textChanged(const QString&)), this, SLOT(setButtonsEnabled(const QString&)));
    setFixedWidth(1000);
    setFixedHeight(100);
    setLayout(searchLayout);
}

void SearchPanel::showPanel(){
    show();
}

void SearchPanel::setButtonsEnabled(const QString& text){
    searchPrevious->setEnabled(!text.isEmpty());
    continueSearching->setEnabled(!text.isEmpty());
    replace->setEnabled(!text.isEmpty());
    replaceAndContinueSearching->setEnabled(!text.isEmpty());
    replaceAll->setEnabled(!text.isEmpty());
}
