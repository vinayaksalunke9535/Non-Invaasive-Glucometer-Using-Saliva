
/*
 * Pulse Oximeter Monitoring
 * Sensor: PulseSensor / MAX30100
 */

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PULSE_INPUT = A0;
const int PULSE_BLINK = 13;
const int PULSE_FADE = 5;

PulseSensorPlayground pulseSensor;

void setup()
{
    Serial.begin(9600);

    pulseSensor.analogInput(PULSE_INPUT);
    pulseSensor.blinkOnPulse(PULSE_BLINK);
    pulseSensor.fadeOnPulse(PULSE_FADE);

    if (!pulseSensor.begin())
    {
        while (1)
        {
            digitalWrite(PULSE_BLINK, LOW);
            delay(500);
            digitalWrite(PULSE_BLINK, HIGH);
            delay(500);
        }
    }
}

void loop()
{
    int signal = pulseSensor.getLatestSample();

    Serial.print("Signal: ");
    Serial.println(signal);

    if (pulseSensor.sawStartOfBeat())
    {
        int bpm = pulseSensor.getBeatsPerMinute();

        Serial.print("Heart Rate: ");
        Serial.print(bpm);
        Serial.println(" BPM");
    }

    delay(500);
}
