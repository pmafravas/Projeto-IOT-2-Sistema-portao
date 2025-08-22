#include <WifiLocal.h>
#include <WifiSecrets.h> //Read the WifiSecrets_example.h for more informations
#include <WiFi.h>

//Constructor
WifiLocal::WifiLocal()
{
    Serial.print("\nInitializing Wifi");

    //Retrieve the data from the secrets file
    localNet = localNetSecrets;
    netPassword = netPasswordSecrets;
   
    //Connects to the WiFi
    int attemptsBeforeWarning = 10;
    while(WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin(localNet, netPassword);
        attemptsBeforeWarning--;
        delay(1000);
        Serial.print("."); //To show the user that the code is running
        if(attemptsBeforeWarning == 0)
        {
            attemptsBeforeWarning = 10;
            Serial.println("\n\n Verify that your Wifi informations are correct.");
        }
    }
    Serial.println("\n\nWifi connected.");
}

//Destructor
WifiLocal::~WifiLocal()
{
    WiFi.disconnect();
}

bool WifiLocal::IsConnected() 
{
   if(WiFi.status() == WL_CONNECTED) { return true;}
   return false;
}