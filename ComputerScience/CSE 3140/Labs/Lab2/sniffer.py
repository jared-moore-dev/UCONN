from scapy.all import *
def process_packet(pkt):
#  pkt.show()
	if pkt.haslayer(IP):
        	ip = pkt[IP]
        	print("IP:{} --> {}".format(ip.src, ip.dst))
	elif pkt.haslayer(TCP):
        	tcp = pkt[TCP]
        	print ("TCP ports:{} --> {}".format(tcp.sport, tcp.dport))
	elif pkt.haslayer(UDP):
        	udp = pkt[UDP]
        	print ("UDP ports:{} --> {}".format(udp.sport,udp.dport))
	if pkt.haslayer(Ether):
        	eth = pkt[Ether]
        	print("Ether ports:{} --> {}".format(eth.src, eth.dst))
	else:
        	print("other protocol")
packets = sniff(iface = "eth0", filter = "icmp", prn = process_packet, count = 5)
print(packets)
