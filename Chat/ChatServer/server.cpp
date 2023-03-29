#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <WinSock2.h>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#define MAX_SIZE 1024
#define MAX_CLIENT 3
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::thread;
// for demonstration only. never save your password in the code!



struct SOCKET_INFO {
	SOCKET sck;
	string user;
};
std::vector<SOCKET_INFO> sck_list;
SOCKET_INFO server_sock;
int client_count = 0;
//1. ���� �ʱ�ȭ
// socket(), bind(), listen();
// ������ �����ϰ�, �ּҸ� �����ְ�, Ȱ��ȭ -> ������
void server_init();
// 2. Ŭ���̾�Ʈ �߰� '
// accept() recv()
// ������ �����ϰ� Ŭ���̾�Ʈ�� ������ �г����� ����
void add_client();
//3. Ŭ���̾�Ʈ���� msg ������
// send()
void send_msg(const char* msg);
// 4. Ŭ���̾�Ʈ���� ä�� ������ ����
// �����ߴٸ� �����߽��ϴ� ���� �����
void recv_msg(int idx);
//5. ���� �ݾ���.
void del_client(int idx);
int main() {
	// MySQL Connector/C++ �ʱ�ȭ
	string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
	string username = "user"; // �����ͺ��̽� �����
	string password = "1234"; // �����ͺ��̽� ���� ��й�ȣ
	sql::Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;
	//sql::

	WSADATA wsa;
	int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	// winsock version 2.2 ���
	// winsock �ʱ�ȭ �ϴ� �Լ�
	// ���� �����ϸ� 0 ��ȯ, �����ϸ� 0 �̿��� �� ��ȯ


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
	// �����ͺ��̽� ���� ����
	//chatuser���̺� ����
	stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS chatuser");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE chatuser (id serial PRIMARY KEY, name VARCHAR(50), password INTEGER);");
	cout << "Finished creating table" << endl;
	//stmt = con->createStatement();
	//chathistory���̺� ����
	stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS chat");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE chat (id serial PRIMARY KEY, name VARCHAR(50), chat VARCHAR(50));");
	cout << "Finished creating table" << endl;
	delete stmt;

	pstmt = con->prepareStatement("INSERT INTO chatuser(name, password) VALUES(?,?)");
	pstmt->setString(1, "������");
	pstmt->setInt(2, 1087);
	pstmt->execute();
	cout << "One row inserted." << endl;
	pstmt->setString(1, "������");
	pstmt->setInt(2, 9876);
	pstmt->execute();
	cout << "One row inserted." << endl;
	
	

	//���̵�/��� DB���� �˻��ؼ� �ִ��� Ȯ��
	pstmt = con->prepareStatement("SELECT name, password FROM chatuser;");
	result = pstmt->executeQuery();

	while (result->next())
	{
		printf("Reading from table=(%s, %d)\n", result->getString(1).c_str(), result->getInt(2));

	}
	
	// ��Ž���

	//WSADATA wsa;
	//int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	// winsock version 2.2 ���
	// winsock �ʱ�ȭ �ϴ� �Լ�
	// ���� �����ϸ� 0 ��ȯ, �����ϸ� 0 �̿��� �� ��ȯ
	if (!code) {
		
		server_init();

		std::thread th1[MAX_CLIENT];
		for (int i = 0; i < MAX_CLIENT; i++) {
			th1[i] = std::thread(add_client);
		}
		while (1) {
			string text, msg = "";
			std::getline(cin, text);
			const char* buf = text.c_str();
			msg = server_sock.user + ':' + buf;
			send_msg(msg.c_str());
		
			
		}
		for (int i = 0; MAX_CLIENT; i++) {
			th1[i].join();
		}
	
		closesocket(server_sock.sck);
		WSACleanup();
		return 0;
	}

	delete pstmt;
	delete con;
}
/*�Լ� ������*/
//1. ���� �ʱ�ȭ
void server_init() {
	server_sock.sck = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	/*
	socket(int AF, int ���Ÿ��, int PROTOCOL)
	- �ּ� ü�� ����
	- ��� Ÿ�� ����
	- � �������� ����Ұ���
	*/
	SOCKADDR_IN server_addr = {};
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(7777);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//localhost = 127.0.0.1
	bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr));
	/*
	bind(SOCKET s, const sockaddr *name, int namelen);
	- socket() ���� ������� ����
	- ���ϰ� ������ �ּ� ������ ��� �ִ� ����ü
		(�ڵ忡���� server_addr)
	- �ι�° �Ű������� ũ��
	*/
	listen(server_sock.sck, SOMAXCONN);
	/*listen(SOCKET s, int backlog)*/
	server_sock.user = "server";
	// ������ ������ ���� ����
	cout << "server On!" << endl;
}
//2. Ŭ���̾�Ʈ ���� & �߰�
void add_client() {
	SOCKADDR_IN addr = {};
	int addrsize = sizeof(addr);
	char buf[MAX_SIZE] = {};
	ZeroMemory(&addr, addrsize); // addr 0���� �ʱ�ȭ
	SOCKET_INFO new_client = {};
	new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
	/*
	accept(SOCKET s, sockaddr* addr, &addrsize);
	- socket() ���� ������� ����
	- client�� �ּ� ������ ������ ����ü
	- 2�� �Ű������� ũ��
	*/
	recv(new_client.sck, buf, MAX_SIZE, 0);
	/*
	recv(SOCKET s, const char *buf, int len, int flags)
	- accept() ������� ���� (����� ���� ����)
	- �����͸� ���� ����
	- �ι�° �Ű������� ����
	- flag
	*/

	new_client.user = string(buf);
	// buf�� string���� ��ȯ�ؼ� �����
	string msg = "[����]" + new_client.user + "���� �����߽��ϴ�!";
	cout << msg << endl;
	sck_list.push_back(new_client);
	std::thread th(recv_msg, client_count);
	client_count++;
	cout << "[����] ���� ������ �� : " << client_count << "��" << endl;
	send_msg(msg.c_str());
	th.join();
}
void send_msg(const char* msg) {
	for (int i = 0; i < client_count; i++) {
		send(sck_list[i].sck, msg, MAX_SIZE, 0);
	}
}
void recv_msg(int idx) {
	char buf[MAX_SIZE] = {};
	string msg = "";
	while (1) {
		ZeroMemory(&buf, MAX_SIZE);
		if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) {
			// ���� ���������� �޾Ҵٸ�
			msg = sck_list[idx].user + ':' + buf;
			cout << msg << endl;
			send_msg(msg.c_str());
		}
		else {
			msg = "[����]" + sck_list[idx].user + "���� �����߽��ϴ�.";
			cout << msg << endl;
			send_msg(msg.c_str());
			del_client(idx);
			return;
		}
	}
}
void del_client(int idx) {
	closesocket(sck_list[idx].sck);
	client_count--;
}


