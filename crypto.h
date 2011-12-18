#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QTime>
#include <QGlobal.h>

#include <cstddef>

#define SEPARATOR "@@@"
#define USRMARK "<USR_INFO>"

#define HOST 0
#define GUEST 1

#define NAME 0
#define KEY 1
#define INSTITUTE 2
#define EMAIL 3
#define MAGIC 4

#define MAGIC_MARK "\\"

class Crypto
{
public:
  static const int CryptoHost = HOST;
  static const int CryptoGuest = GUEST;

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

  QString getUsrMagic() {return usrMagic;}
  QString getGuestMagic() {return guestMagic;}

  QString read(const QString &_filename);

protected:
  bool write(const QString &_content, const QString &_filename);
  QString crypt(const QString &_info, const int _magic);
  QString encrypt(const QString &_info, const int _magic);

  QString genMagic(const QString &_key);

private:
  QString usrname, guestName;
  QString key, guestKey;
  QString institute, guestInstitute;
  QString email, guestEmail;
  QString usrInfo, guestInfo;
  QString usrMagic, guestMagic;
};

#endif
