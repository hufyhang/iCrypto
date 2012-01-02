#ifndef _RESULT_DIALOG_H
#define _RESULT_DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include "result_widget.h"

class ResultDialog : public QDialog
{
Q_OBJECT

public:
  ResultDialog(const QString &_content, QWidget *parent = 0);
  ~ResultDialog();

private:
  ResultWidget *widget;
  QVBoxLayout *layout;
};

#endif

