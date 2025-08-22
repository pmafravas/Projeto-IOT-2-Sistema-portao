#ifndef WIFI_LOCAL_H
#define WIFI_LOCAL_H

class WifiLocal
{
private:
    const char* localNet;
    const char* netPassword;
public:
    WifiLocal();
    ~WifiLocal();
    bool IsConnected();
};

#endif