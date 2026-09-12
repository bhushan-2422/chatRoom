# ChatRoomCpp

A lightweight TCP-based chat system built in C++ with **Boost.Asio**.  
The project demonstrates asynchronous socket communication, client session management, message framing, and concurrent processing.

---

## What This Project Does

ChatRoomCpp provides a server-client chat environment where multiple users can connect to a common room and exchange messages.

The main responsibilities are divided into:

- **Server** — accepts incoming client connections.
- **Session** — maintains communication with an individual client.
- **Room** — keeps track of connected participants and distributes messages.
- **Message** — handles message formatting and parsing.
- **Client** — connects to the server and provides the user interface for sending messages.

---

## Core Technologies

| Technology | Purpose |
|---|---|
| **C++** | Application implementation |
| **Boost.Asio** | TCP networking and asynchronous I/O |
| **TCP** | Reliable client-server communication |
| **Threads** | Concurrent execution |
| **Custom Message Protocol** | Encoding and decoding messages |

---

## System Design

The application follows a simple server-side room/session model.

