output: build/main.o build/webcrawler.o
	g++ build/main.o build/webcrawler.o -o build/output -lcurl

build/main.o: src/main.cpp
	mkdir -p build
	g++ -std=c++11 -Iinclude -c src/main.cpp -o build/main.o

build/webcrawler.o: src/webCrawler.cpp
	mkdir -p build
	g++ -std=c++11 -Iinclude -c src/webCrawler.cpp -o build/webcrawler.o

test: test/test_WebCrawler.o build/webcrawler.o
	mkdir -p test
	g++ test/test_WebCrawler.o build/webcrawler.o -o test/test_WebCrawler -lcurl
	./test/test_WebCrawler

test/test_WebCrawler.o: test/test_WebCrawler.cpp
	mkdir -p test
	g++ -std=c++11 -Iinclude -c test/test_WebCrawler.cpp -o test/test_WebCrawler.o

clean:
	rm -f build/*.o build/output test/test_WebCrawler test/test_WebCrawler.o
