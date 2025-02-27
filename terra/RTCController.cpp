// #include "RTCController.h"

// RTCController::RTCController() {}

// void RTCController::init()
// {
//   Wire.begin();
// }

// String RTCController::toString()
// {
//   String str;
//   str += getYear();
//   str += "-";
//   str += getMonth();
//   str += "-";
//   str += getDay();
//   str += " ";
//   str += getHours();
//   str += ":";
//   str += getMinutes();
//   str += ":";
//   str += getSeconds();
//   return str;
// }

// void RTCController::printClock()
// {
//   Serial.print(F("Date: "));
//   Serial.println((toString()));
// }

// void GetDateStuff(byte &Year, byte &Month, byte &Day, byte &DoW,
//                   byte &Hour, byte &Minute, byte &Second)
// {
//   // Call this if you notice something coming in on
//   // the serial port. The stuff coming in should be in
//   // the order YYMMDDwHHMMSS, with an 'x' at the end.
//   boolean GotString = false;
//   char InChar;
//   byte Temp1, Temp2;
//   char InString[20];

//   byte j = 0;
//   while (!GotString)
//   {
//     if (Serial.available())
//     {
//       InChar = Serial.read();
//       InString[j] = InChar;
//       j += 1;
//       if (InChar == 'x')
//       {
//         GotString = true;
//       }
//     }
//   }
//   Serial.println(InString);
//   // Read Year first
//   Temp1 = (byte)InString[0] - 48;
//   Temp2 = (byte)InString[1] - 48;
//   Year = Temp1 * 10 + Temp2;
//   // now month
//   Temp1 = (byte)InString[2] - 48;
//   Temp2 = (byte)InString[3] - 48;
//   Month = Temp1 * 10 + Temp2;
//   // now date
//   Temp1 = (byte)InString[4] - 48;
//   Temp2 = (byte)InString[5] - 48;
//   Day = Temp1 * 10 + Temp2;
//   // now Day of Week
//   DoW = (byte)InString[6] - 48;
//   // now Hour
//   Temp1 = (byte)InString[7] - 48;
//   Temp2 = (byte)InString[8] - 48;
//   Hour = Temp1 * 10 + Temp2;
//   // now Minute
//   Temp1 = (byte)InString[9] - 48;
//   Temp2 = (byte)InString[10] - 48;
//   Minute = Temp1 * 10 + Temp2;
//   // now Second
//   Temp1 = (byte)InString[11] - 48;
//   Temp2 = (byte)InString[12] - 48;
//   Second = Temp1 * 10 + Temp2;
// }

// void RTCController::setTime(DateTime date)
// {
//   while (!Serial)
//   {
//     ; // wait for serial port to connect. Needed for native USB port only
//   }

//   mClock.setClockMode(false); // set to 24h
//   //setClockMode(true);	// set to 12h

//   // Serial.println("Year : " + date.year());
//   mClock.setYear(date.year() - 2000);
//   mClock.setMonth(date.month());
//   mClock.setDate(date.day());
//   // mClock.setDoW(date.dayOfTheWeek());
//   mClock.setHour(date.hour());
//   mClock.setMinute(date.minute());
//   mClock.setSecond(date.second());
// }