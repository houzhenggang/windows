#pragma once
#define IFF_RUNNING    (1<<6)
#define IFF_PROMISC  (1 << 8)
#define IFNAMSIZ        16
#define IF_NAMESIZE	32
struct ifmap {
	unsigned long   mem_start;
	unsigned long   mem_end;
	unsigned short  base_addr;
	unsigned char   irq;
	unsigned char   dma;
	unsigned char   port;
};

struct ifreq {
	char ifr_name[IFNAMSIZ]; /* Interface name */
	union {
		struct sockaddr ifr_addr;
		struct sockaddr ifr_dstaddr;
		struct sockaddr ifr_broadaddr;
		struct sockaddr ifr_netmask;
		struct sockaddr ifr_hwaddr;
		short           ifr_flags;
		int             ifr_ifindex;
		int             ifr_metric;
		int             ifr_mtu;
		struct ifmap    ifr_map;
		char            ifr_slave[IFNAMSIZ];
		char            ifr_newname[IFNAMSIZ];
		char           *ifr_data;
	};
};

struct ifconf {
	int                 ifc_len; /* size of buffer */
	union {
		char           *ifc_buf; /* buffer address */
		struct ifreq   *ifc_req; /* array of structures */
	};
};

unsigned int if_nametoindex(const char *ifname);