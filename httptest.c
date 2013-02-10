#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct request_header {
    char *accept;
    char *accept_charset;
    char *accept_encoding;
    char *accept_language;
    char *accept_ranges;
    char *age;
    char *allow;
    char *authorization;
    char *cache_control;
    char *connection;
    char *content_encoding;
    char *content_language;
    char *content_length;
    char *content_location;
    char *content_md5;
    char *content_range;
    char *content_type;
    char *date;
    char *etag;
    char *expect;
    char *expires;
    char *from;
    char *host;
    char *if_match;
    char *if_modified_since;
    char *if_none_match;
    char *if_range;
    char *if_unmodified_since;
    char *last_modified;
    char *location;
    char *max_forwards;
    char *pragma;
    char *proxy_authenticate;
    char *proxy_authorization;
    char *range;
    char *referer;
    char *retry_after;
    char *server;
    char *te;
    char *trailer;
    char *transfer_encoding;
    char *upgrade;
    char *user_agent;
    char *vary;
    char *via;
    char *warning;
    char *www_authenticate;

    char *path;
    char *method;
    char *port;
};


char *
create_request(struct request_header r)
{
    char * req;
    req = (char *)(malloc(sizeof(char) * 1024));
    if (!r.method || !r.host || !r.path) 
    {
        return NULL;
    }
    strcpy(req, r.method);
    strcat(req, " ");
    if (!r.path)
    {
        strcat(req, "/");
    }
    else
    {
        strcat(req, r.path);
    }
    strcat(req, " HTTP/1.1\n");

    if (r.accept) 
    {
        strcat(req, "Accept: ");
        strcat(req, r.accept);
        strcat(req, "\n");
    }

    if (r.accept_charset) 
    {
        strcat(req, "Accept-Charset: ");
        strcat(req, r.accept_charset);
        strcat(req, "\n");
    }

    if (r.accept_encoding) 
    {
        strcat(req, "Accept-Encoding: ");
        strcat(req, r.accept_encoding);
        strcat(req, "\n");
    }

    if (r.accept_language) 
    {
        strcat(req, "Accept-Language: ");
        strcat(req, r.accept_language);
        strcat(req, "\n");
    }

    if (r.accept_ranges)
    {
        strcat(req, "Accept_Ranges: ");
        strcat(req, r.accept_ranges);
        strcat(req, "\n");
    }

    if (r.age)
    {
        strcat(req, "Age: ");
        strcat(req, r.age);
        strcat(req, "\n");
    }

    if (r.allow)
    {
        strcat(req, "Allow: ");
        strcat(req, r.allow);
        strcat(req, "\n");
    }

    if (r.authorization)
    {
        strcat(req, "Authorization: ");
        strcat(req, r.authorization);
        strcat(req, "\n");
    }

    if (r.cache_control)
    {
        strcat(req, "Cache-Control: ");
        strcat(req, r.cache_control);
        strcat(req, "\n");
    }

    if (r.connection)
    {
        strcat(req, "Connection: ");
        strcat(req, r.connection);
        strcat(req, "\n");
    }

    if (r.content_encoding)
    {
        strcat(req, "Content-Encoding: ");
        strcat(req, r.connection);
        strcat(req, "\n");
    }

    if (r.content_language)
    {
        strcat(req, "Content-Language: ");
        strcat(req, r.content_language);
        strcat(req, "\n");
    }

    if (r.content_length)
    {
        strcat(req, "Content-Length: ");
        strcat(req, r.content_length);
        strcat(req, "\n");
    }

    if (r.content_location)
    {
        strcat(req, "Content-Location: ");
        strcat(req, r.content_location);
        strcat(req, "\n");
    }

    if (r.content_md5)
    {
        strcat(req, "Content-MD5: ");
        strcat(req, r.content_md5);
        strcat(req, "\n");
    }

    if (r.content_range)
    {
        strcat(req, "Content-Range: ");
        strcat(req, r.content_range);
        strcat(req, "\n");
    }

    if (r.content_type)
    {
        strcat(req, "Content-Type: ");
        strcat(req, r.content_type);
        strcat(req, "\n");
    }

    if (r.date)
    {
        strcat(req, "Date: ");
        strcat(req, r.date);
        strcat(req, "\n");
    }

    if (r.etag)
    {
        strcat(req, "Etag: ");
        strcat(req, r.etag);
        strcat(req, "\n");
    }

    if (r.expect)
    {
        strcat(req, "Expect: ");
        strcat(req, r.expect);
        strcat(req, "\n");
    }

    if (r.expires)
    {
        strcat(req, "Expires: ");
        strcat(req, r.expires);
        strcat(req, "\n");
    }

    if (r.from)
    {
        strcat(req, "From: ");
        strcat(req, r.from);
        strcat(req, "\n");
    }

    if (r.host) 
    {
        // 色々制約あるけど、それはまたあとで
        strcat(req, "Host: ");
        strcat(req, r.host);
        strcat(req, "\n");
    }

    if (r.if_match)
    {
        strcat(req, "If-Match: ");
        strcat(req, r.if_match);
        strcat(req, "\n");
    }

    if (r.if_modified_since)
    {
        strcat(req, "If-Modified-Since: ");
        strcat(req, r.if_modified_since);
        strcat(req, "\n");
    }

    if (r.if_none_match)
    {
        strcat(req, "If-None-Match: ");
        strcat(req, r.if_none_match);
        strcat(req, "\n");
    }

    if (r.if_range)
    {
        strcat(req, "If-Range: ");
        strcat(req, r.if_range);
        strcat(req, "\n");
    }

    if (r.if_unmodified_since)
    {
        strcat(req, "If-Unmodified-Since: ");
        strcat(req, r.if_unmodified_since);
        strcat(req, "\n");
    }

    if (r.last_modified)
    {
        strcat(req, "Last-Modified: ");
        strcat(req, r.last_modified);
        strcat(req, "\n");
    }

    if (r.location)
    {
        strcat(req, "Location: ");
        strcat(req, r.location);
        strcat(req, "\n");
    }

    if (r.max_forwards)
    {
        strcat(req, "Max-Forwards: ");
        strcat(req, r.max_forwards);
        strcat(req, "\n");
    }

    if (r.pragma)
    {
        strcat(req, "Pragma: ");
        strcat(req, r.pragma);
        strcat(req, "\n");
    }

    if (r.proxy_authenticate)
    {
        strcat(req, "Proxy-Authenticate: ");
        strcat(req, r.proxy_authenticate);
        strcat(req, "\n");
    }

    if (r.proxy_authorization)
    {
        strcat(req, "Proxy-Authorization: ");
        strcat(req, r.proxy_authorization);
        strcat(req, "\n");
    }

    if (r.range)
    {
        strcat(req, "Range: ");
        strcat(req, r.range);
        strcat(req, "\n");
    }

    if (r.referer)
    {
        strcat(req, "Referer: ");
        strcat(req, r.referer);
        strcat(req, "\n");
    }

    if (r.retry_after)
    {
        strcat(req, "Retry-After: ");
        strcat(req, r.retry_after);
        strcat(req, "\n");
    }

    if (r.server)
    {
        strcat(req, "Server: ");
        strcat(req, r.server);
        strcat(req, "\n");
    }

    if (r.te)
    {
        strcat(req, "TE: ");
        strcat(req, r.te);
        strcat(req, "\n");
    }
    
    if (r.trailer)
    {
        strcat(req, "Trailer: ");
        strcat(req, r.trailer);
        strcat(req, "\n");
    }

    if (r.transfer_encoding)
    {
        strcat(req, "Transfer-Encoding: ");
        strcat(req, r.transfer_encoding);
        strcat(req, "\n");
    }

    if (r.upgrade)
    {
        strcat(req, "Upgrade: ");
        strcat(req, r.upgrade);
        strcat(req, "\n");
    }

    if (r.user_agent)
    {
        strcat(req, "User-Agent: ");
        strcat(req, r.user_agent);
        strcat(req, "\n");
    }

    if (r.vary)
    {
        strcat(req, "Vary: ");
        strcat(req, r.vary);
        strcat(req, "\n");
    }

    if (r.via)
    {
        strcat(req, "Via: ");
        strcat(req, r.via);
        strcat(req, "\n");
    }

    if (r.warning)
    {
        strcat(req, "Warning: ");
        strcat(req, r.warning);
        strcat(req, "\n");
    }

    if (r.www_authenticate)
    {
        strcat(req, "WWW-Authenticate: ");
        strcat(req, r.www_authenticate);
        strcat(req, "\n");
    }

    strcat(req, "\n\0");
    return req;
}

int
httptest(struct request_header r, int debug)
{
    struct sockaddr_in server;
    int sock;
    char buf[1024];
    char *req;
    int n;
    int size = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    inet_pton(AF_INET, r.host, &server.sin_addr.s_addr);
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    memset(buf, 0, sizeof(buf));
    req = create_request(r);
    if (debug)
    {
        printf("###################[Request]##################\n");
        printf("%s\n", req);
        printf("##############################################\n");
    }

    size = strlen(req);
    write(sock, req, size);
    n = read(sock, buf, sizeof(buf));
    if (debug)
    {
        printf("###################[Response]#################\n");
    }

    printf("%s", buf);

    if (debug)
    {
        printf("##############################################\n");
    }

    close(sock);

    return 0;
}
