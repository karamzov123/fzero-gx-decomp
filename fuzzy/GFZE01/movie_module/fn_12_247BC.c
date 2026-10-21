/* Non-matching: best partial attempt (99.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* SFHDS_SetHdr, from the CC0 MK Deception decomp (sfd_hds.c) */

typedef struct SfdHandle SfdHandle;
typedef struct SFHHandle SFHHandle;

extern SFHHandle *fn_12_3310C(const unsigned char *data, int size);
extern int fn_12_32EAC(SFHHandle *decoder, int *is_sfd_header);
extern void fn_12_330E0(SFHHandle *decoder);
extern int fn_12_24670(SfdHandle *handle, const unsigned char *data, int size);

int fn_12_247BC(SfdHandle* handle, int stream_index,
                 const unsigned char* data, int size, int* header_flag)
{
    SFHHandle* decoder;
    unsigned int start_byte_1;
    unsigned int start_byte_0;
    unsigned char prefix_byte_0;
    unsigned char prefix_byte_1;
    int is_sfd_header;
    int header_valid;
    const unsigned char* header;
    int header_size;
    unsigned int start_code;

    *header_flag = 0;
    if (stream_index != 2) {
        return 0;
    }
    header = data - 6;
    start_byte_0 = data[-6];
    start_byte_1 = header[1];
    header_size = size + 6;
    start_code = start_byte_0;
    start_code = (start_code << 8) | start_byte_1;
    start_code <<= 8;
    start_code |= header[2];
    start_code <<= 8;
    start_code |= header[3];
    if ((int)start_code != 0x1BF) {
        prefix_byte_0 = header[-2];
        header -= 2;
        prefix_byte_1 = header[1];
        header_size += 2;
        start_code = prefix_byte_0;
        start_code = (start_code << 8) | prefix_byte_1;
        start_code <<= 8;
        start_code |= start_byte_0;
        start_code <<= 8;
        start_code |= start_byte_1;
        if ((int)start_code != 0x1BF) {
            return 0;
        }
    }
    decoder = fn_12_3310C(header - 12, header_size + 12);
    if (decoder == 0) {
        header_valid = 0;
    } else {
        if (fn_12_32EAC(decoder, &is_sfd_header) == 0) {
            is_sfd_header = 0;
        }
        fn_12_330E0(decoder);
        header_valid = is_sfd_header;
    }
    if (header_valid == 0) {
        return 0;
    }
    *header_flag = fn_12_24670(handle, header - 12, header_size + 12);
    return 1;
}

