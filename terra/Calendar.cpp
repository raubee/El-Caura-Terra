// #include "Calendar.h"

// bool Calendar::isInMeeting()
// {
//     return isInSimpleMeeting() || isInDailyMeeting();
// }

// bool Calendar::isInSimpleMeeting()
// {
//     uint32_t currentTime = RTClib::now().unixtime();

//     for (int i = 0; i < mMeetings.size(); i++)
//     {
//         uint32_t startDate = mMeetings[i].startDate.unixtime();
//         uint32_t endDate = mMeetings[i].endDate.unixtime();

//         if (currentTime >= startDate && currentTime < endDate)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// bool Calendar::isInDailyMeeting()
// {
//     uint32_t currentTime = RTClib::now().unixtime();

//     for (int i = 0; i < mDailyMeetings.size(); i++)
//     {
//         uint32_t startHour = mDailyMeetings[i].startHour.unixtime();
//         uint32_t endHour = mDailyMeetings[i].endHour.unixtime();

//         if (currentTime >= startHour && currentTime < endHour)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// void Calendar::planMeeting(CalendarEntry entry)
// {
//     Serial.println("plan meeting");
//     mMeetings.push_back(entry);
// }

// void Calendar::planDailyMeeting(DailyEntry entry)
// {
//     Serial.println("plan daily meeting");
//     mDailyMeetings.push_back(entry);
// }