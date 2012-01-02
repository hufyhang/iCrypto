#ifndef _RESULT_WIDGET_H
#define _RESULT_WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class ResultWidget : public QWidget
{
Q_OBJECT

public:
  ResultWidget(const QString &_content, QWidget *parent = 0);
  ~ResultWidget();

private:
  QTextEdit *text;
  QVBoxLayout *layout;
};

#endif

