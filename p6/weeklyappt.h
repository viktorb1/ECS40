#ifndef WEEKLYAPPT_H
#define WEEKLYAPPT_H

#include "appt.h"

class WeeklyAppointment : public Appointment
{
  char series[8];
  int seriesCount;
public:
  WeeklyAppointment();
  virtual ~WeeklyAppointment();
  virtual WeeklyAppointment* clone() const;
  virtual WeeklyAppointment* read(istream &is);
  WeeklyAppointment(const WeeklyAppointment &weeklyappt);
  const char* getSeries() const;
  int getSeriesCount() const;
  virtual ostream& write(ostream &os) const;
}; // class WeeklyAppointment


#endif