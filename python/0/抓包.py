import asyncio
from scapy.all import sniff, wrpcap

async def packet_callback(packet):
    packets.append(packet)
    if len(packets) >= batch_size:
        await save_packets()
        packets.clear()

async def save_packets():
    if packets:
        filename = f"captured_packets_{file_counter}.pcap"
        wrpcap(filename, packets)
        print(f"数据包已保存到 {filename}")
        global file_counter
        file_counter += 1

if __name__ == "__main__":
    print("开始抓包...")
    packets = []
    batch_size = 100  # 每次保存100个数据包
    file_counter = 1  # 文件计数器

    loop = asyncio.get_event_loop()
    try:
        loop.run_in_executor(None, sniff, prn=packet_callback, count=0)  # 捕获数据包
        loop.run_forever()
    except KeyboardInterrupt:
        print("停止抓包")
    finally:
        loop.run_until_complete(save_packets())  # 保存剩余的数据包
        loop.close()
