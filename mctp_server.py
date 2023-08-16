import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 5600  # Port to listen on (non-privileged ports are > 1023)

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.bind((HOST, PORT))
soc.listen()

print("Starting the server...\n")

try:
    while True:
        conn, addr = soc.accept()
        print("Connected by", addr)

        data = conn.recv(1024)  
        binary = ''.join(format(byte, '08b') for byte in data)

        if data:
            print(f"Received data of size {len(data)} bytes:\n{binary}")
            conn.close()  

                
            new_conn, new_addr = soc.accept()
            print("Connected by", new_addr)

            new_conn.sendall(data)  
            new_conn.close()
            print("Sent data back and closed connection")

except KeyboardInterrupt:
    print("\nTerminating the server...")

finally:
    soc.close()