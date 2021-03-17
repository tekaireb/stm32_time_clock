#include "employee.h"

num_employees = 0;
Employee* employees[] = {};

int _get_employee_index(int id) {
    for (int i = 0; i < num_employees; i++)
        if (employees[i]->id == id)
            return i;
    return -1;
}

Employee* get_employee(int id) {
	return employees[_get_employee_index(id)];
}

void add_event(int id, int clock_in, time_t t) {
    Event event = (Event) {
        .clock_in = clock_in,
        .timestamp = *localtime(&t)
    };
    
    Employee * e = get_employee(id);
    e->events[e->num_events++] = event;
}

void clear_events(int id) {
    Employee * e = get_employee(id);
    memset(&e->events[0], 0, sizeof(e->events));
    e->num_events = 0;
}

void add_employee(int id, char* name, int wage, int admin) {
    employees[num_employees] = malloc(sizeof(Employee));

    *employees[num_employees] = (Employee) {
        .id = id,
        .wage = wage,
        .admin = admin,
        .num_events = 0
    };

    strcpy(employees[num_employees++]->name, name);
}

void remove_employee(int id) {
    int i = _get_employee_index(id);
    
    free(employees[i]);

    num_employees--;
    for (; i < num_employees; i++)
        employees[i] = employees[i + 1];
}

float calculate_hours(Employee* e) {
    float secs = 0;
    for (int j = 0; j < e->num_events - e->num_events % 2 - 1; j += 2)
        secs += difftime(mktime(&e->events[j + 1].timestamp), mktime(&e->events[j].timestamp));
    
    return secs / 3600; // Hours
}

float calculate_pay(Employee* e) {
    return e->wage * calculate_hours(e);
}

void add_demo_data() {
    time_t t = 1613980800, hr = 3600;
    
    add_employee(796, (char*) "Alice", 10, 0);
    add_employee(301, (char*) "Bob", 12, 0);
    add_employee(289, (char*) "Charlie", 15, 1);
    add_employee(445, (char*) "Daniel", 25, 0);
    add_employee(631, (char*) "Edgar", 32, 1);
    add_employee(132, (char*) "Fulgencio", 14, 0);
    add_employee(877, (char*) "Gunther", 40, 1);
    
    add_event(796, 1, t);
    add_event(796, 0, t + 4 * hr);
    add_event(796, 1, t + 5 * hr);
    add_event(796, 0, t + 8 * hr);
    
    add_event(301, 1, t + 120);
    add_event(301, 0, t + 8 * hr + 60);
    
    add_event(289, 1, t + 240);
    add_event(289, 0, t + 7 * hr + 1800);

    add_event(132, 1, t + 240);
}





// ==OLD==

// void calculate_payroll() {
//     printf("\nPAYROLL:");
//     printf("\n%-10s\t %-7s  %-6s  %s", "[Name]", "[Hours]", "[Wage]", "[Compensation]");

//     float secs = 0, hours, pay, sum_total = 0;
//     Employee * e;
//     for (int i = 0; i < num_employees; i++) {
//         e = &employees[i];
//         printf("\n%-10s\t ", e->name);

//         for (int j = 0; j < e->num_events - e->num_events % 2 - 1; j += 2)
//             secs += difftime(mktime(&e->events[j + 1].timestamp), mktime(&e->events[j].timestamp));
//         hours = secs / 3600;
//         printf("%-7.2f  $%-6.2f ", hours, e->wage);

//         pay = hours * e->wage;
//         printf("$%.2f", pay);

//         sum_total += pay;
//         secs = 0;
//     }

//     printf("\nSUM TOTAL: $%0.2f", sum_total);
// }

//void print_data() {
//    printf("EMPLOYEE DATA:\n");
//
//    printf("%-18s\t\t %-5s\t %-5s \n", "[Name]", "[ID]", "[Wage]");
//    Employee * e;
//    for (int i = 0; i < num_employees; i++) {
//        e = &employees[i];
//        printf("%-18s\t\t #%-5d\t $%.2f/hr \n", strcat(e->name, (e->admin ? " (ADMIN)" : "")), e->id, e->wage);
//        for (int j = 0; j < e->num_events; j++) {
//            printf(j == e->num_events - 1 ? " └──" : " ├──");
//            char t[20];
//            strftime(t, sizeof(t), "%I:%M %p (%m/%d)", &e->events[j].timestamp);
//            printf("%s @ %s\n", e->events[j].clock_in ? "IN " : "OUT", t);
//        }
//    }
//
//    printf("\n\n");
//}
//
//int main() {
//    printf("\n\nWELCOME TO TIME CLOCK\n\n");
//
//    add_demo_data();
//    print_data();
//
//    calculate_payroll();
//
//    return 0;
//}
