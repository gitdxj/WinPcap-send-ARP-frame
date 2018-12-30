#include "capthread.h"

using namespace std;

capThread::capThread(QObject *parent)
	: QThread(parent)
{

}

capThread::~capThread()
{

}

void capThread::setPara(pcap_if_t *d)
{
	this->d = d;
}

void capThread::setPara(pcap_if_t * d, std::string srcIP)
{
	this->d = d;
	this->m_src_IP = srcIP;

}

void capThread::setPara(std::string desIP)
{
	this->m_des_IP = desIP;
}

void capThread::run()
{
	pcap_t *adhandle;
	if ( (adhandle= pcap_open(this->d->name,          // name of the device
                              65536,            // portion of the packet to capture. 
                                                // 65536 guarantees that the whole packet will be captured on all the link layers
                              PCAP_OPENFLAG_PROMISCUOUS,    // promiscuous mode
                              1000,             // read timeout
                              NULL,             // authentication on the remote machine
                              errbuf            // error buffer
                              ) ) == NULL)
	{
		exit(1);
	}

	int res;
	struct pcap_pkthdr *header;
	const u_char *pkt_data;
	
	//capture begins
	while((res = pcap_next_ex( adhandle, &header, &pkt_data)) >= 0)
	{

        if(res == 0)
            /* Timeout elapsed */
            continue;

		ethernet_protocol_packet_callback(NULL, header, pkt_data);

	}
}


void capThread::ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    u_short ethernet_type;   
    /* ��̫������ */   
    struct ether_header *ethernet_protocol;   
    /* ��̫��Э����� */   
    u_char *mac_string;   
    /* ��̫����ַ */   
 
	sprintf(this->m_captureInfo,"%s","**************************************************\n");   
	//emit this->getPacket(this->m_captureInfo);

	//sprintf(this->m_captureInfo,"#%d packet\n", packet_number);   
	//emit this->getPacket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%s","time: ");
	//emit this->getPacket(this->m_captureInfo);

	struct tm ltime;
	char timestr[16];
	time_t local_tv_sec = packet_header->ts.tv_sec;
    localtime_s(&ltime, &local_tv_sec);
    strftime( timestr, sizeof timestr, "%H:%M:%S", &ltime);

    sprintf(this->m_captureInfo,"%s\n", timestr);  

	//emit this->getPacket(this->m_captureInfo);
    /* ��ò������ݰ���ʱ�� */   


    sprintf(this->m_captureInfo,"%s","packet length: ");   
	//emit this->getPacket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%d\n", packet_header->len);   
	//emit this->getPacket(this->m_captureInfo);

    sprintf(this->m_captureInfo,"%s","--------   ethernet    --------\n");
	//emit this->getPacket(this->m_captureInfo);

    ethernet_protocol = (struct ether_header*)packet_content;   
    /* �����̫��Э������ */   
    sprintf(this->m_captureInfo,"%s","type: ");  
	emit this->getPacket(this->m_captureInfo);

    ethernet_type = ntohs(ethernet_protocol->ether_type);   
    /* �����̫������ */   
    sprintf(this->m_captureInfo,"%04x\n", ethernet_type);   
    switch (ethernet_type) /* ������̫�������ж� */   
    {   
        case 0x0800:   
            sprintf(this->m_captureInfo,"%s","IP protocal\n");
			emit this->getPacket(this->m_captureInfo);
            break;   
        case 0x0806:   
            sprintf(this->m_captureInfo,"%s","ARP protocal\n");   
			emit this->getPacket(this->m_captureInfo);
            break;   
        case 0x8035:   
            sprintf(this->m_captureInfo,"%s","RARP protocal\n");  
			emit this->getPacket(this->m_captureInfo);
            break;   
        default:   
            break;   
    }   
    sprintf(this->m_captureInfo,"%s","source MAC address: \n");   
	emit this->getPacket(this->m_captureInfo);

    mac_string = ethernet_protocol->ether_shost;   
    sprintf(this->m_captureInfo,"%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
	emit this->getPacket(this->m_captureInfo);
   
	/* ���Դ��̫����ַ */   
    sprintf(this->m_captureInfo,"%s","destination MAC address \n");   
	emit this->getPacket(this->m_captureInfo);
   
	mac_string = ethernet_protocol->ether_dhost;   
    sprintf(this->m_captureInfo,"%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
	emit this->getPacket(this->m_captureInfo);
	
	/* ���Ŀ����̫����ַ */   
    switch (ethernet_type)   
    {   
        case 0x0806:   
            arp_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э��ΪARPЭ�飬���÷���ARPЭ��ĺ�����ע������Ĵ��� */   
        case 0x0800:   
            ip_protocol_packet_callback(argument, packet_header, packet_content);   
            break;   
            /* �ϲ�Э��ΪIPЭ�飬���÷���IPЭ��ĺ�����ע������Ĵ��� */   
        default:   
            break;   
    }   
    printf("**************************************************\n");    
}   

/*
=======================================================================================================================  
������ʵ��ARPЭ������ĺ���������������ص�������ͬ  
=======================================================================================================================  
 */   
void capThread::arp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)   
{   
    struct arp_header *arp_protocol;   
    u_short protocol_type;   
    u_short hardware_type;   
    u_short operation_code;   
    u_char *mac_string;   
    struct in_addr source_ip_address;   
    struct in_addr destination_ip_address;   
    u_char hardware_length;   
    u_char protocol_length;   
    printf("--------   ARPЭ��    --------\n");   
    arp_protocol = (struct arp_header*)(packet_content + 14);   
    hardware_type = ntohs(arp_protocol->arp_hardware_type);   
    protocol_type = ntohs(arp_protocol->arp_protocol_type);   
    operation_code = ntohs(arp_protocol->arp_operation_code);   
    hardware_length = arp_protocol->arp_hardware_length;   
    protocol_length = arp_protocol->arp_protocol_length;   
    printf("Ӳ������:%d\n", hardware_type);   
    printf("Э������ Protocol Type:%d\n", protocol_type);   
    printf("Ӳ����ַ����:%d\n", hardware_length);   
    printf("Э���ַ����:%d\n", protocol_length);   
    printf("ARP Operation:%d\n", operation_code);   
    switch (operation_code)   
    {   
        case 1:   
            printf("ARP����Э��\n");   
            break;   
        case 2:   
            printf("ARPӦ��Э��\n");   
            break;   
        case 3:   
            printf("RARP����Э��\n");   
            break;   
        case 4:   
            printf("RARPӦ��Э��\n");   
            break;   
        default:   
            break;   
    }   
    printf("Դ��̫����ַ: \n");   
    mac_string = arp_protocol->arp_source_ethernet_address;   
    //printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
	sprintf(this->m_captureInfo,"%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));       
	memcpy((void*) &source_ip_address, (void*) &arp_protocol->arp_source_ip_address, sizeof(struct in_addr));   
    printf("ԴIP��ַ:%s\n", inet_ntoa(source_ip_address));   
    printf("Ŀ����̫����ַ: \n");   
    mac_string = arp_protocol->arp_destination_ethernet_address;   
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));   
    memcpy((void*) &destination_ip_address, (void*) &arp_protocol->arp_destination_ip_address, sizeof(struct in_addr));   
    printf("Ŀ��IP��ַ:%s\n", inet_ntoa(destination_ip_address));

	string srcMAC = this->m_captureInfo;
	QString QSrcMAC = QString::fromStdString(srcMAC);
	string desIp = inet_ntoa(destination_ip_address);
	string srcIp = inet_ntoa(source_ip_address);
	//string ip_addr = this->m_src_IP;
	if(desIp == this->m_src_IP && srcIp == this->m_des_IP)
		emit  getMAC(QSrcMAC);
}   

void capThread::tcp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content){}
void capThread::udp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content){}
void capThread::icmp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content){}
void capThread::ip_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content){}
