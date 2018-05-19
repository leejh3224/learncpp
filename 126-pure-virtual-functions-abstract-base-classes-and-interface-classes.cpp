// body of all member functions are pure virtual functions => interface class
class IErrorLog
{
public:
  virtual bool openLog(const char *filename) = 0;
  virtual bool closeLog() = 0;
  virtual bool writeError(const char *errorMessage) = 0;
  virtual ~IErrorLog(){};
};

// interface in use
double mySqrt(double value, IErrorLog &log)
{
  if (value < 0.0)
  {
    log.writeError("Tried to take square root of value less than 0");
    return 0.0;
  }
  else
    return sqrt(value);
}