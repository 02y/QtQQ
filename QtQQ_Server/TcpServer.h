#pragma once

#include <QTcpServer>

class TcpServer : public QTcpServer
{
	Q_OBJECT

public:
	TcpServer(int port);
	~TcpServer();

public:
	bool run();   //监听端口有没有连接

protected:
	//客户端有新的连接时
	void incomingConnection(qintptr socketDescriptor);   //void incomingConnection(int socketDescriptor) 老版本写法

signals:
	void signalTcpMsgComes(QByteArray&);

private slots:
	//处理数据
	void SocketDataProcessing(QByteArray& SendData, int descriptor);
	//断开连接处理
	void SocketDisconnected(int descriptor);

private:
	int m_port;   //端口号
	QList<QTcpSocket*> m_tcpSocketConnectList;
};
