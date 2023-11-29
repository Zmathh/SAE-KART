import processing.serial.*;
import java.nio.ByteBuffer;
//int SERIAL_BAUD = 115200;

//Serial myPort;

PFont font;

float speed = 30; // Vitesse en km/h
float batteryLevel = 100; // Pourcentage
boolean brakes = false;
float voltage1 = 12.3;
float voltage2 = 11.8;
float current = 5.2;

// Ampères
float temp1 = 21.1; // Température en degrés Celsius
float temp2 = 23.9;
float temp3 = 26.7;
float latitude = 37.7749;
float longitude = -122.4194;

  //pas plus de 100
  float gaugesize = 200;

void setup() {
  size(2000, 1280);
  font = createFont("Orbitron", 24);
  textFont(font);
  // myPort = new Serial(this, "COM10", SERIAL_BAUD);
}

void draw() {
  background(0);
  
 //   if (myPort.available() > 0) {
    // Lire la ligne reçue depuis le port série
 //   String data = myPort.readStringUntil('\n');
  //  if (data != null) {
 // Divisez les données en plusieurs valeurs
  //    String[] values = split(data, ',');
      //if (values.length == 11) {
    //      Convertissez les chaînes en variables correspondantes
    //    brakes = boolean(int(values[0]));
    //    speed = float(values[1]);
    //    batteryLevel = float(values[2]);
    //    voltage1 = float(values[3]);
    //    voltage2 = float(values[4]);
    //    current = float(values[5]);
    //    temp1 = float(values[6]);
    //    temp2 = float(values[7]);
    //    temp3 = float(values[8]);
    //    latitude = float(values[9]);
    //    longitude = float(values[10]);
    //  }
    //}
    //}

  // Compteur de vitesse (convertir mph en km/h)
  drawGauge(gaugesize*04.00, gaugesize*1.00, speed, 0, 200, "Vitesse", "km/h", color(0, 0, 255));

  // Niveau de batterie
  drawGauge(gaugesize*07.00, gaugesize*5.00, batteryLevel, 0, 100, "Batterie", "%", color(0, 255, 0));

  // Tension 1
  drawGauge(gaugesize*1.00, gaugesize*3.00, voltage1, 0, 20, "Tension 1", "V", color(255, 0, 0));

  // Tension 2
  drawGauge(gaugesize*3.00, gaugesize*3.00, voltage2, 0, 20, "Tension 2", "V", color(255, 0, 0));

  // Courant
  drawGauge(gaugesize*5.00, gaugesize*3.00, current, 0, 10, "Courant", "A", color(255, 0, 0));

  // Température 1 (°C)
  drawGauge(gaugesize*1.00, gaugesize*5.00, temp1, -20, 100, "Batteries Droite", "°C", color(255, 140, 0));
 
  // Température 2 (°C)
  drawGauge(gaugesize*3.00, gaugesize*5.00, temp2, -20, 100, "Batteries Gauche", "°C", color(255, 140, 0));

  // Température 3 (°C)
  drawGauge(gaugesize*5.00, gaugesize*5.00, temp3, -20, 100, "Température 3", "°C", color(255, 140, 0));

  // État des freins
  text("Freins : " + (brakes ? "Activés" : "Désactivés"), gaugesize*3.50, gaugesize*0.25);

  // Coordonnées GPS
  text("Latitude: " + nf(latitude, 2, 6), gaugesize*6.25, gaugesize*3.00);
  text("Longitude: " + nf(longitude, 2, 6), gaugesize*6.25, gaugesize*3.50);
}

void drawGauge(float x, float y, float value, float minValue, float maxValue, String label, String unit, color col) {
  float angle = map(value, minValue, maxValue, -PI/4, 5*PI/4);
  fill(col);

  arc(x, y, gaugesize*1.60, gaugesize*1.60, -PI/4, angle);
  fill(0);
  ellipse(x, y, gaugesize*.65, gaugesize*.65);
  fill(255);
  textSize(gaugesize* 0.12);
  text(label, x - 30, y + 90);
  text(nf(value, 2, 1) + unit, x - gaugesize*0.20, y + gaugesize*.05);

  // Ajoute des graduations
  noFill();
  stroke(255);
  for (float v = minValue; v <= maxValue; v += (maxValue - minValue) / 10) {
    float gradAngle = map(v, minValue, maxValue, -PI/4, 5*PI/4);
    float gradX = x + cos(gradAngle) * gaugesize *0.85;
    float gradY = y + sin(gradAngle) * gaugesize *0.85;
    float labelX = x + cos(gradAngle) * gaugesize *0.75;
    float labelY = y + sin(gradAngle) * gaugesize *0.75;
    line(gradX, gradY, labelX, labelY);
    textSize(gaugesize*0.08);
    text(nf(v, 0, 0), labelX - 0, labelY -0);
  }
}
