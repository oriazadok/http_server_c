# HTTP Server C

## Description
This project is a simple HTTP server implemented in C. It demonstrates how to handle HTTP requests and serve static content such as HTML files. The server is capable of responding to basic HTTP GET requests.

## Features
- Simple HTTP server implemented in C
- Serves static HTML files
- Lightweight and easy to set up
- Ideal for learning the basics of HTTP server implementation

## Prerequisites
- **C Compiler (GCC or Clang)**: Ensure that you have a C compiler installed on your system.
- **Make**: This project uses a `Makefile` to compile the source code.

## Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/oriazadok/http_server_c.git
   ```

2. **Navigate to the project directory**:
   ```bash
   cd http_server_c
   ```

3. **Compile the server**:
   Run the following command to compile the server:
   ```bash
   make
   ```

## How to Run
1. **Start the server**:
   After compiling, start the server using the following command:
   ```bash
   ./server
   ```

2. **Access the server**:
   Open a web browser and go to `http://localhost:6789/HelloWorld.html` to view the content served by the server.

3. **Serve your own HTML files**:
   You can modify or add HTML files in the server directory to be served by the HTTP server. For example, the project includes a sample `HelloWorld.html` file.

## How to Stop
Press `CTRL + C` in the terminal where the server is running to stop the server.

## Files Included
- **server.c**: The source code for the HTTP server.
- **HelloWorld.html**: A sample HTML file served by the server.
- **Makefile**: Used to compile the server.

## License
This project is licensed under the MIT License.
