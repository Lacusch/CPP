#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
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
      throw std::logic_error("Database corrupted or empty");
    if (line.compare("date,exchange_rate") != 0)
      throw(std::logic_error) "Invalid header file, required format is: "
                              "date,exchange_rate";
    while (std::getline(data_csv, line))
      database.insert(
          std::pair<std::string, float>(getDate(line), getValue(line)));
    data_csv.close();
    validateDatabase();
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
          std::string date = line.substr(0, line.find(" "));
          float coin_nbr = std::atof(line.substr(line.find("|"), +2).c_str());
          float value = getExchangeRate(date);
          if (value > 0) {
            std::cout << date << "=>" << coin_nbr << std::fixed
                      << std::setprecision(2) << coin_nbr * value << std::endl;
          } else {
            std::cout << "Error: "
                      << "No information on this date" << std::endl;
          }
        }
    }
    input.close();
  }
}

bool BitcoinExchange::validLine(std::string const &line) const {
  errors error;
  std::string date = line.substr(0, line.find(" "));
  std::string value;
  if (line.find("|") != std::string::npos) {
    value = line.substr(line.find("|") + 2);
    error = NO_ERROR;
  } else
    error = NO_VALUE;
  if (error != NO_ERROR || (error = validDate(line)) || (error = validValue(line))) {
    printError(error);
    return false;
  }
  return true;
}
errors BitcoinExchange::validDate(std::string line) const {
  std::string date, year, month, day;
  date = line.substr(0, line.find(" "));
  year = date.substr(0, date.find("-"));
  month = date.substr(5, 2);
  day = date.substr(8, 2);
  std::stringstream y_stream(year), m_stream(month), d_stream(day);
  int y_int, m_int, d_int;
  y_stream >> y_int, m_stream >> m_int, d_stream >> d_int;
  if (y_int < 2008 || y_int > 2025)
    return WRONG_YEAR;
  if (invalidMonth(month))
    return WRONG_MONTH;
  if (invalidDay(day))
    return WRONG_DAY;
  return NO_ERROR;
};

bool BitcoinExchange::invalidMonth(std::string month) const {
  std::map<int, int>::const_iterator monthIt = daysOfMonth.begin();
  if (month[0] == '0' && month.length() == 2)
    month = month.substr(1);
  for (; monthIt != daysOfMonth.end(); monthIt++)
    if (monthIt->first == std::atoi(month.c_str()))
      return false;
  return true;
}

bool BitcoinExchange::invalidDay(std::string day) const {
  std::map<int, int>::const_iterator dayIT = daysOfMonth.begin();
  if (day[0] == '0' && day.length() == 2)
    day = day.substr(1);
  if (day[0] == '0' && day.length() == 2)
    day = day.substr(1);
  for (; dayIT != daysOfMonth.end(); dayIT++)
    if (dayIT->first == std::atoi(day.c_str()) && std::atoi(day.c_str()) > 0 &&
        dayIT->second >= std::atoi(day.c_str()))
      return false;
  return true;
}

void BitcoinExchange::printError(errors error) const {
  switch (error) {
  case (NO_ERROR):
    break;
  case (WRONG_YEAR):
    std::cout << "Error: "
              << "Year is invalid" << std::endl;
    break;
  case (WRONG_MONTH):
    std::cout << "Error: "
              << "Month is invalid" << std::endl;
    break;
  case (WRONG_DAY):
    std::cout << "Error: "
              << "Day is invalid" << std::endl;
    break;
  case (NO_VALUE):
    std::cout << "Error: "
              << "No value given" << std::endl;
    break;
  case (NOT_POSITIVE):
    std::cout << "Error: "
              << "Number is not positive" << std::endl;
    break;
  case (OUT_OF_RANGE):
    std::cout << "Error: "
              << "Out of range, number is too big" << std::endl;
    break;
  }
}

errors BitcoinExchange::validValue(std::string const &line) const {
  std::string value = line.substr(line.find("|", +1));
  std::stringstream number_stream(value);
  float number;
  number_stream >> number;
  if (number < 0)
    return NOT_POSITIVE;
  if (number > 1000)
    return OUT_OF_RANGE;
  return NO_ERROR;
}

float BitcoinExchange::getExchangeRate(std::string date) const {
  std::map<std::string, float>::const_iterator dataBase = database.begin();
  for (; dataBase != database.begin(); dataBase++) {
    if (dataBase->first.compare(date) == 0)
      return dataBase->second;
  }
  dataBase = database.lower_bound(date);
  if (dataBase == database.begin())
    return -1;
  dataBase--;
  return dataBase->second;
}