#ifndef _UI_H
#define _UI_H

#include "crypto.h"
#include "result_dialog.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTabWidget>
#include <QMessageBox>
#include <QGridLayout>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QFileDialog>

class Ui : public QWidget
{
Q_OBJECT

public:
  Ui(QWidget *parent = 0);
  ~Ui();
  void gotoTab(const int _index);

public slots:
  void loadUserProfile();
  void saveProfile();
  void startCrypto();
  void loadGuestProfile();
  void startEncrypto();

private:
  Crypto *crypto;

  QVBoxLayout *layout;
  QTabWidget *tab;
  QWidget *usrWidget, *guestWidget;
  QLabel *usr_usrname_label, *usr_key_label, *usr_institute_label, *usr_email_label;
  QLabel *guest_usrname_label, *guest_key_label, *guest_institute_label, *guest_email_label;
  QLineEdit *usr_usrname, *usr_key, *usr_institute, *usr_email;
  QLineEdit *guest_usrname, *guest_key, *guest_institute, *guest_email;

  QGridLayout *usrLayout, *guestLayout;
};

#endif
