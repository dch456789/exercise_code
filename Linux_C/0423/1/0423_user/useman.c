#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define SIZE 128

int main(void)
{
	int sockFD = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockFD) {
		perror("socket失败了。");
		exit(1);
	}
	struct sockaddr_in userAddr;
	userAddr.sin_addr.s_addr = inet_addr("110.110.110.2");
	userAddr.sin_family = AF_INET;
	userAddr.sin_port = htons(8601);

	socklen_t len = sizeof(struct sockaddr_in);
	if (bind(sockFD, (const struct sockaddr*)(&userAddr), len)) {
		perror("bind失败！");
		exit(1);
	}

	fprintf(stderr, "[客户端]\tbind执行成功，服务器正运行在：[%s : %d]上\n", "110.110.110.2", 8600);

	//数据收发
	char message[SIZE] = "\0";
	int index = rand() % 1000 + 1000;
	while (1) {
		struct sockaddr_in targetAddr;
		targetAddr.sin_family = AF_INET;
		targetAddr.sin_port = htons(8600);
		targetAddr.sin_addr.s_addr = inet_addr("110.110.110.2");
		bzero(message, SIZE);
		sprintf(message, "this is #%d", index++);

		if (sendto(sockFD, message, strlen(message), 0, (const struct sockaddr*)(&targetAddr), sizeof(targetAddr)) > 0); {
			printf("向%s : [%d] 发送消息：%s\n", "110.110.110.2", 8600, message);
		}
		sleep(rand()%3 + 2);
	}

	return 0;
}