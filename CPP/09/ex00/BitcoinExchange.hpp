#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
class BitcoinExchange {
public:
  // orthodox
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &cpy);
  BitcoinExchange &operator=(BitcoinExchange const &cpy);
  static unsigned int getDateOfMonth();

private:
  std::map<unsigned int, unsigned int> daysOfMonth;
  std::map<std::string, float> database;
  void setDaysOfMonth();
  void validateDatabase() const;
  std::string getDate(std::string);
  float getValue(std::string);
};
#endif
