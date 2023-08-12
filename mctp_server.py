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

        data = conn.recv(64)

        if data:
            binary_data = ''.join(format(byte, '08b') for byte in data)
            #binary_data = [bin(byte)[2:].zfill(8) for byte in data]
            print(binary_data)
            print(len(data))

        conn.close()

except KeyboardInterrupt:
    print("\nTerminating the server...")

finally:
    soc.close()