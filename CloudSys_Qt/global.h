#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>



class Global
{
public:
    Global();
    static QString DECODING_KEY;
    static QString USER_NAME;
    static const QString SERVER_IP;
    static const int FTP_SERVER_UPLOAD_PORT = 23335;
    static const int FTP_SERVER_DOWNLOAD_PORT = 23334;
    static const int SERVICE_COMMON_PORT = 23333;
};

#endif // GLOBAL_H
