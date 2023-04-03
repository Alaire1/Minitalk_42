# Minitalk
Minitalk is a small client-server program for sending and receiving messages between two processes using the signals in UNIX systems.

## Usage
The program consists of two parts: the server and the client. The server listens for incoming messages, and the client sends messages to the server.

To run the server, simply execute the compiled program without any arguments:

```C
./server
```
This will start the server and display its process ID. The server will wait for incoming messages and display them on the console.

To send a message, run the client program with the server's process ID and the message to send as arguments:

```c
./client [SERVER_PID] [MESSAGE]
```
For example:

```C
./client 1234 "Hello, world!"
```
This will send the message "Hello, world!" to the server with process ID 1234.

## Implementation
The implementation of the program is divided into two parts: the client and the server.

### Server
The server listens for incoming signals from the client and translates them into a message. It then displays the message on the console.

#### Signal Translation
The signal translation function, ft_signal_translation, is called whenever the server receives a signal from the client. The function takes the signal as an argument and processes it to construct the message.

The function uses two static variables to keep track of the current bit and the accumulated byte. Whenever the function receives a signal, it checks if it is a SIGUSR1 or SIGUSR2 signal. If it is a SIGUSR1 signal, it sets the current bit to 1 by using a bitwise OR operation with the bit mask. If it is a SIGUSR2 signal, it sets the current bit to 0.

After setting the current bit, the function increments the bit counter. If the bit counter reaches the total number of bits in a byte, the function prints the accumulated byte to the console as a character, and resets the bit counter and the byte accumulator.

#### Main Function
The main function of the server initializes the signal handlers for SIGUSR1 and SIGUSR2 signals, and then enters an infinite loop that waits for incoming signals. The loop uses the pause() function to wait for signals, and then calls the signal translation function to process the signal.

### Client
The client sends messages to the server by sending a series of signals, one for each bit in the message.

#### Bit Sending
The bit sending function, ft_send_bits, takes the process ID of the server and a byte of the message as arguments. The function then sends a series of signals to the server, one for each bit in the byte.

The function first checks if the process ID is valid. If it is not, the function simply returns without sending any signals.

The function then initializes the signal handlers for SIGUSR1 and SIGUSR2 signals. If the signal handlers fail to initialize, the function returns without sending any signals.

The function then enters a loop that sends signals for each bit in the byte. The loop uses a bitwise AND operation with a bit mask to isolate each bit in the byte, and then sends a SIGUSR1 signal if the bit is 1, or a SIGUSR2 signal if the bit is 0.

After sending each signal, the function increments the bit counter and waits for a short period of time using the usleep() function to allow the server to process the signal.

#### Main Function
The main function of the client parses the command line arguments to obtain the server's process ID and the message to send. It then sends each byte of the message to the server
