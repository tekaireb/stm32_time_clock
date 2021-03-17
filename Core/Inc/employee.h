/*
 * employee.h
 *
 *  Created on: Mar 2, 2021
 *      Author: Tyler
 */

#ifndef SRC_EMPLOYEE_H_
#define SRC_EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Event: records clock in/out events associated with an employee
typedef struct {
    int clock_in;
    struct tm timestamp;
} Event;

// Employee: holds information associated with an employee
typedef struct {
    int id;
    char name[50];
    float wage;
    int admin;
    Event events[50];
    int num_events;
} Employee;

extern int num_employees;
extern Employee* employees[50];

Employee* get_employee(int id);

void add_event(int id, int clock_in, time_t t);

void clear_events(int id);

void add_employee(int id, char* name, int wage, int admin);

void remove_employee(int id);

float calculate_hours(Employee* e);

float calculate_pay(Employee* e);

void add_demo_data();


#endif /* SRC_EMPLOYEE_H_ */
