#include "ui.h"

Ui::Ui(QWidget *parent) : QWidget(parent)
{
  crypto = new Crypto();
  layout = new QVBoxLayout();
  tab = new QTabWidget();
  usrWidget = new QWidget();
  guestWidget = new QWidget();

  usr_usrname_label = new QLabel(tr("Username"));
  usr_usrname_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  usr_key_label = new QLabel(tr("Safe-key"));
  usr_key_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  usr_institute_label = new QLabel(tr("Institute"));
  usr_institute_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  usr_email_label = new QLabel(tr("E-mail"));
  usr_email_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  guest_usrname_label = new QLabel(tr("Guest name"));
  guest_usrname_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  guest_key_label = new QLabel(tr("Safe-key"));
  guest_key_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  guest_institute_label = new QLabel(tr("Institute"));
  guest_institute_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  guest_email_label = new QLabel(tr("E-mail"));

  usr_usrname = new QLineEdit();
  usr_key = new QLineEdit();
  usr_institute = new QLineEdit();
  usr_email = new QLineEdit();

  guest_usrname = new QLineEdit();
  guest_usrname->setReadOnly(true);
  guest_usrname->setText(crypto->getGuestName());
  guest_key = new QLineEdit();
  guest_key->setReadOnly(true);
  guest_key->setText(crypto->getGuestKey());
  guest_institute = new QLineEdit();
  guest_institute->setReadOnly(true);
  guest_institute->setText(crypto->getGuestInstitute());
  guest_email = new QLineEdit();
  guest_email->setReadOnly(true);
  guest_email->setText(crypto->getGuestEmail());

  /*
  usrProfileButton = new QPushButton(tr("Load User Profile"), this);
  usrFileButton = new QPushButton(tr("Crypto File"), this);
  usrSaveButton = new QPushButton(tr("Save"), this);
  guestProfileButton = new QPushButton(tr("Load Guest Profile"), this);
  guestFileButton = new QPushButton(tr("Encrypto File"), this);

  connect(usrProfileButton, SIGNAL(clicked()), this, SLOT(loadUserProfile()));
  connect(usrFileButton, SIGNAL(clicked()), this, SLOT(startCrypto()));
  connect(usrSaveButton, SIGNAL(clicked()), this, SLOT(saveProfile()));
  connect(guestProfileButton, SIGNAL(clicked()), this, SLOT(loadGuestProfile()));
  connect(guestFileButton, SIGNAL(clicked()), this, SLOT(startEncrypto()));
  */

  usrLayout = new QGridLayout(this);
  guestLayout = new QGridLayout(this);

  usrLayout->addWidget(usr_usrname_label, 0, 0, 1, 1);
  usrLayout->addWidget(usr_usrname, 0, 1, 1, 3);
  usrLayout->addWidget(usr_key_label, 1, 0, 1, 1);
  usrLayout->addWidget(usr_key, 1, 1, 1, 3);
  usrLayout->addWidget(usr_institute_label, 2, 0, 1, 1);
  usrLayout->addWidget(usr_institute, 2, 1, 1, 3);
  usrLayout->addWidget(usr_email_label, 3, 0, 1, 1);
  usrLayout->addWidget(usr_email, 3, 1, 1, 3);

  /*
  usrLayout->addWidget(usrSaveButton, 4, 0, 2, 1);
  usrLayout->addWidget(usrProfileButton, 4, 1, 2, 1);
  usrLayout->addWidget(usrFileButton, 4, 2, 2, 2);
  */

  guestLayout->addWidget(guest_usrname_label, 0, 0, 1, 1);
  guestLayout->addWidget(guest_usrname, 0, 1, 1, 3);
  guestLayout->addWidget(guest_key_label, 1, 0, 1, 1);
  guestLayout->addWidget(guest_key, 1, 1, 1, 3);
  guestLayout->addWidget(guest_institute_label, 2, 0, 1, 1);
  guestLayout->addWidget(guest_institute, 2, 1, 1, 3);
  guestLayout->addWidget(guest_email_label, 3, 0, 1, 1);
  guestLayout->addWidget(guest_email, 3, 1, 1, 3);

  /*
  guestLayout->addWidget(guestProfileButton, 4, 0, 2, 2);
  guestLayout->addWidget(guestFileButton, 4, 2, 2, 2);
  */

  usrWidget->setLayout(usrLayout);
  guestWidget->setLayout(guestLayout);

  tab->addTab(usrWidget, tr("Host"));
  tab->addTab(guestWidget, tr("Guest"));

  layout->addWidget(tab);

  setLayout(layout);
}

Ui::~Ui()
{
}

void Ui::loadUserProfile()
{
  QString filename = "";
  QFileDialog *dialog = new QFileDialog(this);
  filename = dialog->getOpenFileName(this, tr("Open..."), "", tr("iCrypto profile (*.pro)"));
  if(filename.length() != 0) {
    crypto->encrptoUser(filename, 0);
    usr_usrname->setText(crypto->getUsrname());
    usr_key->setText(crypto->getKey());
    usr_institute->setText(crypto->getInstitute());
    usr_email->setText(crypto->getEmail());
  }
}

void Ui::saveProfile()
{
  QString filename = "";
  QFileDialog *dialog = new QFileDialog(this);
  filename = dialog->getSaveFileName(this, tr("Save..."), "", tr("iCrypto profile (*.pro)"));
  if(filename.length() != 0) {
    if(crypto->cryptoUser(usr_usrname->text(), usr_key->text(), usr_institute->text(),
                          usr_email->text(), filename)) {
      QMessageBox::information(0, tr("iCrypto"), tr("User profile created."));
    }
    else {
      QMessageBox::critical(0, tr("iCrypto"), tr("Cannot create user profile."));
    }
  }
}

void Ui::startCrypto()
{
  QString from = "";
  QFileDialog *dialog = new QFileDialog(this);
  from = dialog->getOpenFileName(this, tr("Open..."), "", tr("Text file (*.txt)"));
  if(from.length() != 0) {
    QString to = "";
    QFileDialog *dialog = new QFileDialog(this);
    to = dialog->getSaveFileName(this, tr("Save as..."), "", tr("iCrypto file (*.icr)"));
    if(to.length() != 0) {
      crypto->cryptoInfo(from, to);
    }
  }
}

void Ui::loadGuestProfile()
{
  QString filename = "";
  QFileDialog *dialog = new QFileDialog(this);
  filename = dialog->getOpenFileName(this, tr("Open..."), "", tr("iCrypto profile (*.pro)"));
  if(filename.length() != 0) {
    crypto->encrptoUser(filename, 1);
    guest_usrname->setText(crypto->getGuestName());
    guest_key->setText(crypto->getGuestKey());
    guest_institute->setText(crypto->getGuestInstitute());
    guest_email->setText(crypto->getGuestEmail());
  }
}

void Ui::startEncrypto()
{
  QString from = "";
  QFileDialog *dialog = new QFileDialog(this);
  from = dialog->getOpenFileName(this, tr("Open..."), "", tr("iCrypto file (*.icr)"));
  if(from.length() != 0) {
    QString to = "";
    QFileDialog *dialog = new QFileDialog(this);
    to = dialog->getSaveFileName(this, tr("Save as..."), "", tr("Text file (*.txt)"));
    if(to.length() != 0) {
      crypto->encryptoInfo(from, to);
    }
  }
}
