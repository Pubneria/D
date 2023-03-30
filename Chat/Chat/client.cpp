#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include <WS2tcpip.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#define MAX_SIZE 1024
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::thread;
const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "user"; // �����ͺ��̽� �����
const string password = "1234"; // �����ͺ��̽� ���� ��й�ȣ
SOCKET client_sock;
string my_nick; //���̵� <-�ܼ��Է°�
int pass;//�н����� <- �ܼ��Է°�
int pass_1;//�н�����Ȯ��
string my_nick2; //���̵� <-DB��
int pass2;//�н�����<-DB��
int flag=0; //�α��μ����÷���. 1�̸鼺��
int flag2 = 0;//ȸ�������÷���
int set=2; //���� 0�̸� ȸ������, 1�̸� �α���
int chat_recv() {
	char buf[MAX_SIZE] = {};
	string msg;
	while (1) {
		ZeroMemory(&buf, MAX_SIZE);
		if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
			msg = buf;
			string user;
			std::stringstream ss(msg);
			ss >> user;
			if (user != my_nick) cout << buf << endl;
		}
		else {
			cout << "Server Off!" << endl;
			return -1;
		}
	}
}
int main() {
	
	sql::Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;
	// MySQL Connector/C++ �ʱ�ȭ
	//sql::
	try //Ŀ���� �����۾�
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	// please create database "chatuser_db" ahead of time
	con->setSchema("chatuser_db");
	// connector���� �ѱ� ����� ���� ����
	stmt = con->createStatement(); // �߰�!!
	stmt->execute("set names euckr"); // �߰�!!
	if (stmt) { delete stmt; stmt = nullptr; } // �߰�!!

	//-------------------------------------


	WSADATA wsa;
	int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (!code) {
		while (set>1) {
			cout << " ȸ�������Ͻ÷��� 0����, �α����Ͻ÷��� 1���� �����ּ���>>";
			cin >> set;
			if (set > 1)
			{   
				cout << " �߸����Է��Դϴ�.�ٽ��Է��ϼ���>>";
				cout << endl;
			}
			else
			{
				break;
			}
		}
		if (set == 0) 
		{
			while (1) {
				cout << " ����� �г��� �Է� >>";
				cin >> my_nick;
				cout << " ����� ��й�ȣ �Է� >>";
				cin >> pass;
				cout << " ��й�ȣ Ȯ�� >>";
				cin >> pass_1;
				if (pass != pass_1)
				{cout << "��й�ȣ�� �߸��Է��ϼ̽��ϴ�. ó������ �ٽ� �Է��Ͽ� �ֽʽÿ�\n";}
				else {


					//���̵�/��� DB���� �˻��ؼ� �ִ��� Ȯ��
					pstmt = con->prepareStatement("SELECT name, password FROM chatuser;");
					result = pstmt->executeQuery();
					while (result->next())
					{
						my_nick2 = result->getString(1).c_str();
						pass2 = result->getInt(2);
						if ((my_nick == my_nick2))
						{
							flag2 = 1;
						}
					}
					if (flag2 == 1)
					{
						printf("�ߺ��ȴг����� �����մϴ�\n");
						flag2 = 0;
					}
					else
					{
						printf("ȸ�������̿Ϸ�Ǿ����ϴ�\n");
						pstmt = con->prepareStatement("INSERT INTO chatuser(name, password) VALUES(?,?)");
						pstmt->setString(1, my_nick);
						pstmt->setInt(2, pass);
						pstmt->execute();

						pstmt = con->prepareStatement("SELECT name, chat FROM chat;");
						result = pstmt->executeQuery();
						while (result->next())
						{
						printf("Reading from table=(%s, %s)\n", result->getString(1).c_str(), result->getString(2).c_str());

						}
						break;
					}
				}
			}

		}
		else if (set == 1) 
		{

			while (flag == 0) {

				cout << " ����� �г��� �Է� >>";
				cin >> my_nick;
				cout << " ����� ��й�ȣ �Է� >>";
				cin >> pass;
				//���̵�/��� DB���� �˻��ؼ� �ִ��� Ȯ��
				pstmt = con->prepareStatement("SELECT name, password FROM chatuser;");
				result = pstmt->executeQuery();

				while (result->next())
				{
					//printf("Reading from table=(%s, %d)\n", result->getString(1).c_str(), result->getInt(2));
					my_nick2 = result->getString(1).c_str();
					pass2 = result->getInt(2);
					if ((my_nick == my_nick2) && (pass == pass2))
					{
						flag = 1;
					}
				}
				if (flag == 1)
				{
					printf("�α��μ���\n");
					pstmt = con->prepareStatement("SELECT name, chat FROM chat;");
					result = pstmt->executeQuery();
					while (result->next())
					{
						printf("Reading from table=(%s, %s)\n", result->getString(1).c_str(), result->getString(2).c_str());

					}

				}
				else
				{
					printf("�α��ν���. �ٽ��Է��Ͻʽÿ�\n");
				}
			}
		}
		else{ }
		client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		SOCKADDR_IN client_addr = {};
		client_addr.sin_family = AF_INET;
		client_addr.sin_port = htons(7777);
		InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);
		while (1) {
			if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) {
				cout << "Server Connect" << endl;
				send(client_sock, my_nick.c_str(), my_nick.length(), 0);
				break;
			}
			cout << "connecting..." << endl;
		}
		std::thread th2(chat_recv);
		int count = 0;
		while (1) {
			string text;
			if (count == 0) {
				std::getline(cin, text);
				const char* buffer = text.c_str();

			}
			else {
				std::getline(cin, text);
				const char* buffer2 = text.c_str();
				send(client_sock, buffer2, strlen(buffer2), 0);
				pstmt = con->prepareStatement("INSERT INTO chat(name, chat) VALUES(?,?)");
				pstmt->setString(1, my_nick);
				pstmt->setString(2, text);
				pstmt->execute();
			}
			count++;
		}
		th2.join();
		closesocket(client_sock);


		delete pstmt;
		delete con;
	}
	WSACleanup();
	return 0;
}