/*
 * Non-Invasive Glucometer Using Saliva
 */

const int sensor = A0;

int oldValue = 0;
int newValue = 0;
int maxValue = 0;

float saliva = 0;

int condition = 0;

void setup()
{
    Serial.begin(9600);

    while (analogRead(sensor) == 0)
    {
        Serial.println("INSERT SAMPLE");
        delay(5000);
    }

    Serial.println("SAMPLE DETECTED");
}

void loop()
{
    while (condition == 0)
    {
        oldValue = analogRead(sensor);

        delay(500);

        newValue = analogRead(sensor);

        if (newValue < oldValue)
        {
            maxValue = oldValue;

            if (maxValue <= 20)
            {
                saliva = 0;
            }
            else
            {
                saliva = (((maxValue * 16.0) / 89.0) - 3.595505618);
            }

            condition = 1;
        }
    }

    Serial.print("Estimated Blood Glucose : ");
    Serial.print(saliva);
    Serial.println(" mg/dL");

    while (true)
    {
    }
}
