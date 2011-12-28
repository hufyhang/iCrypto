#include "crypto.h"

Crypto::Crypto()
{
  usrname = institute = email = "";
  guestName = guestKey = guestInstitute = guestEmail = "N/A";
  usrInfo = "";
  guestInfo = "";
  usrMagic = "";
  guestMagic = "";
}

Crypto::~Crypto()
{
}

QString Crypto::read(const QString &_filename)
{
  QString buffer = "";
  QFile file(_filename);
  if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    buffer = in.readAll();
  }
  file.close();
  return buffer;
}

bool Crypto::write(const QString &_content, const QString &_filename)
{
  bool result = false;
  QFile file(_filename);
  if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    out << _content;
    result = true;
  }
  file.close();
  return result;
}

QString Crypto::crypt(const QString &_info, const int _magic)
{
  QString buffer = _info;
  int len = buffer.length();

  for(int index = 0; index != len; ++index) {
    if(buffer[index] == '\n') {
      continue;
    }
    buffer[index] = QChar::fromAscii(buffer[index].toAscii() + _magic);
  }

  return buffer;
}

QString Crypto::encrypt(const QString &_info, const int _magic)
{
  QString buffer = _info;
  int len = buffer.length();

  for(int index = 0; index != len; ++index) {
    if(buffer[index] == '\n') {
      continue;
    }
    buffer[index] = QChar::fromAscii(buffer[index].toAscii() - _magic);
  }

  return buffer;
}

bool Crypto::cryptoInfo(const QString &_content, const QString &_filename)
{
  if(usrInfo.isEmpty()) {
    return false;
  }

  bool ok;
  QString code = crypt(read(_content), getUsrMagic().toInt(&ok));
  code = usrInfo + code;
  write(code, _filename);
  return true;
}

bool Crypto::encryptoInfo(const QString &_content, const QString &_filename)
{
  if(guestInfo.isEmpty()) {
    return false;
  }
  QString code = read(_content);
  code.remove(guestInfo, Qt::CaseSensitive);

  bool ok;
  QString con = encrypt(code, getGuestMagic().toInt(&ok));
  write(con, _filename);
  return true;
}

bool Crypto::cryptoUser(const QString &_usrname, const QString &_key, 
                        const QString &_institute, const QString &_email, 
                        const QString &_filename)
{
  QString buffer = USRMARK + _usrname + SEPARATOR + _key + SEPARATOR + _institute + SEPARATOR + _email + USRMARK;

  int institute_len = _institute.length();
  int key_len = _key.length();
  int mail_len = _email.length();
  int magic =  institute_len + mail_len - key_len;
  QString mag = QString::number(magic);

  if(write(mag + MAGIC_MARK + crypt(buffer, magic), _filename)) {
    encrptoUser(_filename, HOST);
    return true;
  }
  else {
    return false;
  }
}

void Crypto::encrptoUser(const QString &_filename, const int _Role)
{
  QString info = read(_filename);
  QString buffer = info;
  if(buffer.isEmpty()) {
    return;
  }
 
  QStringList temp = info.split(MAGIC_MARK);
  QString magic = temp.at(0);
  bool ok;
  int magic_code = magic.toInt(&ok);

  int index = magic.length() + 1;
  buffer.remove(0, index);

  QString code = encrypt(buffer, magic_code);

  code.remove(USRMARK, Qt::CaseSensitive);
  QStringList list = code.split(SEPARATOR, QString::KeepEmptyParts, Qt::CaseSensitive);
  QString name = list.at(NAME);
  QString ke = list.at(KEY);
  QString ins = list.at(INSTITUTE);
  QString mail = list.at(EMAIL);

  switch(_Role) {
  case HOST:
    usrname = name;
    key = ke;
    institute = ins;
    email = mail;
    usrInfo = info;
    usrMagic = magic;
    break;

  case GUEST:
    guestName = name;
    guestKey = ke;
    guestInstitute = ins;
    guestEmail = mail;
    guestInfo = info;
    guestMagic = magic;
    break;
  }
}

