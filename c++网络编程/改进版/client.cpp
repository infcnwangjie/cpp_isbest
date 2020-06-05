#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
using namespace std;
int main(){
    //创建套接字
    int s_server = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    connect(s_server, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	char send_buf[]="i love china";


	int send_len = send(s_server, send_buf, 100, 0);

	const int BUFFERSIZE=100;
    //读取服务器传回的数据
    char buffer[BUFFERSIZE]={0};
    read(s_server, buffer, BUFFERSIZE);

    cout<<"Message form server:"<< buffer<<endl;

    //关闭套接字
    close(s_server);
    return 0;
}
