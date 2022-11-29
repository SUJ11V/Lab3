#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;	
	ssize_t nread;
	char buf[1024];

	/* 파일 "data"를 읽기 위해 개방한다 */
	fd = open("data", O_RDONLY);
	
	/* 데이터를 읽어들인다 */
	nread = read(fd, buf, 1024);
	
	/* 파일을 폐쇄한다 */
	close(fd);
}
