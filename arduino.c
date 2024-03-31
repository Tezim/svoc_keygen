#include <Arduino.h>

#define PIN_OFFSET 14
#define BIT_SECURITY 10

void setup() {
    // begin serial communication
    Serial.begin(9600);
    // initial seed with ID * current temperature
    randomSeed(GetTemp());
    randomSeed(analogRead(random(9) + PIN_OFFSET));
}


/*
* Read the temperature value from internal sensor
* Sensor is in the processor itself so the value is internal temperature
* Calculate the temperature via linear aproximation, this can be calibrated to lower the noise
* reference : https://www.netquote.it/nqmain/2011/04/arduino-nano-v3-internal-temperature-sensor/
*/
unsigned long GetTemp(void)
{
    unsigned int wADC;
    // initialize ADC reading
    ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
    ADCSRA |= _BV(ADEN);
    delay(20);
    ADCSRA |= _BV(ADSC);
    while (bit_is_set(ADCSRA, ADSC));
    wADC = ADCW;
    // calculate temerature (may be calibrated)
    return (wADC - 324.31) / 1.22;
}

// output only clean output of analog read for testing of output interval numbers
void get_sample_clean(int n_samples, int _delay, int pin){
    for (int i = 0; i < n_samples; i++){
        int sample = analogRead(pin + PIN_OFFSET);
        Serial.println(sample); // send to serial
        delay(_delay);
    }
}


void gen_sample_alg(int n_samples, int _delay){
    int randomValue = random(9) + PIN_OFFSET;
    for (int i = 0; i < n_samples; i++){
        int pin = analogRead(randomValue) % 8;
        int sample = analogRead(pin + PIN_OFFSET);
        byte lowByte = sample & 0xFF; // Get the least significant 8 bits
        Serial.write(lowByte); // send to serial
        delay(_delay);
    }
}


void loop() {
    gen_sample_alg(10, 50);
}
