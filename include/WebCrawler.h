#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

#include <string>
#include <vector>
#include <unordered_set>

// Define class
class WebCrawler {
private:
    // Memorize url visited
    std::unordered_set<std::string> discoveredWebsites;

public:
    void Crawl(const std::string& startUrl);
    std::vector<std::string> GetLinksFromHtml(const std::string& rawHtml);
    // Define function to manage HTTP data
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
    // Define function for HTTP requests
    std::string ReadRawHtml(const std::string& url);
};

#endif
