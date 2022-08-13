#include <cstdio>
#include <bits/stdc++.h>
 
const int buf_size = 4096;
unsigned char buf[4096];
int buf_len = 0, buf_pos = 0;
 
inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}
 
inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}
 
inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}
 
inline int readInt() {
    int s = 1, c = readChar();
    int x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
 
/** Write */
 
int write_buf_pos = 0;
char write_buf[4096];
 
inline void writeChar( int x ) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}
 
inline void flush() {
    if (write_buf_pos)
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}
 
inline void writeInt( int x, char end) {
    int output_len = -1;
 
    if (x < 0)
        writeChar('-'), x = -x;
 
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
 
using namespace std;
 
int main() {
 
    int n, m, k;
    n = readInt(), m = readInt(), k = readInt();
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            matrix[i][j] = readInt();
        }
    }
    vector<int> row_map(n + 1), col_map(m + 1);
    iota(row_map.begin(), row_map.end(), 0);
    iota(col_map.begin(), col_map.end(), 0);
    char s;
    int x, y;
    while (k--) {
        s = readChar();
        x = readInt(), y = readInt();
        if (s == 'c') {
            swap(col_map[x], col_map[y]);
        } else if (s == 'r') {
            swap(row_map[x], row_map[y]);
        } else {
            writeInt(matrix[row_map[x]][col_map[y]], '\n');
        }
    }
    flush();
 
    return 0;
}