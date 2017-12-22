#include <iostream>
#include <fcntl.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <sys/stat.h>

#define FOURCC(c1, c2, c3, c4) \
    ((c1) << 24 | (c2) << 16 | (c3) << 8 | (c4))

inline void MakeFourCCString(uint32_t x, char *s) {
    s[0] = x >> 24;
    s[1] = (x >> 16) & 0xff;
    s[2] = (x >> 8) & 0xff;
    s[3] = x & 0xff;
    s[4] = '\0';
}

using namespace std;

ssize_t readAt(int fd, off64_t offset, void* data, size_t size) {
	off64_t result = lseek64(fd, offset, SEEK_SET);
    if (result == -1) {
        cout << "ERROR readAt lseek fail" << endl;
        return 0;
    }

    return ::read(fd, data, size);
}

void parseChunk(int fd, off64_t* offset, int depth) {
	ssize_t readed = 0;
	uint32_t hdr[2];
	char chunk[5];
	uint64_t chunk_size;
	int32_t chunk_type;
	off64_t data_offset;

	while ((readed = readAt(fd, *offset, hdr, 8)) != 0) {

    	chunk_size = ntohl(hdr[0]);
    	chunk_type = ntohl(hdr[1]);

    	MakeFourCCString(chunk_type, chunk);

    	cout << "at offset " << *offset << " depth " << depth << endl;
    	cout << "readed " << readed << endl;
    	cout << "chunk size " << chunk_size << endl;
    	cout << "chunk type " << chunk << endl;
    	data_offset = *offset + 8;
    	switch(chunk_type) {
	        case FOURCC('m', 'o', 'o', 'v'):
	        case FOURCC('t', 'r', 'a', 'k'):
	        case FOURCC('m', 'd', 'i', 'a'):
	        case FOURCC('m', 'i', 'n', 'f'):
	        case FOURCC('d', 'i', 'n', 'f'):
	        case FOURCC('s', 't', 'b', 'l'):
	        case FOURCC('m', 'v', 'e', 'x'):
	        case FOURCC('m', 'o', 'o', 'f'):
	        case FOURCC('t', 'r', 'a', 'f'):
	        case FOURCC('m', 'f', 'r', 'a'):
	        case FOURCC('u', 'd', 't', 'a'):
	        case FOURCC('i', 'l', 's', 't'):
	        case FOURCC('s', 'i', 'n', 'f'):
	        case FOURCC('s', 'c', 'h', 'i'):
	        case FOURCC('e', 'd', 't', 's'):
	        case FOURCC('w', 'a', 'v', 'e'):
	        {
		        off64_t stop_offset = *offset + chunk_size;
		        cout << "go to next depth, should stop at " << stop_offset << endl;
	            *offset = data_offset;
	            while (*offset < stop_offset) {
	                parseChunk(fd, offset, depth + 1);
	                cout << "returned to depth " << depth << endl;
	            }

	            if (*offset != stop_offset) {
	                cout << "ERROR offset not match " << *offset << endl;
	            }
	            break;

	        }
	        default:
	        {
	        	*offset += chunk_size;
	        	break;
	        }
	    }
	}
}

int main() {
	int fd = open("test.mp4", O_RDONLY);
	off64_t totaloffset = 0;
	parseChunk(fd, &totaloffset, 0);
	return 0;
}