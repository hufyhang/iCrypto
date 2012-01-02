#include "result_widget.h"

ResultWidget::ResultWidget(const QString &_content, 
                           QWidget *parent) : QWidget(parent)
{
  text = new QTextEdit(this);
  text->setLineWrapMode(QTextEdit::WidgetWidth);
  text->setText(_content);

  layout = new QVBoxLayout();
  layout->addWidget(text);

  setLayout(layout);
}

ResultWidget::~ResultWidget()
{
}

