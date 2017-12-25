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

int get_file_size(const char* filename) {
	struct  stat finfo;
	int size = stat(filename, &finfo);
	return finfo.st_size;
}

void parseChunk(int fd, off64_t* offset, off64_t end, int depth) {
	ssize_t readed = 0;
	uint32_t hdr[2];
	char chunk[5];
	uint64_t chunk_size;
	int32_t chunk_type;
	off64_t data_offset;
	off64_t chunk_data_size;

	while ((readed = readAt(fd, *offset, hdr, 8)) != 0 && *offset < end) {

    	chunk_size = ntohl(hdr[0]);
    	chunk_type = ntohl(hdr[1]);

    	MakeFourCCString(chunk_type, chunk);

    	cout << "at offset " << *offset << " end " << end << endl;
    	cout << "readed " << readed << endl;
    	/* size is stored by byte*/
    	cout << "chunk size " << chunk_size  << "(bytes)"<< endl;
    	cout << "chunk type " << chunk << endl;
    	data_offset = *offset + 8;
    	chunk_data_size = chunk_size - 8;
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
	            *offset = data_offset;
	            cout << "go to " << depth + 1 << " stop at " << stop_offset << endl;
	            parseChunk(fd, offset, stop_offset, depth + 1);
	            cout << "returned to depth " << depth << endl;

	            if (*offset != stop_offset) {
	                cout << "ERROR offset "<< *offset <<" not match " << stop_offset << endl;
	            } else {
	            	cout << "returned success " << *offset <<endl;
	            }
	            break;

	        }
	        case FOURCC('f', 't', 'y', 'p'):
	        {
	        	off64_t stop_offset = *offset + chunk_size;
	        	*offset = data_offset;

	        	/*major_brand*/
	        	uint32_t brand;
	        	char dinfo[5];
	        	readAt(fd, *offset, &brand, 4);
	        	brand = ntohl(brand);
	        	MakeFourCCString(brand, dinfo);
	        	cout << "major_brand " << dinfo << endl;

	        	/*minor_version*/
	        	*offset += 4;
	        	readAt(fd, *offset, &brand, 4);
	        	brand = ntohl(brand);
	        	cout << "minor_version "  << brand << endl;

	        	/*compatible_brands*/
	        	*offset += 4;
	        	while (*offset < stop_offset) {
	        		readAt(fd, *offset, &brand, 4);
	        		brand = ntohl(brand);
	        		MakeFourCCString(brand, dinfo);
	        		cout << "compatible_brands " << dinfo << endl;
	        		*offset += 4;
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

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "please just input filename" << endl;
		return 0;
	}
	auto filename = argv[1];
	auto filesize = get_file_size(filename);
	cout << "the file's size " << filesize << endl;
	int fd = open(filename, O_RDONLY);
	off64_t beginoffset = 0;
	off64_t totaloffset = filesize;
	parseChunk(fd, &beginoffset, filesize, 0);
	return 0;
}