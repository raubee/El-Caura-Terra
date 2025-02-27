// #ifndef CALENDARY_ENTRY_HPP
// #define CALENDARY_ENTRY_HPP

// #include "DS3231.h"

// struct CalendarEntry
// {
//     DateTime startDate;
//     DateTime endDate;
// };

// struct DailyEntry
// {
//     DateTime startHour;
//     DateTime endHour;
// };

// struct WeeklyEntry : DailyEntry
// {
//     WeeklyEntry(DateTime start, DateTime end, uint8_t *days, uint8_t daysSize) : daysOfTheWeek(days),
//                                                                                  nbDays(daysSize){
//                                                                                      startHour = start;
//                                                                                      endHour = end;
//                                                                                  };
//     uint8_t *daysOfTheWeek;
//     uint8_t nbDays;
// };

// #endif // CALENDARY_ENTRY_HPP