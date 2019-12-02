// Copyright (c) 2019 Joseph Palermo All rights reserved.
//
// Created by: Joseph Palermo
// Created on: November 2019
// This program rounds takes a number and rounds it

#include <iostream>
#include <iomanip>
#include <cmath>

float Rounding(float &number, float decimalPoint) {
    // this function takes a number and rounds it

    // variables
    float roundedNumber;

    // process
    roundedNumber = number*pow(10, decimalPoint);
    roundedNumber = roundedNumber + 0.5;
    roundedNumber = static_cast<int>(roundedNumber);
    roundedNumber = roundedNumber/pow(10, decimalPoint);

    return roundedNumber;
}

int main() {
    // this function gets a number from the user and outputs the rounded number

    // variables
    std::string userNumberAsString;
    std::string decimalPlaceAsString;
    float userRoundedNumber;
    float userNumber;
    int decimalPlace;

    // process
    while (true) {
        std::cout << "Enter the number you want to be rounded:" << std::endl;
        std::cin >> userNumberAsString;
        std::cout << "Enter how many decimals you want left:" \
        << std::endl;
        std::cin >> decimalPlaceAsString;

        try {
            userNumber = std::stof(userNumberAsString);
            decimalPlace = std::stoi(decimalPlaceAsString);
            if (userNumber == std::stof(userNumberAsString) && \
                decimalPlace == std::stoi(decimalPlaceAsString)) {
                    userRoundedNumber = Rounding(userNumber, decimalPlace);
                    std::cout << "" << std::endl;
                    std::cout << "Your rounded number is: " \
                    << userRoundedNumber << std::endl;
                    break;
                } else {
                    std::cout << "Please insert a number" << std::endl;
                    break;
                }
        } catch (std::invalid_argument) {
            std::cout << "" << std::endl;
            std::cout << "Please insert a number" << std::endl;
            break;
        }
    }
}
