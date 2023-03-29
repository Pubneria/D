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
//1. 소켓 초기화
// socket(), bind(), listen();
// 소켓을 생성하고, 주소를 묶어주고, 활성화 -> 대기상태
void server_init();
// 2. 클라이언트 추가 '
// accept() recv()
// 연결을 설정하고 클라이언트가 전송한 닉네임을 받음
void add_client();
//3. 클라이언트에게 msg 보내기
// send()
void send_msg(const char* msg);
// 4. 클라이언트에게 채팅 내용을 받음
// 퇴장했다면 퇴장했습니다 공지 띄워즘
void recv_msg(int idx);
//5. 소켓 닫아줌.
void del_client(int idx);
int main() {
	// MySQL Connector/C++ 초기화
	string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
	string username = "user"; // 데이터베이스 사용자
	string password = "1234"; // 데이터베이스 접속 비밀번호
	sql::Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;
	//sql::

	WSADATA wsa;
	int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	// winsock version 2.2 사용
	// winsock 초기화 하는 함수
	// 실행 성공하면 0 반환, 실패하면 0 이외의 값 반환


	try //커넥터 사전작업
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
	// connector에서 한글 출력을 위한 셋팅
	stmt = con->createStatement(); // 추가!!
	stmt->execute("set names euckr"); // 추가!!
	if (stmt) { delete stmt; stmt = nullptr; } // 추가!!
	// 데이터베이스 쿼리 실행
	//chatuser테이블 생성
	stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS chatuser");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE chatuser (id serial PRIMARY KEY, name VARCHAR(50), password INTEGER);");
	cout << "Finished creating table" << endl;
	//stmt = con->createStatement();
	//chathistory테이블 생성
	stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS chat");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE chat (id serial PRIMARY KEY, name VARCHAR(50), chat VARCHAR(50));");
	cout << "Finished creating table" << endl;
	delete stmt;

	pstmt = con->prepareStatement("INSERT INTO chatuser(name, password) VALUES(?,?)");
	pstmt->setString(1, "박지원");
	pstmt->setInt(2, 1087);
	pstmt->execute();
	cout << "One row inserted." << endl;
	pstmt->setString(1, "김정관");
	pstmt->setInt(2, 9876);
	pstmt->execute();
	cout << "One row inserted." << endl;
	
	

	//아이디/비번 DB에서 검색해서 있는지 확인
	pstmt = con->prepareStatement("SELECT name, password FROM chatuser;");
	result = pstmt->executeQuery();

	while (result->next())
	{
		printf("Reading from table=(%s, %d)\n", result->getString(1).c_str(), result->getInt(2));

	}
	
	// 통신시작

	//WSADATA wsa;
	//int code = WSAStartup(MAKEWORD(2, 2), &wsa);
	// winsock version 2.2 사용
	// winsock 초기화 하는 함수
	// 실행 성공하면 0 반환, 실패하면 0 이외의 값 반환
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
/*함수 구현부*/
//1. 소켓 초기화
void server_init() {
	server_sock.sck = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	/*
	socket(int AF, int 통신타입, int PROTOCOL)
	- 주소 체계 형식
	- 통신 타입 설정
	- 어떤 프로토콜 사용할건지
	*/
	SOCKADDR_IN server_addr = {};
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(7777);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//localhost = 127.0.0.1
	bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr));
	/*
	bind(SOCKET s, const sockaddr *name, int namelen);
	- socket() 으로 만들어준 소켓
	- 소켓과 연결할 주소 정보를 담고 있는 구조체
		(코드에서는 server_addr)
	- 두번째 매개변수의 크기
	*/
	listen(server_sock.sck, SOMAXCONN);
	/*listen(SOCKET s, int backlog)*/
	server_sock.user = "server";
	// 서버가 켜지면 나올 문구
	cout << "server On!" << endl;
}
//2. 클라이언트 연결 & 추가
void add_client() {
	SOCKADDR_IN addr = {};
	int addrsize = sizeof(addr);
	char buf[MAX_SIZE] = {};
	ZeroMemory(&addr, addrsize); // addr 0으로 초기화
	SOCKET_INFO new_client = {};
	new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
	/*
	accept(SOCKET s, sockaddr* addr, &addrsize);
	- socket() 으로 만들어준 소켓
	- client의 주소 정보를 저장할 구조체
	- 2번 매개변수의 크기
	*/
	recv(new_client.sck, buf, MAX_SIZE, 0);
	/*
	recv(SOCKET s, const char *buf, int len, int flags)
	- accept() 만들어준 소켓 (통신을 위한 소켓)
	- 데이터를 받을 변수
	- 두번째 매개변수의 길이
	- flag
	*/

	new_client.user = string(buf);
	// buf를 string으로 변환해서 담아줌
	string msg = "[공지]" + new_client.user + "님이 입장했습니다!";
	cout << msg << endl;
	sck_list.push_back(new_client);
	std::thread th(recv_msg, client_count);
	client_count++;
	cout << "[공지] 현재 접속자 수 : " << client_count << "명" << endl;
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
			// 만약 정상적으로 받았다면
			msg = sck_list[idx].user + ':' + buf;
			cout << msg << endl;
			send_msg(msg.c_str());
		}
		else {
			msg = "[공지]" + sck_list[idx].user + "님이 퇴장했습니다.";
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


