#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "httptest.c"

struct request_header
analyze_arg(int argc, char *argv[])
{
    struct request_header r = {};
    int result;
    while ((result=getopt(argc, argv, "dh:p:m:")) != -1)
    {
        switch (result) {
            case 'd':
                break;
            case 'h':
                r.host = optarg;
                break;
            case 'p':
                r.port = optarg;
                break;
            case 'm':
                if (strcmp("GET", optarg) == 0)
                {
                    r.method = "GET";
                }
                else if (strcmp("POST", optarg) == 0)
                {
                    r.method = "POST";
                }
                else if (strcmp("OPTIONS", optarg) == 0)
                {
                    r.method = "OPTIONS";
                }
                else if (strcmp("HEAD", optarg) == 0)
                {
                    r.method = "HEAD";
                }
                else if (strcmp("PUT", optarg) == 0)
                {
                    r.method = "PUT";
                }
                else if (strcmp("DELETE", optarg) == 0)
                {
                    r.method = "DELETE";
                }
                else if (strcmp("TRACE", optarg) == 0)
                {
                    r.method = "TRACE";
                }
                else if (strcmp("CONNECT", optarg) == 0)
                {
                    r.method = "CONNECT";
                }
                else
                {
                    printf("no method\n");
                    exit(1);
                }
                break;
        }
    }
    if (!r.host)
    {
        printf("no host specified.\n");
        exit(2);
    }
    if (!r.path)
    {
        r.path = "/";
    }
    if (!r.method)
    {
        r.method = "GET";
    }
    return r;
}

int main(int argc, char *argv[])
{
    struct request_header r = analyze_arg(argc, argv);
    return httptest(r, 1);
}
