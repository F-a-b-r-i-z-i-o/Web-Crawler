#include "WebCrawler.h"
#include <queue>
#include <regex>
#include <iostream>
#include <curl/curl.h>
using namespace std;

/**
 * Bfs implementation for discover url.
 *
 * @param string of url.
 * @return None.
 */
void WebCrawler::Crawl(const string& startUrl)
{
    queue<string> queue;
    queue.push(startUrl);
    discoveredWebsites.insert(startUrl);

    while (!queue.empty()) {
        string actualUrl = queue.front();
        queue.pop();
        cout << "Visiting: " << actualUrl << endl;

        string actualUrlHtml = ReadRawHtml(actualUrl);
        vector<string> urls = GetLinksFromHtml(actualUrlHtml);

        for (const auto& url : urls) {
            if (discoveredWebsites.find(url) == discoveredWebsites.end()) {
                discoveredWebsites.insert(url);
                queue.push(url);
            }
        }
    }
}

/**
 * Use regex for match links.
 *
 * @param string raw of html document .
 * @return vector of string.
 */
vector<string> WebCrawler::GetLinksFromHtml(const string& rawHtml)
{
    vector<string> links;
    regex urlRegex(R"(https?://(?:[-\w.]|(?:%\da-fA-F]{2}))+)");
    smatch urlMatch;

    auto searchStart = rawHtml.cbegin();
    while (regex_search(searchStart, rawHtml.cend(), urlMatch, urlRegex)) {
        links.push_back(urlMatch[0]);
        searchStart = urlMatch.suffix().first;
    }

    return links;
}

/**
 * Callback function for writing received data from an HTTP request into a std::string.
 *
 * @param contents Pointer to the data received by libcurl.
 * @param size Size of each data element received.
 * @param nmemb Number of data elements received.
 * @param userp Pointer to a user-provided std::string where the received data will be appended.
 * @return The total number of bytes processed by this callback function.
 */
size_t WebCrawler::WriteCallback(void* contents, size_t size, size_t nmemb, string* userp)
{
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/**
 * HTTP request with libcurl
 *
 * @param string url
 * @return string with HTTP data
 */
string WebCrawler::ReadRawHtml(const string& url)
{
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}
