#define TEMP_SENSOR_PIN A0
#define TEMP_TUNE 1.0

void setup()
{
    Serial.begin(9600);
    pinMode(TEMP_SENSOR_PIN, INPUT);
}

void loop()
{
    // int tempSensorValue = analogRead(TEMP_SENSOR_PIN);
    // float voltage = tempSensorValue * (5.0 / 1023.0);
    // //float temperatureC = (voltage - 0.5) * 100.0;
    // float temperatureC = (voltage - 0.5) * 100.0 * TEMP_TUNE;

    // Serial.print("Temperature: ");
    // Serial.print(temperatureC);
    // Serial.println(" °C");

    // delay(1000);
    int raw = analogRead(TEMP_SENSOR_PIN);
    float voltage = raw * (5.0 / 1023.0);
    float Rsensor = 1700.0 * (5.0 - voltage) / voltage;
    float temperature = ((Rsensor - 1000.0) / 7.7 + 25.0) * TEMP_TUNE;
    Serial.println(temperature);

    delay(1000);
}
