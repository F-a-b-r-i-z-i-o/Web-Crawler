# WebCrawler

## Introduction 📘
This project is a simple yet powerful web crawler written in C++. It navigates the web using a breadth-first search (BFS) algorithm to discover and visit URLs. Starting from a given URL, it fetches the page's HTML content, extracts all the links within, and continues this process for each new link found. It's an excellent tool for data mining, SEO analysis, and exploring the vastness of the web.

## What is a Web Crawler? 🕷️
A web crawler, also known as a web spider or web robot, is a program that browses the World Wide Web in a methodical, automated manner. It's used to index the content of websites all over the internet, allowing search engines to gather information, check links, and update their web content databases.

## Features 🌟
- **BFS Algorithm**: Efficiently discovers web pages without revisiting the same page.
- **HTTP Requests**: Powered by `libcurl` for making network requests.
- **Link Extraction**: Utilizes regular expressions to parse URLs from HTML content.

## Dependencies 📦
- **C++ Compiler**: GCC or Clang with support for C++11. It's crucial to have a compiler that supports C++11 standards, as the project utilizes features introduced in this version of the language.
- **libcurl**: A library for transferring data with URLs. It's essential for handling HTTP requests.

## Installing Dependencies 🔧
Before building the project, you need to ensure that `libcurl` is installed on your system and that you have a C++ compiler that supports the C++11 standard. Here's how you can install these dependencies on various platforms:

- **Ubuntu/Debian**:
  ```sh
  sudo apt-get install libcurl4-openssl-dev g++
  ```
- **macOS** (using Homebrew):
  ```sh
  brew install curl
  brew install gcc
  ```
- **Windows**: Check the official [curl website](https://curl.haxx.se/download.html) for Windows installation instructions and download MinGW or another compiler suite that supports C++11.

## Building the Project 🛠️
Use the provided Makefile for an easy build process. Here are the commands you can use:

- **Compile the project**:
  ```sh
  make
  ```
  This will generate an executable in the `build` directory.

- **Run the web crawler**:
  After compiling, you can start the crawler with:
  ```sh
  ./build/output 
  ```

## Testing 🧪
To compile and run the tests, ensuring everything is working as expected:

```sh
make test
```

This compiles the test suite and executes it, displaying the test results.

## Cleaning Up 🧹
To remove compiled files and clean up your project directory:

```sh
make clean
```

## Changing Output Directory 📁
To change the output directory of the compiled project or tests, you can modify the Makefile. Look for lines setting the output path and adjust them as needed.
