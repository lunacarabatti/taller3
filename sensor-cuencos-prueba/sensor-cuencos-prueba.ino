#include <CapacitiveSensor.h>

// Configuración de pines capacitivos (Pin_Envio, Pin_Lectura)
CapacitiveSensor sensor1 = CapacitiveSensor(2, 3); // Flor 1 (Derecha)
CapacitiveSensor sensor2 = CapacitiveSensor(2, 4); // Flor 2 (Centro)
CapacitiveSensor sensor3 = CapacitiveSensor(2, 5); // Flor 3 (Izquierda)

// Umbrales Bajos (ideal para resistencias de 1M)
// En reposo deberían dar números muy bajos (ej: 0 a 30).
// Ponemos los umbrales en 150 para que no salten solos.
int umbral1 = 150; 
int umbral2 = 150; 
int umbral3 = 150; 

void setup() {
  Serial.begin(9600);

  // Desactiva la autocalibración continua de la librería
  sensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sensor3.set_CS_AutocaL_Millis(0xFFFFFFFF);

  Serial.println("--- PRUEBA CON RESISTENCIAS DE 1M ---");
}

void loop() {
  long val1 = sensor1.capacitiveSensor(30);
  long val2 = sensor2.capacitiveSensor(30);
  long val3 = sensor3.capacitiveSensor(30);

  // Muestra de valores en el Serial Monitor
  Serial.print("S1 (Der): "); Serial.print(val1);
  Serial.print("\t S2 (Cen): "); Serial.print(val2);
  Serial.print("\t S3 (Izq): "); Serial.print(val3);

  // Verificación individual
  if (val1 > umbral1) {
    Serial.print("  -> [ FLOR 1 DETECTADA ]");
  }
  if (val2 > umbral2) {
    Serial.print("  -> [ FLOR 2 DETECTADA ]");
  }
  if (val3 > umbral3) {
    Serial.print("  -> [ FLOR 3 DETECTADA ]");
  }

  Serial.println();
  delay(100);
}