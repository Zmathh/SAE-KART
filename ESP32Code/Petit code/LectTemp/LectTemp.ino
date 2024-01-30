//26C°

//Port
/*
int SC=48;
int CSN=38;
int SIO=47;
*/

int SC=6;
int CSN=5;
int SIO=4;

//Variable

bool Lect[20];
int i;
float Somme=0;
int a;
float puiss;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SC,OUTPUT);
  pinMode(CSN,OUTPUT);
  pinMode(SIO,INPUT);

  digitalWrite(CSN,HIGH);
  Serial.println("Ready");
}

void loop() {
  Somme=0;
  digitalWrite(CSN,LOW);
  // put your main code here, to run repeatedly:
  for(i=0;i<16;i++){
    digitalWrite(SC,HIGH);
    Attend();
    Lect[i]=digitalRead(SIO);
    Serial.print(Lect[i]);
    digitalWrite(SC,LOW);
    Attend();
  }
  for(i=0;i<16;i++){
    digitalWrite(SC,HIGH);
    Attend();
    digitalWrite(SC,LOW);
    Attend();

  }
  Serial.println(" ");
  Serial.println("-------------------");
  Serial.println(" ");
  digitalWrite(CSN,HIGH);
  delay(500);

  for(i=1;i<14;i++){
    puiss=128/pow(2,(i-1));
    Somme=Somme+Lect[i]*puiss;
    /*Serial.print(Somme);
    Serial.print("= Somme + ");
    Serial.print(Lect[i]);
    Serial.print("*");
    Serial.println(puiss);
    Serial.println("----- pour i = ");
    Serial.println(Lect[i]);*/

  }
  Serial.println(Somme);
}


  void Attend(){
  for(a=0;a<30000;a++){
  __asm__("nop\n\t");
  }
}