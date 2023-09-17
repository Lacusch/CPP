#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
class BitcoinExchange {
public:
  // orthodox
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(BitcoinExchange &cpy);
  BitcoinExchange &operator=(BitcoinExchange &cpy);

private:
  std::map<unsigned int, unsigned int> daysOfMonth;
  std::map<std::string, float>database;
  };
#endif
