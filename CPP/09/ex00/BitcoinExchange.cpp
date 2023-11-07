#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

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

std::string BitcoinExchange::getDate(std::string line) const {
  return line.substr(0, line.find(","));
}

float BitcoinExchange::getValue(std::string line) const {
  if (line.find(",") != std::string::npos && line[line.size() - 1] != ',') {
    return (atof(line.substr(line.find(",") + 1).c_str()));
  } else
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
  std::fstream inputCsv(input_file.c_str());
  if (inputCsv.is_open() || inputCsv.peek() != inputCsv.eof()) {
    std::getline(inputCsv, line);
    if (line.compare("date | value") != 0)
      throw std::logic_error("invalid header in input file");
  } else {
    throw std::logic_error(input_file + " can't be opened");
  }
  while (std::getline(inputCsv, line)) {
    if (line.find_first_not_of(VALID) != std::string::npos) {
      throw std::logic_error("invalid character found in input .csv");
    }
  }
  inputCsv.close();
}

// void checkInputFileDub(std::string input_file) {
//   std::string line;
//   std::fstream inputCsv(input_file.c_str());
//   inputCsv.close();
// }

void BitcoinExchange::exchange() {
  std::string line;
  std::ifstream input(input_path.c_str());
  if (input.is_open()) {
    size_t i = 0;
    while (std::getline(input, line)) {
      if (i > 0)
        if (validLine(line)) {
          std::string date = line.substr(0, line.find(" "));

          float coin_nbr = std::atof(line.substr(line.find("|") + 2).c_str());
          float value = getExchangeRate(date);
          if (value >= 0) {
            std::cout << date << " => " << coin_nbr << " = " << std::fixed
                      << std::setprecision(2) << coin_nbr * value << std::endl;
          } else {
            std::cout << "Error: "
                      << "No information on this date" << std::endl;
          }
        }
      i++;
    }
    input.close();
  }
}

bool BitcoinExchange::validLine(std::string const &line) {
  errors error;
  std::string date = line.substr(0, line.find(" "));
  std::string value;
  if (line.find("|") != std::string::npos) {
    value = line.substr(line.find("|") + 2);
    error = NO_ERROR;
  } else
    error = NO_VALUE;
  if (error != NO_ERROR || (error = validDate(line)) ||
      (error = validValue(line))) {
    printError(error);
    return false;
  }
  return true;
}
errors BitcoinExchange::validDate(std::string line) {
  if (line.size() < 14)
    return BAD_INPUT;
  if (line.substr(0, 4).find_first_not_of(DIGITS) != std::string::npos)
    return BAD_INPUT;
  if (line[4] != '-' || line[7] != '-' || line[11] != '|' || line[10] != ' ' ||
      line[12] != ' ')
    return BAD_INPUT;
  if (line.substr(5, 2).find_first_not_of(DIGITS) != std::string::npos)
    return BAD_INPUT;
  if (line.substr(8, 2).find_first_not_of(DIGITS) != std::string::npos)
    return BAD_INPUT;
  if (line.substr(13, std::string::npos).find_first_not_of("123456789.") !=
      std::string::npos)
    return BAD_INPUT;
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
  if (invalidDay(day, month))
    return WRONG_DAY;
  return NO_ERROR;
};

bool BitcoinExchange::invalidMonth(std::string month) const {
  if (month[0] == '0' && month.length() == 2)
    month = month.substr(1);
  for (std::map<int, int>::const_iterator monthIt = daysOfMonth.begin();
       monthIt != daysOfMonth.end(); monthIt++)
    if (monthIt->first == std::atoi(month.c_str()))
      return false;
  return true;
}

bool BitcoinExchange::invalidDay(std::string day, std::string month) {
  std::map<int, int>::iterator monthIt = daysOfMonth.begin();
  if (day[0] == '0' && day.length() == 2)
    day = day.substr(1);
  if (month[0] == '0' && month.length() == 2)
    month = month.substr(1);
  for (; monthIt != daysOfMonth.end(); monthIt++)
    if (monthIt->first == std::atoi(month.c_str()) &&
        std::atoi(day.c_str()) > 0 && monthIt->second >= std::atoi(day.c_str()))
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
  case (BAD_INPUT):
    std::cout << "Error: "
              << "bad input" << std::endl;
    break;
  }
}

errors BitcoinExchange::validValue(std::string const &line) const {
  std::string value = line.substr(line.find("|") + 1);
  std::stringstream string_stream(value);
  float number;
  string_stream >> number;
  if (number < 0)
    return NOT_POSITIVE;
  if (number > 1000)
    return OUT_OF_RANGE;
  return NO_ERROR;
}

float BitcoinExchange::getExchangeRate(std::string date) {
  std::map<std::string, float>::iterator dataBase = database.begin();
  for (; dataBase != database.end(); dataBase++) {
    if (dataBase->first.compare(date) == 0) {
      return dataBase->second;
    }
  }
  dataBase = database.lower_bound(date);
  if (dataBase == database.begin())
    return -1;
  dataBase--;
  return dataBase->second;
}
