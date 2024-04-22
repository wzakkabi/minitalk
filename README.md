# Minitalk

## Description
Minitalk is a simple client-server communication program developed as part of the 42 curriculum. The project aims to create a basic communication system between a client and a server using UNIX signals. Minitalk allows the client to send a string message to the server, which then receives and displays the message.

<img width="1676" alt="Screen Shot 2024-04-22 at 8 22 55 PM" src="https://github.com/wzakkabi/minitalk/assets/114888333/d3bcbb83-1f91-459b-a63c-a9abd12de60e">

## Features
- Implements a client-server communication system using UNIX signals.
- Supports the transmission of string messages from the client to the server.
- Handles message encoding and decoding to ensure reliable communication.
- Provides error handling and validation of incoming messages.

## Getting Started
To use Minitalk, follow these steps:

1. Clone the repository to your local machine:
```shell
git clone https://github.com/wzakkabi/minitalk.git
```

2. Compile the source files for both the client and server:

```shell
make
```

3. Run the server:
```shell
./server
```

4. Run the client with the server's PID as an argument:
```shell
./client [server_pid] [Enter a message]
```

5. Enter a message in the client terminal, which will be transmitted to the server.

## Usage
To use Minitalk:
- Start the server.
- Run the client with the server's PID as an argument.
- Enter a message in the client terminal.


## Credits
The Minitalk project was developed by [walid zakkabi](https://github.com/wzakkabi)

## Contact
For questions, suggestions, or issues, contact [wzakkabi@gmail.com].

