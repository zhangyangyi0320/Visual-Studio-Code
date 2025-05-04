from scapy.all import sniff, wrpcap

def packet_callback(packet):
    packets.append(packet)

if __name__ == "__main__":
    i = 0
    print("开始抓包...")
    while True:
        packets = []
        sniff(prn=packet_callback, count=100)  # 捕获100个数据包
        wrpcap(f"D:/pcap/{str(i)}.pcap", packets)  # 保存数据包到文件
        print(f"数据包已保存到 {str(i)}.pcap")
        print("按 Ctrl+C 停止抓包")
        print("继续抓包...")
        i += 1