#ifndef _WINDOW_H
#define _WINDOW_H

#include "ui.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QIcon>

class Window : public QMainWindow
{
Q_OBJECT

public:
  Window(QWidget *parent = 0);
  ~Window();

protected:
  void createActions();
  void createMenus();
  void createToolbars();

private:
  Ui *ui;
  QWidget *topFiller, *bottomFiller, *container;
  QVBoxLayout *layout;

  QMenu *fileMenu, *helpMenu;
  QMenu *usrSubMenu, *guestSubMenu;
  QAction *saveUsrAct, *loadUsrAct, *cryptAct;
  QAction *loadGuestAct, *encryptAct;
  QToolBar *fileToolbar;
};

#endif

