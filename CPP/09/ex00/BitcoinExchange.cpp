#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <sys/_types/_size_t.h>
/**
 * @brief Construct a new Bitcoin Exchange:: Bitcoin Exchange object
 *
 */
BitcoinExchange::BitcoinExchange(char *cStringPath) {
  input_path = cStringPath;
  checkInputPath(input_path);
  setDaysOfMonth();
  std::ifstream data_csv("./data/data.csv");
  std::string line;
  if (data_csv.is_open()) {
    std::getline(data_csv, line);
    if (data_csv.peek() == std::ifstream::traits_type::eof())
      if (line.compare("date,exchange_rate") != 0)
        throw std::logic_error("Database corrupted or empty");
    throw(std::logic_error) "Invalid header file, required format is: "
                            "date,exchange_rate";
    while (std::getline(data_csv, line))
      database.insert(
          std::pair<std::string, float>(getDate(line), getValue(line)));
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

std::string BitcoinExchange::getDate(std::string line) const {
  return line.substr(0, line.find(","));
}

float BitcoinExchange::getValue(std::string line) const {
  if (line.find(",") != std::string::npos && line[line.size() - 1] != ',')
    return std::stof(line.substr(line.find(",") + 1));
  else
    throw std::logic_error("Invalid value in csv database");
  return -1;
}

void BitcoinExchange::checkInputPath(std::string inputPath) {
  if (inputPath.find(".csv") == std::string::npos || inputPath.length() < 5)
    throw std::logic_error("Not a .csv file");
  checkInputFile(inputPath);
};

void BitcoinExchange::checkInputFile(std::string input_file) {
  std::string line;
  std::fstream inputCsv("./data" + input_file);
  if (inputCsv.is_open()) {
    if (line.compare("date | value") != 0)
      throw std::logic_error("invalid header in input file");
    inputCsv.close();
  }
}

void BitcoinExchange::exchange() {
  std::string line;
  std::ifstream input(input_path);
  if (input.is_open()) {
    size_t i = 0;
    while (std::getline(input, line)) {
      if (i++ > 0)
        if (validLine(line)) {
          // print out
          // getExchangeRate();
        }
    }
  }
}

bool BitcoinExchange::validLine(std::string const &line) {

  errors error;
  std::string date = line.substr(0, line.find(" "));
  std::string value;
  if (line.find("|") != std::string::npos)
    value = line.substr(line.find("|") + 2);
  else
    error = NO_VALUE;
  if (error || (error = validDate(line)) || (error = validValue(line))) {
    printError(error);
    return true;
  }
}
errors BitcoinExchange::validDate(std::string const &line) {
  std::string date, year, month, day;
  
};

void BitcoinExchange::printError(errors error) const {
  switch (error) {
  case (NO_ERROR):
    break;
  case (WRONG_YEAR):
    std::cout << "" << std::endl;
    break;
  case (WRONG_MONTH):
    std::cout << "" << std::endl;
    break;
  case (WRONG_DAY):
    std::cout << "" << std::endl;
    break;
  case (NO_VALUE):
    std::cout << "" << std::endl;
    break;
  case (NOT_POSITIVE):
    std::cout << "" << std::endl;
    break;
  case (OUT_OF_RANGE):
    std::cout << "" << std::endl;
    break;
  }
}
