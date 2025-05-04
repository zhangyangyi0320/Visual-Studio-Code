from scapy.all import sniff, IP, TCP, UDP, ICMP
import datetime

def packet_callback(packet):
    """处理捕获到的数据包"""
    now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")
    if IP in packet:
        src_ip = packet[IP].src
        dst_ip = packet[IP].dst

        # 处理TCP数据包
        if TCP in packet:
            src_port = packet[TCP].sport
            dst_port = packet[TCP].dport
            print(f"{now} [TCP] {src_ip}:{src_port} -> {dst_ip}:{dst_port}")

        # 处理UDP数据包
        elif UDP in packet:
            src_port = packet[UDP].sport
            dst_port = packet[UDP].dport
            print(f"{now} [UDP] {src_ip}:{src_port} -> {dst_ip}:{dst_port}")

        # 处理ICMP数据包
        elif ICMP in packet:
            print(f"{now} [ICMP] {src_ip} -> {dst_ip}")

        # 其他协议
        else:
            print(f"{now} [Other] {src_ip} -> {dst_ip}")

def main():
    print("开始抓包，按Ctrl+C停止...")
    try:
        # 指定要监听的网络接口（可选）
        # interface = "eth0"  # 替换为你的网络接口名称
        # sniff(iface=interface, prn=packet_callback, store=0)
        sniff(prn=packet_callback, store=False)
    except KeyboardInterrupt:
        print("抓包结束")

if __name__ == "__main__":
    main()
