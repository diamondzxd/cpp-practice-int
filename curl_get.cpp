#include <iostream>
#include <curl/curl.h>
#include <string>

using namespace std;

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data)
{
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.co.in/");
        // curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        // curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

        std::string response_string;
        std::string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        char *url;
        // long response_code;
        // double elapsed;
        curl_easy_perform(curl);
        // curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        // curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

        // cout << response_string << endl;
        // cout << header_string << endl;

        // cout << response_code << endl;
        // cout << elapsed << endl;
        cout << url << endl;

        curl_easy_cleanup(curl);
        curl = NULL;
    }
}