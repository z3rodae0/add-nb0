#include <stdio.h>
#include <stddef.h> 
#include <stdint.h>
#include <netinet/in.h>

uint32_t my_ntol(uint32_t a){
        uint32_t a1 = (a & 0xff000000) >> 24;
        uint32_t a2 = (a & 0x00ff0000) >> 8;
        uint32_t a3 = (a & 0x0000ff00) << 8;
        uint32_t a4 = (a & 0x000000ff) << 24;

        return a1 | a2 | a3 | a4;
}
uint32_t my_ntohs(uint32_t a){
	uint32_t a1 = (a & 0x000000ff) << 24;
        uint32_t a2 = (a & 0x0000ff00) << 8;
        uint32_t a3 = (a & 0x00ff0000) >> 8;
        uint32_t a4 = (a & 0xff000000) >> 24;

        return a1 | a2 | a3 | a4;
}

int main(int argc, char *argv[]){
	FILE * f1 = fopen(argv[argc-2], "rb");
	FILE * f2 = fopen(argv[argc-1], "rb");
	uint8_t buf1[4];
	uint8_t buf2[4];
	uint32_t *ptr1;
	uint32_t *ptr2;

	fread(buf1, sizeof(uint8_t), 4, f1);
	fread(buf2, sizeof(uint8_t), 4, f2);
	
	ptr1 = reinterpret_cast<uint32_t*>(buf1);
	ptr2 = reinterpret_cast<uint32_t*>(buf2);

	*ptr1 = ntohl(*ptr1);
	*ptr2 = ntohl(*ptr2);
	printf("%d(%p) + %d(%p) = %d(%p)",*ptr1,*ptr1,*ptr2,*ptr2,(*ptr1+(*ptr2)),(*ptr1+(*ptr2)));
	return 0;
}

	

