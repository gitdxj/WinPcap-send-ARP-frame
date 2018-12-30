#ifndef CAPTHREAD_H
#define CAPTHREAD_H

#include <QThread>
#include "packetHeader.h"
#include <pcap.h>
#include <string>

class capThread : public QThread
{
	Q_OBJECT

public:
	capThread(QObject *parent);
	~capThread();
	void run();
	void sendARP(QString);
	void setPara(pcap_if_t *);
	void setPara(pcap_if_t * d, std::string srcIP);
	void setPara(std::string desIP);

	void tcp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void udp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void icmp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void arp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void ip_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);
	void ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content);

signals:
	void getPacket(QString);
	void getMAC(QString);
private:
	pcap_if_t *d;
	std::string m_src_IP;
	std::string m_des_IP;
	char errbuf[PCAP_ERRBUF_SIZE];
	char m_captureInfo[1000];
	std::string s_captureInfo;
};

#endif // CAPTHREAD_H
