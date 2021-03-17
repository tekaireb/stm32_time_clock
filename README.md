# Time Clcok
<b>STM32-based Bluetooth time clock</b>

## Description
This is a time clock which allows employees to clock in and out via Bluetooth. An administrator interface allows users to see all employees at a glance and holds more detailed data about clock in and out events. The system also determines the number of hours worked by each employee and calculates payroll for the pay period.

## Technologies
Built in C/C++. Makes use of the HAL library for STM32.
Components:
 - STM32L476
 - HC-05 Bluetooth Module
 - ILI9341 TFT LCD

## Screenshots

<p align="center">
  <br/><br/><span>Main Screen</span><br/>
  <img alt="Main Screen" src="https://raw.githubusercontent.com/tekaireb/stm32_time_clock/main/Screenshots/Main Screen.png">
  <br/><br/><span>Employee List</span><br/>
  <img alt="Employee List" src="https://raw.githubusercontent.com/tekaireb/stm32_time_clock/main/Screenshots/Employee List.png">
    <br/><br/><span>Employee Profile</span><br/>
  <img alt="Employee Profile" src="https://raw.githubusercontent.com/tekaireb/stm32_time_clock/main/Screenshots/Employee Profile.png">
  <br/><br/><span>Payroll</span><br/>
  <img alt="Payroll" src="https://raw.githubusercontent.com/tekaireb/stm32_time_clock/main/Screenshots/Payroll.png">
  <br/><br/><span>Help Screen</span><br/>
  <img alt="Help Screen" src="https://raw.githubusercontent.com/tekaireb/stm32_time_clock/main/Screenshots/Help Screen.png">
</p>

Driver for LCD (ILI9341) based on work by [olegv142](https://github.com/olegv142/STM32L4-ILI9341).
