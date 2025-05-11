from scapy.all import sniff, wrpcap

def packet_callback(packet):
    packets.append(packet)

if __name__ == "__main__":
    i = 0
    packets = []  # 将 packets 列表移到循环外部
    print("开始抓包...")
    try:
        while True:
            sniff(prn=packet_callback, count=100)  # 捕获100个数据包
            wrpcap(f"{str(i)}.pcap", packets)  # 保存数据包到文件
            print(f"数据包已保存到 {str(i)}.pcap")
            print("按 Ctrl+C 停止抓包")
            print("继续抓包...")
            i += 1
    except KeyboardInterrupt:
        print("停止抓包")
        wrpcap(f"{str(i)}.pcap", packets)  # 保存剩余的数据包
        print(f"剩余数据包已保存到 {str(i)}.pcap")
