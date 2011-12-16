#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>

#include <cstddef>

#define SEPARATOR "@@@"
#define USRMARK "<USR_INFO>"
#define MAGIC 6

#define HOST 0
#define QUEST 1

#define NAME 0
#define KEY 1
#define INSTITUTE 2
#define EMAIL 3

class Crypto
{
public:
  Crypto();
  ~Crypto();

  bool cryptoUser(const QString &_usrname, const QString &_key, const QString &_institute, const QString &_email, const QString &_filename);
  void encrptoUser(const QString &_filename, const int _Role);
  bool cryptoInfo(const QString &_content,
                     const QString &_filename);
  bool encryptoInfo(const QString &_content, const QString &_filename);

  QString getUsrname() {return usrname;}
  QString getKey() {return key;}
  QString getInstitute() {return institute;}
  QString getEmail() {return email;}

  QString getGuestName() {return guestName;}
  QString getGuestKey() {return guestKey;}
  QString getGuestInstitute() {return guestInstitute;}
  QString getGuestEmail() {return guestEmail;}

protected:
  QString read(const QString &_filename);
  bool write(const QString &_content, const QString &_filename);
  QString crypt(const QString &_info);
  QString encrypt(const QString &_info);

private:
  QString usrname, guestName;
  QString key, guestKey;
  QString institute, guestInstitute;
  QString email, guestEmail;
  QString usrInfo, guestInfo;
};

#endif
