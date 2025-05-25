from scapy.all import *

def get_ip_address(url):
    try:
        ip_address = socket.gethostbyname(url)
        return ip_address
    except socket.gaierror as e:
        return "0.0.0.0"
    
target_ip = get_ip_address(input("请输入目标IP地址："))
start_port = int(input("请输入起始端口号："))
end_port = int(input("请输入结束端口号："))
port_range = range(start_port, end_port + 1)

for port in port_range:
    packet = IP(dst=target_ip)/TCP(dport=port, flags="S")  # 构造SYN扫描包
    response = sr1(packet, timeout=1, verbose=0)  # 发送包并等待响应
    if response is not None and response.haslayer(TCP):
        if response.getlayer(TCP).flags == 0x12:  # 如果收到SYN-ACK
            print(f"端口{port}开放")
            sr(IP(dst=target_ip)/TCP(dpot=port, flags="R"), timeout=1, verbose=0)  # 发送RST包关闭连接
        elif response.getlayer(TCP).flags == 0x14:  # 如果收到RST-ACK
            print(f"端口{port}关闭")
    else:
        print(f"端口{port}未响应")
