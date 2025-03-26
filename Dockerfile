FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y g++ lib32z1 xinetd && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf && \
    chown -R root:root /home/ctf

WORKDIR /home/ctf

COPY vulnerable_echo_server.cpp .
RUN g++ -fno-stack-protector -z execstack -no-pie vulnerable_echo_server.cpp -o vulnerable_echo_server

COPY ctf.xinetd /etc/xinetd.d/ctf
COPY start.sh .

RUN chmod +x start.sh

EXPOSE 9999

CMD ["./start.sh"]
