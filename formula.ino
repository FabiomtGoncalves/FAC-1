
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SERIAL_MONITOR

void formula(float);
float Random(int, int);

float A_0 = 2;
float A_1 = 1.5;
float P = 5;
float pi = 3.14;
float w = 2*pi/P;
float R = 1;
float to = 0;
float samples = 200;
float tf = 20;
float increment = (tf - to) / (samples - 1);
float t = to;
String start;

void setup() {
  Serial.begin(115200);
  while(!Serial);
}


void loop() {
  if (Serial.available() > 0){
    start = Serial.readStringUntil('\n');
    if (start == "start"){
      t = to;
    }
  }
  if (t < tf){
    t += increment;
  }
  else {
    t = to;
  }
  f(t);
  Serial.println("end");
}

void f(float t){
  float f = A_0 + A_1 * sin(w * t);
  float data_ruido = f + R * Random(-1,1);

#ifdef SERIAL_MONITOR
  Serial.print("t = ");
#endif

  Serial.print(t);

#ifdef SERIAL_MONITOR  
  Serial.print("   f(t) = ");
#endif

  Serial.print(f);
  
#ifdef SERIAL_MONITOR  
  Serial.print("   ruido = ");
#endif

  Serial.print(data_ruido);

  Serial.println();
  delay(200);
}

float Random(int lower, int upper){
  int l = lower * 1000;
  int u = upper * 1000;
  int rnd = random(l,u);
  float rndNum = rnd /1000.0;
  return rndNum;
}
