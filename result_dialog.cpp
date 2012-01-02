#include "result_dialog.h"

ResultDialog::ResultDialog(const QString &_content, 
                           QWidget *parent) : QDialog(parent)
{
  widget = new ResultWidget(_content);
  layout = new QVBoxLayout();
  layout->addWidget(widget);
  setLayout(layout);

  setWindowTitle(tr("iCrypto Preview"));
  setMinimumSize(560, 400);
}

ResultDialog::~ResultDialog()
{
}


