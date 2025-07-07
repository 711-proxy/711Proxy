
      
       
    #include "stdafx.h"
    #include "curl/curl.h"
    #pragma comment(lib, "libcurl.lib")
    static size_t write_buff_data(char *buffer, size_t size, size_t nitems, void *outstream)
    {
        memcpy(outstream, buffer, nitems * size);
        return nitems * size;
    }

    int GetUrlHTTP(char *url, char *buff)
    {
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl)
        {
            // user:pass http
            curl_easy_setopt(curl, CURLOPT_PROXY, "http://user:pass@ip:port");
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)buff);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_buff_data);
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 10L);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 50L);
            curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, 2000000L);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if (res == CURLE_OK)
            {
                return res;
            }
            else
            {
                printf("%d", res);
            }
        }
        return res;
    }

    int GetUrlSocks5(char *url, char *buff)
    {
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl)
        {
            // user:pass socks5
            curl_easy_setopt(curl, CURLOPT_PROXY, "socks5://user:pass@ip:port");
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)buff);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_buff_data);
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 10L);
            curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 50L);
            curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, 2000000L);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if (res == CURLE_OK)
            {
                return res;
            }
            else
            {
                printf("%d", res);
            }
        }
        return res;
    }

    int main()
    {
        char *buff = (char *)malloc(1024 * 1024);
        memset(buff, 0, 1024 * 1024);
        GetUrlHTTP("http://ipinfo.io/json", buff);
        printf("response: %s", buff);
        memset(buff, 0, 1024 * 1024);
        GetUrlSocks5("http://ipinfo.io/json", buff);
        printf("response: %s", buff);
        free(buff);
        Sleep(10 * 1000);
        return 0;
    }
          
    
