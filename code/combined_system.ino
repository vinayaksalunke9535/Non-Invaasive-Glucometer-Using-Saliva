/*
 * Non-Invasive Glucometer Using Saliva
 * with Pulse Oximeter
 *
 * Academic Prototype
 */

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int glucoseSensor = A0;

const int PULSE_INPUT = A0;
const int PULSE_BLINK = 13;
const int PULSE_FADE = 5;

PulseSensorPlayground pulseSensor;

int oldValue = 0;
int newValue = 0;
int maxValue = 0;
float salivaGlucose = 0;
int condition = 0;

void setup()
{
    Serial.begin(9600);

    pulseSensor.analogInput(PULSE_INPUT);
    pulseSensor.blinkOnPulse(PULSE_BLINK);
    pulseSensor.fadeOnPulse(PULSE_FADE);
    pulseSensor.begin();

    while (analogRead(glucoseSensor) == 0)
    {
        Serial.println("INSERT SAMPLE");
        delay(3000);
    }

    Serial.println("SAMPLE DETECTED");
}

void loop()
{
    if (condition == 0)
    {
        oldValue = analogRead(glucoseSensor);
        delay(500);
        newValue = analogRead(glucoseSensor);

        if (newValue < oldValue)
        {
            maxValue = oldValue;

            if (maxValue <= 20)
                salivaGlucose = 0;
            else
                salivaGlucose = (((maxValue * 16.0) / 89.0) - 3.595505618);

            condition = 1;
        }
    }

    Serial.print("Estimated Blood Glucose: ");
    Serial.print(salivaGlucose);
    Serial.println(" mg/dL");

    if (pulseSensor.sawStartOfBeat())
    {
        Serial.print("Heart Rate: ");
        Serial.print(pulseSensor.getBeatsPerMinute());
        Serial.println(" BPM");
    }

    delay(1000);
}
