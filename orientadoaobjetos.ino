class Robot {
  private:
    int PinIN1;
    int PinIN2;
    int PinIN3;
    int PinIN4;
    int Pin_sensor1;
    int Pin_sensor2;

  public:
    Robot(int in1, int in2, int in3, int in4, int sensor1, int sensor2) {
      PinIN1 = in1;
      PinIN2 = in2;
      PinIN3 = in3;
      PinIN4 = in4;
      Pin_sensor1 = sensor1;
      Pin_sensor2 = sensor2;
    }

    void setup() {
      Serial.begin(9600);
      pinMode(PinIN1, OUTPUT);
      pinMode(PinIN2, OUTPUT);
      pinMode(PinIN3, OUTPUT);
      pinMode(PinIN4, OUTPUT);
      pinMode(Pin_sensor1, INPUT);
      pinMode(Pin_sensor2, INPUT);
    }

    void loop() {
      int value1 = digitalRead(Pin_sensor1);
      int value2 = digitalRead(Pin_sensor2);

      Serial.print("Sensor Izquierdo: ");
      Serial.print(value1);
      Serial.print(" | Sensor Derecho: ");
      Serial.println(value2);

      if (value1 == LOW && value2 == LOW) {
        Serial.println("Adelante");
        MotorAdelante();
      }
      else if (value1 == HIGH && value2 == HIGH) {
        Serial.println("Detenido");
        MotorStop();
      }
      else if (value1 == HIGH && value2 == LOW) {
        Serial.println("Izquierda");
        MotorIzquierda();
      }
      else if (value2 == HIGH && value1 == LOW) {
        Serial.println("Derecha");
        MotorDerecha();
      }

      delay(20);
    }

    void MotorIzquierda() {
      digitalWrite(PinIN1, HIGH);
      digitalWrite(PinIN2, LOW);
      digitalWrite(PinIN3, HIGH);
      digitalWrite(PinIN4, LOW);
    }

    void MotorDerecha() {
      digitalWrite(PinIN1, LOW);
      digitalWrite(PinIN2, HIGH);
      digitalWrite(PinIN3, LOW);
      digitalWrite(PinIN4, HIGH);
    }

    void MotorAdelante() {
      digitalWrite(PinIN1, LOW);
      digitalWrite(PinIN2, HIGH);
      digitalWrite(PinIN3, HIGH);
      digitalWrite(PinIN4, LOW);
    }

    void MotorStop() {
      digitalWrite(PinIN1, LOW);
      digitalWrite(PinIN2, LOW);
      digitalWrite(PinIN3, LOW);
      digitalWrite(PinIN4, LOW);
    }
};

// Crear una instancia del robot
Robot miRobot(2, 3, 4, 5, 8, 9);

void setup() {
  miRobot.setup();
}

void loop() {
  miRobot.loop();
}
