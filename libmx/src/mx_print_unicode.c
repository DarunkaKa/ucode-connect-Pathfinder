#include "../inc/libmx.h" 

void mx_print_unicode(wchar_t c) {
    unsigned char mult_char;
    int count = 0;
    int tm = 0;
    if (c >= 0x00 && c < 0x80) {
        mult_char = ((c >> 0) & 0x7F) | 0x00;
        count = 1;
    }
    if (c >= 0x80 && c < 0x800) {
        mult_char = ((c >> 6) & 0x1F) | 0xC0;
        tm = 6;
        count = 2;
    }
    if (c >= 0x800 && c < 0x10000) {
        mult_char = ((c >> 12) & 0x0F) | 0xE0;
        tm = 12;
        count = 3;
    }
    if (c >= 0x10000 && c < 0x110000) {
        mult_char = ((c >> 18) & 0x07) | 0xF0;
        tm = 18;
        count = 4;
    }
    unsigned char new_arr[count];
    new_arr[0] = mult_char;
    int i = 1;
    while (i < count) {
        new_arr[i] = ((c >> (tm - i * 6)) & 0x3F) | 0x80;
        i++;
    }
    write(1, new_arr, count);
}


