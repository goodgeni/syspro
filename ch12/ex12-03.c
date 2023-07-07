#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int sockfd;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n", sockfd);

	close(sockfd);

}
