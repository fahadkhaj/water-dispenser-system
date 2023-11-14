#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int trig = 13;
const int echo = 12;
int sensor = A0;
int relay = A5;

int sensorState = 0;

void setup()
{

    // put your setup code here, to run once: lcd.begin(16,2); pinMode(sensor,INPUT); pinMode(relay,OUTPUT);; pinMode(trig,INPUT); pinMode(echo,OUTPUT);; lcd.setCursor(0,0);
    lcd.print("COIN BASED        ");

    lcd.setCursor(0, 1);
    lcd.print("WATER DISPENSERY          ");

    delay(2000);
}

void loop()
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long duration = pulseIn(echo, HIGH);
    long distance = (duration / 2) / 29.1;
    sensorState = digitalRead(sensor);

    if (sensorState == HIGH)

    {

        if (distance < 17)
        {

            lcd.setCursor(0, 0);
            lcd.print("PLEASE WAIT        ");
            delay(1000);
            lcd.setCursor(0, 1);

            lcd.print("WATER DELEVERING         ");

            delay(1000);
            digitalWrite(relay, HIGH);

            delay(0); // water delevering time
        }

        else
        {

            lcd.setCursor(0, 0);

            lcd.print("NO WATER IN TANK       ");

            digitalWrite(relay, LOW);
        }
    }

    else if (sensorState == LOW)

    {

        lcd.setCursor(0, 0);

        lcd.print("PLEASE INSERT        ");

        lcd.setCursor(0, 1);
        lcd.print("COIN                ");
        digitalWrite(relay, LOW);
    }
}
