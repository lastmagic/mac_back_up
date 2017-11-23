#include <stdio.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
	int tcpSd;
	socklen_t optLen;
	int optVal;	
	
	tcpSd = socket(PF_INET, SOCK_STREAM, 0);
	
	//TCP_NODELAY
	optLen = sizeof(optVal);	
	getsockopt(tcpSd, IPPROTO_IP, IP_TOS, (void *)&optVal, &optLen);
	printf("IP TOS of tcpSd: %d\n", optVal);
	
	optVal = IPTOS_THROUGHPUT; 
	setsockopt(tcpSd, IPPROTO_IP, IP_TOS, (void *)&optVal, optLen);
	
	getsockopt(tcpSd, IPPROTO_IP, IP_TOS, (void *)&optVal, &optLen);
	printf("IP TOS of tcpSd: %d\n", optVal);



	close(tcpSd);
	return 0;
}

