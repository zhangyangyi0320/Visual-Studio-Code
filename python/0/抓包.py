from scapy.all import sniff, wrpcap  # 从 scapy 库导入 sniff 和 wrpcap 函数
import time  # 导入时间模块
import socket  # 导入 socket 模块
import pyperclip  # 导入 pyperclip 模块，用于剪贴板操作（此处未使用）

def get_ip_address(url):
    # 获取指定 URL 的 IP 地址
    try:
        ip_address = socket.gethostbyname(url)  # 使用 socket.gethostbyname 获取 URL 对应的 IP 地址
        return ip_address  # 返回 IP 地址
    finally:
        return "0.0.0.0"  # 如果发生异常，返回默认 IP 地址 "0.0.0.0"

def packet_callback(packet):
    # 数据包回调函数，用于处理捕获到的数据包
    timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(packet.time))  # 将数据包的时间戳转换为可读的格式
    print(f"捕获到数据包，时间: {timestamp}, 长度: {len(packet)} 字节")  # 打印数据包的时间和长度
    packets.append(packet)  # 将捕获到的数据包添加到 packets 列表

if __name__ == "__main__":
    i = 0  # 初始化计数器 i
    packets = []  # 初始化数据包列表 packets
    # 设置 BPF 过滤器表达式
    a = input('请输入源IP地址: ')  # 输入源 IP 地址
    b = input('请输入目标IP地址: ')  # 输入目标 IP 地址
    print("开始抓包...")  # 打印开始抓包提示
    try:
        while True:
            # 使用 BPF 过滤器表达式来过滤源 IP 地址为 192.168.1.1 且目标 IP 地址为 192.168.1.2 的数据包
            sniff(prn=packet_callback, count=100, filter=f"src host {get_ip_address(a)} and dst host {get_ip_address(a)}")
            wrpcap(f"{str(i)}.pcap", packets)  # 保存捕获到的数据包到文件
            print(f"数据包已保存到 {str(i)}.pcap")  # 打印保存文件提示
            print("按 Ctrl+C 停止抓包")  # 提示用户如何停止抓包
            print("继续抓包...")  # 提示继续抓包
            i += 1  # 计数器 i 自增
    except KeyboardInterrupt:
        # 捕获用户中断（Ctrl+C）事件
        print("停止抓包")  # 打印停止抓包提示
        wrpcap(f"{str(i)}.pcap", packets)  # 保存剩余的数据包到文件
        print(f"剩余数据包已保存到 {str(i)}.pcap")  # 打印保存剩余数据包的提示
