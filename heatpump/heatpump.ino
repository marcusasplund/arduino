#include <MitsubishiHeatpumpIR.h>
#include <IRremote.h>

IRSenderPWM irSender(9);
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;



MitsubishiFDHeatpumpIR *heatpumpIR;

void setup()
{
  Serial.begin(9600);
  heatpumpIR = new MitsubishiFDHeatpumpIR();
  irrecv.enableIRIn(); // Start the receiver

  delay(500);

  Serial.println(F("Starting"));
}

void loop()
{

  heatpumpIR->send(irSender, POWER_ON, MODE_HEAT, FAN_3, 30, VDIR_AUTO, HDIR_AUTO);
  delay(1500);
  heatpumpIR->send(irSender, POWER_ON, MODE_DRY,  FAN_2, 20, VDIR_AUTO, HDIR_AUTO);
  delay(1500);
  heatpumpIR->send(irSender, POWER_ON, MODE_FAN, FAN_AUTO, 18, VDIR_AUTO, HDIR_AUTO);
  delay(1500);
  heatpumpIR->send(irSender, POWER_ON, MODE_COOL, FAN_1, 18, VDIR_AUTO, HDIR_AUTO);
  delay(2500);
  heatpumpIR->send(irSender, POWER_OFF, MODE_COOL, FAN_1, 18, VDIR_AUTO, HDIR_AUTO);
  delay(1500);

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(2000);

}
