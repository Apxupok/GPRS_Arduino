/* 
*  Код инициализации GSM/GPRS Shield A9 с платами Arduino Uno  
*  Подробности: https://wiki.iarduino.ru/page/gsm-gprs-shield-internet
*/

// Подключаем библиотеку GprsModem
#include <GprsModem.h> 
// Подключаем библиотеку SoftwareSerial
#include <SoftwareSerial.h>

// Назначаем GPIO пины для связи с GSM/GPRS Shield A9
// Пин включения GSM/GPRS-модуля
constexpr int PIN_PWR = 7;
// Пин приёма данных из контроллера в GSM/GPRS-модуль
constexpr int PIN_RX = 8;
// Пин передачи данных из контроллера в GSM/GPRS-модуль
constexpr int PIN_TX = 9;

// Создаём объект mySerial для работы с функциями библиотеки SoftwareSerial
// В параметрах указываем пины RX и TX
SoftwareSerial mySerial(PIN_RX, PIN_TX);

// Создаём объект класса GprsModem
// В параметрах передаём объект Serial к которому подключён GSM/GPRS-модуль
// и пин включения GSM/GPRS-модуля
GprsModem myModem(mySerial, PIN_PWR);

// Создаём объект класса GprsClient
// В параметрах передаём объект Serial к которому подключён GSM/GPRS-модуль
GprsClient myClient(mySerial);


void setup() { 
  // Открываем консоль
  Serial.begin(9600);

  // Ждём готовность модема GSM/GPRS Shield к работе
  Serial.print("Инициализация модема, подождите пожалуйста...");
  while (myModem.status() != GPRS_OK) {
    Serial.print(".");
    myModem.begin();
  }
  Serial.println("Инициализация модема прошла успешно");

  // Получаем последний статус
  switch (myModem.status()) {
    case GPRS_OK: {
      Serial.println("Модуль готов к работе");
      break;
    }
    case GPRS_REG_NO: {
      Serial.println("Модем не зарегистрирован в сети оператора связи");
      break;
    }
    case GPRS_SPEED_ERR: {
      Serial.println("Не удалось согласовать скорость UART");
      break;
    }
    case GPRS_UNKNOWN: {
      Serial.println("Статус неизвестен");
      break;
    }
    case GPRS_SLEEP: {
      Serial.println("Режим ограниченной функциональности");
      break;
    }
    case GPRS_SIM_NO: {
      Serial.println("Нет SIM-карты");
      break;
    }
    case GPRS_SIM_FAULT: {
      Serial.println("SIM-карта неисправна");
      break;
    }
    case GPRS_SIM_ERR: {
      Serial.println("SIM-карта не прошла проверку");
      break;
    }
    case GPRS_REG_FAULT: {
      Serial.println("Оператор отклонил регистрацию модема");
      break;
    }
    case GPRS_SIM_PIN: {
      Serial.println("Требуется ввод PIN-кода");
      break;
    }
    case GPRS_SIM_PUK: {
      Serial.println("Требуется ввод PUK1");
      break;
    }
    default: {
      break;
    }
  }

  Serial.println("Обновляем статус модема...");
  switch (myModem.updateStatus()) {
    case GPRS_OK: {
      Serial.println("Модуль готов к работе");
      break;
    }
    case GPRS_REG_NO: {
      Serial.println("Модем не зарегистрирован в сети оператора связи");
      break;
    }
    case GPRS_SPEED_ERR: {
      Serial.println("Не удалось согласовать скорость UART");
      break;
    }
    case GPRS_UNKNOWN: {
      Serial.println("Статус неизвестен");
      break;
    }
    case GPRS_SLEEP: {
      Serial.println("Режим ограниченной функциональности");
      break;
    }
    case GPRS_SIM_NO: {
      Serial.println("Нет SIM-карты");
      break;
    }
    case GPRS_SIM_FAULT: {
      Serial.println("SIM-карта неисправна");
      break;
    }
    case GPRS_SIM_ERR: {
      Serial.println("SIM-карта не прошла проверку");
      break;
    }
    case GPRS_REG_FAULT: {
      Serial.println("Оператор отклонил регистрацию модема");
      break;
    }
    case GPRS_SIM_PIN: {
      Serial.println("Требуется ввод PIN-кода");
      break;
    }
    case GPRS_SIM_PUK: {
      Serial.println("Требуется ввод PUK1");
      break;
    }
    default: {
      break;
    }
  }
}

void loop() {
}