# Minitalk

Minitalk is a client-server communication program written in C for the 42
curriculum. The client sends a text message to the server using only the Unix
signals `SIGUSR1` and `SIGUSR2`.

Each character is transmitted bit by bit. The server reconstructs the message,
prints it to standard output, and acknowledges receipt through signals.

## Build

The build expects the project's `ft_printf` library in the `ft_printf/`
directory.

```sh
git clone <repository-url>
cd minitalk
make
```

This creates the `server` and `client` executables. The bonus targets can be
built with:

```sh
make bonus
```

## Usage

Start the server first:

```sh
./server
```

The server prints its process ID. In another terminal, pass that PID and a
message to the client:

```sh
./client <server-pid> "Hello from Minitalk!"
```

The server remains active and can receive further messages until it is stopped
with `Ctrl+C`.

For the bonus executables, use the same workflow:

```sh
./bonus_server
./bonus_client <server-pid> "Hello from the bonus client!"
```

The implementation supports multi-byte text such as UTF-8 because the message
is transmitted byte by byte.
