#include "SendSender.h"


SendSender::SendSender (XMLConfig * x, SendBuffer * buf)
{
  port = atoi(x->SendPort.c_str() ); //reading port from config
  buffer = buf;
}

SendSender::~SendSender (void)
{
}

void SendSender::Start ()
{
  try {
 QTcpSocket *socket=new QTcpSocket();
 socket->connectToHost("127.0.0.1", 9000); // ��� ������ ���� � ���������?
	    QSharedPointer<Send> sendData;
 sendData = buffer->Dequeue();
		QByteArray block;
        QDataStream sendStream(&block, QIODevice::ReadWrite);
        sendStream << quint16(0) << sendData;
        sendStream.device()->seek(0);
        sendStream << (quint16)(block.size() - sizeof(quint16));
 socket->write(block,block.size());
  }
  catch (exception& e) {
    cout << "SendSender: Exception: " << e.what () << endl; //TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "SendSender: Exception: %s", e.what());
    #endif
  }

	
	
	
	// try {
 //   
	//boost::asio::io_service io_service;
	//tcp::endpoint endpoint (tcp::v4 (), port);
 //   tcp::acceptor acceptor (io_service, endpoint);

 //   tcp::iostream socketStream;

 //   cout << "SendSender: Waiting for connection.." << endl; //TODO: write in log
 //   #ifdef ENABLE_LOGGING
	//  RAW_LOG (INFO, "SendSender: Waiting for connection..");
 //   #endif
 //   acceptor.accept (*socketStream.rdbuf ()); // waiting from connection from any IP
 //   cout << "SendSender: Connected!" << endl; //TODO: write in log
	//  #ifdef ENABLE_LOGGING
 //   RAW_LOG (INFO, "SendSender: Connected!");
 //   #endif 
	//
	//  while (!socketStream.fail() ) {
	//	//boost::archive::xml_oarchive oa (socketStream); // We want to send objects in XML
	//    QSharedPointer<Send> sendData;
	//    sendData = buffer->Dequeue(); // Reading Send object from buffer
	//	QByteArray block;
 //       QDataStream sendStream(&block, QIODevice::ReadWrite);
 //
 //       sendStream << quint16(0) << sendData;
 //       sendStream.device()->seek(0);
 //       sendStream << (quint16)(block.size() - sizeof(quint16));
	//	socketStream.write(block,block.size());
	//	//oa << sendData; // Serializing and sending it
	//  } 
 // }
 // catch (exception& e) {
 //   cout << "SendSender: Exception: " << e.what () << endl; //TODO: write in log
 //   #ifdef ENABLE_LOGGING
	//  RAW_LOG (INFO, "SendSender: Exception: %s", e.what());
 //   #endif
 // }

}