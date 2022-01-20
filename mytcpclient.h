#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>

class MyTcpClient : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpClient(int argc, char* argv[], QObject *parent = nullptr);

public slots:
    void connected();
    void readyRead();

private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
};

