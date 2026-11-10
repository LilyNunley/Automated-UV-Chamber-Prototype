#include <Esplora.h>

// TinkerKit OUT_A is Digital Pin 11
const int RELAY_PIN = 11; 

// 2 hours = 120 minutes in milliseconds (120 * 60 * 1000)
// Change this number if you want a different time (e.g., 3600000UL = 1 hour)
const unsigned long RUN_TIME = 10000UL; 

bool timerRunning = false;
unsigned long startTime = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  
  // ACTIVE-LOW SONGLE RELAY: Start with outlet OFF (HIGH)
  digitalWrite(RELAY_PIN, HIGH); 
  Esplora.writeRGB(255, 0, 0); // Red LED = Outlet OFF / Ready
}

void loop() {
  // Press Bottom Button (SWITCH_1) to START the 2-hour timer
  if (Esplora.readButton(SWITCH_1) == LOW && !timerRunning) {
    timerRunning = true;
    startTime = millis();
    digitalWrite(RELAY_PIN, LOW);  // LOW turns Songle relay ON
    Esplora.writeRGB(0, 255, 0);   // Green LED = Outlet ON
    Esplora.tone(1000, 150);       // Short start beep
    delay(250);                    // Debounce delay
  }

  // Press Left Button (SWITCH_2) to RESET / TURN OFF early
  if (Esplora.readButton(SWITCH_2) == LOW) {
    timerRunning = false;
    digitalWrite(RELAY_PIN, HIGH); // HIGH turns Songle relay OFF
    Esplora.writeRGB(255, 0, 0);   // Red LED = Outlet OFF
    Esplora.tone(400, 200);        // Low reset beep
    delay(250);                    // Debounce delay
  }

  // Automatically shut off after 2 hours (7200000 ms)
  if (timerRunning && (millis() - startTime >= RUN_TIME)) {
    timerRunning = false;
    digitalWrite(RELAY_PIN, HIGH); // HIGH turns Songle relay OFF
    Esplora.writeRGB(255, 0, 0);   // Red LED = Outlet OFF
    
    // Play a 3-note end-of-timer chime
    Esplora.tone(880, 200);
    delay(250);
    Esplora.tone(880, 200);
    delay(250);
    Esplora.tone(1175, 400);
  }
}
