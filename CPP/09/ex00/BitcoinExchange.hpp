#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include "iostream"
#include <map>
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
  std::map<unsigned int, unsigned int> daysOfMonth;
  std::map<std::string, float> database;
  std::string input_path;
  void setDaysOfMonth();
  void validateDatabase() const;
  std::string getDate(std::string line) const;
  float getValue(std::string line) const;
  void checkInputPath(std::string input_path);
  void checkInputFile(std::string input_file);
  bool validLine(std::string const &line);
  errors validDate(std::string const &line);
  errors validValue(std::string const &line);
  void printError(errors error)const;
};
#endif
