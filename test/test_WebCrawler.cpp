#include "WebCrawler.h"
#include <iostream>
#include <cassert>

// No real call HTTP for test
void testGetLinksFromHtml() {
    WebCrawler crawler;
    std::string htmlContent = "<html><body>"
                              "<a href='https://www.example.com'>Example</a>"
                              "<a href='https://www.example2.com'>Example2</a>"
                              "</body></html>";
    auto links = crawler.GetLinksFromHtml(htmlContent);

    assert(links.size() == 2);
    assert(links[0] == "https://www.example.com");
    assert(links[1] == "https://www.example2.com");

    std::cout << "testGetLinksFromHtml passed." << std::endl;
}

int main() {
    testGetLinksFromHtml();
    return 0;
}
