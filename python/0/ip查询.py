import socket
import pyperclip
ip0 = ''
ip1 = ''
def get_ip_address(url):
    try:
        ip_address = socket.gethostbyname(url)
        return ip_address
    except socket.gaierror as e:
        return f"无法获取IP地址: {url}: {e}"

if __name__ == "__main__":
    url = input("查询的网址: ")
    while True:
        ip1 = get_ip_address(url)
        if ip1.startswith("无法获取IP地址"):
            print(ip1)
            break
        if ip0!=ip1:
            print(f"{url} 的IP地址是: {ip1}")
            pyperclip.copy(ip1)
            print("ip已复制到剪切板")
        ip0 = ip1