// #ifndef CALENDAR_JSON_FORMATTER_HPP
// #define CALENDAR_JSON_FORMATTER_HPP

// #include "JsonFormatter.hpp"
// #include "RTCController.h"
// #include "Calendar.h"

// class CalendarJsonFormatter : public JsonFormatter
// {
// public:
//     CalendarJsonFormatter(Calendar &calendar, String prefix) : mCalendar(calendar),
//                                                                mPrefix(prefix)
//     {
//     }

//     void appendJson(StaticJsonDocument<FULL_JSON_SIZE> &document)
//     {
//         listMeetings(document);
//         listDailyMeetings(document);
//     }

//     void listMeetings(StaticJsonDocument<FULL_JSON_SIZE> &document)
//     {
//         JsonArray json = document.createNestedArray(mPrefix + "meetings");
//         const Vector<CalendarEntry> meetings = mCalendar.getMeetings();

//         if (meetings.size() == 0)
//             Serial.println("no meeting planned");

//         for (int i = 0; i < meetings.size(); i++)
//         {
//             JsonObject object = JsonObject();
//             object.getOrAddMember("startAt").set(formatMeeting(meetings[i].startDate));
//             object.getOrAddMember("endAt").set(formatMeeting(meetings[i].endDate));
//             json.add(object);
//         }
//     }

//     JsonArray listDailyMeetings(StaticJsonDocument<FULL_JSON_SIZE> &document)
//     {
//         JsonArray json = document.createNestedArray(mPrefix + "daily_meetings");
//         const Vector<DailyEntry> &meetings = mCalendar.getDailyMeetings();

//         if (meetings.size() == 0)
//             Serial.println("no daily meeting planned");

//         for (int i = 0; i < meetings.size(); i++)
//         {
//             JsonObject object = JsonObject();
//             object.getOrAddMember("startAt").set(formatDailyMeeting(meetings[i].startHour));
//             object.getOrAddMember("endAt").set(formatDailyMeeting(meetings[i].endHour));
//             json.add(object);
//         }
//     }

//     String formatDailyMeeting(const DateTime &date)
//     {
//         return String(date.hour() + '-' + date.minute() + '-' + date.second());
//     }

//     String formatMeeting(const DateTime &date)
//     {
//         return String(date.year() + '-' + date.month() + '-' + date.day() + '-' + +date.hour() + '-' + date.minute() + '-' + date.second());
//     }

// private:
//     Calendar &mCalendar;
//     String mPrefix;
// };

// #endif // CALENDAR_JSON_FORMATTER_HPP