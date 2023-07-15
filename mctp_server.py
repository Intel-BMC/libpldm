import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 5600  # Port to listen on (non-privileged ports are > 1023)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

print("Starting the server... \n")
try:
    while True:
        conn, addr = s.accept()
        data = conn.recv(32)
        #binary_data = ''.join(format(byte, '08b') for byte in data)
        binary_data = [bin(byte)[2:].zfill(8) for byte in data]
        print(binary_data)
        print(len(data))
        print("\n")

        conn.close()

except KeyboardInterrupt:
    print("Terminating the server...")

finally:
    s.close()