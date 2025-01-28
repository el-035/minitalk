#!/bin/bash

# Replace these variables with your actual values
CLIENT="./client"    # Path to your client executable
SERVER_PID=6287     # Replace with your server's PID

# Check if the client exists
if [ ! -f "$CLIENT" ]; then
  echo "Error: Client executable not found at $CLIENT"
  exit 1
fi

# Check if the server PID is provided
if ! kill -0 $SERVER_PID 2>/dev/null; then
  echo "Error: Server process with PID $SERVER_PID not found."
  exit 1
fi

# Loop to send 100 rapid messages
for i in $(seq 1 100); do
  MESSAGE="Message $i"
  $CLIENT $SERVER_PID "$MESSAGE" &
done

echo "Sent 100 rapid messages to server with PID $SERVER_PID."
