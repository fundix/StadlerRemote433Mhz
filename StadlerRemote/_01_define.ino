#define DEBUG

char    SerialByteIn;                              // Temporary variable
String  SerialReadBuffer = "";                   // Read/Write Buffer 2 for Serial
boolean SerialEnd = false;                      // Flag to indicate End of Serial String

boolean commandMode = false;                    // Send AT commands

//--------- DHT ----------
#define       PIN_DHT D4
#define       DHTTYPE DHT22
float         temperature = 0.0;
float         humidity    = 0.0;

const int     timme_hum = 20 * 1000;


