Project Title :
LoRa Based Emergency Communication System.

Description :
This project helps people communicate in forest or remote areas without mobile network using LoRa technology.

Components Used :

[ Transmitter ]

• ESP32 Microcontroller
• LoRa Module
• GPS Module
• Emergency Push Button
• Battery
• Battery Monitoring Circuit


[ Receiver ]

• ESP32 Microcontroller
• LoRa Module
• OLED Display
• GSM Module
• Relay Module

Working

• The user has to carry the transmitter device when they are traveling to a remote area.
• This device is really important for the user's safety.
• In case something bad happens, the user just needs to press the emergency button on the transmitter device.
• The ESP32 then reads the GPS coordinates from the GPS module.
• This helps the system figure out where the user is.
• The location data is sent using the LoRa module.
• The LoRa module is special because it can send messages over long distances.
• The receiver ESP32 gets the LoRa message.
• Then the location is shown on the OLED screen.
• This is how the people helping the user know where they are.
• The system also sends the location to an application or a web platform using Wi-Fi.
• At the time the GSM module sends an SMS alert to the rescue teams.
• This way everyone who needs to know is informed.
• If needed, the relay module can even turn on a forest monitoring camera or a drone.
• This helps with surveillance and rescue operations.
• The system always checks the battery level.
• This is to make sure the system keeps working without any problems.
