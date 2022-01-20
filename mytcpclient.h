#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>

class MyTcpClient : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpClient(int argc, char* argv[], QObject *parent = nullptr);

public slots:
    void connected();   //müssen theoretisch nicht im Abschnitt "slots" sein
    void readyRead();

private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
};

