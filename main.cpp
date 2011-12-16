#include "window.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setWindowIcon(QIcon("key.icns"));
  Window window;
  window.show();
  return app.exec();
}

