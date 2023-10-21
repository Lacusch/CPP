#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
/**
 * @brief Construct a new Bitcoin Exchange:: Bitcoin Exchange object
 *
 */
BitcoinExchange::BitcoinExchange() {
  setDaysOfMonth();
  std::ifstream data_csv("./data/data.csv");
  std::string line;
  if (data_csv.is_open()) {
    std::getline(data_csv, line);
    if (data_csv.peek() == std::ifstream::traits_type::eof())
      throw std::logic_error("Database corrupted or empty");
    if (line.compare("date,exchange_rate") != 0)
      throw(std::logic_error) "Invalid header file, required format is: "
                              "date,exchange_rate";
    while (std::getline(data_csv, line))
      database.insert(
          std::pair<std::string, float>(getDate(line), getValue(line)));
    // getDate return a substring of the date
    // getValue returns the value as a float
    data_csv.close();
    validateDatabase();
    // check the database for errors;
  } else {
    throw std::logic_error("Error: Can't find data");
  }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy) { *this = cpy; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &cpy) {
  this->daysOfMonth = cpy.daysOfMonth;
  this->database = cpy.database;
  return *this;
}

/**
 * @brief Set the Days of Month in a map
 * @example  January: <1, 31> February <2, 27>, etc);
 * @param exchange The exchange the data is located in
 */
void BitcoinExchange::setDaysOfMonth() {
  daysOfMonth.insert(std::make_pair(1, 31));
  daysOfMonth.insert(std::make_pair(2, 28));
  daysOfMonth.insert(std::make_pair(3, 31));
  daysOfMonth.insert(std::make_pair(4, 30));
  daysOfMonth.insert(std::make_pair(5, 31));
  daysOfMonth.insert(std::make_pair(6, 30));
  daysOfMonth.insert(std::make_pair(7, 31));
  daysOfMonth.insert(std::make_pair(8, 31));
  daysOfMonth.insert(std::make_pair(9, 30));
  daysOfMonth.insert(std::make_pair(10, 31));
  daysOfMonth.insert(std::make_pair(11, 30));
  daysOfMonth.insert(std::make_pair(12, 31));
}

void BitcoinExchange::validateDatabase() const {}
