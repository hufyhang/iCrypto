#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
  container = new QWidget();
  ui = new Ui();
  topFiller = new QWidget();
  topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  bottomFiller = new QWidget();
  bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  layout = new QVBoxLayout();
  layout->addWidget(topFiller);
  layout->addWidget(ui);
  layout->addWidget(bottomFiller);

  container->setLayout(layout);
  setCentralWidget(container);

  createActions();
  createMenus();
  createToolbars();

  setUnifiedTitleAndToolBarOnMac(true);
  setMinimumSize(640, 300);
  setWindowTitle(tr("iCrypto"));

  statusBar()->showMessage(tr("iCrypto Ver. 1.0"));
}

Window::~Window()
{
}

void Window::createActions()
{
  saveUsrAct = new QAction(QIcon(":/img/save.png"), tr("&Save..."), this);
  saveUsrAct->setStatusTip(tr("Save & generate user profile document."));
  connect(saveUsrAct, SIGNAL(triggered()), ui, SLOT(saveProfile()));

  loadUsrAct = new QAction(QIcon(":/img/open.png"), tr("&Load host..."), this);
  loadUsrAct->setStatusTip(tr("Open & load existing user profile as hosts."));
  connect(loadUsrAct, SIGNAL(triggered()), ui, SLOT(loadUserProfile()));

  cryptAct = new QAction(QIcon(":/img/record.png"), tr("&Crypto..."), this);
  cryptAct->setStatusTip(tr("Crypto document."));
  connect(cryptAct, SIGNAL(triggered()), ui, SLOT(startCrypto()));

  loadGuestAct = new QAction(QIcon(":/img/open.png"), tr("&Load guest..."), this);
  loadGuestAct->setStatusTip(tr("Open & load existing user profile as guests."));
  connect(loadGuestAct, SIGNAL(triggered()), ui, SLOT(loadGuestProfile()));

  encryptAct = new QAction(QIcon(":/img/play.png"), tr("&Encrypto..."), this);
  encryptAct->setStatusTip(tr("Encrypto document."));
  connect(encryptAct, SIGNAL(triggered()), ui, SLOT(startEncrypto()));
}

void Window::createToolbars()
{
  fileToolbar = addToolBar(tr("File"));

  fileToolbar->addAction(loadUsrAct);
  fileToolbar->addAction(saveUsrAct);
  fileToolbar->addAction(cryptAct);
  fileToolbar->addSeparator();
  fileToolbar->addAction(loadGuestAct);
  fileToolbar->addAction(encryptAct);

  fileToolbar->setFloatable(false);
  fileToolbar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea | 
                               Qt::LeftToolBarArea | Qt::RightToolBarArea);
  addToolBar(Qt::TopToolBarArea, fileToolbar);
}

void Window::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));
  helpMenu = menuBar()->addMenu(tr("&Help"));

  usrSubMenu = fileMenu->addMenu(tr("Host"));
  usrSubMenu->addAction(loadUsrAct);
  usrSubMenu->addAction(saveUsrAct);
  usrSubMenu->addSeparator();
  usrSubMenu->addAction(cryptAct);

  guestSubMenu = fileMenu->addMenu(tr("Guest"));
  guestSubMenu->addAction(loadGuestAct);
  guestSubMenu->addSeparator();
  guestSubMenu->addAction(encryptAct);
}

