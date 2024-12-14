#include<Arduino.h>
void setup() {
  // 设置13号端口为输出模式
  pinMode(13, OUTPUT);
}
void loop() {
  // 使13号端口输出高电平
  digitalWrite(13, HIGH);
  delay(1000); // 延迟1秒
  // 使13号端口输出低电平
  digitalWrite(13, LOW);
  delay(1000); // 延迟1秒
}