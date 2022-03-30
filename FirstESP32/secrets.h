#include <pgmspace.h>

#define SECRET
#define THINGNAME "MyNewESP32"

const char WIFI_SSID[] = "vroommates2";
const char WIFI_PASSWORD[] = "threebigps";
const char AWS_IOT_ENDPOINT[] = "at8juirnhepke-ats.iot.us-west-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVANor2yznHsuXPu9WsXmsbytymO+/MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMTA1MjkwMjIw
MDVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDenkRv19l3Rr3iU4U9
2k40LyB6NkS/IjF5PJeFtuxYnbFl1fZevAbs+yxo8cRUaGwWFKHHbOuNWEALOBpF
6014DLBbaAQ+yXK19R8v6YjCwAChKyqbKbzRWM7ROPI/sGaq3wKZjElRcCQEQmeq
wUMXh+6OXS6uFGiMF6YSnMc3rb2ld6zgwdr26zoOMkOumuWJC/XY19qD3OZRvgIU
PSaURP9FdPjLAKCptrwFz08U4f7zEF5Y2X5uwLNOZAd9GFxYH+bL/8lThz4dt/Ao
TPy4tjRCOlIvVhTzYm7B5lvME0Hs3cl0PVQ12LcdpFrf0SH8el1PnCxH3RL8MNcp
YTx/AgMBAAGjYDBeMB8GA1UdIwQYMBaAFDC2J+Rfq2yPnTsE1LSHw4urDO53MB0G
A1UdDgQWBBS5xwMyssrGIpZzLwl7gOqLBMOMTjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAPY9EhtietzLaPQ1U383wJxDZ
NU+IvDxeHjxu2UYDs+ziKMkp6aCz39PCN++gul9DshxOWFVUGKqNTcrBKSyug7qw
KN2guM5u17tbf8A7dkfpE8XGK8UIg5suDy0eBKFgt37Lcb+sjuDpzq9Knd3flLxD
eMmbd8EtZAt9KpFM4nnBbDOtJVOcncQQumQMHynwDW3udr3cKyh4BYugomJ7cLOB
a8LTrciFUvAsib+8qy2X+BrzqI7RLh030ny7Vr8yzozseePdkbZkWZkQa4SeocL3
2zen7Yb79EFm0e/BpHooNWRF/NzL6ueGph9h4G35c2SEjq6tgO/PekH72Auscw==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA3p5Eb9fZd0a94lOFPdpONC8gejZEvyIxeTyXhbbsWJ2xZdX2
XrwG7PssaPHEVGhsFhShx2zrjVhACzgaRetNeAywW2gEPslytfUfL+mIwsAAoSsq
mym80VjO0TjyP7Bmqt8CmYxJUXAkBEJnqsFDF4fujl0urhRojBemEpzHN629pXes
4MHa9us6DjJDrprliQv12Nfag9zmUb4CFD0mlET/RXT4ywCgqba8Bc9PFOH+8xBe
WNl+bsCzTmQHfRhcWB/my//JU4c+HbfwKEz8uLY0QjpSL1YU82JuweZbzBNB7N3J
dD1UNdi3HaRa39Eh/HpdT5wsR90S/DDXKWE8fwIDAQABAoIBAFRVSoHAGG7aCrcB
gtlSqQuVyszhYBu0HV/bN199U32ih4CXlJSA0HLYGBPNet2rDT80I7FDrtxF0UUu
xK02HYvb6rdF6U3LzLvnlx/0bU2xpMtpaeOL5S69YOPbmdHMxqf2gaqffWrve4Vt
jo4eVodEhHfEDxn9OznO/6fPYpzRbJ/LVRp0rZwtmLKCYUSLCyzty+Doc/GUjbxD
LJo+9s6d45+5tjsZksXALvkrw3rRXHAlvDWVZqyootBIa8NmzfavvJrSwWLkI8/1
dcicG17+mWLzjCBSBB3T0Wu96iLFz71qbFuWW5ZNXJsOOTaqvKKmTspoSyQ49ZOJ
mMbXe1ECgYEA+J7uvJbUYsgVyI0VJVfFwbvVZ8k1D+Eg+Wjiv5qyiWtI6NWewSq3
pN4DqkigTZQTjf0uD9QtZ1kpLZgiklA4ksuIi1HckR7zgSWhuoByCoCwn626CEGZ
wgYhWg2TaAzRt4tkZEau50alwlYzTJGjEZw05hoex4Mtlnk/1rO1m6kCgYEA5TnD
Hcjfee1S106o1FCUp9FzjG9XrMNqe6wVEQcJ0HFaWgA2gVLEL1lgwbA0TzwFYKSG
kBsBZ1ZFlVrnrSBkPkIi02HPM1JJ++3gLkWkBzDq5qcdIk2xDza2hk8in8OreV//
fIXTEQB4mZoNhIFtiZzsXvruRtRBLXWjUrgX7+cCgYEA80WYtwIjObEs13ttKIgV
IjdoXtCb0jjoqgN+dBur/Rj0U5fLapog7fqrvXCpIp/07mfBLY3hC5JL36hQk7hZ
UxJDPofQelO90y3+bV6HuE0qBmTYdoGyMQ8MjXBhP1vjzWRgzFn5hKY1Rc5RDegn
lvCxNkJywahS8D0eQTjBSFkCgYBSz3dJv1PcvHv9BJHBggryRZy001SdOUuyugwy
RpSpFQpLEWCff8MYR/XIg1uidFCNBWMHlHoBVw10U4724IjWZRYnv2IXbFcGCH3A
ua/0WRvDkAPabK7WjDGMe/JKPWopQyENX1tM/RqUgy72+7sSx/ospgKG3A9f2OvT
6mXbaQKBgHuNrumIRC18E3ZWd5nZbqVy7PG2qTTT6ndD+/3AIHy8WOkpNal9BnDs
IsXqNLnQ/BFG7DF8ko7sht6ulR8+JU574ZzI9Z5YF6KC1flRVbVBi/V1VLwEd8M0
ZHww3raVtDPWDekngqseI59XpkWcmF8FQcFJtPhpDnJR+qanEOUs
-----END RSA PRIVATE KEY-----
)KEY";
