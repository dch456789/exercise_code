#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 128

void* readData(void*);

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

	//启动线程读取数据
	pthread_t tid;
	pthread_create(&tid, NULL, readData, &sockFD);
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
		sleep(rand() % 3 + 2);
	}

	return 0;
}

void* readData(void* args)
{
	if (NULL == args) {
		return NULL;
	}
	printf("\t\t接收数据的线程启动！\n");
	int* fd = (int*)args;
	char data[SIZE] = "\0";
	struct sockaddr_in peerAddr;
	socklen_t len = sizeof(struct sockaddr_in);
	while (1) {
		if (recvfrom(*fd, data, SIZE, 0, (struct sockaddr*)(&peerAddr), &len) > 0) {
			char peerAddrHost[20] = "\0";
			inet_ntop(AF_INET, (const void*)&(peerAddr.sin_addr), peerAddrHost, sizeof(peerAddr));
			//
			int num;
			sscanf(data, "OK#%d", &num);
			printf("\t\t%s：[%d]的数据到达：%d\n", peerAddrHost, ntohs(peerAddr.sin_port), num);
			sleep(rand() % 3 + 1);

			
			continue;
		}
		sleep(rand() % 3 + 1);
	}
}