#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <strings.h>

#define SIZE 128

int main(void)
{
	int sockFD = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockFD) {
		perror("socket失败了。");
		exit(1);
	}
	struct sockaddr_in serverAddr;
	serverAddr.sin_addr.s_addr = inet_addr("110.110.110.2");
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8600);

	socklen_t len = sizeof(struct sockaddr_in);
	if (bind(sockFD, (const struct sockaddr*)(&serverAddr), len)) {
		perror("bind失败！");
		exit(1);
	}

	fprintf(stderr, "服务端的bind执行成功，服务器正运行在：[%s : %d]上\n", "110.110.110.2", 8600);


	char data[SIZE] = "\0";
	struct sockaddr_in peerAddr;
	while (1) {
		bzero(&peerAddr, sizeof(0));
		if (recvfrom(sockFD, data, SIZE, 0, (struct sockaddr*)(&peerAddr), &len) > 0) {
			char peerAddrHost[20] = "\0";
			inet_ntop(AF_INET, (const void*)&(peerAddr.sin_addr), peerAddrHost, sizeof(peerAddr));
			printf("%s：[%d]的数据到达：%s\n", peerAddrHost, ntohs(peerAddr.sin_port), data);
			sleep(rand() % 3 + 1);

			//编号：
			int num = 0;
			sscanf(data, "this is #%d", &num);
			printf("消息编号：%d\n", num);

			//回复确认
			char recvmess[32] = "\0";
			sprintf(recvmess, "OK#%d", num);
			if (sendto(sockFD, recvmess, strlen(recvmess), 0, (struct sockaddr*)(&peerAddr), len) > 0) {
				printf("编号[%d] 已回复", num);
			}

			continue;
		}
		sleep(rand() % 3 + 1);
	}

	return 0;
}