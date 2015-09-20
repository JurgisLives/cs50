/**
 * 
 *
 x* Read temperature and humidity values from SHT11 sensor, activate fan (via custom circuit using tip120 transistor) and humidifier (via Powerswitch Tail II) at threshold values for proper mushroom growth
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

// Define which pin to be used to communicate with Base pin of TP120 transistor
int RPMPIN = A0;
int samples = 0;
int fan_pin = 6; //PWM10

// Define powerswitch pin info
int switch_pin = 5;


void setup()
{

 	analogReference(DEFAULT);
     
        //setup switch

	//setup fan
	//pinMode(fan_pin, OUTPUT); // Set pin for output to control TIP120 Base pin
	analogWrite(fan_pin, 255); // By changing values from 0 to 255 you can control motor speed
        
	pinMode(switch_pin, OUTPUT); // Set pin for output to control TIP120 Base pin
        digitalWrite(switch_pin, HIGH);
	// TCCR0B = _BV(CS00) | _BV(CS02); <-- add this to remove noise at sub-max pwm speeds

	//start serial output
	Serial.begin(9600);

	Serial.println("Starting up");

	
}

void loop()
{
	float temp_c;
	float temp_f;
	float humidity;

	// Read values from the sensor
	temp_c = sht1x.readTemperatureC();
	temp_f = sht1x.readTemperatureF();
	humidity = sht1x.readHumidity();

	// Print the values to the serial port
	Serial.print("Temperature: ");
	Serial.print(temp_c, DEC);
	Serial.print("C / ");
	Serial.print(temp_f, DEC);
	Serial.print("F. Humidity: ");
	Serial.print(humidity);
	Serial.println("%");
        
        if(temp_f > 75.8)
        {
            analogWrite(fan_pin, 255);
        }
        else 
        {
            analogWrite(fan_pin, LOW);
        }
        
        if(humidity < 49.00)
        {
          digitalWrite(switch_pin, HIGH);
        }
        else
        {
          digitalWrite(switch_pin, LOW);
        }
        
	delay(1000);
        
}


