#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, LED_BUILTIN);

int bx, by, dx, dy; 

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(display.width()/4,display.height()/2);             // Start at top-left corner
  display.println(F("Ball Game"));
  display.display();
  delay(5000);
  
  bx = display.width()/2;
  by = display.height()/2;
  dx = dy = 3; 
}

void loop() {

  display.clearDisplay();  
  display.drawRect(1, 1, display.width()-1, display.height()-1, SSD1306_WHITE);  
  display.fillCircle(bx, by, 3, SSD1306_WHITE);
  display.display();
  delay(50);
  bx += dx;
  by += dy;
  if(bx < 0 || bx > display.width()) dx = -dx; 
  if(by < 0 || by > display.height()) dy = -dy; 
  
}
