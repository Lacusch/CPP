#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include "iostream"
#include <map>
#include <sstream>
#include <string>
enum errors {
  NO_ERROR,
  WRONG_YEAR,
  WRONG_MONTH,
  WRONG_DAY,
  NO_VALUE,
  NOT_POSITIVE,
  OUT_OF_RANGE,
};

class BitcoinExchange {
public:
  ;
  // orthodox
  BitcoinExchange(char *input_path);
  ~BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &cpy);
  BitcoinExchange &operator=(BitcoinExchange const &cpy);
  void exchange();

private:
  std::map< int, int> daysOfMonth;
  std::map<std::string, float> database;
  std::string input_path;
  void setDaysOfMonth();
  void validateDatabase() const;
  std::string getDate(std::string line) const;
  float getValue(std::string line) const;
  void checkInputPath(std::string input_path);
  void checkInputFile(std::string input_file);
  bool validLine(std::string const &line) const;
  errors validDate(std::string) const;
  errors validValue(std::string const &line) const;
  void printError(errors error) const;
  bool invalidMonth(std::string month) const;
  bool invalidDay(std::string day) const;
  float getExchangeRate(std::string date) const;
};
#endif
