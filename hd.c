#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 16
void hd( FILE *fp );
void pr(int address, unsigned char buffer[], int cnt);

int main(int argc, char *argv[])
{
    int ret = 0;

    if ( argc < 2 )
    {
        hd(stdin);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *fp = fopen( argv[i], "rb");
            if ( NULL == fp )
            {
                fprintf( stderr, "Can't open %s\n", argv[i]);
                ++ret;
            }
            else
            {
                hd(fp);
                fclose(fp);
            }
        }
    }
    return ret;
}

void hd( FILE *fp )
{
    int ch;
    int cnt = 0;
    unsigned char buffer[BUFSIZE];
    int address = 0;

    while ( EOF != ( ch = fgetc(fp) ) )
    {
        buffer[cnt] = ch;
        ++cnt;

        if ( BUFSIZE == cnt)
        {
            pr(address, buffer, cnt);
            address += cnt;
            cnt = 0;
        }
    }
    if ( cnt > 0)
    {
        pr( address, buffer, cnt);
    }
    
}

void pr( int address, unsigned char buffer[], int cnt)
{
    printf("%08x ", address);

    for (int i = 0; i < cnt; ++i)
    {
        printf(" %02x", buffer[i]);
    }

    for (int i = cnt; i < BUFSIZE; ++i)
    {
        printf("   ");
    }

    printf(" |");

    for (int i = 0; i < cnt; ++i)
    {
        putchar(isgraph(buffer[i]) ? buffer[i] : '.');
    }
    printf("|\n");
}