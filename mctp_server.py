import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 5600  # Port to listen on (non-privileged ports are > 1023)

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.bind((HOST, PORT))
soc.listen()

print("Starting the server...")

try:
    while True:
        conn, addr = soc.accept()
        print("\nConnected by", addr)

        data = conn.recv(1024)  
        #binary = ''.join(format(byte, '08b') for byte in data)

        if data:
            print(f"Received data of size {len(data)} bytes: ", end="")
            for byte in data:
                print(f"0x{byte:02X} | ", end="")
            print()
            conn.close()  

                
            new_conn, new_addr = soc.accept()
            print("\nConnected by", new_addr)

            new_conn.sendall(data)  
            new_conn.close()
            print("Sent data back and closed connection")
            
        conn, addr = soc.accept()
        print("\nConnected by", addr)

        data = conn.recv(1024)  
        #binary = ''.join(format(byte, '08b') for byte in data)
        if data:
            print(f"Received data of size {len(data)} bytes: ", end="")
            for byte in data:
                print(f"0x{byte:02X} | ", end="")
            print()
            conn.close()
        

except KeyboardInterrupt:
    print("\nTerminating the server...")

finally:
    soc.close()