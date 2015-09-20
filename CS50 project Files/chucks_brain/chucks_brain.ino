/**
 * chucks_brain.ino
 * Fletcher Harrinton and Yero Rudzinskas 
 * 
 *
 * Read temperature and humidity values from SHT11 sensor, activate fan (via custom circuit using tip120 transistor) and humidifier (via Powerswitch Tail II) at threshold values for proper mushroom growth
 * SHT11, SHT15) sensor.
 *
 * sensing setup sourced from Jonathan Oxer <jon@oxer.com.au>
 * 
 */

#include "SHT1x.h"

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);

int temp_max = 85;
int humid_min = 49;
int humid_max = 85;

// Define which pin to be used to communicate with Base pin of TP120 transistor
int fan_pin = 6; //PWM10

// Define powerswitch pin info
int switch_pin = 5;


void setup()
{

 	analogReference(DEFAULT); //standard ref voltage
       
	pinMode(switch_pin, OUTPUT); // Set pin for output to control TIP120 Base pi

	//start serial output
	Serial.begin(9600);
	
}

void loop()
{
        //initialize environment variables
	float temp_c;
	float temp_f;
	float humidity;

	// Read values from the sensor
	temp_c = sht1x.readTemperatureC();
	temp_f = sht1x.readTemperatureF();
	humidity = sht1x.readHumidity();

	// Print the values to the serial port
	
	Serial.print(temp_f, 0);
        Serial.print("T");

        Serial.print("\n");
        
	Serial.print(humidity, 0);
        Serial.print("H");
        
        Serial.print("\n");
	
        //turn devices on and off given threshold values
        if(temp_f > temp_max)
        {
            analogWrite(fan_pin, 255);
        }
        else if (temp_f < temp_max)
        {
            analogWrite(fan_pin, 0);
        }
        
        if(humidity < humid_min || humidity > humid_max)
        {
          digitalWrite(switch_pin, HIGH);
        }
        else
        {
          digitalWrite(switch_pin, LOW);
        }
        
	delay(1000);
        
}

