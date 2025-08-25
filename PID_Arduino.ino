float Kp = 1.2;
float Ki = 0.05;
float Kd = 0.1;

int velo = 50;
int ldr1 = A3;
int ldr2 = A4;
int motor1 = A1;
int motor2 = A2;

int err = 0, errAnterior = 0;
float somaErro = 0;
float pid = 0;
int x1 = 0, x2 = 0;

void funcPid(int v1, int v2){
  int leitura1 = v1;
  int leitura2 = v2;
  err = leitura1 - leitura2;
  somaErro += err;
  int derivada = err - errAnterior; 
  pid = (Kp * err) + (Ki * somaErro) + (Kd * derivada);
  x1 = velo + pid;
  x2 = velo - pid;
  x1 = constrain(x1, 0, 255);
  x2 = constrain(x2, 0, 255);
  analogWrite(motor1, x1);
  analogWrite(motor2, x2);
  errAnterior = err;
}

void setup() {
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  funcPid(analogRead(ldr1), analogRead(ldr2));
  delay(10);
}
